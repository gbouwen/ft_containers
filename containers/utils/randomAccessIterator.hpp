// RandomAccessIterator.hpp

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft {

	template <typename T>
	class randomAccessIterator {

	public:

		typedef	T					value_type;
		typedef	ptrdiff_t			difference_type;
		typedef	value_type*			pointer;
		typedef	value_type&			reference;

	private:

		pointer	_ptr;

	public:

	// --- CONSTRUCTORS/DESTRUCTOR ---

		randomAccessIterator(): _ptr(NULL) { };

		randomAccessIterator(pointer x): _ptr(x) { };

		randomAccessIterator(const randomAccessIterator &x) {
			*this = x;
		};

		~randomAccessIterator() { };

	// --- OPERATOR OVERLOADS ---

		randomAccessIterator&	operator=(const randomAccessIterator &rhs) {
			if (this != &rhs)
				_ptr = rhs._ptr;
			return (*this);
		};

		friend bool				operator==(const randomAccessIterator& a, const randomAccessIterator& b) { return (a._ptr == b._ptr); };

		friend bool				operator!=(const randomAccessIterator& a, const randomAccessIterator& b) { return (a._ptr != b._ptr); };

		reference				operator*() const { return (*_ptr); };

		pointer					operator->() { return (_ptr); };

		// prefix
		randomAccessIterator&	operator++() {
			_ptr++;
			return (*this);
		};

		// postfix
		randomAccessIterator	operator++(int) {
			randomAccessIterator temp = *this;

			++(*this);
			return (temp);
		};

		// prefix
		randomAccessIterator&	operator--() {
			_ptr--;
			return (*this);
		};

		// postfix
		randomAccessIterator	operator--(int) {
			randomAccessIterator temp = *this;

			--(*this);
			return (temp);
		};

		randomAccessIterator	operator+(int distance) {
			randomAccessIterator temp = *this;

			temp._ptr += distance;
			return (temp);
		};

		friend randomAccessIterator	operator+(int distance, randomAccessIterator& it) {
			it._ptr += distance;
			return (it);
		};

		randomAccessIterator	operator-(int& distance) {
			randomAccessIterator temp = *this;

			temp._ptr -= distance;
			return (temp);
		};

		// a - b

		/* don't know about this one */

		friend bool				operator<(const randomAccessIterator& a, const randomAccessIterator& b) { return (a._ptr < b._ptr); };

		friend bool				operator>(const randomAccessIterator& a, const randomAccessIterator& b) { return (a._ptr > b._ptr); };

		friend bool				operator<=(const randomAccessIterator& a, const randomAccessIterator& b) { return (a._ptr <= b._ptr); };

		friend bool				operator>=(const randomAccessIterator& a, const randomAccessIterator& b) { return (a._ptr >= b._ptr); };

		// a += n

		/* need to check this */

		// a -= n

		/* need to check this */

		reference				operator[](int index) { return *(_ptr + index); };

	}; // class randomAccessIterator
}; // namespace ft

#endif
