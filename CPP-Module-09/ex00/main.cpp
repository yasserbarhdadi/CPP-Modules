#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <filename>" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange exchange;
		exchange.processFile(argv[1]);
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		return 1;
	}
	return 0;
}
