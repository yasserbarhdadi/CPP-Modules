#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./RPN \"number number sign etc..\"" << std::endl;
		return 1;
	}
	try
	{
		std::cout << RPN::calculate(argv[1]) << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		return 1;
	}
	return 0;
}
