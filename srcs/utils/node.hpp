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

		// constructors/destructor/operator=

			node(): _parent(), _left(), _right(), _data() { }

			node(const node &src): _parent(src._parent), _left(src._left), _right(src._right), _data(src._data) { }

			node(value_type x): _parent(), _left(), _right(), _data(x) { }

			node(node_pointer parent, value_type x): _parent(parent), _left(), _right(), _data(x) { }

			node& operator=(const node& rhs) {
				if (this != rhs) {
					_data   = rhs._data;
					_left   = rhs._left;
					_right  = rhs._right;
					_parent = rhs._parent;
				}
				return *this;
			}

			~node() { }

		// operator overloads

			bool operator==(const node& rhs) {
				return (_parent == rhs._parent && _left == rhs._left && _right == rhs._right && _data == rhs._data);
			}

			bool operator!=(const node& rhs) { return (!(*this == rhs)); }

		// ---

			node_pointer get_begin() {
				node_pointer temp = this;

				while (temp->_left) {
					temp = temp->_left;
				}
				return (temp);
			}

	}; // class node

}; // namespace ft

#endif
