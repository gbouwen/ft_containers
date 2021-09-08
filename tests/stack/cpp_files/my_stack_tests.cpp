// stack_tests.cpp

#include <iostream>
#include <sys/time.h>
#include <iomanip>

#include "../../../srcs/vector.hpp"
#include "../../../srcs/stack.hpp"

typedef ft::stack<int>			int_stack;
typedef ft::stack<std::string>	string_stack;

void calc_time_taken(struct timeval start, struct timeval end, std::string function_name)
{
	double time_taken;

	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
	std::cout << "--------------------" << std::endl;
	std::cout << function_name << "-> time taken = " << std::fixed << time_taken << std::setprecision(6) << " sec" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void stack_constructor_1()
{

}

void stack_constructor()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	stack_constructor_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_stack.constructor()");
}

void stack_empty_1()
{
	int_stack test;

	std::cout << "test.empty() = " << test.empty() << std::endl;
}

void stack_empty_2()
{
	int_stack test;

	std::cout << "test.empty() = " << test.empty() << std::endl;
	test.push(5);
	std::cout << "test.empty() = " << test.empty() << std::endl;
}

void stack_empty()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	stack_empty_1();
	stack_empty_2();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_stack.empty()");
}

void stack_size_1()
{
	int_stack test;

	std::cout << "test.size() = " << test.size() << std::endl;
}

void stack_size_2()
{
	int_stack test;

	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 1000; i++)
		test.push(i);
	std::cout << "test.size() = " << test.size() << std::endl;
}

void stack_size_3()
{
	int_stack test;

	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 10000; i++)
		test.push(i);
	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 1000; i++)
		test.pop();
	std::cout << "test.size() = " << test.size() << std::endl;
}

void stack_size()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	stack_size_1();
	stack_size_2();
	stack_size_3();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_stack.size()");
}

void stack_top_1()
{
	int_stack test;

	for (int i = 0; i < 1000; i++)
		test.push(i);
	std::cout << "test.top() = " << test.top() << std::endl;
	for (int i = 0; i < 100; i++)
		test.pop();
	std::cout << "test.top() = " << test.top() << std::endl;
	for (int i = 0; i < 100; i++)
		test.pop();
	std::cout << "test.top() = " << test.top() << std::endl;
}

void stack_top()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	stack_top_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_stack.top()");
}

void stack_push_1()
{
	string_stack test;

	for (int i = 0; i < 10000; i++)
		test.push("hoi");
}

void stack_push_2()
{
	int_stack test;

	for (int i = 0; i < 10000; i++)
		test.push(i);
}

void stack_push()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	stack_push_1();
	stack_push_2();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_stack.push()");
}

void stack_pop_1()
{
	string_stack test;

	for (int i = 0; i < 10000; i++)
		test.push("hoi");
	for (int i = 0; i < 10000; i++)
		test.pop();
}

void stack_pop_2()
{
	int_stack test;

	for (int i = 0; i < 10000; i++)
		test.push(i);
	for (int i = 0; i < 10000; i++)
		test.pop();
}

void stack_pop()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	stack_pop_1();
	stack_pop_2();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_stack.pop()");
}

void stack_member_functions()
{
	std::cout << "--- STACK MEMBER FUNCTIONS ---" << std::endl;
	stack_constructor();
	stack_empty();
	stack_size();
	stack_top();
	stack_push();
	stack_pop();
}

void stack_relational_operators()
{
	std::cout << "--- STACK RELATIONAL OPERATORS ---" << std::endl;
}

void stack_main(void)
{
	stack_member_functions();
	stack_relational_operators();
}

int main(void)
{
	stack_main();
	return (0);
}
