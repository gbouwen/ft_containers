// RandomAccessIterator.hpp

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft {

	template <typename T>
	class random_access_iterator {

	public:

		typedef	T					value_type;
		typedef	ptrdiff_t			difference_type;
		typedef	value_type*			pointer;
		typedef	value_type&			reference;

	private:

		pointer	_ptr;

	public:

	// --- CONSTRUCTORS/DESTRUCTOR ---

		random_access_iterator(): _ptr(NULL) { };

		random_access_iterator(pointer x): _ptr(x) { };

		random_access_iterator(const randomAccessIterator &x) {
			*this = x;
		};

		~random_access_iterator() { };

	// --- OPERATOR OVERLOADS ---

		random_access_iterator&	operator=(const randomAccessIterator &rhs) {
			if (this != &rhs)
				_ptr = rhs._ptr;
			return (*this);
		};

		friend bool	operator==(const random_access_iterator& a, const randomAccessIterator& b) { return (a._ptr == b._ptr); };

		friend bool	operator!=(const random_access_iterator& a, const randomAccessIterator& b) { return (a._ptr != b._ptr); };

		reference	operator*() const { return (*_ptr); };

		pointer	operator->() { return (_ptr); };

		// prefix
		random_access_iterator&	operator++() {
			_ptr++;
			return (*this);
		};

		// postfix
		random_access_iterator	operator++(int) {
			random_access_iterator temp = *this;

			++(*this);
			return (temp);
		};

		// prefix
		random_access_iterator&	operator--() {
			_ptr--;
			return (*this);
		};

		// postfix
		random_access_iterator	operator--(int) {
			random_access_iterator temp = *this;

			--(*this);
			return (temp);
		};

		random_access_iterator	operator+(int distance) {
			random_access_iterator temp = *this;

			temp._ptr += distance;
			return (temp);
		};

		friend random_access_iterator	operator+(int distance, randomAccessIterator& it) {
			it._ptr += distance;
			return (it);
		};

		random_access_iterator	operator-(int distance) {
			random_access_iterator temp = *this;

			temp._ptr -= distance;
			return (temp);
		};

		friend difference_type	operator-(random_access_iterator& a, randomAccessIterator& b) {
			return (a._ptr - b._ptr);
		};

		friend bool	operator<(const random_access_iterator& a, const randomAccessIterator& b) { return (a._ptr < b._ptr); };

		friend bool	operator>(const random_access_iterator& a, const randomAccessIterator& b) { return (a._ptr > b._ptr); };

		friend bool	operator<=(const random_access_iterator& a, const randomAccessIterator& b) { return (a._ptr <= b._ptr); };

		friend bool	operator>=(const random_access_iterator& a, const randomAccessIterator& b) { return (a._ptr >= b._ptr); };

		random_access_iterator&	operator+=(int distance) {
			_ptr += distance;
			return (*this);
		};

		random_access_iterator&	operator-=(int distance) {
			_ptr -= distance;
			return (*this);
		};

		reference				operator[](int index) { return *(_ptr + index); };

	}; // class random_access_iterator
}; // namespace ft

#endif
