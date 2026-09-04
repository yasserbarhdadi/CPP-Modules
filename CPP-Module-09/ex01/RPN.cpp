#include "RPN.hpp"
#include <cstdlib>
#include <sstream>
#include <stack>
#include <stdexcept>

int RPN::calculate(const std::string& expression)
{
    std::stack<int> values;
    std::istringstream input(expression);
    std::string token;
    while (input >> token)
    {
        if (token.size() == 1 && token[0] >= '0' && token[0] <= '9')
            values.push(token[0] - '0');
        else if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (values.size() < 2)
                throw std::runtime_error("Error");
            int second = values.top();
            values.pop();
            int first = values.top();
            values.pop();
            if (token == "/" && second == 0)
                throw std::runtime_error("Error");
            if (token == "+")
                values.push(first + second);
            else if (token == "-")
                values.push(first - second);
            else if (token == "*")
                values.push(first * second);
            else
                values.push(first / second);
        }
        else
            throw std::runtime_error("Error");
    }
    if (values.size() != 1)
        throw std::runtime_error("Error");
    return values.top();
}