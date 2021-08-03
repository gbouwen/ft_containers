// Vector.hpp

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>

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

	// !!! MEMBER FUNCTIONS !!!

	// --- CONSTRUCTOR/DESTRUCTOR/OPERATOR= ---

	// --- ITERATORS ---

	// --- CAPACITY ---

	// --- ELEMENT ACCESS ---

	// --- MODIFIERS ---

	// --- ALLOCATOR ---

	// !!! NON MEMBER FUNCTION OVERLOADS !!!

	// --- RELATIONAL OPERATORS ---

	// --- SWAP ---

	private:

	};
};

#endif
