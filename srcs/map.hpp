// Map.hpp

#ifndef MAP_HPP
# define MAP_HPP

# include <stdio.h> ///////////////////

# include <cstddef>
# include <memory>

# include "utils/pair.hpp"
# include "utils/make_pair.hpp"
# include "utils/less_binary_function.hpp"
# include "utils/node.hpp"
# include "utils/bidirectional_iterator.hpp"

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
		// reverse_iterator
		// const_reverse_iterator
		typedef ptrdiff_t																	difference_type;
		typedef size_t																		size_type;

		typedef ft::node<value_type>														node;
		typedef ft::node<value_type>*														node_pointer;

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

			size_type		_size;
			node_pointer	_root;
			node_pointer	_end;
			Compare			_comp;
			allocator_type	_allocator;

		public:

		// --- CONSTRUCTOR/DESTRUCTOR/OPERATOR= ---

			// default constructor
			explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
					: _size(0), _root(), _comp(comp), _allocator(alloc) {
				_end = new node();
			}

			// destructor
			~map() {
				clear();
			}

		// --- ITERATORS ---

			// returns iterator to first element
			iterator begin() {
				if (empty())
					return (end());
				return (iterator(_root->get_begin(_root)));
			}

			// returns const_iterator to first element
			const_iterator begin() const {
				if (empty())
					return (end());
				return (const_iterator(_root->get_begin(_root)));
			}

			// returns iterator to element after last
			iterator end() { return (iterator(_end)); }

			// returns const_iterator to element after last
			const_iterator end() const { return (const_iterator(_end)); }

		// --- CAPACITY ---

			// returns true if empty
			bool empty() const { return (!_size); }

			// returns container size
			size_type size() const { return (_size); }

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
					set_end();
					return (ft::pair<iterator, bool>(begin(), true));
				}

				node_pointer temp = _root;
				if (!find_unique_last_node(temp, val))
					return (ft::pair<iterator, bool>(iterator(temp), false));
				else if (val.first < temp->_data.first)
					temp = insert_left_leaf(temp, val);
				else
					temp = insert_right_leaf(temp, val);
				set_end();
				return (ft::pair<iterator, bool>(iterator(temp), true));
			}

			// erases element position
			void erase(iterator position) {
				if (!count(position->first))
					return ;
				node_pointer node = find_node(position->first);
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

			// deletes map content + deallocates
			void clear() {
				if (!empty())
					delete_tree(_root);
				// DO WITH ITERATORS WHEN ERASE(3)() WORKS
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
				for (iterator it = begin(); it != end(); it++) {
					if (it->first == k)
						return (it);
				}
				return (end());
			}

			// returns iterator to k if k is in map
			// returns end if k is not in map
			const_iterator find(const key_type& k) const {
				for (const_iterator it = begin(); it != end(); it++) {
					if (it->first == k)
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
				print_tree(_root);
				return (_allocator);
			}

		private:

			// if map is empty, set root to val
			void create_new_root(const value_type& val) {
				_root = new node(val);
				_root->_parent = _end;
				_size++;
			}

			// returns newly inserted left leaf
			node_pointer insert_left_leaf(node_pointer parent, const value_type& val) {
				node_pointer child = new node(val);

				parent->_left = child;
				child->_parent = parent;
				child->_left = NULL;
				child->_right = NULL;
				_size++;
				return (child);
			}

			// returns newly inserted right leaf
			node_pointer insert_right_leaf(node_pointer parent, const value_type& val) {
				node_pointer child = new node(val);

				parent->_right = child;
				child->_parent = parent;
				child->_left = NULL;
				child->_right = NULL;
				_size++;
				return (child);
			}

			// sets last element to _end
			void set_end() {
				node_pointer last = _root->get_last_element(_root);

				last->_right = _end;
				_end->_parent = last;
			}

			// returns true if successfully found last unique node,
			// returns false if the key already exists within the map
			bool find_unique_last_node(node_pointer& temp, const value_type& val) {
				while (temp->_left || temp->_right) {
					if (temp->_data.first == val.first)
						return (false);
					if (val.first < temp->_data.first) {
						if (temp->_left != NULL && !temp->_left->is_empty())
							temp = temp->_left;
						else
							break ;
					}
					else if (val.first > temp->_data.first) {
						if (temp->_right != NULL && !temp->_right->is_empty())
							temp = temp->_right;
						else
							break ;
					}
				}
				if (temp->_data.first == val.first)
					return (false);
				return (true);
			}

			// returns node_pointer which has k as first
			node_pointer find_node(const key_type& k) {
				node_pointer temp = _root;

				while (temp) {
					if (temp->_data.first == k)
						break ;
					else if (k > temp->_data.first)
						temp = temp->_right;
					else if (k < temp->_data.first)
						temp = temp->_left;
				}
				return (temp);
			}

			// removes node from tree
			void remove_node(node_pointer node) {
				if (!node->_left && !node->_right)
					delete_leaf(node);
				else if (node->_left && !node->_right)
					delete_node_with_only_left_child(node);
				else if (node->_right && !node->_left)
					delete_node_with_only_right_child(node);
				else
					delete_node_with_two_children(node);
				std::cout << _root->_right->_data.first << std::endl;
			}

			// deletes leaf node and changes parent pointer
			void delete_leaf(node_pointer node) {
				if (node->_parent->_right == node)
					node->_parent->_right = NULL;
				else if (node->_parent->_left == node)
					node->_parent->_left = NULL;
				_size--;
				delete (node);
			}

			// deletes node that is the left and only child of parent
			// changes parent pointer(left or right) to point to child of node
			void delete_node_with_only_left_child(node_pointer node) {
				if (node->_parent->_left == node) {
					node->_parent->_left = node->_left;
					node->_left->_parent = node->_parent;
				}
				else if (node->_parent->_right == node) {
					node->_parent->_right = node->_left;
					node->_left->_parent = node->_parent;
				}
				_size--;
				delete (node);
			}

			// deletes node that is the right and only child of parent
			// changes parent pointer(left or right) to point to child of node
			void delete_node_with_only_right_child(node_pointer node) {
				if (size() == 1) {
					_size--;
					delete (node);
					return ;
				}
				if (node->_parent->_left == node) {
					node->_parent->_left = node->_right;
					node->_right->_parent = node->_parent;
				}
				else if (node->_parent->_right == node) {
					node->_parent->_right = node->_right;
					node->_right->_parent = node->_parent;
				}
				_size--;
				delete (node);
			}

			// deletes node with two children and changes parent pointer
			void delete_node_with_two_children(node_pointer node) {
				node_pointer temp = node->get_last_element(node->_left);

				if (node == _root)
					_root = temp;
				if (node->_parent->_right == node)
					node->_parent->_right = temp;
				else if (node->_parent->_left == node)
					node->_parent->_left = temp;
				if (temp->_left)
					temp->_parent->_right = temp->_left;
				if (node->_right != temp)
					temp->_right = node->_right;
				if (node->_left != temp)
					temp->_left = node->_left;
				temp->_parent->_right = NULL;
				temp->_parent = node->_parent;
				_size--;
				std::cout << "Deleting = " << node->_data.first << std::endl;
				delete (node);
			}

			// deletes the tree recursively
			// CAN BE REMOVED WHEN ERASE WORKS WITH ITERATORS
			// CAN BE REMOVED WHEN ERASE WORKS WITH ITERATORS
			// CAN BE REMOVED WHEN ERASE WORKS WITH ITERATORS
			void delete_tree(node_pointer node) {
				if (!node)
					return ;
				delete_tree(node->_left);
				delete_tree(node->_right);
				_size--;
				delete (node);
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
//				std::cout << std::endl;
				for (int i = count; i < space; i++)
					std::cout << " ";
				std::cout << root->_data.first << ", " << root->_data.second << std::endl;
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
