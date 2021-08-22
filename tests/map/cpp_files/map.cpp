// map.cpp

#include <utility>
#include <map>
#include <iostream>

void pair_test_1()
{
	std::pair<std::string, int>	pair_one;
	std::pair<std::string, int>	pair_two("hi", 1);
	std::pair<std::string, int>	pair_three(pair_two);
	std::pair<std::string, int>	pair_four = pair_three;

	pair_one = std::make_pair<std::string, int>("eyo", 0);

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

void test_empty_1()
{
	std::map<int, int>	map;

	std::cout << "map.empty() = " << map.empty() << std::endl;
}

void test_size_1()
{
	std::map<int, int>	map;

	std::cout << "map.size() = " << map.size() << std::endl;
}

void test_max_size_1()
{

}

void capacity()
{
	test_empty_1();
	test_size_1();
//	test_max_size_1();
}

void observers()
{
	std::map<char, int>					map;
	std::map<char, int>::key_compare	comp_one = map.key_comp();
	std::map<char, int>::value_compare	comp_two = map.value_comp();
	(void)comp_one;
	(void)comp_two;
}

int	main(void)
{
	std::cout << "--- test map ---" << std::endl;
//	pair();
//	capacity();
//	observers();
	std::cout << "----------------" << std::endl;
	return (0);
}
