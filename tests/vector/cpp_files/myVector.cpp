// myVector.cpp

#include <iostream>
#include "../../../containers/Vector.hpp"

void constructors_destructor_operator() {

}

void iterators() {

}

void capacity() {
	ft::vector<int>	vector_one;

	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.max_size() = " << vector_one.max_size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	std::cout << "vector_one.empty() = " << vector_one.empty() << std::endl;

	std::cout << "vector_one.assign(5, 100)" << std::endl;;

	vector_one.assign(5, 100);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.max_size() = " << vector_one.max_size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	std::cout << "vector_one.empty() = " << vector_one.empty() << std::endl;
}

void element_access() {
	ft::vector<int>	vector_one;

	vector_one.assign(5, 100);
	for (size_t i = 0; i < vector_one.size(); i++) {
		std::cout << vector_one[i] << std::endl;
	}
	vector_one.assign(2, 50);
	for (size_t i = 0; i < vector_one.size(); i++) {
		std::cout << vector_one[i] << std::endl;
	}
	try {
		std::cout << "vector_one.front() = " << vector_one.front() << std::endl;
		std::cout << "vector_one.at(0) = " << vector_one.at(0) << std::endl;
		std::cout << "vector_one.back() = " << vector_one.back() << std::endl;
		std::cout << "vector_one.at(100) = " << vector_one.at(100) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

void modifiers() {

}

void allocator() {

}

void relational_operators() {

}

void swap() {

}

int	main(void) {
	std::cout << "myVector test" << std::endl;
	//CONSTRUCTORS/DESTRUCTOR/OPERATOR=
	ft::vector<int>	vector_one;

	//ITERATORS

	//CAPACITY
	capacity();
	//ELEMENT ACCESS
	element_access();
	//MODIFIERS

	//ALLOCATOR

	//RELATIONAL OPERATORS

	//SWAP

	return (0);
}
