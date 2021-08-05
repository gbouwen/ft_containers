// myVector.cpp

#include <iostream>
#include "../../../containers/Vector.hpp"

void constructors_destructor_operator() {

	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

void iterators() {

	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

void capacity() {
	std::cout << "------------------------------- TESTING CAPACITY -------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
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
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

void element_access() {
	std::cout << "------------------------------- TESTING ELEMENT ACCESS -------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	ft::vector<int>	vector_one;

	vector_one.assign(5, 100);
	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	vector_one.assign(2, 50);
	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	try {
		std::cout << "vector_one.front() = " << vector_one.front() << std::endl;
		std::cout << "vector_one.at(0) = " << vector_one.at(0) << std::endl;
		std::cout << "vector_one.back() = " << vector_one.back() << std::endl;
		std::cout << "vector_one.at(100) = " << vector_one.at(100) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

void modifiers() {
	std::cout << "------------------------------- TESTING MODIFIERS ------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	ft::vector<int>	vector_one;

	std::cout << "vector_one.push_back(100)" << std::endl;
	vector_one.push_back(100);
	std::cout << "vector_one.front() = " << vector_one.front() << std::endl;
	vector_one.assign(5, 5);
	std::cout << "vector_one.assign(5, 5)" << std::endl;
	vector_one.push_back(6);
	std::cout << "vector_one.push_back(6)" << std::endl;
	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	std::cout << "vector_one.pop_back()" << std::endl;
	vector_one.pop_back();
	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

void allocator() {

	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

void relational_operators() {

	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

void swap() {

	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
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
	modifiers();
	//ALLOCATOR

	//RELATIONAL OPERATORS

	//SWAP

	return (0);
}
