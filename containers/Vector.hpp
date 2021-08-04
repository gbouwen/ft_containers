// Vector.hpp

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <stddef.h>
# include <memory>
# include <limits>

namespace ft {

	// !!! TEMPLATE PARAMETERS !!!
	template < class T, class Alloc = std::allocator<T> >
	class vector {

	public:

	// !!! MEMBER TYPES !!!
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

	public:

	// !!! MEMBER FUNCTIONS !!!

	// --- CONSTRUCTORS/DESTRUCTOR/OPERATOR= ---

	// --- empty vector
		explicit vector(const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _capacity(0), _allocator(alloc) { };

		//explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) {

		//}

		//template <class InputIterator>
		//vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) {

		//}

		//vector(const vector& x) {

		/*}*/

	// --- ITERATORS ---

	// --- CAPACITY ---

		// returns number of elements in vector
		size_type	size() const { return (_size); };

		// returns maximum number of elements vector can hold
		size_type	max_size() const { return (_allocator.max_size()); };

		// returns number of elements vector can hold
		size_type	capacity() const { return (_capacity); };

		// returns true if container size == 0, false otherwise
		bool		empty() const { return (!_size); };

	// --- ELEMENT ACCESS ---

	// --- MODIFIERS ---
		/*template <class InputIterator>*/
  		/*void assign (InputIterator first, InputIterator last) { };*/

		/*void assign (size_type n, const value_type& val) { };*/

	// --- ALLOCATOR ---
		allocator_type get_allocator() const {
			return (_allocator);
		}

	// !!! NON MEMBER FUNCTION OVERLOADS !!!

	// --- RELATIONAL OPERATORS ---

	// --- SWAP ---

	};
};

#endif
