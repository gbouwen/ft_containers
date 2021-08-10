// Vector.hpp

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stddef.h>
# include <memory>
# include <limits>
# include <stdexcept>

# include "utils/randomAccessIterator.hpp"

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

	public:

		typedef T									value_type;
		typedef Alloc								allocator_type;
		typedef value_type&							reference;
		typedef const value_type&					const_reference;
		typedef value_type*							pointer;
		typedef const value_type*					const_pointer;
		typedef randomAccessIterator<value_type>	iterator;
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator
		typedef ptrdiff_t							difference_type;
		typedef size_t								size_type;

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
				_array[i] = temp[i];
			_allocator.deallocate(temp, _capacity);
			_capacity = n;
		};

	public:

	// --- CONSTRUCTORS/DESTRUCTOR/OPERATOR= ---

		// constructs empty vector
		explicit vector(const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _capacity(0), _allocator(alloc) { };

		// constructs vector with n elements, each element is a copy of val
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		: _size(n), _capacity(n), _allocator(alloc) {
			_array = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(&_array[i], val);
		};

		// constructs vector with a copy of each of the elements in x
		vector(const vector& x) {
			_array = _allocator.allocate(x.capacity());
			for (size_type i = 0; i < x.size(); i++)
				_allocator.construct(&_array[i], x[i]);
			_size = x.size();
			_capacity = x.capacity();
		};

		// destroys and deallocates vector
		~vector() {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(&_array[i]);
			_allocator.deallocate(_array, _capacity);
		};

		// assigns new contents to vector, replaces its current contents, and modifies its size
		vector& operator= (const vector& x) {
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
		};

	// --- ITERATORS ---

		// returns iterator to beginning
		randomAccessIterator<value_type> begin() {
			return (randomAccessIterator<value_type>(_array));
		};

		// returns iterator to end
		randomAccessIterator<value_type> end() {
			return (randomAccessIterator<value_type>(_array + _size));
		};

	// --- CAPACITY ---

		// returns number of elements in vector
		size_type	size() const { return (_size); };

		// returns maximum number of elements vector can hold
		size_type	max_size() const { return (_allocator.max_size()); };

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
		};

		// returns number of elements vector can hold
		size_type	capacity() const { return (_capacity); };

		// returns true if container size == 0, false otherwise
		bool		empty() const { return (!_size); };

		// requests that vector capacity is at least enough to contain n elements
		// if n <= _capacity, nothing happens
	  	void		reserve(size_type n) {
			if (n > _capacity) {
				reallocate(n);
			}
		};

	// --- ELEMENT ACCESS ---

		// accesses element at position n
		reference operator[](size_type n) { return (reference(_array[n])); };

		// accesses element at position n
		const_reference operator[](size_type n) const { return (const_reference(_array[n])); };

		// accesses element at position n, throws exception when out of bounds
		reference at(size_type n) {
			if (n >= _size)
				throw (std::out_of_range("out of range"));
			return (reference(_array[n]));
		};

		// accesses element at position n, throws exception when out of bounds
		const_reference at(size_type n) const {
			if (n >= _size)
				throw (std::out_of_range("out of range"));
			return (const_reference(_array[n]));
		};

		// accesses first element of vector
		reference front() { return (reference(_array[0])); };

		// accesses first element of vector
		const_reference front() const { return (const_reference(_array[0])); };

		// accesses last element of vector
		reference back() { return (reference(_array[_size - 1])); };

		// accesses last element of vector
		const_reference back() const { return (const_reference(_array[_size - 1])); };

	// --- MODIFIERS ---

		// assigns new contents to vector, replaces its current contents, and modifies its size
		void	assign(size_type n, const value_type& val) {
			if (n > _capacity)
				reallocate(n);
			for (size_type i = 0; i < n; i++) {
				_allocator.destroy(&_array[i]);
				_allocator.construct(&_array[i], val);
			}
			_size = n;
		};

		// adds element at the end of vector
		void	push_back(const value_type& val) {
			if (_size + 1 > _capacity && _capacity > 0)
				reallocate(_capacity * 2);
			else
				reallocate(1);
			_allocator.construct(&_array[_size], val);
			_size++;
		};

		// deletes last element of vector
		void	pop_back() {
			_allocator.destroy(&_array[_size - 1]);
			_size--;
		};

		// exchanges contents of vector with the contents of x
		void swap (vector& x) {
			vector	temp(*this);

			*this = x;
			x = temp;
		};

		// removes all elements from vector
		void	clear() {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(&_array[i]);
			_size = 0;
		};

	// --- ALLOCATOR ---

		allocator_type get_allocator() const { return (_allocator); };

	}; // class vector

	// --- RELATIONAL OPERATORS ---

	// --- SWAP ---

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); };

}; // namespace ft

#endif
