// iterator_traits.hpp

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft {

	template <class Iterator>
	class iterator_traits {

	public:

		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;

	}; // class iterator_traits

	template <class T>
	class iterator_traits<T*> {

	public:

		typedef std::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;

	}; // class iterator_traits<T*>

	template <class T>
	class iterator_traits<const T*> {

	public:

		typedef std::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;

	}; // class iterator_traits<const T*>

}; // namespace ft

#endif
