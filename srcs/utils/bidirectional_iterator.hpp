// bidirectional_iterator.hpp

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "node.hpp"

namespace ft {

	template <typename Pair, typename Pointer, typename Reference>
	class bidirectional_iterator {

		public:

			typedef std::bidirectional_iterator_tag							iterator_category;
			typedef Pair													value_type;
			typedef Pointer													pointer;
			typedef Reference												reference;
			typedef ptrdiff_t												difference_type;
			typedef ft::node<Pair>											node;
			typedef ft::node<Pair>*											node_pointer;
			typedef ft::node<Pair>&											node_reference;
			typedef bidirectional_iterator<Pair, Pointer, Reference>		iterator;
			typedef bidirectional_iterator<Pair, const Pair*, const Pair&>	const_iterator;

		private:

			node_pointer	_node;

		public:

		// --- CONSTRUCTORS/DESTRUCTOR ---

			bidirectional_iterator(): _node() { }

			bidirectional_iterator(node_pointer x): _node(x) { }

			bidirectional_iterator(const bidirectional_iterator &x) { *this = x; }

			~bidirectional_iterator() { }

		// --- OPERATOR OVERLOADS ---

			operator const_iterator() const { return (const_iterator(_node)); }

			bidirectional_iterator&	operator=(const bidirectional_iterator &rhs) {
				if (this != &rhs)
					_node = rhs._node;
				return (*this);
			}

			bool	operator==(const bidirectional_iterator& b) { return (_node == b._node); }

			bool	operator!=(const bidirectional_iterator& b) { return (_node != b._node); }

			reference	operator*() const { return (_node->_data); }

			pointer		operator->() { return (&(_node->_data)); }

			node_pointer get_node() const { return (_node); }

			// prefix
			iterator&	operator++() {
				_node = _node->get_next_node(_node);

				return (*this);
			}

			// postfix
			iterator	operator++(int) {
				iterator temp = *this;

				_node = _node->get_next_node(_node);
				return (temp);
			}

			// prefix
			iterator&	operator--() {
				_node = _node->get_previous_node(_node);

				return (*this);
			}

			// postfix
			iterator	operator--(int) {
				iterator temp = *this;

				_node = _node->get_previous_node(_node);
				return (temp);
			}

	}; // class bidirectional_iterator

}; // namespace ft

#endif
