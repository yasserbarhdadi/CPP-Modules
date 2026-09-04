#pragma once

#include <list>
#include <vector>

class PmergeMe
{
private:
	static std::vector<int>::iterator vectorPosition(std::vector<int>& values, int value);
	static std::list<int>::iterator listPosition(std::list<int>& values, int value);

public:
	static void sortVector(std::vector<int>& values);
	static void sortList(std::list<int>& values);
};
