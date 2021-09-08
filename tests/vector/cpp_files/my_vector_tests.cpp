// vector_tests.cpp

#include <iostream>
#include <sys/time.h>
#include <iomanip>

#include "../../../srcs/vector.hpp"

typedef ft::vector<int>			int_vector;
typedef ft::vector<std::string>	string_vector;

void calc_time_taken(struct timeval start, struct timeval end, std::string function_name)
{
	double time_taken;

	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
	std::cout << "--------------------" << std::endl;
	std::cout << function_name << "-> time taken = " << std::fixed << time_taken << std::setprecision(6) << " sec" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void vector_constructor_1()
{
	int_vector test_1;
	int_vector test_2(5, 100);
	int_vector test_3(test_2);

	std::cout << "test_1.size() = " << test_1.size() << std::endl;
	std::cout << "test_2.size() = " << test_2.size() << std::endl;
	std::cout << "test_3.size() = " << test_3.size() << std::endl;
}

void vector_constructor_2()
{
	int_vector test_1(10, 100);
	int_vector test_2(test_1.begin(), test_1.end());

	for (size_t i = 0; i < test_1.size(); i++)
		std::cout << test_1[i] << std::endl;
	for (size_t i = 0; i < test_2.size(); i++)
		std::cout << test_2[i] << std::endl;
}

void vector_equals_overload_1()
{
	int_vector test_1;
	int_vector test_2(5, 100);

	test_1 = test_2;
	std::cout << "test_1.size() = " << test_1.size() << std::endl;
	std::cout << "test_2.size() = " << test_2.size() << std::endl;
}

void vector_constructors()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	vector_constructor_1();
	vector_constructor_2();
	vector_equals_overload_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_vector.constructor()");
}

void vector_begin_1()
{
	string_vector test(5, "hoi");

	string_vector::iterator it = test.begin();
	std::cout << *it << std::endl;
}

void vector_end_1()
{
	int_vector test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (int_vector::iterator it = test.begin(); it != test.end(); it++)
		std::cout << *it;
	std::cout << std::endl;
}

void vector_end_2()
{
	int_vector test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (int_vector::iterator it = test.end()--; it != test.begin(); it--)
		std::cout << *it;
	std::cout << std::endl;
}

void vector_rbegin_1()
{
	int_vector test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (int_vector::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
		std::cout << *it;
	std::cout << std::endl;
}

void vector_rend_1()
{
	int_vector test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (int_vector::reverse_iterator it = test.rend()--; it != test.rbegin(); it--)
		std::cout << *it;
	std::cout << std::endl;
}

void vector_iterators()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	vector_begin_1();
	vector_end_1();
	vector_end_2();
	vector_rbegin_1();
	vector_rend_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_vector.iterators()");
}

void vector_size_1()
{
	int_vector test;

	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 1000; i++)
		test.push_back(i);
	std::cout << "test.size() = " << test.size() << std::endl;
}

void vector_size_2()
{
	int_vector test;

	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 1000; i++)
		test.push_back(i);
	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 123; i++)
		test.pop_back();
	std::cout << "test.size() = " << test.size() << std::endl;
}

void vector_max_size_1()
{
	int_vector		test_1;
	string_vector	test_2;

	std::cout << "test_1.max_size() = " << test_1.max_size() << std::endl;
	std::cout << "test_2.max_size() = " << test_2.max_size() << std::endl;
}

void vector_resize_1()
{
	int_vector test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	std::cout << "test.size() = " << test.size() << std::endl;
	test.resize(5);
	std::cout << "test.size() = " << test.size() << std::endl;
}

void vector_resize_2()
{
	int_vector test;

	for (int i = 0; i < 5; i++)
		test.push_back(i);
	std::cout << "test.size() = " << test.size() << std::endl;
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test[i];
	std::cout << std::endl;
	test.resize(10, 5);
	std::cout << "test.size() = " << test.size() << std::endl;
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test[i];
	std::cout << std::endl;
}

void vector_resize_3()
{
	int_vector test;

	for (int i = 0; i < 5; i++)
		test.push_back(i);
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test[i];
	std::cout << std::endl;
	test.resize(50, 5);
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test[i];
	std::cout << std::endl;
}

void vector_capacity_1()
{
	int_vector test;

	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	for (int i = 0; i < 5; i++)
		test.push_back(i);
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	test.resize(50, 5);
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	test.resize(5);
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_empty_1()
{
	int_vector test;

	std::cout << "test.empty() = " << test.empty() << std::endl;
	for (int i = 0; i < 5; i++)
		test.push_back(i);
	std::cout << "test.empty() = " << test.empty() << std::endl;
}

void vector_reserve_1()
{
	int_vector test;

	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	test.reserve(100);
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	for (int i = 0; i < 20; i++)
		test.push_back(i);
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	test.reserve(20);
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_capacity()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	vector_size_1();
	vector_size_2();
	vector_max_size_1();
	vector_resize_1();
	vector_resize_2();
	vector_resize_3();
	vector_capacity_1();
	vector_empty_1();
	vector_reserve_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_vector.capacity()");
}

void vector_main(void)
{
	vector_constructors();
	vector_iterators();
	vector_capacity();
//	vector_element_access();
//	vector_modifiers();
//	vector_relational_operators();
//	vector_swap()
}

int main(void)
{
	vector_main();
	return (0);
}
