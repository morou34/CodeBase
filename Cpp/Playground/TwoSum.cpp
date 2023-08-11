#include <iostream>
#include <set>
#include <vector>
#include <cmath>

std::set<int> twoSum(std::vector<int> &nums, int target)
{
    std::vector<int> indices;
    std::set<int> myset;
    for (auto const &num : nums)
        myset.insert(num);

    return myset;
};

int main()
{
    std::set<int> sorted_nums;
    int target{0}, t1, t2;
    std::vector<int> mynums = {0, 4, 3, 0};
    sorted_nums = twoSum(mynums, target);

    for (auto const &num : sorted_nums)
        std::cout << num << " | ";

    auto it = sorted_nums.begin();
    auto jt = sorted_nums.begin();
    std::cout << "\n____________\n";
    while (true)
    {

        if (*it + *jt < target && jt != sorted_nums.end())
        {
            std::cout << *it << " + " << *jt << " = " << *it + *jt << std::endl;
            jt = std::next(jt, 1);

            continue;
        }
        if (*it + *jt > target || jt == sorted_nums.end())
        {
            std::cout << *it << " + " << *jt << " = " << *it + *jt << std::endl;
            jt = std::next(it, 1);
            it = std::next(it, 1);

            std::cout << "\n_______this_________\n";
            continue;
        }
        if (*it + *jt == target)
        {
            std::cout << *it << " + " << *jt << " = " << *it + *jt << std::endl;
            t1 = *it;
            t2 = *jt;

            break;
        }
    }
    std::vector<int> indices;
    for (size_t i{0}; i < mynums.size(); i++)
    {

        if (mynums.at(i) == t1 || mynums.at(i) == t2)
        {
            indices.push_back(i);
            continue;
        }
    }

    for (size_t i = 0; i < indices.size(); i++)
    {
        std::cout << indices.at(i) << " " << std::endl;
    }
    return 0;
}