#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>   // pair
#include <algorithm> // transform

struct President
{
    std::string name;
    std::string country;
    int year;

    friend std::ostream &operator<<(std::ostream &os, const President &presi);

    President(std::string p_name, std::string p_country, int p_year)
        : name(std::move(p_name)), country(std::move(p_country)), year(p_year)
    {
        std::cout << name << "is being constructed.\n";
    }
    President(President &&other)
        : name(std::move(other.name)), country(std::move(other.country)), year(other.year)
    {
        std::cout << name << " is being moved.\n";
    }
    President &operator=(const President &other) = default;

    bool operator<(const President &other)
    {
        return this->name < other.name;
    }

    bool operator==(const President &other)
    {
        return this->name == other.name;
    }
};

std::ostream &operator<<(std::ostream &os, const President &presi)
{
    os << presi.name << " | " << presi.year;
    return os;
}

template <typename T>
void print(const std::vector<T> &vec)
{
    auto it = vec.begin();
    std::cout << "[ ";
    while (it != vec.end())
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << "]\n";
}

int main(int argc, char const *argv[])
{
    std::vector<President> presidents;

    // emplace_back(): avoids extra copy or move
    presidents.emplace_back("Donald Trump", "USA", 2016);

    // Push_back(): creates then moves the object.
    presidents.push_back(President("Nelson Mandela", "South Africa", 1994));

    // displaying presidents info << operator testing.
    std::cout << presidents.at(0) << std::endl;
    std::cout << presidents.at(1) << std::endl;

    std::vector<int> vec1{1, 2, 3, 4, 5};
    std::vector<int> vec2{77, 99};

    print(vec1);
    print(vec2);
    std::copy(vec2.begin(), vec2.end(), std::back_inserter(vec1));
    print(vec1);
    print(vec2);

    // TRANSFORM WITH 1 ARGUMENT

    /*
    OutputIterator transform(
        InputIterator1 first1,
        InputIterator1 last1,
        OutputIterator result,
        BinaryOperation op);
    */
    std::map<int, int> games{
        {1, 10},
        {2, 15},
        {3, 20},
    };
    ;

    std::vector<int> titles;
    // start, end, destination, predicate/ lambda/ function
    std::transform(games.begin(), games.end(), std::back_inserter(titles), [](const std::map<int, int>::value_type &pair)
                   { return pair.first; });
    std::cout << "Keys: ";
    print(titles);

    /*
    OutputIterator transform(
        InputIterator1 first1,
        InputIterator1 last1,
        InputIterator2 first2,
        OutputIterator result,
        BinaryOperation op);
    */

    std::vector<int> numbers1 = {1, 5, 42, 7, 8};
    std::vector<int> numbers2 = {10, 7, 4, 2, 2};
    std::vector<int> results;

    std::transform(numbers1.begin(), numbers1.end(),
                   numbers2.begin(),
                   std::back_inserter(results),
                   [](int i, int j)
                   { return i + j; });

    print(numbers1);
    std::cout << " + \n";
    print(numbers2);
    std::cout << " = \n";
    print(results);

    return 0;
}
