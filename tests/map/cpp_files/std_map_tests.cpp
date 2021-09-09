// map_tests.cpp

#include <iostream>
#include <sys/time.h>
#include <iomanip>

#include <map>

typedef std::map<int, char>			int_char_map;
typedef std::map<int, int>			int_int_map;
typedef std::map<int, std::string>	int_string_map;
typedef std::pair<int, char>		int_char_pair;
typedef std::pair<int, int>			int_int_pair;
typedef std::pair<int, std::string>	int_string_pair;

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

	for (int i = 0; i < 10; i++) {
		test_one.insert(int_char_pair(i, 'a'));
	}

	int_char_map test_two(test_one);
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
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.constructor()");
}

void map_iterators()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.iterators()");
}

void map_capacity()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.capacity()");
}

void map_element_access()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.capacity()");
}

void map_modifiers()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.modifiers()");
}

void map_operations()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "std_map.relational_operators()");
}

void map_main(void)
{
	map_constructors();
//	map_iterators();
//	map_capacity();
//	map_element_access();
//	map_modifiers();
//	map_operations();
}

int main(void)
{
	map_main();
	return (0);
}
