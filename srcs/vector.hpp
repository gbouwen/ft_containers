// Vector.hpp

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include <memory>
# include <limits>
# include <stdexcept>

# include "utils/random_access_iterator.hpp"
# include "utils/reverse_iterator.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
# include "utils/equal_lexicographical_compare.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

		public:

			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef value_type&										reference;
			typedef const value_type&								const_reference;
			typedef value_type*										pointer;
			typedef const value_type*								const_pointer;
			typedef random_access_iterator<T, T*, T&>				iterator;
			typedef random_access_iterator<T, const T*, const T&>	const_iterator;
			typedef reverse_iterator<const_iterator>				const_reverse_iterator;
			typedef reverse_iterator<iterator>						reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

		private:

			pointer			_array;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_allocator;

			void reallocate(size_type n) {
				pointer	temp;

				temp = _array;
				_array = _allocator.allocate(n);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_array[i], temp[i]);
				_allocator.deallocate(temp, _capacity);
				_capacity = n;
			}

		public:

		// --- CONSTRUCTORS/DESTRUCTOR/OPERATOR= ---

			// constructs empty vector
			explicit vector(const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _capacity(0), _allocator(alloc) { }

			// constructs vector with n elements, each element is a copy of val
			explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
			: _size(n), _capacity(n), _allocator(alloc) {
				_array = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_array[i], val);
			}

			// constructs vector with as many elements in range [first, last]
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = NULL): _allocator(alloc)  {
				_size = last - first;
				_capacity = last - first;
				_array = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(&_array[i], *(first + i));
			}

			// constructs vector with a copy of each of the elements in x
			vector(const vector& x) {
				_array = _allocator.allocate(x.capacity());
				for (size_type i = 0; i < x.size(); i++)
					_allocator.construct(&_array[i], x[i]);
				_size = x.size();
				_capacity = x.capacity();
			}

			// destroys and deallocates vector
			~vector() {
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(&_array[i]);
				_allocator.deallocate(_array, _capacity);
			}

			// assigns new contents to vector, replaces its current contents, and modifies its size
			vector& operator=(const vector& x) {
				if (x.size() > _capacity && _array) {
					this->~vector();
					_array = _allocator.allocate(x.capacity());
					for (size_type i = 0; i < x.size(); i++)
						_allocator.construct(&_array[i], x[i]);
					_capacity = x.capacity();
				}
				else {
					if (!_array) {
						_array = _allocator.allocate(x.capacity());
						_capacity = x.capacity();
					}
					for (size_type i = 0; i < x.size(); i++)
						_allocator.construct(&_array[i], x[i]);
				}
				_size = x.size();
				return (*this);
			}

		// --- ITERATORS ---

			// returns iterator to first element
			iterator begin() { return (iterator(_array)); }

			// returns const_iterator to first element
			const_iterator begin() const { return (const_iterator(_array)); }

			// returns iterator to element after last
			iterator end() { return (iterator(_array + _size)); }

			// returns const_iterator to element after last
			const_iterator end() const { return (const_iterator(_array + _size)); }

			// returns reverse_iterator to last element
			reverse_iterator rbegin() { return (reverse_iterator(_array + _size - 1)); }

			// returns const_reverse_iterator to last element
			const_reverse_iterator rbegin() const { return (const_reverse_iterator(_array + _size - 1)); }

			// returns reverse_iterator to element before first
			reverse_iterator rend() { return (reverse_iterator(_array - 1)); }

			// returns const_reverse_iterator to element before first
			const_reverse_iterator rend() const { return (const_reverse_iterator(_array - 1)); }

		// --- CAPACITY ---

			// returns number of elements in vector
			size_type	size() const { return (_size); }

			// returns maximum number of elements vector can hold
			size_type	max_size() const { return (_allocator.max_size()); }

			// resizes container so it contains n elements
			void		resize(size_type n, value_type val = value_type()) {
				if (n < _size) {
					for (size_type i = n; i < _size; i++)
						_allocator.destroy(&_array[i]);
				}
				else if (n > _size && n <= _capacity) {
					for (size_type i = _size; i < n; i++)
						_allocator.construct(&_array[i], val);
				}
				else if (n > _capacity) {
					reallocate(n);
					for (size_type i = _size; i < n; i++)
						_allocator.construct(&_array[i], val);
				}
				_size = n;
			}

			// returns number of elements vector can hold
			size_type	capacity() const { return (_capacity); }

			// returns true if container size == 0, false otherwise
			bool		empty() const { return (!_size); }

			// requests that vector capacity is at least enough to contain n elements
			// if n <= _capacity, nothing happens
			void		reserve(size_type n) {
				if (n > _capacity) {
					reallocate(n);
				}
			}

		// --- ELEMENT ACCESS ---

			// accesses element at position n
			reference operator[](size_type n) { return (reference(_array[n])); }

			// accesses element at position n
			const_reference operator[](size_type n) const { return (const_reference(_array[n])); }

			// accesses element at position n, throws exception when out of bounds
			reference at(size_type n) {
				if (n >= _size)
					throw (std::out_of_range("out of range"));
				return (reference(_array[n]));
			}

			// accesses element at position n, throws exception when out of bounds
			const_reference at(size_type n) const {
				if (n >= _size)
					throw (std::out_of_range("out of range"));
				return (const_reference(_array[n]));
			}

			// accesses first element of vector
			reference front() { return (reference(_array[0])); }

			// accesses first element of vector
			const_reference front() const { return (const_reference(_array[0])); }

			// accesses last element of vector
			reference back() { return (reference(_array[_size - 1])); }

			// accesses last element of vector
			const_reference back() const { return (const_reference(_array[_size - 1])); }

		// --- MODIFIERS ---

			// assigns new contents to vector, based on values between [first, last]
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = NULL) {
				_size = last - first;
				if (_size > _capacity)
					reallocate(_size);
				for (size_type i = 0; i < _size; i++) {
					_allocator.destroy(&_array[i]);
					_allocator.construct(&_array[i], *(first + i));
				}
			}

			// assigns new contents to vector, replaces its current contents, and modifies its size
			void assign(size_type n, const value_type& val) {
				if (n > _capacity)
					reallocate(n);
				for (size_type i = 0; i < n; i++) {
					_allocator.destroy(&_array[i]);
					_allocator.construct(&_array[i], val);
				}
				_size = n;
			}

			// adds element at the end of vector
			void push_back(const value_type& val) {
				if (_capacity == 0)
					reallocate(1);
				else if (_size + 1 > _capacity)
					reallocate(_capacity * 2);
				_allocator.construct(&_array[_size], val);
				_size++;
			}

			// deletes last element of vector
			void pop_back() {
				_allocator.destroy(&_array[_size - 1]);
				_size--;
			}

			// inserts element before position
			iterator insert(iterator position, const value_type& val) {
				size_type new_element_index = position - begin();

				_size += 1;
				if (_size >= _capacity)
					reallocate(_capacity * 2);
				for (size_type i = _size - 1; i > new_element_index; i--)
					_array[i] = _array[i - 1];
				_array[new_element_index] = val;
				return (iterator(begin() + new_element_index));
			}

			// inserts n elements before position
			void insert(iterator position, size_type n, const value_type& val) {
				size_type start_index = position - begin();

				_size += n;
				if (_size >= _capacity)
					reallocate(_capacity * 2);
				for (size_type i = _size - 1; i > start_index + n - 1; i--)
					_array[i] = _array[i - 1];
				for (size_type i = start_index; i < n; i++)
					_array[i] = val;
			}

			// inserts elements from first to last starting at position
			template <class InputIterator>
			void insert(iterator position, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = NULL) {
				size_type start_index = position - begin();
				size_type range = first - last;

			_size += range;
				if (_size >= _capacity)
					reallocate(_capacity * 2);
				for (size_type i = _size - 1; i > start_index + range - 1; i--)
					_array[i] = _array[i - 1];
				for (size_type i = start_index; i < range; i++)
					_array[i] = *(first + 1);
			}

			// removes a single element at position
			iterator erase(iterator position) {
				size_type start_index = position - begin();

				_size -= 1;
				for (size_type i = start_index; i < _size; i++)
					_array[i] = _array[i + 1];
				return (iterator(begin() + start_index));
			}

			// removes a range of elements from first to last
			iterator erase(iterator first, iterator last) {
				size_type start_index = first - begin();
				size_type range = first - last;

				_size -= range;
				for (size_type i = start_index; i < _size; i++)
					_array[i] = _array[i + 1];
				return (iterator(begin() + start_index));
			}

			// exchanges contents of vector with the contents of x
			void swap(vector& x) {
				vector temp(*this);

				*this = x;
				x = temp;
			}

			// removes all elements from vector
			void clear() {
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(&_array[i]);
				_size = 0;
			}

		// --- ALLOCATOR ---

			allocator_type get_allocator() const { return (_allocator); }

		}; // class vector

	// --- RELATIONAL OPERATORS ---

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs == rhs)); }

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs > rhs)); }

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (rhs < lhs); }

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (!(lhs < rhs)); }

	// --- SWAP ---

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }

}; // namespace ft

#endif
