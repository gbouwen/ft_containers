// stack_tests.cpp

#include <iostream>
#include <vector>

#include "../../srcs/vector.hpp"
#include "../../srcs/stack.hpp"

#include "../time_function.hpp"

void stack_constructor_1()
{
	ft::vector<int>	my_vector(10, 100);
	ft::stack<int>	test(my_vector);

	std::cout << "test.top() = " << test.top() << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
}

void stack_constructor_2()
{
	std::vector<int>					std_vector(10, 100);
	ft::stack< int, std::vector<int> >	test(std_vector);

	std::cout << "test.top() = " << test.top() << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
}

void stack_constructor()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	stack_constructor_1();
	stack_constructor_2();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "ft_stack.constructor()");
}

void stack_empty_1()
{
	ft::stack<int> test;

	std::cout << "test.empty() = " << test.empty() << std::endl;
}

void stack_empty_2()
{
	ft::stack<int> test;

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
	calc_time_taken(start, end, "ft_stack.empty()");
}

void stack_size_1()
{
	ft::stack<int> test;

	std::cout << "test.size() = " << test.size() << std::endl;
}

void stack_size_2()
{
	ft::stack<int> test;

	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 1000; i++)
		test.push(i);
	std::cout << "test.size() = " << test.size() << std::endl;
}

void stack_size_3()
{
	ft::stack<int> test;

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
	calc_time_taken(start, end, "ft_stack.size()");
}

void stack_top_1()
{
	ft::stack<int> test;

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
	calc_time_taken(start, end, "ft_stack.top()");
}

void stack_push_1()
{
	ft::stack<std::string> test;

	for (int i = 0; i < 10000; i++)
		test.push("hoi");
}

void stack_push_2()
{
	ft::stack<int> test;

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
	calc_time_taken(start, end, "ft_stack.push()");
}

void stack_pop_1()
{
	ft::stack<std::string> test;

	for (int i = 0; i < 10000; i++)
		test.push("hoi");
	for (int i = 0; i < 10000; i++)
		test.pop();
}

void stack_pop_2()
{
	ft::stack<int> test;

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
	calc_time_taken(start, end, "ft_stack.pop()");
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

void stack_less_1()
{
	ft::stack<int>	test_1;
	ft::stack<int>	test_2;

	test_1.push(10);
	test_2.push(20);
	std::cout << "test_1 == test_2 : " << (test_1 == test_2) << std::endl;
	std::cout << "test_1 != test_2 : " << (test_1 != test_2) << std::endl;
	std::cout << "test_1 < test_2 : " << (test_1 < test_2) << std::endl;
	std::cout << "test_1 <= test_2 : " << (test_1 <= test_2) << std::endl;
	std::cout << "test_1 > test_2 : " << (test_1 > test_2) << std::endl;
	std::cout << "test_1 >= test_2 : " << (test_1 >= test_2) << std::endl;
}

void stack_equal_1()
{
	ft::stack<int>	test_1;
	ft::stack<int>	test_2;

	test_1.push(10);
	test_2.push(10);
	std::cout << "test_1 == test_2 : " << (test_1 == test_2) << std::endl;
	std::cout << "test_1 != test_2 : " << (test_1 != test_2) << std::endl;
	std::cout << "test_1 < test_2 : " << (test_1 < test_2) << std::endl;
	std::cout << "test_1 <= test_2 : " << (test_1 <= test_2) << std::endl;
	std::cout << "test_1 > test_2 : " << (test_1 > test_2) << std::endl;
	std::cout << "test_1 >= test_2 : " << (test_1 >= test_2) << std::endl;
}

void stack_greater_1()
{
	ft::stack<int>	test_1;
	ft::stack<int>	test_2;

	test_1.push(10);
	test_2.push(20);
	std::cout << "test_1 == test_2 : " << (test_1 == test_2) << std::endl;
	std::cout << "test_1 != test_2 : " << (test_1 != test_2) << std::endl;
	std::cout << "test_1 < test_2 : " << (test_1 < test_2) << std::endl;
	std::cout << "test_1 <= test_2 : " << (test_1 <= test_2) << std::endl;
	std::cout << "test_1 > test_2 : " << (test_1 > test_2) << std::endl;
	std::cout << "test_1 >= test_2 : " << (test_1 >= test_2) << std::endl;
}

void stack_relational_operators()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	stack_less_1();
	stack_equal_1();
	stack_greater_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "ft_stack.relational_operators()");
}

void stack_main(void)
{
	stack_member_functions();
	stack_relational_operators();
}
