// vector.cpp

#include <iostream>
#include <vector>

// CONSTRUCTORS/DESTRUCTOR/OPERATOR

void test_fill_constructor_1() {
	std::cout << "std::vector_one<int>	vector_one(10, 100)" << std::endl;
	std::vector<int>	vector_one(10, 100);

	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void test_fill_constructor_2() {
	std::cout << "std::vector_one<int>	vector_one(10, 100)" << std::endl;
	std::vector<int>	vector_one(2, 3);

	for (size_t i = 0; i < vector_one.size(); i++)
		std::cout << vector_one[i] << std::endl;
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void test_copy_constructor_1() {
	std::vector<int>	vector_one(10, 25);
	std::vector<int>	vector_two(vector_one);

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
	std::vector<int>	vector_one(10, 25);
	std::vector<int>	vector_two;

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
	std::vector<int>	vector_one(10, 25);
	std::vector<int>	vector_two(20, 100);

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

void test_begin_1()
{
	std::vector<int>	vector_one(5, 100);

	std::cout << "vector_one.begin()" << std::endl;
	std::vector<int>::iterator it = vector_one.begin();
	std::cout << "*it = " << *it << std::endl;
}

void test_for_loop_1()
{
	std::vector<int>	vector_one(5, 20);

	for (std::vector<int>::iterator it = vector_one.begin(); it != vector_one.end(); it++)
		std::cout << "*it = " << *it << std::endl;
}

void test_add_to_it_1()
{
	std::vector<int>			vector_one(10, 100);
	std::vector<int>::iterator	it_one = vector_one.begin();
	std::vector<int>::iterator it_two = it_one + 5;

	std::cout << *it_two << std::endl;
}

void test_add_it_to_int_1()
{
	std::vector<int>			vector_one(10, 100);
	std::vector<int>::iterator	it_one = vector_one.begin();
	std::vector<int>::iterator	it_two = 5 + it_one;

	std::cout << *it_two << std::endl;
}

void test_sub_it_from_it_1()
{
	std::vector<int>			vector_one(10, 100);
	std::vector<int>::iterator	it_one = vector_one.begin();
	std::vector<int>::iterator	it_two = it_one + 5;

	std::cout << it_two - it_one << std::endl;
}

void test_plus_equals_it_1()
{
	std::vector<int>			vector_one(10, 100);
	std::vector<int>::iterator	it_one = vector_one.begin();

	it_one += 5;
	std::cout << *it_one << std::endl;
}

void test_rev_it_1()
{
	std::vector<int>	vector_one;

	for (size_t i = 0; i < 10; i++)
		vector_one.push_back(i);

	std::cout << "--- iterator ---" << std::endl;
	for (std::vector<int>::iterator it_one = vector_one.begin(); it_one != vector_one.end(); it_one++)
		std::cout << *it_one << std::endl;

	std::cout << "--- reverse_iterator ---" << std::endl;
	for (std::vector<int>::reverse_iterator it_two = vector_one.rbegin(); it_two != vector_one.rend(); it_two++)
		std::cout << *it_two << std::endl;
}

void test_const_it_1()
{
	std::vector<int> vector_one;

	for (size_t i = 0; i < 10; i++)
		vector_one.push_back(i);

	for (std::vector<int>::const_iterator it_one = vector_one.begin(); it_one != vector_one.end(); it_one++)
		std::cout << *it_one << std::endl;
}

void iterators() {
	std::cout << "------------------------------- TESTING ITERATORS ------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;

//	test_begin_1();
//	test_for_loop_1();
//	test_add_to_it_1();
//	test_add_it_to_int_1();
//	test_sub_it_from_it_1();
//	test_plus_equals_it_1();
//	test_rev_it_1();
	test_const_it_1();
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

// CAPACITY

void test_size_1() {
	std::vector<int> vector_one(10, 100);

	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
}

void test_size_2() {
	std::vector<int> vector_one;

	for (int i = 0; i < 10; i++)
		vector_one.push_back(i);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
}

void test_size_3() {
	std::vector<int> vector_one(500, 100);

	vector_one.push_back(100);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
}

void test_size_4() {
	std::vector<int> vector_one(500, 100);

	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	for (int i = 0; i < 130; i++)
		vector_one.pop_back();
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
}

void size() {
	std::cout << "--- TESTING SIZE ---" << std::endl;
	test_size_1();
	test_size_2();
	test_size_3();
	test_size_4();
	std::cout << "--------------------" << std::endl;
}

void max_size() {
	std::cout << "--- TESTING MAX_SIZE ---" << std::endl;
	std::vector<int>			vector_one;
	std::vector<std::string>	vector_two;
	std::vector<double>			vector_three;
	std::vector<float>			vector_four;

	std::cout << "vector_one<int>.max_size() = " << vector_one.max_size() << std::endl;
	std::cout << "vector_two<std::string>.max_size() = " << vector_two.max_size() << std::endl;
	std::cout << "vector_three<double>.max_size() = " << vector_three.max_size() << std::endl;
	std::cout << "vector_four<float>.max_size() = " << vector_four.max_size() << std::endl;
	std::cout << "--------------------" << std::endl;
}

void test_resize_1() {
	std::cout << "--- TESTING RESIZE ---" << std::endl;
	std::vector<int>	vector_one(10, 100);

	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	vector_one.resize(100);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	vector_one.resize(12);
	std::cout << "vector_one.size() = " << vector_one.size() << std::endl;
	std::cout << "----------------------" << std::endl;
}

void test_resize_2() {
	std::vector<int> vector_one(10, 100);

	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	vector_one.resize(100);
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	vector_one.resize(1000);
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void resize() {
	test_resize_1();
	test_resize_2();
}

void test_capacity_1() {
	std::vector<int> vector_one;

	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void test_capacity_2() {
	std::vector<int> vector_one(10, 100);

	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	vector_one.resize(1);
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	vector_one.resize(120);
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void capacity() {
	std::cout << "--- TESTING CAPACITY ---" << std::endl;
	test_capacity_1();
	test_capacity_2();
	std::cout << "------------------------" << std::endl;
}

void test_empty_1() {
	std::vector<int>	vector_one;

	std::cout << "vector_one.empty() = " << vector_one.empty() << std::endl;
}

void test_empty_2() {
	std::vector<int> vector_one(10, 100);

	std::cout << "vector_one.empty() = " << vector_one.empty() << std::endl;
}

void empty() {
	std::cout << "--- TESTING EMPTY ---" << std::endl;
	test_empty_1();
	test_empty_2();
	std::cout << "---------------------" << std::endl;
}

void test_reserve_1() {
	std::vector<int>	vector_one;

	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	vector_one.reserve(10);
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	vector_one.reserve(1);
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
}

void reserve() {
	std::cout << "--- TESTING RESERVE ---" << std::endl;
	test_reserve_1();
	std::cout << "-----------------------" << std::endl;
}

void capacity_all() {
	std::cout << "------------------------------- TESTING CAPACITY -------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;

	size();
	max_size();
	resize();
	capacity();
	empty();
	reserve();
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
}

// ELEMENT ACCESS

void element_access() {
	std::cout << "------------------------------- TESTING ELEMENT ACCESS -------------------" << std::endl;
	std::cout << "--------------------------------------------------------------------------" << std::endl;
	std::vector<int>	vector_one;

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
	std::vector<int>	vector_one;

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
	std::vector<int>	vector_one;

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
	std::vector<int>	vector_one(3, 100);
	std::vector<int>	vector_two(5, 200);

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
	std::cout << "vector test" << std::endl;

//	constructors_destructor_operator();
//	modifiers();
//	capacity_all();
//	relational_operators();
	iterators();
	return (0);
}
