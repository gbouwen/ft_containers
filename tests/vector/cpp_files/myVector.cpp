// myVector.cpp

#include <iostream>
#include "../../../containers/Vector.hpp"

int	main(void)
{
	std::cout << "myVector test" << std::endl;
	//CONSTRUCTORS/DESTRUCTOR/OPERATOR=
	ft::vector<int>	vector_one;

	//ITERATORS

	//CAPACITY
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.max_size() = " << vector_one.max_size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	std::cout << "vector_one.empty() = " << vector_one.empty() << std::endl;

	//ELEMENT ACCESS

	//MODIFIERS

	//ALLOCATOR
	vector_one.get_allocator().allocate(5);

	//RELATIONAL OPERATORS

	//SWAP

	return (0);
}
