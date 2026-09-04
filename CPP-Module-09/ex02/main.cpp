#include "PmergeMe.hpp"
#include <cerrno>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <time.h>

static int parsePositive(const char *text)
{
	char *end = NULL;
	errno = 0;
	long value = std::strtol(text, &end, 10);
	if (*text == '\0' || *end != '\0' || errno == ERANGE || value <= 0 || value > 2147483647L)
		throw std::runtime_error("Error");
	return static_cast<int>(value);
}

static double elapsed(const timespec& start, const timespec& end)
{
	return (end.tv_sec - start.tv_sec) * 1000000.0
		+ (end.tv_nsec - start.tv_nsec) / 1000.0;
}

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
		return 1;
	}
	try
	{
		std::vector<int> values;
		std::list<int> listValues;
		for (int index = 1; index < argc; ++index)
		{
			int value = parsePositive(argv[index]);
			values.push_back(value);
			listValues.push_back(value);
		}
		std::cout << "Before:";
		for (std::vector<int>::const_iterator it = values.begin(); it != values.end(); ++it)
			std::cout << " " << *it;
		std::cout << std::endl;
		timespec vectorStart;
		timespec vectorEnd;
		timespec listStart;
		timespec listEnd;
		clock_gettime(CLOCK_MONOTONIC, &vectorStart);
		PmergeMe::sortVector(values);
		clock_gettime(CLOCK_MONOTONIC, &vectorEnd);
		clock_gettime(CLOCK_MONOTONIC, &listStart);
		PmergeMe::sortList(listValues);
		clock_gettime(CLOCK_MONOTONIC, &listEnd);
		std::cout << "After:";
		for (std::vector<int>::const_iterator it = values.begin(); it != values.end(); ++it)
			std::cout << " " << *it;
		std::cout << std::endl;
		std::cout << "Time to process a range of " << values.size() << " elements with std::vector : "
				  << std::fixed << std::setprecision(5) << elapsed(vectorStart, vectorEnd) << " us" << std::endl;
		std::cout << "Time to process a range of " << listValues.size() << " elements with std::list : "
				  << elapsed(listStart, listEnd) << " us" << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << exception.what() << std::endl;
		return 1;
	}
	return 0;
}
