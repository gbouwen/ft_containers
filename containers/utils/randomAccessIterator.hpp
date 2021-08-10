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

		reference				operator*() const { return (*_ptr); };

		pointer					operator->() { return (_ptr); };

		// prefix
		randomAccessIterator&	operator++() {
			_ptr++;
			return (*this);
		};

		// postfix
		randomAccessIterator&	operator++(int) {
			randomAccessIterator& temp = *this;

			++(*this);
			return (temp);
		}

		friend bool operator== (const randomAccessIterator& a, const randomAccessIterator& b) { return a._ptr == b._ptr; };

		friend bool operator!= (const randomAccessIterator& a, const randomAccessIterator& b) { return a._ptr != b._ptr; };

	}; // class randomAccessIterator
}; // namespace ft

#endif
