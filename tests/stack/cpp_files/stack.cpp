// stack.cpp

#include <iostream>
#include <stack>

void test_empty_1()
{
	std::stack<int>	stack;

	std::cout << "stack.empty() = " << stack.empty() << std::endl;
}

void test_empty_2()
{
	std::stack<int>	stack;

	std::cout << "stack.empty() = " << stack.empty() << std::endl;
	stack.push(5);
	std::cout << "stack.empty() = " << stack.empty() << std::endl;
}

void test_size_1()
{
	std::stack<int>	stack;

	std::cout << "stack.size() = " << stack.size() << std::endl;
	stack.push(5);
	std::cout << "stack.size() = " << stack.size() << std::endl;
}

void test_size_2()
{
	std::stack<int>	stack;

	std::cout << "stack.size() = " << stack.size() << std::endl;
	for (int i = 0; i < 100; i++)
		stack.push(i);
	std::cout << "stack.size() = " << stack.size() << std::endl;
}

void test_top_1()
{
	std::stack<int>	stack;

	stack.push(5);
	std::cout << "stack.top() = " << stack.top() << std::endl;
}

void test_top_2()
{
	std::stack<int>	stack;

	for (int i = 0; i < 10; i++)
	{
		stack.push(i);
		std::cout << "stack.push(i) = " << i << std::endl;
		std::cout << "stack.top() = " << stack.top() << std::endl;
	}
}

void test_pop_1()
{
	std::stack<int>	stack;

	for (int i = 0; i <= 100; i++)
		stack.push(i);
	for (int i = 0; i <= 100; i++)
	{
		if (i % 10 == 0)
			std::cout << "stack.top() = " << stack.top() << std::endl;
		stack.pop();
	}
}

void member_functions()
{
	std::cout << "--- test empty ---" << std::endl;
	test_empty_1();
	test_empty_2();
	std::cout << "------------------" << std::endl;
	std::cout << "--- test size ---" << std::endl;
	test_size_1();
	test_size_2();
	std::cout << "-----------------" << std::endl;
	std::cout << "--- test top ---" << std::endl;
	test_top_1();
	test_top_2();
	std::cout << "----------------" << std::endl;
	std::cout << "--- test pop ---" << std::endl;
	test_pop_1();
	std::cout << "----------------" << std::endl;
}

void test_equal_operator_1()
{
	std::stack<int>	stack_one;
	std::stack<int>	stack_two;

	stack_one.push(5);
	stack_two.push(5);
	std::cout << "stack_one.push(5); stack_one.top() = " << stack_one.top() << std::endl;
	std::cout << "stack_two.push(5); stack_two.top() = " << stack_two.top() << std::endl;
	std::cout << "stack_one == stack_two : " << (stack_one == stack_two) << std::endl;
}

void test_equal_operator_2()
{
	std::stack<int>	stack_one;
	std::stack<int>	stack_two;

	stack_one.push(5);
	stack_two.push(12);
	std::cout << "stack_one.push(5); stack_one.top() = " << stack_one.top() << std::endl;
	std::cout << "stack_two.push(12); stack_two.top() = " << stack_two.top() << std::endl;
	std::cout << "stack_one == stack_two : " << (stack_one == stack_two) << std::endl;
}

void test_not_equal_operator_1()
{
	std::stack<int>	stack_one;
	std::stack<int>	stack_two;

	stack_one.push(5);
	stack_two.push(12);
	std::cout << "stack_one.push(5); stack_one.top() = " << stack_one.top() << std::endl;
	std::cout << "stack_two.push(12); stack_two.top() = " << stack_two.top() << std::endl;
	std::cout << "stack_one != stack_two : " << (stack_one != stack_two) << std::endl;
}

void test_not_equal_operator_2()
{
	std::stack<int>	stack_one;
	std::stack<int>	stack_two;

	stack_one.push(5);
	stack_two.push(5);
	std::cout << "stack_one.push(5); stack_one.top() = " << stack_one.top() << std::endl;
	std::cout << "stack_two.push(5); stack_two.top() = " << stack_two.top() << std::endl;
	std::cout << "stack_one != stack_two : " << (stack_one != stack_two) << std::endl;
}

void non_member_functions()
{
	std::cout << "--- test operators ---" << std::endl;
	test_equal_operator_1();
	test_equal_operator_2();
	test_not_equal_operator_1();
	test_not_equal_operator_2();
	std::cout << "----------------------" << std::endl;
}

int	main(void)
{
	std::cout << "--- test stack ---" << std::endl;
	member_functions();
	non_member_functions();
	return (0);
}
