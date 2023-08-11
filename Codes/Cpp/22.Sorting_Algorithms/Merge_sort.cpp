#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
vector<int> merge(int low, int mid, int high, vector<int> arr)
{
    return 1;
}

vector<int> merge_sort(int low, int high, vector<int> arr)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        merge_sort(low, mid, arr);
        merge_sort(mid + 1, high, arr);

        merge(low, mid, high, arr);
    }
}

int main()
{
    srand((unsigned)time(NULL));
    vector<int> numbers;

    auto generate_number = []()
    {
        int random = rand() % 101;
        return random;
    };

    for (size_t i = 0; i < 101; i++)
        numbers.push_back(generate_number());

    int low, high;
    low = 0;
    high = numbers.size() - 1;

    auto sorted_vec = merge_sort(low, high, numbers);

    return 1;
}