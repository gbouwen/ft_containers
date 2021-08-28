// myMap.cpp

#include "../../../srcs/map.hpp"
#include "../../../srcs/utils/pair.hpp"
#include "../../../srcs/utils/make_pair.hpp"
#include "../../../srcs/utils/node.hpp"

#include <string>
#include <iostream>

// --- PAIR ---

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
	ft::pair<std::string, int>	pair_one;
	ft::pair<std::string, int>	pair_two("hi", 1);
	ft::pair<std::string, int>	pair_three(pair_two);
	ft::pair<std::string, int>	pair_four = pair_three;

	pair_one = ft::make_pair<std::string, int>("eyo", 0);

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

void test_iterator_constructor_1()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('l', 500));
	map.insert(ft::pair<char, int>('d', 500));
	map.insert(ft::pair<char, int>('v', 500));
	map.insert(ft::pair<char, int>('q', 500));
	map.insert(ft::pair<char, int>('a', 500));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('x', 500));
	ft::map<char, int>::iterator first = map.find('a');
	ft::map<char, int>::iterator last = map.find('x');

	ft::map<char, int> map_two(first, last);
	for (ft::map<char, int>::iterator it = map_two.begin(); it != map_two.end(); it++) {
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void test_copy_constructor_1()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('l', 500));
	map.insert(ft::pair<char, int>('d', 500));
	map.insert(ft::pair<char, int>('v', 500));
	map.insert(ft::pair<char, int>('q', 500));
	map.insert(ft::pair<char, int>('a', 500));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('x', 500));

	ft::map<char, int> map_two(map);
	for (ft::map<char, int>::iterator it = map_two.begin(); it != map_two.end(); it++) {
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void constructors()
{
//	test_iterator_constructor_1();
	test_copy_constructor_1();
}

// -- CAPACITY ---

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

// --- OBSERVERS ---

void observers()
{
	ft::map<char, int>					map;
	ft::map<char, int>::key_compare		comp_one = map.key_comp();
	ft::map<char, int>::value_compare	comp_two = map.value_comp();
	(void)comp_one;
	(void)comp_two;
}

// --- ITERATORS ---

void test_begin_1()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	ft::map<char, int>::iterator it = map.begin();
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void test_it_plus_1()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('l', 500));
	map.insert(ft::pair<char, int>('d', 500));
	map.insert(ft::pair<char, int>('v', 500));
	map.insert(ft::pair<char, int>('q', 500));
	map.insert(ft::pair<char, int>('a', 500));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('x', 500));
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << "it->first = " << it->first << std::endl;
		std::cout << "it->second = " << it->second << std::endl;
	}
}

void test_end_1()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('a', 100));

	ft::map<char, int>::iterator it = map.end();
	it--;
	it--;
	it--;
	it--;
	it--;
	it--;
	it--;
	it--;
	it--;
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void test_it_minus_1()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('l', 500));
	map.insert(ft::pair<char, int>('d', 500));
	map.insert(ft::pair<char, int>('v', 500));
	map.insert(ft::pair<char, int>('q', 500));
	map.insert(ft::pair<char, int>('a', 500));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('x', 500));
	ft::map<char, int>::iterator it = map.end();
//	map.get_allocator();
	for (; it != map.begin(); it--) {
		std::cout << "it->first = " << it->first << std::endl;
		std::cout << "it->second = " << it->second << std::endl;
	}
	std::cout << "it->first = " << it->first << std::endl;
	std::cout << "it->second = " << it->second << std::endl;
	it--;
	std::cout << "it->first = " << it->first << std::endl;
	std::cout << "it->second = " << it->second << std::endl;
}

void iterators()
{
	test_begin_1();
	test_it_plus_1();
	test_end_1();
	test_it_minus_1();
}

// --- MODIFIERS ---

void insert_test_1()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('l', 500));
	map.insert(ft::pair<char, int>('d', 500));
	map.insert(ft::pair<char, int>('v', 500));
	map.insert(ft::pair<char, int>('q', 500));
	map.insert(ft::pair<char, int>('a', 500));
	map.insert(ft::pair<char, int>('e', 500));
	ft::map<char, int>::iterator it = map.begin();
	std::cout << "it->first = " << it->first << std::endl;
	std::cout << "it->second = " << it->second << std::endl;
}

void insert_test_2()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('l', 500));
	map.insert(ft::pair<char, int>('d', 500));
	map.insert(ft::pair<char, int>('v', 500));
	map.insert(ft::pair<char, int>('q', 500));
	map.insert(ft::pair<char, int>('a', 500));
	map.insert(ft::pair<char, int>('e', 500));
	ft::map<char, int>::iterator first = map.find('a');
	ft::map<char, int>::iterator last = map.find('v');
	ft::map<char, int>	map_two;
	map_two.insert(first, last);
	for (ft::map<char, int>::iterator it = map_two.begin(); it != map_two.end(); it++) {
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void erase_test_1()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('l', 500));
	map.insert(ft::pair<char, int>('d', 500));
	map.insert(ft::pair<char, int>('v', 500));
	map.insert(ft::pair<char, int>('q', 500));
	map.insert(ft::pair<char, int>('a', 500));
	map.insert(ft::pair<char, int>('e', 500));
	ft::map<char, int>::iterator it = map.find('v');
	std::cout << "map.size() = " << map.size() << std::endl;;
	std::cout << "map.erase('v')" << std::endl;
	map.erase(it);
	std::cout << "map.size() = " << map.size() << std::endl;;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void erase_test_2()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('v', 100));
	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('l', 100));
	map.insert(ft::pair<char, int>('m', 100));
	map.insert(ft::pair<char, int>('q', 100));
	map.insert(ft::pair<char, int>('o', 100));
	map.insert(ft::pair<char, int>('w', 100));
	ft::map<char, int>::iterator it = map.find('w');
	std::cout << "map.size() = " << map.size() << std::endl;;
	std::cout << "map.erase('w')" << std::endl;
	map.erase(it);
	std::cout << "map.size() = " << map.size() << std::endl;;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void erase_test_3()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('v', 100));
	ft::map<char, int>::iterator it = map.find('v');
	std::cout << "map.size() = " << map.size() << std::endl;;
	std::cout << "map.erase('v')" << std::endl;
	map.erase(it);
	std::cout << "map.size() = " << map.size() << std::endl;;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void erase_test_4()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	ft::map<char, int>::iterator it = map.find('g');
	std::cout << "map.size() = " << map.size() << std::endl;;
	std::cout << "map.erase('g')" << std::endl;
	map.erase(it);
	std::cout << "map.size() = " << map.size() << std::endl;;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void erase_test_5()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	std::cout << "map.size() = " << map.size() << std::endl;;
	std::cout << "map.erase('g')" << std::endl;
	map.erase('g');
	std::cout << "map.size() = " << map.size() << std::endl;;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void erase_test_6()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('v', 100));
	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('l', 100));
	map.insert(ft::pair<char, int>('m', 100));
	map.insert(ft::pair<char, int>('q', 100));
	map.insert(ft::pair<char, int>('o', 100));
	map.insert(ft::pair<char, int>('w', 100));
//	ft::map<char, int>::iterator first = map.find('a');
	ft::map<char, int>::iterator first = map.find('l');
	ft::map<char, int>::iterator last = map.find('v');
	std::cout << "map.size() = " << map.size() << std::endl;;
	map.erase(first, last);
	std::cout << "map.size() = " << map.size() << std::endl;;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++) {
		std::cout << it->first << std::endl;
		std::cout << it->second << std::endl;
	}
}

void clear_test_1()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('g', 100));
	map.insert(ft::pair<char, int>('l', 500));
	map.insert(ft::pair<char, int>('d', 500));
	map.insert(ft::pair<char, int>('v', 500));
	map.insert(ft::pair<char, int>('q', 500));
	map.insert(ft::pair<char, int>('a', 500));
	map.insert(ft::pair<char, int>('e', 500));

	std::cout << map.size() << std::endl;
	std::cout << "map.clear();" << std::endl;
	map.clear();
	std::cout << map.size() << std::endl;
}

void modifiers()
{
//	insert_test_1();
	insert_test_2();
//	erase_test_1();
//	erase_test_2();
//	erase_test_3();
//	erase_test_4();
//	erase_test_5();
//	erase_test_6();
//	clear_test_1();
}

void element_access()
{
	ft::map<char, int>	map;

	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('b', 200));
	map.insert(ft::pair<char, int>('c', 300));
	map.insert(ft::pair<char, int>('d', 400));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('f', 600));
	map.insert(ft::pair<char, int>('g', 700));

	std::cout << "map[a] = " << map['a'] << std::endl;
	std::cout << "map[b] = " << map['b'] << std::endl;
	std::cout << "map[c] = " << map['c'] << std::endl;
	std::cout << "map[d] = " << map['d'] << std::endl;
	std::cout << "map[e] = " << map['e'] << std::endl;
	std::cout << "map[f] = " << map['f'] << std::endl;
	std::cout << "map[g] = " << map['g'] << std::endl;
}

void test_find_1()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('b', 200));
	map.insert(ft::pair<char, int>('c', 300));
	map.insert(ft::pair<char, int>('d', 400));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('f', 600));
	map.insert(ft::pair<char, int>('g', 700));

	ft::map<char, int>::iterator it = map.find('c');
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
	it++;
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void test_find_2()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('b', 200));
	map.insert(ft::pair<char, int>('c', 300));
	map.insert(ft::pair<char, int>('d', 400));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('f', 600));
	map.insert(ft::pair<char, int>('g', 700));

	ft::map<char, int>::iterator it = map.find('x');
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
	it--;
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void test_count_1()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('b', 200));
	map.insert(ft::pair<char, int>('c', 300));
	map.insert(ft::pair<char, int>('d', 400));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('f', 600));
	map.insert(ft::pair<char, int>('g', 700));

	std::cout << "map.count('a') = " << map.count('a') << std::endl;
	std::cout << "map.count('b') = " << map.count('b') << std::endl;
	std::cout << "map.count('c') = " << map.count('c') << std::endl;
	std::cout << "map.count('x') = " << map.count('x') << std::endl;
}

void test_lower_bound_1()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('b', 200));
	map.insert(ft::pair<char, int>('c', 300));
	map.insert(ft::pair<char, int>('d', 400));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('f', 600));
	map.insert(ft::pair<char, int>('g', 700));

	ft::map<char, int>::iterator it = map.lower_bound('c');
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
	it++;
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void test_lower_bound_2()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('b', 200));
	map.insert(ft::pair<char, int>('d', 400));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('f', 600));
	map.insert(ft::pair<char, int>('g', 700));

	ft::map<char, int>::iterator it = map.lower_bound('c');
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
	it++;
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void test_upper_bound_1()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('b', 200));
	map.insert(ft::pair<char, int>('c', 300));
	map.insert(ft::pair<char, int>('d', 400));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('f', 600));
	map.insert(ft::pair<char, int>('g', 700));

	ft::map<char, int>::iterator it = map.upper_bound('c');
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
	it++;
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void test_upper_bound_2()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('b', 200));
	map.insert(ft::pair<char, int>('d', 400));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('f', 600));
	map.insert(ft::pair<char, int>('g', 700));

	ft::map<char, int>::iterator it = map.upper_bound('c');
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
	it++;
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void test_equal_range_1()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('b', 200));
	map.insert(ft::pair<char, int>('c', 300));
	map.insert(ft::pair<char, int>('d', 400));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('f', 600));
	map.insert(ft::pair<char, int>('g', 700));

	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> pair = map.equal_range('c');
	std::cout << pair.first->first << std::endl;
	std::cout << pair.second->second << std::endl;
}

void test_equal_range_2()
{
	ft::map<char, int> map;

	map.insert(ft::pair<char, int>('a', 100));
	map.insert(ft::pair<char, int>('b', 200));
	map.insert(ft::pair<char, int>('d', 400));
	map.insert(ft::pair<char, int>('e', 500));
	map.insert(ft::pair<char, int>('f', 600));
	map.insert(ft::pair<char, int>('g', 700));

	ft::pair<ft::map<char, int>::iterator, ft::map<char, int>::iterator> pair = map.equal_range('c');
	std::cout << pair.first->first << std::endl;
	std::cout << pair.second->second << std::endl;
}

void operations()
{
   /* test_find_1();*/
	//test_find_2();
	//test_count_1();
   /* test_lower_bound_1();*/
	//test_lower_bound_2();
	//test_upper_bound_1();
	/*test_upper_bound_2();*/
	test_equal_range_1();
	test_equal_range_2();
}

int	main(void)
{
	std::cout << "--- test myMap ---" << std::endl;
//	pair();
	constructors();
//	capacity();
//	observers();
//	iterators();
//	modifiers();
//	element_access();
//	operations();
	std::cout << "----------------" << std::endl;
	return (0);
}
