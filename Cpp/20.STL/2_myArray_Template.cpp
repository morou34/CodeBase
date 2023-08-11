#include <string>
#include <iostream>

template <typename T, int N>
class Array
{
    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr)
    {
        os << "[ ";
        for (const auto &val : arr.values)
            os << val << " ";
        os << "]";
        return os;
    }

private:
    int length{N};
    T values[N];

public:
    Array() = default;
    Array(T initial_val) { fill(initial_val); }

    void fill(T value)
    {
        for (auto &val : values)
            val = value;
    }

    int size() { return length; };
};

int main(int argc, char const *argv[])
{
    Array<int, 5> data;
    Array<double, 5> prices(59.99);

    std::cout << data << std::endl;
    std::cout << prices << std::endl;
    std::cout << prices.size() << std::endl;

    Array<std::string, 4> names;
    std::cout << names << std::endl;

    Array<char, 20> alphas{'A'};
    std::cout << alphas << std::endl;

    return 0;
}
