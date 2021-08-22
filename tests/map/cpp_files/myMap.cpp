// myMap.cpp

#include "../../../srcs/map.hpp"
#include "../../../srcs/utils/pair.hpp"
#include "../../../srcs/utils/make_pair.hpp"
#include "../../../srcs/utils/node.hpp"
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

void test_empty_1()
{
	ft::map<int, int>	map;

	std::cout << "map.empty() = " << map.empty() << std::endl;
}

void test_size_1()
{
	ft::map<int, int>	map;

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
	ft::map<char, int>					map;
	ft::map<char, int>::key_compare		comp_one = map.key_comp();
	ft::map<char, int>::value_compare	comp_two = map.value_comp();
	(void)comp_one;
	(void)comp_two;
}

//void node()
//{
	//ft::node	*node = new ft::node;
	//ft::node	*node_two = new ft::node;
	//ft::node	*node_three = new ft::node;
	//ft::node	*temp = new ft::node;

	//node->data = 100;
	//node_two->data = 200;
	//node_three->data = 300;
	//node->root = NULL;
	//node->left = node_two;
	//node->right = node_three;
	//node_two->root = node;
	//node_two->left = NULL;
	//node_two->right = NULL;
	//node_three->root = node;
	//node_three->left = NULL;
	//node_three->right = NULL;

	//temp = node;
	//while (temp)
	//{
		//std::cout << temp->data << std::endl;
		//temp = temp->left;
	//}
	//temp = node;
	//while (temp)
	//{
		//std::cout << temp->data << std::endl;
		//temp = temp->right;
	//}
//}

int	main(void)
{
	std::cout << "--- test myMap ---" << std::endl;
//	pair();
//	capacity();
//	observers();
//	node();
	std::cout << "----------------" << std::endl;
	return (0);
}
