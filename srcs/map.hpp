// Map.hpp

#ifndef MAP_HPP
# define MAP_HPP

# include <sys/time.h>

# include <cstddef>
# include <memory>
# include <algorithm>

# include "utils/pair.hpp"
# include "utils/make_pair.hpp"
# include "utils/less_binary_function.hpp"
# include "utils/node.hpp"
# include "utils/bidirectional_iterator.hpp"
# include "utils/reverse_iterator.hpp"
# include "vector.hpp"

namespace ft {

	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator< ft::pair<const Key, T> > >
	class map {

		public:

		typedef Key																			key_type;
		typedef T																			mapped_type;
		typedef ft::pair<const key_type, mapped_type>										value_type;
		typedef Compare																		key_compare;
		typedef Alloc																		allocator_type;
		typedef value_type&																	reference;
		typedef const value_type&															const_reference;
		typedef value_type*																	pointer;
		typedef const value_type*															const_pointer;
		typedef bidirectional_iterator<value_type, value_type*, value_type&>				iterator;
		typedef bidirectional_iterator<value_type, const value_type*, const value_type&>	const_iterator;
		typedef reverse_iterator<const_iterator>											const_reverse_iterator;
		typedef reverse_iterator<iterator>													reverse_iterator;
		typedef ptrdiff_t																	difference_type;
		typedef size_t																		size_type;

		typedef ft::node<value_type>														node;
		typedef ft::node<value_type>*														node_pointer;

		typedef typename Alloc::template rebind<node>::other								node_allocator;

		class value_compare: ft::binary_function<value_type, value_type, bool> {

			friend class map;

			protected:

				Compare	comp;
				value_compare(Compare c) : comp(c) {}

			public:

				typedef bool		result_type;
				typedef value_type	first_argument_type;
				typedef value_type	second_argument_type;

				bool operator() (const value_type& x, const value_type& y) const {
					return comp(x.first, y.first);
				}

		}; // class value_compare

		private:

			node_allocator	_allocator;
			Compare			_comp;
			size_type		_size;
			node_pointer	_root;
			node_pointer	_begin;
			node_pointer	_end;
			bool			_duplicate;
			node_pointer	_latest;

		public:

		// --- CONSTRUCTOR/DESTRUCTOR/OPERATOR= ---

			// default constructor
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _allocator(alloc), _comp(comp), _size(0), _root(), _begin(), _end(), _duplicate(false), _latest() {
				value_type empty = value_type(0, 0);
				_begin = _allocator.allocate(1);
				_allocator.construct(_begin, empty);
				_begin->_empty = true;
				_end = _allocator.allocate(1);
				_allocator.construct(_end, empty);
				_end->_empty = true;
			}

			// constructs map with elements between [first, last]
			template <class InputIterator>
			map(InputIterator first, InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type())
					: _allocator(alloc), _comp(comp), _size(0), _root(), _begin(), _end(), _duplicate(false), _latest() {
				value_type empty = value_type(0, 0);
				_begin = _allocator.allocate(1);
				_allocator.construct(_begin, empty);
				_begin->_empty = true;
				_end = _allocator.allocate(1);
				_allocator.construct(_end, empty);
				_end->_empty = true;
				_allocator.construct(_end, empty);
				insert(first, last);
			}

			// copy constructor
			map(const map& x) {
				_comp = x._comp;
				_allocator = x._allocator;
				_size = 0;
				_root = NULL;
				value_type empty = value_type(0, 0);
				_begin = _allocator.allocate(1);
				_allocator.construct(_begin, empty);
				_begin->_empty = true;
				_end = _allocator.allocate(1);
				_allocator.construct(_end, empty);
				_end->_empty = true;
				_allocator.construct(_end, empty);
				_duplicate = x._duplicate;
				_latest = NULL;
				insert(x.begin(), x.end());
			}

			// destructor
			~map() {
				if (_size)
					delete_tree(_root);
				else {
					_allocator.destroy(_begin);
					_allocator.destroy(_end);
					_allocator.deallocate(_begin, 1);
					_allocator.deallocate(_end, 1);
				}
			}

			// operator overload=
			map& operator=(const map& x) {
				if (this != &x) {
					clear();
					_allocator = x._allocator;
					_comp = x._comp;
					_size = 0;
					_root = NULL;
					_begin = x._begin;
					_end = x._end;
					insert(x.begin(), x.end());
				}
				return (*this);
			}

			// --- ITERATORS ---

			// returns iterator to first element
			iterator begin() {
				if (empty())
					return (end());
				return (iterator(_begin->_parent));
			}

			// returns const_iterator to first element
			const_iterator begin() const {
				if (empty())
					return (end());
				return (const_iterator(_begin->_parent));
			}

			// returns iterator to element after last
			iterator end() { return (iterator(_end)); }

			// returns const_iterator to element after last
			const_iterator end() const { return (const_iterator(_end)); }

			// returns reverse_iterator to reverse beginning (last element of container)
			reverse_iterator rbegin() { return (reverse_iterator(_end->_parent)); }

			// returns const_reverse_iterator to reverse beginning (last element of container)
			const_reverse_iterator rbegin() const { return (_end->_parent); }

			// returns reverse_iterator to reverse end (element before first)
			reverse_iterator rend() { return (reverse_iterator(_begin)); }

			// returns const_reverse_iterator to reverse end (element before first)
			const_reverse_iterator rend() const { return (const_reverse_iterator(_begin)); }

		// --- CAPACITY ---

			// returns true if empty
			bool empty() const { return (!_size); }

			// returns container size
			size_type size() const { return (_size); }

			// returns max container size
			size_type max_size() const { return (_allocator.max_size()); }

		// --- ELEMENT ACCESS ---

			mapped_type& operator[](const key_type& k) {
				return ((*((insert(ft::make_pair(k, mapped_type()))).first)).second);
			}

		// --- MODIFIERS ---

			// inserts new pair, returns pair with iterator to new element as first
			// returns bool as second: true if succeeded, false if key already exists
			ft::pair<iterator, bool> insert(const value_type& val) {
				_duplicate = false;
				remove_begin_end();
				_root = insert_node(_root, NULL, val);
				set_begin_end();
				if (_duplicate)
					return (ft::make_pair<iterator, bool>(iterator(_latest), false));
				else
					return (ft::make_pair<iterator, bool>(iterator(_latest), true));
			}

			// inserts new pair, returns iterator to newly added element or element with same key
			iterator insert(iterator position, const value_type& val) {
				if (find(val->first) == position)
					return (position);
				ft::pair<iterator, bool> pair = insert(val);
				return (pair->first);
			}

			// inserts range of iterators
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last) {
				while (first != last) {
					insert(*first);
					first++;
				}
			}

			// erases element position
			void erase(iterator position) {
				remove_begin_end();
				_root = erase_node(_root, position.first);
				set_begin_end();
			}

			// erases element with key k
			size_type erase(const key_type& k) {
				_erased = true;
				remove_begin_end();
				_root = erase_node(_root, k);
				set_begin_end();
				if (_erased)
					return (1);
				return (0);
			}

			// erases range [first, last]
			/*void erase(iterator first, iterator last) {*/
				//while (first != last) {
					//iterator temp = first;
					//temp++;
					//erase(first);
					//first = find(temp->first);
				//}
			/*}*/

			// exchanges contents of map with the contents of x
			void swap(map& x) {
				map temp(*this);

				*this = x;
				x = temp;
			}

			// deletes map content + deallocates
			void clear() {
				/*erase(begin(), end());*/
			}

		// --- OBSERVERS ---

			// returns key_compare object
			key_compare key_comp() const { return (_comp); }

			// returns value_compare object
			value_compare value_comp() const { return (value_compare(_comp)); }

		// --- OPERATIONS ---

			// returns iterator to k if k is in map
			// returns end if k is not in map
			iterator find(const key_type& k) {
				key_compare comp = key_comp();
				for (iterator it = begin(); it != end(); it++) {
					if (!comp(it->first, k) && !comp(k, it->first))
						return (it);
				}
				return (end());
			}

			// returns iterator to k if k is in map
			// returns end if k is not in map
			const_iterator find(const key_type& k) const {
				key_compare comp = key_comp();
				for (const_iterator it = begin(); it != end(); it++) {
					if (!comp(it->first, k) && !comp(k, it->first))
						return (it);
				}
				return (end());
			}

			// counts elements with k as key
			// returns 1 if found
			// returns 0 if not found
			// (keys can only occur once in a map)
			size_type count(const key_type& k) const { return (find(k) != end()) ? (1) : (0); }

			// if k is a key, returns const_iterator to k
			// if k is not a key, returns const_iterator after where k is supposed to go
			iterator lower_bound(const key_type& k) {
				iterator 	it = begin();
				key_compare	comp = key_comp();
				for (; it != end(); it++) {
					if (!comp(it->first, k))
						break ;
				}
				return (it);
			}

			// if k is a key, returns const_iterator to k
			// if k is not a key, returns const_iterator after where k is supposed to go
			const_iterator lower_bound(const key_type& k) const {
				const_iterator	it = begin();
				key_compare		comp = key_comp();
				for (; it != end(); it++) {
					if (!comp(it->first, k))
						break ;
				}
				return (it);
			}

			// if k is a key, returns const_iterator to k
			// if k is not a key, returns const_iterator after where k is supposed to go
			iterator upper_bound(const key_type& k) {
				iterator 	it = begin();
				key_compare	comp = key_comp();
				for (; it != end(); it++) {
					if (comp(k, it->first))
						break ;
				}
				return (it);
			}

			// if k is a key, returns const_iterator to k
			// if k is not a key, returns const_iterator after where k is supposed to go
			const_iterator upper_bound(const key_type& k) const {
				const_iterator	it = begin();
				key_compare		comp = key_comp();
				for (; it != end(); it++) {
					if (comp(k, it->first))
						break ;
				}
				return (it);
			}

			// returns pair of iterators, first is lower_bound, second is upper_bound
			pair<iterator, iterator> equal_range(const key_type& k) {
				iterator first = lower_bound(k);
				iterator second = upper_bound(k);

				return (pair<iterator, iterator>(first, second));
			};

			// returns pair of const_iterators, first is lower_bound, second is upper_bound
			pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
				const_iterator first = lower_bound(k);
				const_iterator second = upper_bound(k);

				return (pair<const_iterator, const_iterator>(first, second));
			};

		// --- ALLOCATOR ---

			// returns allocator
			allocator_type get_allocator() const {
				return (_allocator);
			}


			//REMOVE THIS REMOVE THIS REMOVE THIS
			//REMOVE THIS REMOVE THIS REMOVE THIS
			//REMOVE THIS REMOVE THIS REMOVE THIS
			void print_tree() const {
				std::cout << "-----" << std::endl;
				print_tree(_root);
				std::cout << "-----" << std::endl;
			}

		private:

			node_pointer balance_after_erase(node_pointer node) {
				int balance_factor = calc_balance_factor(node);

				if (node->_left && node->_right && (balance_factor < -1 || balance_factor > 1)) {
					if (get_height(node->_left) < get_height(node->_right)) {
						if (node->_right->_left && node->_right->_right) {
							if (node->_right->_left->_height > node->_right->_right->_height) { // right left
								node->_right = rotate_right(node->_right);
								return (rotate_left(node));
							}
							else // right right
								return (rotate_left(node));
						}
					} else {
						if (node->_left->_left && node->_left->_right) {
							if (node->_left->_left->_height > node->_left->_right->_height) // left left
								return (rotate_right(node));
							else { // left right
								node->_left = rotate_left(node->_left);
								return (rotate_right(node));
							}
						}
					}
				}
				return (node);
			}

			node_pointer create_new_node_erase(node_pointer old_node, const value_type& val) {
				node_pointer node;

				node = _allocator.allocate(1);
				_allocator.construct(node, val);
				node->_parent = old_node->_parent;
				node->_right = old_node->_right;
				node->_left = old_node->_left;
				node->_height = 1;
				return (node);
			}

			node_pointer erase_node(node_pointer node, const key_type& k) {
				key_compare comp = key_compare();

				if (node) {
					if (!comp(k, node->_data.first) && !comp(node->_data.first, k)) { // equal
						if (!node->_right && node->_left) {
							if (node->_parent) {
								if (comp(node->_parent->_data.first, node->_data.first)) // less
									node->_parent->_right = node->_left;
								else
									node->_parent->_left = node->_left;

								node->_parent->_height = std::max(get_height(node->_parent->_left), get_height(node->_parent->_right)) + 1;
							}

							node_pointer temp = node->_left;
							temp->_parent = node->_parent;
							_allocator.destroy(node);
							_allocator.deallocate(node, 1);
							_size--;
							temp->_left = balance_after_erase(temp->_left);
							return (temp->_left);
						}
						else if (!node->_left && node->_right) {
							if (node->_parent) {
								if (comp(node->_parent->_data.first, node->_data.first)) // less
									node->_parent->_right = node->_right;
								else
									node->_parent->_left = node->_right;

								node->_parent->_height = std::max(get_height(node->_parent->_left), get_height(node->_parent->_right)) + 1;
							}

							node_pointer temp = node->_right;
							temp->_parent = node->_parent;
							_allocator.destroy(node);
							_allocator.deallocate(node, 1);
							_size--;
							temp->_right = balance_after_erase(temp->_right);
							return (temp->_right);
						}
						else if (!node->_left && !node->_right) {
							if (node->_parent) {
								if (comp(node->_parent->_data.first, node->_data.first)) // less
									node->_parent->_right = NULL;
								else
									node->_parent->_left = NULL;

								node->_parent->_height = std::max(get_height(node->_parent->_left), get_height(node->_parent->_right)) + 1;
								_allocator.destroy(node);
								_allocator.deallocate(node, 1);
								_size--;
								return (NULL);
							}
						}
						else {
							node_pointer temp = node;
							temp = temp->_right;
							while (temp->_left)
								temp = temp->_left;
							node->_right = erase_node(node->_right, temp->_data.first);
							node_pointer new_node = create_new_node_erase(node, temp->_data);
							_allocator.destroy(node);
							_allocator.deallocate(node, 1);
							new_node = balance_after_erase(new_node);
						}
					}
					else if (comp(k, node->_data.first)) { // less
						node->_left = erase_node(node->_left, k);
						node = balance_after_erase(node);
					} else if (comp(node->_data.first, k)) { // greater
						node->_right = erase_node(node->_right, k);
						node = balance_after_erase(node);
					}
					if (node)
						node->_height = std::max(get_height(node->_left), get_height(node->_right)) + 1;
				}
				else
					_erased = false;
				return (node);
			}

			node_pointer create_new_node(node_pointer parent, const value_type& val) {
				node_pointer node;

				node = _allocator.allocate(1);
				_allocator.construct(node, val);
				node->_parent = parent;
				node->_right = NULL;
				node->_left = NULL;
				node->_height = 1;
				_size++;
				_latest = node;
				return (node);
			}

			int get_height(node_pointer node) {
				if (!node)
					return (0);
				return (node->_height);
			}

			int calc_balance_factor(node_pointer node) {
				if (!node)
					return (0);
				return (get_height(node->_left) - get_height(node->_right));
			}

			node_pointer rotate_right(node_pointer node) {
				key_compare		comp = key_compare();
				node_pointer	temp = node->_left;

				node->_left = temp->_right;
				if (temp->_right)
					temp->_right->_parent = node;
				temp->_right = node;
				temp->_parent = node->_parent;
				node->_parent = temp;
				if (temp->_parent && comp(node->_data.first, temp->_parent->_data.first))
					temp->_parent->_left = temp;
				else if (temp->_parent && comp(temp->_parent->_data.first, node->_data.first))
					temp->_parent->_right = temp;
				node = temp;

				if (node->_left)
					node->_left->_height = std::max(get_height(node->_left->_left), get_height(node->_left->_right)) + 1;
				if (node->_right)
					node->_right->_height = std::max(get_height(node->_right->_left), get_height(node->_right->_right)) + 1;
				node->_height = std::max(get_height(node->_left), get_height(node->_right)) + 1;
				if (node->_parent)
					node->_parent->_height = std::max(get_height(node->_parent->_left), get_height(node->_parent->_right)) + 1;
				return (node);
			}

			node_pointer rotate_left(node_pointer node) {
				key_compare		comp = key_compare();
				node_pointer	temp = node->_right;

				node->_right = temp->_left;
				if (temp->_left)
					temp->_left->_parent = node;
				temp->_left = node;
				temp->_parent = node->_parent;
				node->_parent = temp;
				if (temp->_parent && comp(node->_data.first, temp->_parent->_data.first))
					temp->_parent->_left = temp;
				else if (temp->_parent && comp(temp->_parent->_data.first, node->_data.first))
					temp->_parent->_right = temp;
				node = temp;

				if (node->_left)
					node->_left->_height = std::max(get_height(node->_left->_left), get_height(node->_left->_right)) + 1;
				if (node->_right)
					node->_right->_height = std::max(get_height(node->_right->_left), get_height(node->_right->_right)) + 1;
				node->_height = std::max(get_height(node->_left), get_height(node->_right)) + 1;
				if (node->_parent)
					node->_parent->_height = std::max(get_height(node->_parent->_left), get_height(node->_parent->_right)) + 1;
				return (node);
			}

			node_pointer insert_node(node_pointer node, node_pointer parent, const value_type& val) {
				key_compare compare = key_compare();

				if (!node)
					return (create_new_node(parent, val));
				if (compare(val.first, node->_data.first)) // less
					node->_left = insert_node(node->_left, node, val);
				else if (compare(node->_data.first, val.first)) // greater
					node->_right = insert_node(node->_right, node, val);
				else { // equals
					_duplicate = true;
					_latest = node;
					return (node);
				}
				node->_height = std::max(get_height(node->_left), get_height(node->_right)) + 1;
				int balance_factor = calc_balance_factor(node);

				if (balance_factor > 1 && compare(val.first, node->_left->_data.first)) // left left
					return (rotate_right(node));
				else if (balance_factor > 1 && compare(node->_left->_data.first, val.first)) { // left right
					node->_left = rotate_left(node->_left);
					return (rotate_right(node));
				}
				if (balance_factor < -1 && compare(val.first, node->_right->_data.first)) { // right left
					node->_right = rotate_right(node->_right);
					return (rotate_left(node));
				}
				else if (balance_factor < -1 && compare(node->_right->_data.first, val.first)) // right right
					return (rotate_left(node));
				return (node);
			}

			void remove_begin_end() {
				if (_begin->_parent)
					_begin->_parent->_left = NULL;
				_begin->_parent = NULL;
				if (_end->_parent)
					_end->_parent->_right = NULL;
				_end->_parent = NULL;
			}

			void set_begin_end() {
				node_pointer first = _root->get_first_element(_root);
				node_pointer last = _root->get_last_element(_root);

				first->_left = _begin;
				_begin->_parent = first;
				last->_right = _end;
				_end->_parent = last;
			}

			void	delete_tree(node_pointer node) {
				if (!node)
					return ;
				delete_tree(node->_left);
				delete_tree(node->_right);
				_allocator.destroy(node);
				_allocator.deallocate(node, 1);
			}

			// REMOVE THIS REMOVE THIS REMOVE THIS REMOVE THIS
			// REMOVE THIS REMOVE THIS REMOVE THIS REMOVE THIS
			// REMOVE THIS REMOVE THIS REMOVE THIS REMOVE THIS
			void	print_tree_utils(node_pointer root, int space) const
			{
			   int count = 5;
				if (root == NULL)
					return;
				space += count;
				print_tree_utils(root->_right, space);
				std::cout << std::endl;
				for (int i = count; i < space; i++)
					std::cout << " ";
				std::cout << root->_data.first << ",  = " << root->_height << std::endl;
				print_tree_utils(root->_left, space);
			}

			// REMOVE THIS REMOVE THIS REMOVE THIS REMOVE THIS
			// REMOVE THIS REMOVE THIS REMOVE THIS REMOVE THIS
			// REMOVE THIS REMOVE THIS REMOVE THIS REMOVE THIS
			void	print_tree(node_pointer root) const
			{
				print_tree_utils(root, 0);
			}

	}; // class map
}; // namespace ft

#endif
