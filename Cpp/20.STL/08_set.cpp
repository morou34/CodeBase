#include <iostream>
#include <set>
#include <string>
#include <unordered_set>

template <typename T>
void print(std::set<T> myset)
{
    std::cout << "[ ";
    for (const auto item : myset)
        std::cout << item << " ";
    std::cout << "]" << std::endl;
}
template <typename T>
void print(std::unordered_set<T> myset)
{
    std::cout << "[ ";
    for (const auto item : myset)
        std::cout << item << " ";
    std::cout << "]" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::set<int> unique_numbers{1, 3, 3, 4, -1, 2, 2, 6, 8};
    std::unordered_set<char> alphabs{'A', 'A', 'C', 'W', 'E', 'M', 'I', 'G', 'I'};

    print(unique_numbers);
    print(alphabs);

    return 0;
}
