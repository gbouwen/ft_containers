// Vector.hpp

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stddef.h>
# include <memory>
# include <limits>
# include <stdexcept>

namespace ft {

	template < class T, class Alloc = std::allocator<T> >
	class vector {

	public:

		typedef T					value_type;
		typedef Alloc				allocator_type;
		typedef value_type&			reference;
		typedef const value_type&	const_reference;
		typedef value_type*			pointer;
		typedef const value_type*	const_pointer;
		// iterator
		// const_iterator
		// reverse_iterator
		// const_reverse_iterator
		typedef ptrdiff_t			difference_type;
		typedef size_t				size_type;

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

	// --- ITERATORS ---

	// --- CAPACITY ---

		// returns number of elements in vector
		size_type	size() const { return (_size); };

		// returns maximum number of elements vector can hold
		size_type	max_size() const { return (_allocator.max_size()); };

		// resizes container so it contains n elements
		/*void		resize(size_type n, value_type val = value_type()) {*/

		/*};*/

		// returns number of elements vector can hold
		size_type	capacity() const { return (_capacity); };

		// returns true if container size == 0, false otherwise
		bool		empty() const { return (!_size); };

		// requests that vector capacity is at least enough to contain n elements
		// if n < _capacity, nothing happens
		/*void		reserve(size_type n) {*/

		/*};*/

	// --- ELEMENT ACCESS ---

		// accesses element at position n
		reference operator[](size_type n) { return (_array[n]); };

		// accesses element at position n
		const_reference operator[](size_type n) const { return (_array[n]); };

		// accesses element at position n, throws exception when out of bounds
		reference at(size_type n) {
			if (n >= _size)
				throw (std::out_of_range("out of range"));
			return (_array[n]);
		};

		// accesses element at position n, throws exception when out of bounds
		const_reference at(size_type n) const {
			if (n >= _size)
				throw (std::out_of_range("out of range"));
			return (_array[n]);
		};

		// accesses first element of vector
		reference front() { return (_array[0]); };

		// accesses first element of vector
		const_reference front() const { return (_array[0]); };

		// accesses last element of vector
		reference back() { return (_array[_size - 1]); };

		// accesses last element of vector
		const_reference back() const { return (_array[_size - 1]); };

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

		// deletes last element
		void	pop_back() {
			_allocator.destroy(&_array[_size - 1]);
			_size--;
		};

		// removes all elements from the vector
		void	clear() {
			for (size_type i = 0; i < _size; i++)
				_allocator.destroy(&_array[i]);
			_size = 0;
		};

	// --- ALLOCATOR ---

		allocator_type get_allocator() const { return (_allocator); };

	// --- RELATIONAL OPERATORS ---

	// --- SWAP ---

	};
};

#endif
