#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
#include <ctype.h>

// Method 1
auto palindromeTest = [](std::string text)
{
    std::deque<char> alphas;
    for (const auto &ch : text)
        if (std::isalpha(ch))
            alphas.push_back(ch);

    while (!alphas.empty())
    {
        if (alphas.front() == alphas.back())
        {
            alphas.pop_back();
            alphas.pop_front();
        }
        else
            return false;
    }
    return true;
};

// Method 2
auto palindromeIterator = [](std::string text)
{
    std::deque<char> alphas;
    for (const auto &ch : text)
        if (std::isalpha(ch))
            alphas.push_back(ch);

    auto front_it = alphas.begin();
    auto back_it = alphas.end() - 1;
    while (front_it < back_it)
    {
        std::cout << *front_it << " " << *back_it << std::endl;
        if (*front_it == *back_it)
        {
            ++front_it;
            --back_it;
            std::cout << *front_it << " " << *back_it << std::endl;
        }
        else
            return false;
    }
    return true;
};

int main(int argc, char const *argv[])
{

    // bool isPalindrome = palindromeTest("atta");
    bool isPalindrome = palindromeIterator("hk;d;d434kh");
    std::cout << isPalindrome << std::endl;
    return 0;
}
