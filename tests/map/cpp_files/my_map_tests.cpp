// map_tests.cpp

#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <cstdlib>

#include "../../../srcs/map.hpp"

typedef ft::map<int, char>			int_char_map;
typedef ft::map<int, int>			int_int_map;
typedef ft::map<int, std::string>	int_string_map;
typedef ft::pair<int, char>			int_char_pair;
typedef ft::pair<int, int>			int_int_pair;
typedef ft::pair<int, std::string>	int_string_pair;

void calc_time_taken(struct timeval start, struct timeval end, std::string function_name)
{
	double time_taken;

	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
	std::cout << "--------------------" << std::endl;
	std::cout << function_name << "-> time taken = " << std::fixed << time_taken << std::setprecision(6) << " sec" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void map_constructor_1()
{
	int_char_map test_one;

	for (int i = 0; i < 10; i++)
		test_one.insert(int_char_pair(i, 'a'));

	int_char_map test_two(test_one);
	for (int_char_map::iterator it = test_one.begin(); it != test_one.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
	for (int_char_map::iterator it = test_two.begin(); it != test_two.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_constructor_2()
{
	int_char_map test_one;

	for (int i = 0; i < 10; i++)
		test_one.insert(int_char_pair(i, 'a'));

	int_char_map test_two(test_one.begin(), test_one.end());
	for (int_char_map::iterator it = test_one.begin(); it != test_one.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
	for (int_char_map::iterator it = test_two.begin(); it != test_two.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_equals_overload_1()
{
	int_char_map test_one;

	for (int i = 0; i < 10; i++)
		test_one.insert(int_char_pair(i, 'a'));

	int_char_map test_two = test_one;
	for (int_char_map::iterator it = test_one.begin(); it != test_one.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
	for (int_char_map::iterator it = test_two.begin(); it != test_two.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_constructors()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_constructor_1();
	map_constructor_2();
	map_equals_overload_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_map.constructor()");
}

void map_begin_1()
{
	int_char_map test;

	test.insert(int_char_pair(100, 'a'));
	int_char_map::iterator it = test.begin();
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void map_end_1()
{
	int_int_map test;

	for (int i = 0; i < 10; i++)
		test.insert(int_int_pair(i, i + 100));
	for (int_int_map::iterator it = test.begin(); it != test.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_end_2()
{
	int_int_map test;

	for (int i = 0; i < 10; i++)
		test.insert(int_int_pair(i, i + 100));
	int_int_map::iterator it = test.end();
	it--;
	for (; it != test.begin(); it--)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_rbegin_1()
{
	int_int_map test;

	for (int i = 0; i < 10; i++)
		test.insert(int_int_pair(i, i + 100));
	for (int_int_map::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_rend_1()
{
	int_int_map test;

	for (int i = 0; i < 10; i++)
		test.insert(int_int_pair(i, i + 100));
	int_int_map::reverse_iterator it = test.rend();
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
	calc_time_taken(start, end, "my_map.iterators()");
}

void map_empty_1()
{
	int_int_map test;

	std::cout << "test.empty() = " << test.empty() << std::endl;
	test.insert(int_int_pair(100, 100));
	std::cout << "test.empty() = " << test.empty() << std::endl;
}

void map_size_1()
{
	int_int_map test;

	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 1000; i++)
		test.insert(int_int_pair(i, 100));
	std::cout << "test.size() = " << test.size() << std::endl;
}

void map_max_size_1()
{
	int_int_map		test_one;
	int_char_map	test_two;

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
	calc_time_taken(start, end, "my_map.capacity()");
}

void map_brackets_1()
{
	int_char_map test;

	for (int i = 0 ; i < 100; i++)
		test.insert(int_char_pair(i, 'a'));
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
	calc_time_taken(start, end, "my_map.capacity()");
}

void map_insert_1()
{
	int_int_map test;

	for (int i = 0; i < 1000; i++) {
//		int x = rand() % 10000;
		int y = rand();
//		test.insert(int_int_pair(x, y));
		test.insert(int_int_pair(i, y));
	}
	std::cout << "map.size() = " << test.size() << std::endl;
	std::cout << "map[1] = " << test[1] << std::endl;
	std::cout << "map[10] = " << test[10] << std::endl;
	std::cout << "map[100] = " << test[100] << std::endl;
}

void map_modifiers()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_insert_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_map.modifiers()");
}

void map_operations()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_map.relational_operators()");
}

void map_main(void)
{
//	map_constructors();
//	map_iterators();
//	map_capacity();
//	map_element_access();
	map_modifiers();
//	map_operations();
}

int main(void)
{
	map_main();
	return (0);
}
