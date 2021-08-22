// node.hpp

#ifndef NODE_HPP
# define NODE_HPP

namespace ft {

	template <class T>
	class node {

		public:

			typedef node<T>*	node_pointer;

			typedef	T			value_type;
			typedef T&			reference;
			typedef T*			pointer;

			node_pointer	_parent;
			node_pointer	_left;
			node_pointer	_right;
			value_type		_data;

			node(): _parent(NULL), _left(NULL), _right(NULL), _data(NULL) { }

			node(value_type x): _parent(NULL), _left(NULL), _right(NULL), _data(x) { }

			~node() { }

	}; // class node

}; // namespace ft

#endif
