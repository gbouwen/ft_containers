// reverse_iterator.hpp

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft {

	template <typename Iterator>
	class reverse_iterator {

	public:

		typedef Iterator											iterator_type;
		typedef ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef ft::iterator_traits<Iterator>::value_type			value_type;
		typedef ft::iterator_traits<Iterator>:difference_type		difference_type;
		typedef ft::iterator_traits<Iterator>::pointer				pointer;
		typedef ft::iterator_traits<Iterator>::reference			reference;

	}; // reverse_iterator

}; //namespace ft

#endif
