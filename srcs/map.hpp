// Map.hpp

#ifndef MAP_HPP
# define MAP_HPP

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
			Compare			_comp;
			allocator_type	_allocator;

		public:

		// --- CONSTRUCTOR/DESTRUCTOR/OPERATOR= ---
			explicit map(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()): _size(0), _comp(comp), _allocator(alloc) {
				_root = new node();
			}

		// --- ITERATORS ---

			// returns iterator to first element of map
			iterator begin() { return (iterator(_root->get_begin())); }

			// returns const_iterator to first element of map
			const_iterator begin() const { return (const_iterator(_root->get_begin())); }

		// --- CAPACITY ---

			// returns true if empty
			bool empty() const { return (!_size); }

			// returns container size
			size_type size() const { return (_size); }

			// size_type max_size() const;

		// --- ELEMENT ACCESS ---

		// --- MODIFIERS ---

			// inserts new pair, returns pair with iterator to new element as first
			// returns bool as second: true if succeeded, false if key already exists
			ft::pair<iterator, bool> insert(const value_type& val) {
				if (empty()) {
					create_new_root(val);
					return (ft::pair<iterator, bool>(begin(), true));
				}
				node_pointer temp = _root;
				while (temp->_left || temp->_right) {
					if (temp->_data.first == val.first)
						return (ft::pair<iterator, bool>(iterator(temp), false));
					if (val.first < temp->_data.first) {
						if (temp->_left != NULL)
							temp = temp->_left;
						else
							break ;
					}
					else {
						if (temp->_right != NULL)
							temp = temp->_right;
						else
							break ;
					}
				}
				if (temp->_data.first == val.first)
					return (ft::pair<iterator, bool>(iterator(temp), false));
				if (val.first < temp->_data.first)
					temp = insert_left_leaf(temp, val);
				else
					temp = insert_right_leaf(temp, val);
				return (ft::pair<iterator, bool>(iterator(temp), true));
			}

		// --- OBSERVERS ---

			// returns key_compare object
			key_compare key_comp() const { return (_comp); }

			// returns value_compare object
			value_compare value_comp() const { return (value_compare(_comp)); }

		// --- OPERATIONS ---

		// --- ALLOCATOR ---

			// returns allocator
			allocator_type get_allocator() const { return (_allocator); }

		private:

			void create_new_root(const value_type& val) {
				delete (_root);
				_root = new node(val);
				_size++;
			}

			node_pointer insert_left_leaf(node_pointer parent, const value_type& val) {
				node_pointer child = new node(val);

				parent->_left = child;
				child->_parent = parent;
				_size++;
				return (child);
			}

			node_pointer insert_right_leaf(node_pointer parent, const value_type& val) {
				node_pointer child = new node(val);

				parent->_right = child;
				child->_parent = parent;
				_size++;
				return (child);
			}

			// Function to print binary tree in 2D
			// It does reverse inorder traversal
			void print2DUtil(node_pointer root, int space)
			{
				// Base case
				if (root == NULL)
					return;

				// Increase distance between levels
				space += 7;

				// Process right child first
				print2DUtil(root->_right, space);

				// Print current node after space
				// count
				std::cout<<std::endl;
				for (int i = 10; i < space; i++)
					std::cout<<" ";
				std::cout<<root->_data.first<<"\n";

				// Process left child
				print2DUtil(root->_left, space);
			}

			// Wrapper over print2DUtil()
			void print_tree(node_pointer root)
			{
				// Pass initial space count as 0
				print2DUtil(root, 0);
			}

	}; // class map
}; // namespace ft

#endif
