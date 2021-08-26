// node.hpp

#ifndef NODE_HPP
# define NODE_HPP

# include <iostream>

namespace ft {

	template <class Pair>
	class node {

		public:

			typedef Pair		value_type;
			typedef node<Pair>*	node_pointer;

			node_pointer	_parent;
			node_pointer	_left;
			node_pointer	_right;
			value_type		_data;
			bool			_empty;

		// constructors/destructor/operator=

			node(): _parent(), _left(), _right(), _data(), _empty(true) { }

			node(const node &src): _parent(src._parent), _left(src._left), _right(src._right), _data(src._data), _empty(false) { }

			node(value_type x): _parent(), _left(), _right(), _data(x), _empty(false) { }

			node& operator=(const node& rhs) {
				if (this != rhs) {
					_parent = rhs._parent;
					_left = rhs._left;
					_right = rhs._right;
					_data = rhs._data;
					_empty = rhs._empty;
				}
				return (*this);
			}

			~node() { }

		// operator overloads

			bool operator==(const node& rhs) {
				return (_parent == rhs._parent && _left == rhs._left && _right == rhs._right && _data == rhs._data);
			}

			bool operator!=(const node& rhs) { return (!(*this == rhs)); }

		// helper functions

			bool is_empty() { return (_empty); }

			// returns first element
			node_pointer get_begin(node_pointer node) {
				node_pointer temp = node;

				while (temp->_left) {
					temp = temp->_left;
				}
				return (temp);
			}

			// returns last element
			node_pointer get_last_element(node_pointer node) {
				node_pointer temp = node;

				while (temp->_right && !temp->_right->is_empty()) {
					temp = temp->_right;
				}
				return (temp);
			}

			// returns end (last + 1)
			node_pointer get_end(node_pointer node) {
				node_pointer temp = node;

				while (temp->_right) {
					temp = temp->_right;
				}
				return (temp);
			}

			// returns next element
			node_pointer get_next_node(node_pointer node) {
				node_pointer temp = node;

				if (temp->_right)
					return (get_begin(temp->_right));
				while (temp->_parent && temp->_parent->_data.first < node->_data.first)
					temp = temp->_parent;
				return (temp->_parent);
			}

			// returns previous element
			node_pointer get_previous_node(node_pointer node) {
				node_pointer temp = node;

				if (node->is_empty())
					return (temp->_parent);
				if (temp->_left)
					return (get_last_element(temp->_left));
				while (temp->_parent->_data.first > node->_data.first)
					temp = temp->_parent;
				return (temp->_parent);
			}

	}; // class node
}; // namespace ft

#endif
