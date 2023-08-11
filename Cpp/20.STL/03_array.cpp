#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

int main(int argc, char const *argv[])
{
    auto print = [](const std::array<int, 5> &arr)
    {
        for (const auto &value : arr)
            std::cout << value << ' ';
        std::cout << '\n';
    };

    // print std::array with no initialization, garbage data
    std::array<int, 5> arr1;
    print(arr1);

    std::array<int, 5> arr2{1, 2, 3, 4, 5};
    print(arr2);

    // basic methods.
    std::cout << "size(): " << arr1.size() << std::endl;
    std::cout << "max_size(): " << arr1.max_size() << std::endl;
    std::cout << "empty(): " << arr1.empty() << std::endl;
    std::cout << "arr1.at(2)" << arr2.at(2) << std::endl;
    std::cout << "front(): " << arr1.front() << std::endl;
    arr1.fill(22);

    // Access data pointer

    int *ptr = arr2.data();
    print(arr2);
    *ptr = 100;
    *(++ptr) = 200;
    *(ptr + 2) = 99;
    print(arr2);

    // reverse elements
    std::reverse(arr2.begin(), arr2.end());
    print(arr2);

    return 0;
}
