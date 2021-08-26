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
			iterator begin() { return (iterator(_root->get_begin(_root))); }

			// returns const_iterator to first element
			const_iterator begin() const { return (const_iterator(_root->get_begin(_root))); }

			// returns iterator to element after last
			iterator end() { return (iterator(_end)); }

			// returns const_iterator to element after last
			const_iterator end() const { return (const_iterator(_end)); }

		// --- CAPACITY ---

			// returns true if empty
			bool empty() const { return (!_size); }

			// returns container size
			size_type size() const { return (_size); }

			// size_type max_size() const;

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

			// deletes map content + deallocates
			void clear() {
				if (!empty())
					delete_tree(_root);
			}

		// --- OBSERVERS ---

			// returns key_compare object
			key_compare key_comp() const { return (_comp); }

			// returns value_compare object
			value_compare value_comp() const { return (value_compare(_comp)); }

		// --- OPERATIONS ---

			iterator find(const key_type& k) {
				for (iterator it = begin(); it != end(); it++) {
					if (it->first == k)
						return (it);
				}
				return (end());
			}

		// --- ALLOCATOR ---

			// returns allocator
			allocator_type get_allocator() const {
				print_tree(_root); // REMOVE THIS REMOVE THIS REMOVE THIS REMOVE THIS
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
				_size++;
				return (child);
			}

			// returns newly inserted right leaf
			node_pointer insert_right_leaf(node_pointer parent, const value_type& val) {
				node_pointer child = new node(val);

				parent->_right = child;
				child->_parent = parent;
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

			// deletes the tree recursively
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
				std::cout << std::endl;
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
