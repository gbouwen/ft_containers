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
			node_pointer	_last_nonzero_bf_node;

		public:

		// --- CONSTRUCTOR/DESTRUCTOR/OPERATOR= ---

			// default constructor
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _allocator(alloc), _comp(comp), _size(0), _root(), _begin(), _end(), _last_nonzero_bf_node() {
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
					: _allocator(alloc), _comp(comp), _size(0), _root(), _begin(), _end(),
					_last_nonzero_bf_node() {
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
				_last_nonzero_bf_node = NULL;
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
				if (empty()) {
					create_new_root(val);
					set_begin_end();
					return (ft::pair<iterator, bool>(begin(), true));
				}

				ft::pair<node_pointer, bool> pair = find_last_node(_root, val);
				node_pointer last_node = pair.first;
				if (!pair.second)
					return (ft::make_pair<iterator, bool>(last_node, pair.second));
				key_compare comp = key_compare();
				node_pointer inserted_node;
				if (comp(val.first, last_node->_data.first))
					inserted_node = insert_left_leaf(last_node, val);
				else
					inserted_node = insert_right_leaf(last_node, val);
				balance_tree_insert(inserted_node);
				set_begin_end();
				return (ft::pair<iterator, bool>(iterator(inserted_node), true));
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
				if (!count(position->first))
					return ;
				node_pointer node = find_node_erase(position->first);
				remove_node(node);
			}

			// erases element with key k
			size_type erase(const key_type& k) {
				iterator it = find(k);
				if (it != end()) {
					erase(it);
					return (1);
				}
				return (0);
			}

			// erases range [first, last]
			void erase(iterator first, iterator last) {
				while (first != last) {
					iterator temp = first;
					temp++;
					erase(first);
					first = find(temp->first);
				}
			}

			// exchanges contents of map with the contents of x
			void swap(map& x) {
				map temp(*this);

				*this = x;
				x = temp;
			}

			// deletes map content + deallocates
			void clear() {
				erase(begin(), end());
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
				print_tree(_root);
			}

		private:

			// if map is empty, set root to val
			void create_new_root(const value_type& val) {
				_root = _allocator.allocate(1);
				_allocator.construct(_root, val);
				_root->_parent = NULL;
				_root->_right = NULL;
				_root->_left = NULL;
				_root->_balance_factor = 0;
				_size++;
			}

			void update_parents_balance_factor_insert(node_pointer parent, node_pointer child) {
				while (child != _last_nonzero_bf_node) {
					if (parent->_left == child)
						parent->_balance_factor--;
					else if (parent->_right == child)
						parent->_balance_factor++;
					if (parent->_parent)
						parent = parent->_parent;
					else
						break ;
					if (child->_parent)
						child = child->_parent;
					else
						break ;
				}
				_last_nonzero_bf_node = NULL;
			}

			// returns newly inserted left leaf
			node_pointer insert_left_leaf(node_pointer parent, const value_type& val) {
				node_pointer child = _allocator.allocate(1);
				_allocator.construct(child, val);

				parent->_left = child;
				child->_parent = parent;
				update_parents_balance_factor_insert(parent, child);
				child->_empty = false;
				child->_left = NULL;
				child->_right = NULL;
				child->_balance_factor = 0;
				_size++;
				return (child);
			}

			// returns newly inserted right leaf
			node_pointer insert_right_leaf(node_pointer parent, const value_type& val) {
				node_pointer child = _allocator.allocate(1);
				_allocator.construct(child, val);

				parent->_right = child;
				child->_parent = parent;
				update_parents_balance_factor_insert(parent, child);
				child->_empty = false;
				child->_left = NULL;
				child->_right = NULL;
				child->_balance_factor = 0;
				_size++;
				return (child);
			}

			void set_begin_end() {
				node_pointer first = _root->get_first_element(_root);
				node_pointer last = _root->get_last_element(_root);

				first->_left = _begin;
				_begin->_parent = first;
				last->_right = _end;
				_end->_parent = last;
			}

			// returns node_pointer which has k as first
			node_pointer find_node_erase(const key_type& k) {
				key_compare		comp = key_comp();
				node_pointer	temp = _root;

				while (temp) {
					if (!comp(k, temp->_data.first) && !comp(temp->_data.first, k)) // equals
						break ;
					else if (comp(k, temp->_data.first)) // less
						temp = temp->_left;
					else // greater
						temp = temp->_right;
				}
				return (temp);
			}

			void remove_node(node_pointer node) {
				if (node == _root)
					remove_root();
				else if ((!node->_left || node->_left == _begin) && (!node->_right || node->_right == _end))
					remove_leaf(node);
				else if (node->_left && node->_left != _begin && (!node->_right || node->_right == _end))
					remove_node_with_only_left_child(node);
				else if (node->_right && node->_right != _end && (!node->_left || node->_left == _begin))
					remove_node_with_only_right_child(node);
				else if (node->_left && node->_left != _begin && node->_right && node->_right != _end)
					remove_node_with_two_children(node);
				if (size() != 0)
					set_begin_end();
			}

			void remove_root() {
				if (size() == 1) {
					_allocator.destroy(_root);
					_allocator.deallocate(_root, 1);
					_size--;
				}
				else if (_root->_left && _root->_left != _begin && _root->_right == _end)
					remove_root_only_left_child();
				else if (_root->_right && _root->_right != _end && _root->_left == _begin)
					remove_root_only_right_child();
				else if (_root->_left && _root->_left != _begin && _root->_right && _root->_right != _end)
					remove_root_with_two_children();
			}

			void remove_root_with_two_children() {
				node_pointer max = _root->get_last_element(_root->_left);
				node_pointer del = _root;

				if (_root->_left != max) {
					max->_left = _root->_left;
					_root->_left->_parent = max;
				}
				if (_root->_right != max) {
					max->_right = _root->_right;
					_root->_right->_parent = max;
				}
				max->_parent->_right = NULL;
				_root = max;
				_allocator.destroy(del);
				_allocator.deallocate(del, 1);
				_size--;
			}

			void remove_root_only_left_child() {
				node_pointer del = _root;

				_root->_left->_parent = NULL;
				_root = _root->_left;
				_allocator.destroy(del);
				_allocator.deallocate(del, 1);
				_size--;
			}

			void remove_root_only_right_child() {
				node_pointer del = _root;

				_root->_right->_parent = NULL;
				_root = _root->_right;
				_allocator.destroy(del);
				_allocator.deallocate(del, 1);
				_size--;
			}

			void remove_node_with_two_children(node_pointer node) {
				node_pointer max = node->get_last_element(node->_left);

				if (node->_parent->_right == node)
					node->_parent->_right = max;
				else if (node->_parent->_left == node)
					node->_parent->_left = max;
				if (node->_left != max) {
					max->_left = node->_left;
					node->_left->_parent = max;
				}
				if (node->_right != max) {
					max->_right = node->_right;
					node->_right->_parent = max;
				}
				max->_parent->_right = NULL;
				max->_parent = node->_parent;
				_allocator.destroy(node);
				_allocator.deallocate(node, 1);
				_size--;
			}

			void remove_node_with_only_left_child(node_pointer node) {
				if (node->_parent->_right == node)
					node->_parent->_right = node->_left;
				else if (node->_parent->_left == node)
					node->_parent->_left = node->_left;
				node->_left->_parent = node->_parent;
				_allocator.destroy(node);
				_allocator.deallocate(node, 1);
				_size--;
			}

			void remove_node_with_only_right_child(node_pointer node) {
				if (node->_parent->_right == node)
					node->_parent->_right = node->_right;
				else if (node->_parent->_left == node)
					node->_parent->_left = node->_right;
				node->_right->_parent = node->_parent;
				_allocator.destroy(node);
				_allocator.deallocate(node, 1);
				_size--;
			}

			void remove_leaf(node_pointer node) {
				if (node->_parent->_left == node)
					node->_parent->_left = NULL;
				else if (node->_parent->_right == node)
					node->_parent->_right = NULL;
				_allocator.destroy(node);
				_allocator.deallocate(node, 1);
				_size--;
			}

			void rotate_left(node_pointer pivot_node) {
				node_pointer child = pivot_node->_right;

				if (_root == pivot_node)
					_root = child;
				child->_parent = pivot_node->_parent;
				if (pivot_node->_parent && pivot_node->_parent->_left == pivot_node)
					pivot_node->_parent->_left = child;
				else if (pivot_node->_parent && pivot_node->_parent->_right == pivot_node)
					pivot_node->_parent->_right = child;
				pivot_node->_right = child->_left;
				if (pivot_node->_right)
					pivot_node->_right->_parent = pivot_node;
				child->_left = pivot_node;
				pivot_node->_parent = child;
			}

			void rotate_right(node_pointer pivot_node) {
				node_pointer child = pivot_node->_left;

				if (_root == pivot_node)
					_root = child;
				child->_parent = pivot_node->_parent;
				if (pivot_node->_parent && pivot_node->_parent->_left == pivot_node)
					pivot_node->_parent->_left = child;
				else if (pivot_node->_parent && pivot_node->_parent->_right == pivot_node)
					pivot_node->_parent->_right = child;
				pivot_node->_left = child->_right;
				if (pivot_node->_left)
					pivot_node->_left->_parent = pivot_node;
				child->_right = pivot_node;
				pivot_node->_parent = child;
			}

			void calc_balance_factors_left_right_rotation(node_pointer pivot_node, node_pointer middle, node_pointer node) {
				if (node->_balance_factor == -1) {
					middle->_balance_factor = 0;
					pivot_node->_balance_factor = 1;
				} else if (node->_balance_factor == 0) {
					middle->_balance_factor = 0;
					pivot_node->_balance_factor = 0;
				} else if (node->_balance_factor == 1) {
					middle->_balance_factor = -1;
					pivot_node->_balance_factor = 0;
				}
				if (node)
					node->_balance_factor = 0;
			}

			void calc_balance_factors_right_left_rotation(node_pointer pivot_node, node_pointer middle, node_pointer node) {
				if (node->_balance_factor == 1) {
					middle->_balance_factor = 0;
					pivot_node->_balance_factor = -1;
				} else if (node->_balance_factor == 0) {
					middle->_balance_factor = 0;
					pivot_node->_balance_factor = 0;
				} else if (node->_balance_factor == -1) {
					middle->_balance_factor = 1;
					pivot_node->_balance_factor = 0;
				}
				if (node)
					node->_balance_factor = 0;
			}

			void balance_tree_insert(node_pointer node) {
				node_pointer pivot_node;
				node_pointer pivot_child;

				if (node && node->_parent && node->_parent->_parent) {
					pivot_child = node->_parent;
					pivot_node = node->_parent->_parent;
				}
				else
					return ;
				while (pivot_node) {
					if (pivot_node->_balance_factor < -1 && pivot_child->_left == node) {
						rotate_right(pivot_node);
						pivot_child->_balance_factor = 0;
						pivot_node->_balance_factor = 0;
					} else if (pivot_node->_balance_factor < -1 && pivot_child->_right == node) {
						rotate_left(pivot_node->_left);
						rotate_right(pivot_node);
						calc_balance_factors_left_right_rotation(pivot_node, pivot_child, node);
					} else if (pivot_node->_balance_factor > 1 && pivot_child->_right == node) {
						rotate_left(pivot_node);
						pivot_child->_balance_factor = 0;
						pivot_node->_balance_factor = 0;
					} else if (pivot_node->_balance_factor > 1 && pivot_child->_left == node) {
						rotate_right(pivot_node->_right);
						rotate_left(pivot_node);
						calc_balance_factors_right_left_rotation(pivot_node, pivot_child, node);
					}
					pivot_node = pivot_node->_parent;
					if (pivot_child->_parent)
						pivot_child = pivot_child->_parent;
					if (node->_parent)
						node = node->_parent;
				}
			}

			ft::pair<node_pointer, bool> find_last_node(node_pointer temp, const value_type &val) {
				key_compare comp = key_compare();

				while (temp->_left || temp->_right) {
					if (!comp(val.first, temp->_data.first) && !comp(temp->_data.first, val.first)) { // equals
						return (ft::make_pair<node_pointer, bool>(temp, false));
					}
					if (temp->_balance_factor != 0) {
						_last_nonzero_bf_node = temp;
					}
					if (comp(val.first, temp->_data.first)) { // less
						if (temp->_left && temp->_left != _begin) {
							temp = temp->_left;
						}
						else
							break ;
					} else if (!comp(val.first, temp->_data.first)) { // greater
						if (temp->_right && temp->_right != _end) {
							temp = temp->_right;
						}
						else
							break ;
					}
				}
				if (!comp(val.first, temp->_data.first) && !comp(temp->_data.first, val.first)) // equals
					return (ft::make_pair<node_pointer, bool>(temp, false));
				if (!_last_nonzero_bf_node)
					_last_nonzero_bf_node = _root;
				return (ft::make_pair<node_pointer, bool>(temp, true));
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
				std::cout << root->_data.first << ", bf = " << root->_balance_factor << std::endl;
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
