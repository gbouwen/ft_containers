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

void vector_constructor()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	vector_constructor_1();
	vector_constructor_2();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_vector.constructor()");
}

//void vector_empty()
//{
	//struct timeval	start, end;

	//gettimeofday(&start, NULL);
	//vector_empty_1();
	//vector_empty_2();
	//gettimeofday(&end, NULL);
	//calc_time_taken(start, end, "my_vector.empty()");
//}

//void vector_size()
//{
	//struct timeval	start, end;

	//gettimeofday(&start, NULL);
	//vector_size_1();
	//vector_size_2();
	//vector_size_3();
	//gettimeofday(&end, NULL);
	//calc_time_taken(start, end, "my_vector.size()");
//}

//void vector_top()
//{
	//struct timeval	start, end;

	//gettimeofday(&start, NULL);
	//vector_top_1();
	//gettimeofday(&end, NULL);
	//calc_time_taken(start, end, "my_vector.top()");
//}

//void vector_push()
//{
	//struct timeval	start, end;

	//gettimeofday(&start, NULL);
	//vector_push_1();
	//vector_push_2();
	//gettimeofday(&end, NULL);
	//calc_time_taken(start, end, "my_vector.push()");
//}

//void vector_pop()
//{
	//struct timeval	start, end;

	//gettimeofday(&start, NULL);
	//vector_pop_1();
	//vector_pop_2();
	//gettimeofday(&end, NULL);
	//calc_time_taken(start, end, "my_vector.pop()");
//}

//void vector_relational_operators()
//{
	//struct timeval	start, end;

	//gettimeofday(&start, NULL);
	//vector_less_1();
	//vector_equal_1();
	//vector_greater_1();
	//gettimeofday(&end, NULL);
	//calc_time_taken(start, end, "my_vector.relational_operators()");
//}

void vector_main(void)
{
	vector_constructor();
//	iterators();
//	capacity();
//	element_access();
//	modifiers();
//	vector_relational_operators();
}

int main(void)
{
	vector_main();
	return (0);
}
