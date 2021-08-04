// vector.cpp

#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int>	vector_one;

	std::cout << "Vector test" << std::endl;
	std::cout << "vector_one.max_size() = " << vector_one.max_size() << std::endl;
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	vector_one.assign(5, 100);
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	for (size_t i = 0; i < vector_one.size(); i++) {
		std::cout << vector_one[i] << std::endl;
	}
	std::cout << "--" << std::endl;
	vector_one.assign(2, 50);
	std::cout << "vector_one.capacity() = " << vector_one.capacity() << std::endl;
	for (size_t i = 0; i < vector_one.size(); i++) {
		std::cout << vector_one[i] << std::endl;
	}
	return (0);
}
