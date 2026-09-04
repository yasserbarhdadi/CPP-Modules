#include "PmergeMe.hpp"

std::vector<int>::iterator PmergeMe::vectorPosition(std::vector<int>& values, int value)
{
    std::size_t first = 0;
    std::size_t last = values.size();
    while (first < last)
    {
        std::size_t middle = first + (last - first) / 2;
        if (values[middle] < value)
            first = middle + 1;
        else
            last = middle;
    }
    return values.begin() + first;
}

std::list<int>::iterator PmergeMe::listPosition(std::list<int>& values, int value)
{
    std::list<int>::iterator it = values.begin();
    while (it != values.end() && *it < value)
        ++it;
    return it;
}

void PmergeMe::sortVector(std::vector<int>& values)
{
    if (values.size() < 2)
        return;
    std::vector<int> larger;
    std::vector<int> smaller;
    std::size_t index = 0;
    while (index + 1 < values.size())
    {
        if (values[index] < values[index + 1])
        {
            smaller.push_back(values[index]);
            larger.push_back(values[index + 1]);
        }
        else
        {
            smaller.push_back(values[index + 1]);
            larger.push_back(values[index]);
        }
        index += 2;
    }
    if (index < values.size())
        smaller.push_back(values[index]);
    sortVector(larger);
    values = larger;
    for (std::vector<int>::const_iterator it = smaller.begin(); it != smaller.end(); ++it)
        values.insert(vectorPosition(values, *it), *it);
}

void PmergeMe::sortList(std::list<int>& values)
{
    if (values.size() < 2)
        return;
    std::list<int> larger;
    std::list<int> smaller;
    std::list<int>::iterator it = values.begin();
    while (it != values.end())
    {
        int first = *it;
        ++it;
        if (it == values.end())
        {
            smaller.push_back(first);
            break;
        }
        int second = *it;
        ++it;
        if (first < second)
        {
            smaller.push_back(first);
            larger.push_back(second);
        }
        else
        {
            smaller.push_back(second);
            larger.push_back(first);
        }
    }
    sortList(larger);
    values = larger;
    for (std::list<int>::const_iterator pending = smaller.begin(); pending != smaller.end(); ++pending)
        values.insert(listPosition(values, *pending), *pending);
}
