// myMap.cpp

#include "../../../srcs/utils/pair.hpp"
#include "../../../srcs/utils/make_pair.hpp"
#include <string>
#include <iostream>

void pair_test_1()
{
	ft::pair<std::string, int>	pair_one;
	ft::pair<std::string, int>	pair_two("hi", 1);
	ft::pair<std::string, int>	pair_three(pair_two);
	ft::pair<std::string, int>	pair_four = pair_three;

	pair_one = ft::make_pair<std::string, int>("eyo", 0);

	pair_two.first = "hey";
	pair_two.second = 5;

	std::cout << "pair_one.first = " << pair_one.first << std::endl;
	std::cout << "pair_one.second = " << pair_one.second << std::endl;
	std::cout << "pair_two.first = " << pair_two.first << std::endl;
	std::cout << "pair_two.second = " << pair_two.second << std::endl;
	std::cout << "pair_three.first = " << pair_three.first << std::endl;
	std::cout << "pair_three.second = " << pair_three.second << std::endl;
	std::cout << "pair_four.first = " << pair_four.first << std::endl;
	std::cout << "pair_four.second = " << pair_four.second << std::endl;
}

void pair_test_2()
{
	std::pair<std::string, int>	pair_one;
	std::pair<std::string, int>	pair_two("hi", 1);
	std::pair<std::string, int>	pair_three(pair_two);
	std::pair<std::string, int>	pair_four = pair_three;

	pair_one = std::make_pair<std::string, int>("eyo", 0);

	pair_two.first = "hey";
	pair_two.second = 5;

	std::cout << "pair_one == pair_two: " << (pair_one == pair_two) << std::endl;
	std::cout << "pair_three == pair_four: " << (pair_three == pair_four) << std::endl;
	std::cout << "pair_one != pair_two: " << (pair_one != pair_two) << std::endl;
	std::cout << "pair_three != pair_four: " << (pair_three != pair_four) << std::endl;
	std::cout << "pair_one < pair_two: " << (pair_one < pair_two) << std::endl;
	std::cout << "pair_three <= pair_four: " << (pair_three <= pair_four) << std::endl;
	std::cout << "pair_one > pair_two: " << (pair_one > pair_two) << std::endl;
	std::cout << "pair_three >= pair_four: " << (pair_three >= pair_four) << std::endl;
}

void pair()
{
	std::cout << "--- pair ---" << std::endl;
	pair_test_1();
	pair_test_2();
	std::cout << "------------" << std::endl;
}

int	main(void)
{
	std::cout << "--- test map ---" << std::endl;
	pair();
	std::cout << "----------------" << std::endl;
	return (0);
}
