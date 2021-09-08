// vector_tests.cpp

#include <iostream>
#include <sys/time.h>
#include <iomanip>

#include <vector>

typedef std::vector<int>			int_vector;
typedef std::vector<std::string>	string_vector;

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

void vector_constructor()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	vector_constructor_1();
	vector_constructor_2();
	vector_equals_overload_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "stl_vector.constructor()");
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
	calc_time_taken(start, end, "stl_vector.iterators()");
}

void vector_main(void)
{
//	vector_constructors();
	vector_iterators();
//	vector_capacity();
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
