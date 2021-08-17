// reverse_iterator.hpp

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {

	template <typename Iterator>
	class reverse_iterator {

	public:

		typedef Iterator													iterator_type;
		typedef typename ft::iterator_traits<Iterator>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iterator>::value_type			value_type;
		typedef typename ft::iterator_traits<Iterator>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iterator>::pointer				pointer;
		typedef typename ft::iterator_traits<Iterator>::reference			reference;

	protected:

		iterator_type	_current;

	public:

	// --- CONSTRUCTORS ---

		reverse_iterator(): _current() { };

		explicit reverse_iterator(iterator_type it): _current(it) { };

		template <class Iter>
  		reverse_iterator(const reverse_iterator<Iter>& rev_it): _current(rev_it.base()) { };

	// --- MEMBER FUNCTIONS ---

		iterator_type base() const { return (_current); };

		reference operator*() const {
			iterator_type tmp = _current;

			return (*--tmp);
		};

		pointer	operator->() const { return (&(operator*())); };

		// prefix
		reverse_iterator& operator++() {
			--_current;
			return (*this);
		};

		// postfix
		reverse_iterator operator++(int) {
			reverse_iterator temp = *this;
			--_current;
			return (temp);
		};

		// prefix
		reverse_iterator& operator--() {
			++_current;
			return (*this);
		};

		// postfix
		reverse_iterator operator--(int) {
			reverse_iterator temp = *this;
			++_current;
			return (temp);
		};

		reverse_iterator operator+(difference_type n) const { return (reverse_iterator(_current - n)); };

		reverse_iterator&	operator+=(difference_type n) {
			_current -= n;
			return (*this);
		};

		reverse_iterator operator-(difference_type n) const { return (reverse_iterator(_current + n)); };

		reverse_iterator& operator-=(difference_type n) {
			_current += n;
			return (*this);
		};

		reference operator[](difference_type n) const { return (*(*this + n)); };

	}; // reverse_iterator

	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (lhs.base() == rhs.base());
	};

	template <class Iterator>
	bool operator!=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (!(lhs == rhs));
	};

	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() < lhs.base());
	};

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (!(rhs < lhs));
	};

	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (rhs < lhs);
	};

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
		return (!(lhs < rhs));
	};

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& lhs,
																   const reverse_iterator<Iterator>& rhs) {
		return (rhs.base() - lhs.base());
	};

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
										 const reverse_iterator<Iterator>& rev_it) {
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	};

}; //namespace ft

#endif
