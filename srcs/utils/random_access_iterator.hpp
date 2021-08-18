// random_access_iterator.hpp

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft {

	template <typename T, typename Pointer, typename Reference>
	class random_access_iterator {

	public:

		typedef std::random_access_iterator_tag					iterator_category;
		typedef	T												value_type;
		typedef	Pointer											pointer;
		typedef	Reference										reference;
		typedef	ptrdiff_t										difference_type;
		typedef random_access_iterator<T, Pointer, Reference>	iterator;
		typedef random_access_iterator<T, const T*, const T&>	const_iterator;

	private:

		pointer	_ptr;

	public:

	// --- CONSTRUCTORS/DESTRUCTOR ---

		random_access_iterator(): _ptr(NULL) { }

		random_access_iterator(pointer x): _ptr(x) { }

		random_access_iterator(const random_access_iterator &x) { *this = x; }

		~random_access_iterator() { }

	// --- OPERATOR OVERLOADS ---

		operator const_iterator() const { return (const_iterator(_ptr)); }

		random_access_iterator&	operator=(const random_access_iterator &rhs) {
			if (this != &rhs)
				_ptr = rhs._ptr;
			return (*this);
		}

		friend bool	operator==(const random_access_iterator& a, const random_access_iterator& b) { return (a._ptr == b._ptr); }

		friend bool	operator!=(const random_access_iterator& a, const random_access_iterator& b) { return (a._ptr != b._ptr); }

		reference	operator*() const { return (*_ptr); }

		pointer	operator->() { return (_ptr); }

		// prefix
		iterator&	operator++() {
			_ptr++;
			return (*this);
		}

		// postfix
		iterator	operator++(int) {
			random_access_iterator temp = *this;

			++(*this);
			return (temp);
		}

		// prefix
		iterator&	operator--() {
			_ptr--;
			return (*this);
		}

		// postfix
		iterator	operator--(int) {
			random_access_iterator temp = *this;

			--(*this);
			return (temp);
		}

		iterator operator+(int distance) {
			random_access_iterator temp = *this;

			temp._ptr += distance;
			return (temp);
		}

		friend iterator	operator+(int distance, random_access_iterator& it) {
			it._ptr += distance;
			return (it);
		}

		iterator	operator-(int distance) {
			random_access_iterator temp = *this;

			temp._ptr -= distance;
			return (temp);
		}

		friend difference_type	operator-(random_access_iterator& a, random_access_iterator& b) {
			return (a._ptr - b._ptr);
		}

		friend bool	operator<(const random_access_iterator& a, const random_access_iterator& b) { return (a._ptr < b._ptr); }

		friend bool	operator>(const random_access_iterator& a, const random_access_iterator& b) { return (a._ptr > b._ptr); }

		friend bool	operator<=(const random_access_iterator& a, const random_access_iterator& b) { return (a._ptr <= b._ptr); }

		friend bool	operator>=(const random_access_iterator& a, const random_access_iterator& b) { return (a._ptr >= b._ptr); }

		iterator&	operator+=(int distance) {
			_ptr += distance;
			return (*this);
		}

		iterator&	operator-=(int distance) {
			_ptr -= distance;
			return (*this);
		}

		reference	operator[](int index) { return *(_ptr + index); }

	}; // class random_access_iterator
}; // namespace ft

#endif
