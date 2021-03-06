// vector_tests.cpp

#include <iostream>

#include <vector>

#include "../time_function.hpp"

void vector_constructor_1()
{
	std::vector<int> test_1;
	std::vector<int> test_2(5, 10);
	std::vector<int> test_3(test_2);

	std::cout << "test_1.size() = " << test_1.size() << std::endl;
	std::cout << "test_2.size() = " << test_2.size() << std::endl;
	for (size_t i = 0 ; i < test_2.size(); i++)
		std::cout << test_2.at(i) << " ";
	std::cout << std::endl;
	std::cout << "test_3.size() = " << test_3.size() << std::endl;
}

void vector_constructor_2()
{
	std::vector<int> test_1(10, 100);
	std::vector<int> test_2(test_1.begin(), test_1.end());

	for (size_t i = 0; i < test_1.size(); i++)
		std::cout << test_1[i] << " ";
	std::cout << std::endl;
	for (size_t i = 0; i < test_2.size(); i++)
		std::cout << test_2[i] << " ";
	std::cout << std::endl;
}

void vector_equals_overload_1()
{
	std::vector<int> test_1;
	std::vector<int> test_2(5, 100);

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
	calc_time_taken(start, end, "std_vector.constructor()");
}

void vector_begin_1()
{
	std::vector<std::string>		test(5, "hoi");
	const std::vector<std::string>	test_two(5, "doei");

	std::vector<std::string>::iterator it = test.begin();
	const std::vector<std::string>::const_iterator it_two = test_two.begin();
	std::cout << *it << std::endl;
	std::cout << *it_two << std::endl;
	if (it == it_two)
		std::cout << "EQUAL" << std::endl;
	else if (it != it_two)
		std::cout << "NOT EQUAL" << std::endl;
}

void vector_end_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << *it;
	std::cout << std::endl;
}

void vector_end_2()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	std::vector<int>::iterator it = test.begin();
	for (; it + 1 != test.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	for (; it != test.begin(); it--)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void vector_rbegin_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (std::vector<int>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
		std::cout << *it;
	std::cout << std::endl;
}

void vector_rend_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	std::vector<int>::reverse_iterator it = test.rbegin();
	for (; it != test.rend(); it++)
		std::cout << *it << " ";
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
	calc_time_taken(start, end, "std_vector.iterators()");
}

void vector_size_1()
{
	std::vector<int> test;

	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 1000; i++)
		test.push_back(i);
	std::cout << "test.size() = " << test.size() << std::endl;
}

void vector_size_2()
{
	std::vector<int> test;

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
	std::vector<int>			test_1;
	std::vector<std::string>	test_2;

	std::cout << "test_1.max_size() = " << test_1.max_size() << std::endl;
	std::cout << "test_2.max_size() = " << test_2.max_size() << std::endl;
}

void vector_resize_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	std::cout << "test.size() = " << test.size() << std::endl;
	test.resize(5);
	std::cout << "test.size() = " << test.size() << std::endl;
}

void vector_resize_2()
{
	std::vector<int> test;

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
	std::vector<int> test;

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
	std::vector<int> test;

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
	std::vector<int> test;

	std::cout << "test.empty() = " << test.empty() << std::endl;
	for (int i = 0; i < 5; i++)
		test.push_back(i);
	std::cout << "test.empty() = " << test.empty() << std::endl;
}

void vector_reserve_1()
{
	std::vector<int> test;

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
	try {
		test.reserve(test.max_size() + 1);
	} catch (std::exception &e) {
		std::cout << "can't reserve this :)" << std::endl;
	}
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
	calc_time_taken(start, end, "std_vector.capacity()");
}

void vector_brackets_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test[i];
	std::cout << std::endl;
}

void vector_at_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	try {
		std::cout << test.at(100) << std::endl;
	} catch (std::exception &e) {
		std::cout << "test.at(100) throws error" << std::endl;
	}
}

void vector_front_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	std::cout << test.front() << std::endl;
}

void vector_back_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	std::cout << test.back() << std::endl;
}

void vector_element_access()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	vector_brackets_1();
	vector_at_1();
	vector_front_1();
	vector_back_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_vector.capacity()");
}

void vector_assign_1()
{
	std::vector<int> test;

	test.assign(3, 100);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	test.assign(15, 200);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_assign_2()
{
	std::vector<int> test_one;
	std::vector<int> test_two;

	test_one.assign(15, 200);
	std::cout << "test_one.size() = " << test_one.size() << std::endl;
	std::cout << "test_one.capacity() = " << test_one.capacity() << std::endl;
	for (size_t i = 0; i < test_one.size(); i++)
		std::cout << test_one.at(i);
	std::cout << std::endl;
	test_two.assign(test_one.begin(), test_one.end());
	std::cout << "test_two.size() = " << test_two.size() << std::endl;
	std::cout << "test_two.capacity() = " << test_two.capacity() << std::endl;
	for (size_t i = 0; i < test_two.size(); i++)
		std::cout << test_two.at(i);
	std::cout << std::endl;
	test_two.assign(15, 100);
	std::cout << "test_two.size() = " << test_two.size() << std::endl;
	std::cout << "test_two.capacity() = " << test_two.capacity() << std::endl;
	for (size_t i = 0; i < test_two.size(); i++)
		std::cout << test_two.at(i);
	std::cout << std::endl;
	test_two.assign(test_one.begin(), test_one.end());
	std::cout << "test_two.size() = " << test_two.size() << std::endl;
	std::cout << "test_two.capacity() = " << test_two.capacity() << std::endl;
	for (size_t i = 0; i < test_two.size(); i++)
		std::cout << test_two.at(i);
	std::cout << std::endl;
}

void vector_push_back_1()
{
	std::vector<int> test;

	test.push_back(100);
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	for (int i = 0; i < 10; i++)
		test.push_back(i);
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_push_back_2()
{
	std::vector<int> test;

	for (int i = 0; i < 1000000; i++)
		test.push_back(i);
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_push_back_3()
{
	std::vector<std::string> test;

	for (int i = 0; i < 1000000; i++)
		test.push_back("hoi");
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_pop_back_1()
{
	std::vector<std::string> test;

	for (int i = 0; i < 1000000; i++)
		test.push_back("hoi");
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	test.pop_back();
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	test.pop_back();
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_insert_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	test.insert(test.end(), 50);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_insert_2()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	test.insert(test.end(), 5, 5);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_insert_3()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	test.insert(test.end(), 20, 5);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_insert_4()
{
	std::vector<int> test_one;
	std::vector<int> test_two;

	for (int i = 0; i < 10; i++) {
		test_one.push_back(i);
		std::cout << test_one.at(i);
	}
	std::cout << std::endl;
	std::cout << "test_one.size() = " << test_one.size() << std::endl;
	std::cout << "test_one.capacity() = " << test_one.capacity() << std::endl;
	test_two.insert(test_two.end(), test_one.begin(), test_one.end());
	for (size_t i = 0; i < test_two.size(); i++)
		std::cout << test_two.at(i);
	std::cout << std::endl;
	std::cout << "test_two.size() = " << test_two.size() << std::endl;
	std::cout << "test_two.capacity() a = " << test_two.capacity() << std::endl;
}

void vector_erase_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	std::vector<int>::iterator it = test.begin();
	while (*it != 5) {
		it++;
	}
	test.erase(it);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_erase_2()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
	std::vector<int>::iterator it = test.begin();
	while (*it != 5)
		it++;
	test.erase(test.begin(), it);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test.capacity() = " << test.capacity() << std::endl;
}

void vector_swap_1()
{
	std::vector<int> test_one(3, 100);
	std::vector<int> test_two(5, 200);

	for (size_t i = 0; i < test_one.size(); i++)
		std::cout << test_one.at(i) << " ";
	std::cout << std::endl;
	std::cout << "test_one.size() = " << test_one.size() << std::endl;
	for (size_t i = 0; i < test_two.size(); i++)
		std::cout << test_two.at(i) << " ";
	std::cout << std::endl;
	std::cout << "test_two.size() = " << test_two.size() << std::endl;
	test_one.swap(test_two);
	for (size_t i = 0; i < test_one.size(); i++)
		std::cout << test_one.at(i) << " ";
	std::cout << std::endl;
	std::cout << "test_one.size() = " << test_one.size() << std::endl;
	for (size_t i = 0; i < test_two.size(); i++)
		std::cout << test_two.at(i) << " ";
	std::cout << std::endl;
	std::cout << "test_two.size() = " << test_two.size() << std::endl;
}

void vector_clear_1()
{
	std::vector<int> test;

	for (int i = 0; i < 10; i++)
		test.push_back(i);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	test.clear();
	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 5; i++)
		test.push_back(i);
	for (size_t i = 0; i < test.size(); i++)
		std::cout << test.at(i);
	std::cout << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
}

void vector_modifiers()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	vector_assign_1();
	vector_assign_2();
	vector_push_back_1();
	vector_push_back_2();
	vector_push_back_3();
	vector_pop_back_1();
	vector_insert_1();
	vector_insert_2();
	vector_insert_3();
	vector_insert_4();
	vector_erase_1();
	vector_erase_2();
	vector_swap_1();
	vector_clear_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_vector.modifiers()");
}

void vector_less_1()
{
	std::vector<int>	test_1;
	std::vector<int>	test_2;

	test_1.push_back(10);
	test_2.push_back(20);
	std::cout << "test_1 == test_2 : " << (test_1 == test_2) << std::endl;
	std::cout << "test_1 != test_2 : " << (test_1 != test_2) << std::endl;
	std::cout << "test_1 < test_2 : " << (test_1 < test_2) << std::endl;
	std::cout << "test_1 <= test_2 : " << (test_1 <= test_2) << std::endl;
	std::cout << "test_1 > test_2 : " << (test_1 > test_2) << std::endl;
	std::cout << "test_1 >= test_2 : " << (test_1 >= test_2) << std::endl;
}

void vector_equal_1()
{
	std::vector<int> 	test_1;
	std::vector<int>	test_2;

	test_1.push_back(10);
	test_2.push_back(10);
	std::cout << "test_1 == test_2 : " << (test_1 == test_2) << std::endl;
	std::cout << "test_1 != test_2 : " << (test_1 != test_2) << std::endl;
	std::cout << "test_1 < test_2 : " << (test_1 < test_2) << std::endl;
	std::cout << "test_1 <= test_2 : " << (test_1 <= test_2) << std::endl;
	std::cout << "test_1 > test_2 : " << (test_1 > test_2) << std::endl;
	std::cout << "test_1 >= test_2 : " << (test_1 >= test_2) << std::endl;
}

void vector_greater_1()
{
	std::vector<int>	test_1;
	std::vector<int>	test_2;

	test_1.push_back(20);
	test_2.push_back(10);
	std::cout << "test_1 == test_2 : " << (test_1 == test_2) << std::endl;
	std::cout << "test_1 != test_2 : " << (test_1 != test_2) << std::endl;
	std::cout << "test_1 < test_2 : " << (test_1 < test_2) << std::endl;
	std::cout << "test_1 <= test_2 : " << (test_1 <= test_2) << std::endl;
	std::cout << "test_1 > test_2 : " << (test_1 > test_2) << std::endl;
	std::cout << "test_1 >= test_2 : " << (test_1 >= test_2) << std::endl;
}

void vector_relational_operators()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	vector_less_1();
	vector_equal_1();
	vector_greater_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_vector.relational_operators()");
}

void vector_main(void)
{
	vector_constructors();
	vector_iterators();
	vector_capacity();
	vector_element_access();
	vector_modifiers();
	vector_relational_operators();
}
