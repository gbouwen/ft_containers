// map_tests.cpp

#include <iostream>

#include <map>

#include "../time_function.hpp"

void map_constructor_1()
{
	std::map<int, char> test_one;

	for (int i = 0; i < 10; i++)
		test_one.insert(std::pair<int, char>(i, 'a'));

	std::map<int, char> test_two(test_one);
	for (std::map<int, char>::iterator it = test_one.begin(); it != test_one.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
	for (std::map<int, char>::iterator it = test_two.begin(); it != test_two.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_constructor_2()
{
	std::map<int, char> test_one;

	for (int i = 0; i < 10; i++)
		test_one.insert(std::pair<int, char>(i, 'a'));

	std::map<int, char> test_two(test_one.begin(), test_one.end());
	for (std::map<int, char>::iterator it = test_one.begin(); it != test_one.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
	for (std::map<int, char>::iterator it = test_two.begin(); it != test_two.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_copy_constructor_1()
{
	std::map<int, int> test;

	if (true) {
		std::map<int, int> test_two;

		for (int i = 0; i < 10; i++)
			test_two.insert(std::pair<int, int>(i, i));
		test = test_two;
	}
	for (std::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_equals_overload_1()
{
	std::map<int, char> test_one;

	for (int i = 0; i < 10; i++)
		test_one.insert(std::pair<int, char>(i, 'a'));

	std::map<int, char> test_two = test_one;
	for (std::map<int, char>::iterator it = test_one.begin(); it != test_one.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
	for (std::map<int, char>::iterator it = test_two.begin(); it != test_two.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_constructors()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_constructor_1();
	map_constructor_1();
	map_copy_constructor_1();
	map_equals_overload_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.constructor()");
}

void map_begin_1()
{
	std::map<int, char> test;

	test.insert(std::pair<int, char>(100, 'a'));
	std::map<int, char>::iterator it = test.begin();
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void map_end_1()
{
	std::map<int, int> test;

	for (int i = 0; i < 10; i++)
		test.insert(std::pair<int, int>(i, i + 100));
	for (std::map<int, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_end_2()
{
	std::map<int, int> test;

	for (int i = 0; i < 10; i++)
		test.insert(std::pair<int, int>(i, i + 100));
	std::map<int, int>::iterator it = test.end();
	it--;
	for (; it != test.begin(); it--)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_rbegin_1()
{
	std::map<int, int> test;

	for (int i = 0; i < 10; i++)
		test.insert(std::pair<int, int>(i, i + 100));
	for (std::map<int, int>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_rend_1()
{
	std::map<int, int> test;

	for (int i = 0; i < 10; i++)
		test.insert(std::pair<int, int>(i, i + 100));
	std::map<int, int>::reverse_iterator it = test.rend();
	it--;
	for (; it != test.rbegin(); it--)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_iterators()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_begin_1();
	map_end_1();
	map_end_2();
	map_rbegin_1();
	map_rend_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.iterators()");
}

void map_empty_1()
{
	std::map<int, int> test;

	std::cout << "test.empty() = " << test.empty() << std::endl;
	test.insert(std::pair<int, int>(100, 100));
	std::cout << "test.empty() = " << test.empty() << std::endl;
}

void map_size_1()
{
	std::map<int, int> test;

	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 1000; i++)
		test.insert(std::pair<int, int>(i, 100));
	std::cout << "test.size() = " << test.size() << std::endl;
}

void map_max_size_1()
{
	std::map<int, int>	test_one;
	std::map<int, char>	test_two;

	std::cout << "test_one.max_size() = " << test_one.max_size() << std::endl;
	std::cout << "test_two.max_size() = " << test_two.max_size() << std::endl;
}

void map_capacity()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_empty_1();
	map_size_1();
	map_max_size_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.capacity()");
}

void map_brackets_1()
{
	std::map<int, char> test;

	for (int i = 0 ; i < 100; i++)
		test.insert(std::pair<int, char>(i, 'a'));
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test[5] = " << test[5] << std::endl;
	std::cout << "test[50] = " << test[50] << std::endl;
	std::cout << "test[200] = " << test[200] << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
}

void map_element_access()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_brackets_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.capacity()");
}

void map_insert_1()
{
	std::map<int, int> test;

	for (int i = 0; i < 1000000; i++) {
		test.insert(std::pair<int, int>(i, i + 1));
	}
	std::pair<std::map<int, int>::iterator, bool> pair = test.insert(std::pair<int, int>(10, 0));
	std::cout << pair.first->first << " = " << pair.second << std::endl;
	pair = test.insert(std::pair<int, int>(123456789, 0));
	std::cout << pair.first->first << " = " << pair.second << std::endl;
	std::cout << "map.size() = " << test.size() << std::endl;
	std::cout << "test[1] = " << test[1] << std::endl;
	std::cout << "test[10] = " << test[10] << std::endl;
	std::cout << "test[100] = " << test[100] << std::endl;
}

void map_insert_2()
{
	std::map<int, int> test;

	for (int i = 0; i < 1000000; i++) {
		test.insert(std::pair<int, int>(1000000 - i, i));
	}
	std::cout << "map.size() = " << test.size() << std::endl;
	std::cout << "test[1] = " << test[1] << std::endl;
	std::cout << "test[10] = " << test[10] << std::endl;
	std::cout << "test[100] = " << test[100] << std::endl;
}

void map_insert_3()
{
	std::map<int, int> test;
	std::map<int, int> test_two;

	for (int i = 0; i < 1000000; i++) {
		int x = rand() % 1000000;
		test.insert(std::pair<int, int>(x, i));
	}
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test[1] = " << test[1] << std::endl;
	std::cout << "test[10] = " << test[10] << std::endl;
	std::cout << "test[100] = " << test[100] << std::endl;
	test_two.insert(test.begin(), test.end());
	std::cout << "test_two.size() = " << test_two.size() << std::endl;
	std::cout << "test[1] = " << test_two[1] << std::endl;
	std::cout << "test[10] = " << test_two[10] << std::endl;
	std::cout << "test[100] = " << test_two[100] << std::endl;
}

void map_erase_1()
{
	std::map<int, int> test;

	for (int i = 0; i < 1000000; i++) {
		test.insert(std::pair<int, int>(i, i + 1));
	}
	test.erase(1000);
	test.erase(1000);
	test.erase(900);
	test.erase(400);
	test.erase(10);
	test.erase(9000);
}

void map_erase_2()
{
	std::map<int, int> test;

	for (int i = 0; i < 1000000; i++) {
		test.insert(std::pair<int, int>(i, i + 1));
	}
	std::cout << test.size() << std::endl;
	test.erase(test.begin(), test.end());
	std::cout << test.size() << std::endl;
}

void map_erase_3()
{
	std::map<int, int> test;

	for (int i = 0; i < 1000000; i++) {
		test.insert(std::pair<int, int>(i, i + 1));
	}
	for (int i = 0; i < 1000000; i++) {
		int x = rand() % 1000000;
		test.erase(x);
	}
	std::map<int, int> test_two;

	test_two.insert(std::pair<int, int>(1, 1));
	std::cout << test_two.size() << std::endl;
	test_two.erase(test_two.begin());
	std::cout << test_two.size() << std::endl;
}

void map_swap_1()
{
	std::map<int, int>	test;
	std::map<int, int>	test_two;

	for (int i = 0; i < 10; i++) {
		test.insert(std::pair<int, int>(i, i + 1));
	}
	for (int i = 0; i < 10; i++) {
		test_two.insert(std::pair<int, int>(i + 1, i + 1));
	}
	std::map<int, int>::iterator it_one = test.begin();
	for (; it_one != test.end(); it_one++) {
		std::cout << it_one->first;
	}
	std::cout << std::endl;
	it_one = test.begin();

	std::map<int, int>::iterator it_two = test_two.begin();
	for (; it_two != test_two.end(); it_two++) {
		std::cout << it_two->first;
	}
	std::cout << std::endl;
	it_two = test_two.begin();

	std::cout << it_one->first << std::endl;
	std::cout << it_two->first << std::endl;
	test.swap(test_two);
	std::cout << it_one->first << std::endl;
	std::cout << it_two->first << std::endl;
}

void map_swap_2()
{
	std::map<int, int> test;
	std::map<int, int> test_two;

	for (int i = 0; i < 100; i++)
		test.insert(std::pair<int, int>(i, i + 1));
	for (int i = 0; i < 100; i++)
		test_two.insert(std::pair<int, int>(100 - i, 100 - i + 1));
	std::map<int, int>::iterator it_one = test.begin();
	for (int i = 0; i < 27; i++)
		it_one++;
	std::cout << it_one->first << std::endl;
	std::map<int, int>::iterator it_two = test_two.begin();
	for (int i = 0; i < 40; i++)
		it_two++;
	std::cout << it_two->first << std::endl;
	test.swap(test_two);
	std::cout << it_one->first << std::endl;
	std::cout << it_two->first << std::endl;
	it_one++;
	std::cout << it_one->first << std::endl;
	it_two++;
	std::cout << it_two->first << std::endl;
}

void map_clear_1()
{
	std::map<int, int> test;
	std::map<int, int> test_two;

	for (int i = 0; i < 1000000; i++) {
		int x = rand() % 1000000;
		test.insert(std::pair<int, int>(x, i));
	}
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test[1] = " << test[1] << std::endl;
	std::cout << "test[10] = " << test[10] << std::endl;
	std::cout << "test[100] = " << test[100] << std::endl;
	test.clear();
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test_two.size() = " << test_two.size() << std::endl;
	test_two.clear();
	std::cout << "test_two.size() = " << test_two.size() << std::endl;
}

void map_modifiers()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_insert_1();
	map_insert_2();
	map_insert_3();
	map_erase_1();
	map_erase_2();
	map_erase_3();
	map_swap_1();
	map_swap_2();
	map_clear_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.modifiers()");
}

void map_find_1()
{
	std::map<int, int> test;

	for (int i = 0; i < 100; i++) {
		test.insert(std::pair<int, int>(i, i + 100));
	}
	std::map<int, int>::iterator it = test.find(50);
	std::cout << it->first << "->" << it->second << std::endl;
	it = test.find(700);
	if (it == test.end())
		std::cout << "it == test.end()" << std::endl;
}

void map_count_1()
{
	std::map<int, int> test;

	for (int i = 0; i < 100; i++) {
		test.insert(std::pair<int, int>(i, i + 100));
	}
	size_t c = test.count(50);
	std::cout << c << std::endl;
	c = test.count(1000);
	std::cout << c << std::endl;
}

void map_lower_bound_1()
{
	std::map<int, int> test;

	for (int i = 0; i < 100; i++) {
		test.insert(std::pair<int, int>(i, i + 100));
	}
	std::map<int, int>::iterator it = test.lower_bound(40);
	std::cout << it->first << "->" << it->second << std::endl;
	it = test.lower_bound(500);
	if (it == test.end())
		std::cout << "it == test.end()" << std::endl;
}

void map_upper_bound_1()
{
	std::map<int, int> test;

	for (int i = 0; i < 100; i++) {
		test.insert(std::pair<int, int>(i, i + 100));
	}
	std::map<int, int>::iterator it = test.upper_bound(40);
	std::cout << it->first << "->" << it->second << std::endl;
	it = test.upper_bound(500);
	if (it == test.end())
		std::cout << "it == test.end()" << std::endl;
}

void map_equal_range_1()
{
	std::map<int, int> test;

	for (int i = 0; i < 100; i++) {
		test.insert(std::pair<int, int>(i, i + 100));
	}
	std::pair<std::map<int, int>::iterator, std::map<int, int>::iterator> it_pair = test.equal_range(5);
	std::cout << it_pair.first->first << "->" << it_pair.first->second << std::endl;
	std::cout << it_pair.second->first << "->" << it_pair.second->second << std::endl;
	it_pair = test.equal_range(1000);
	if (it_pair.first == test.end())
		std::cout << "it_pair.first == test.end()" << std::endl;
	if (it_pair.second == test.end())
		std::cout << "it_pair.second == test.second()" << std::endl;
}

void map_operations()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_find_1();
	map_count_1();
	map_lower_bound_1();
	map_upper_bound_1();
	map_equal_range_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.operations()");
}

void map_less_1()
{
	std::map<int, int>	test_1;
	std::map<int, int>	test_2;

	test_1.insert(std::pair<int, int>(100, 100));
	test_1.insert(std::pair<int, int>(300, 300));
	test_1.insert(std::pair<int, int>(500, 500));
	test_2.insert(std::pair<int, int>(100, 100));
	test_2.insert(std::pair<int, int>(300, 300));
	test_2.insert(std::pair<int, int>(400, 400));
	std::cout << "test_1 == test_2 : " << (test_1 == test_2) << std::endl;
	std::cout << "test_1 != test_2 : " << (test_1 != test_2) << std::endl;
	std::cout << "test_1 < test_2 : " << (test_1 < test_2) << std::endl;
	std::cout << "test_1 <= test_2 : " << (test_1 <= test_2) << std::endl;
	std::cout << "test_1 > test_2 : " << (test_1 > test_2) << std::endl;
	std::cout << "test_1 >= test_2 : " << (test_1 >= test_2) << std::endl;
}

void map_equal_1()
{
	std::map<int, int>	test_1;
	std::map<int, int>	test_2;

	test_1.insert(std::pair<int, int>(100, 100));
	test_1.insert(std::pair<int, int>(200, 200));
	test_1.insert(std::pair<int, int>(300, 300));
	test_2.insert(std::pair<int, int>(100, 100));
	test_2.insert(std::pair<int, int>(200, 200));
	test_2.insert(std::pair<int, int>(300, 300));
	std::cout << "test_1 == test_2 : " << (test_1 == test_2) << std::endl;
	std::cout << "test_1 != test_2 : " << (test_1 != test_2) << std::endl;
	std::cout << "test_1 < test_2 : " << (test_1 < test_2) << std::endl;
	std::cout << "test_1 <= test_2 : " << (test_1 <= test_2) << std::endl;
	std::cout << "test_1 > test_2 : " << (test_1 > test_2) << std::endl;
	std::cout << "test_1 >= test_2 : " << (test_1 >= test_2) << std::endl;
}

void map_greater_1()
{
	std::map<int, int>	test_1;
	std::map<int, int>	test_2;

	test_1.insert(std::pair<int, int>(100, 100));
	test_1.insert(std::pair<int, int>(300, 300));
	test_1.insert(std::pair<int, int>(500, 500));
	test_2.insert(std::pair<int, int>(100, 100));
	test_2.insert(std::pair<int, int>(300, 300));
	test_2.insert(std::pair<int, int>(400, 400));
	std::cout << "test_1 == test_2 : " << (test_1 == test_2) << std::endl;
	std::cout << "test_1 != test_2 : " << (test_1 != test_2) << std::endl;
	std::cout << "test_1 < test_2 : " << (test_1 < test_2) << std::endl;
	std::cout << "test_1 <= test_2 : " << (test_1 <= test_2) << std::endl;
	std::cout << "test_1 > test_2 : " << (test_1 > test_2) << std::endl;
	std::cout << "test_1 >= test_2 : " << (test_1 >= test_2) << std::endl;
}

void map_relational_operators()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_less_1();
	map_equal_1();
	map_greater_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.relational_operators()");
}

void map_main(void)
{
	map_constructors();
	map_iterators();
	map_capacity();
	map_element_access();
	map_modifiers();
	map_operations();
	map_relational_operators();
}
