// myVector.cpp

#include <iostream>
#include "../../../containers/Vector.hpp"

// CONSTRUCTORS/DESTRUCTOR/OPERATOR

void test_fill_constructor_1() {
	std::cout << "ft::vector_one<int>	vector_one(10, 100)" << std::endl;
	ft::vector<int>	vector_one(10, 100);

	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void test_fill_constructor_2() {
	std::cout << "ft::vector_one<int>	vector_one(10, 100)" << std::endl;
	ft::vector<int>	vector_one(2, 3);

	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void test_copy_constructor_1() {
	ft::vector<int>	vector_one(10, 25);
	ft::vector<int>	vector_two(vector_one);

	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	for (size_t i = 0; i < vector_two.size(); i++)
		std::cout << vector_two[i] << std::endl;
	std::cout << "vector_two.size() = " << vector_two.size() << std::endl;
	std::cout << "vector_two.capacity() = " << vector_two.capacity() << std::endl;
}

void test_overload_1() {
	ft::vector<int>	vector_one(10, 25);
	ft::vector<int>	vector_two;

	vector_two = vector_one;
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "vector_two.size() = " << vector_two.size() << std::endl;
	std::cout << "vector_two.capacity() = " << vector_two.capacity() << std::endl;
	for (size_t i = 0; i < vector_two.size(); i++)
		std::cout << vector_two[i] << std::endl;
}

void test_overload_2() {
	ft::vector<int>	vector_one(10, 25);
	ft::vector<int>	vector_two(20, 100);

	vector_two = vector_one;
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "vector_two.size() = " << vector_two.size() << std::endl;
	std::cout << "vector_two.capacity() = " << vector_two.capacity() << std::endl;
	for (size_t i = 0; i < vector_two.size(); i++)
		std::cout << vector_two[i] << std::endl;
}

void constructors_destructor_operator() {
	std::cout << "------------------------------- TESTING CAPACITY -------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;

	test_fill_constructor_1();
	test_fill_constructor_2();
	test_copy_constructor_1();
	test_overload_1();
	test_overload_2();
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

// ITERATORS

void iterators() {

	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

// CAPACITY

void resize_test_1() {
	ft::vector<int>	vector_one;

	vector_one.assign(10, 100);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	vector_one.resize(5, 20);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	vector_one.resize(8, 10);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	vector_one.resize(16, 1);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void reserve_test_1() {
	ft::vector<int>	vector_one;

	std::cout << "vector_one.reserve(5)" << std::endl;
	vector_one.reserve(5);
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	std::cout << "vector_one.push_back(12)" << std::endl;
	vector_one.push_back(12);
	std::cout << "vector_one.front() = " << vector_one.front() << std::endl;
	std::cout << "vector_one.reserve(10)" << std::endl;
	vector_one.reserve(10);
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	std::cout << "vector_one.front() = " << vector_one.front() << std::endl;
}

void capacity() {
	std::cout << "------------------------------- TESTING CAPACITY -------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;

	resize_test_1();
	reserve_test_1();
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

// ELEMENT ACCESS

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

// MODIFIERS

void assign_test_1() {
	ft::vector<int>	vector_one;

	std::cout << "vector_one.assign(3, 100)" << std::endl;
	vector_one.assign(3, 100);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	std::cout << "vector_one.assign(15, 200)" << std::endl;
	vector_one.assign(15, 200);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void assign_test_2() {
	ft::vector<int>	vector_one;

	std::cout << "vector_one.assign(3, 100)" << std::endl;
	vector_one.assign(3, 100);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	std::cout << "vector_one.assign(4, 200)" << std::endl;
	vector_one.assign(4, 200);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void swap_test_1() {
	ft::vector<int>	vector_one(3, 100);
	ft::vector<int>	vector_two(5, 200);

	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "------------" << std::endl;
	for (size_t i = 0; i < vector_two.size(); i++)
		std::cout << vector_two[i] << std::endl;
	std::cout << "vector_one.swap(vector_two)" << std::endl;
	vector_one.swap(vector_two);
	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "------------" << std::endl;
	for (size_t i = 0; i < vector_two.size(); i++)
		std::cout << vector_two[i] << std::endl;
}

void modifiers() {
	std::cout << "------------------------------- TESTING MODIFIERS ------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
//	assign_test_1();
//	assign_test_2();
	swap_test_1();
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

// ALLOCATOR

void allocator() {

	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

// RELATIONAL OPERATORS

void relational_operators() {
	std::cout << "------------------------------- TESTING RELATIONAL OPERATORS -------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

// SWAP

void swap() {

	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

int	main(void) {
	std::cout << "myVector test" << std::endl;

//	constructors_destructor_operator();
//	modifiers();
//	capacity();
	relational_operators();
	return (0);
}
