#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <cstdlib>
#include <ctime>

class Person
{
    friend bool operator==(const Person &lhs, const Person &rhs);
    friend bool operator<(const Person &lhs, const Person &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Person &person);

private:
    std::string name;
    int age;

public:
    Person();
    Person(std::string name, int age);
    ~Person();
};

Person::Person() = default;
Person::Person(std::string name, int age) : name{name}, age{age} {}
Person::~Person() {}

bool operator==(const Person &lhs, const Person &rhs)
{
    return (lhs.age == rhs.age && lhs.name == rhs.name);
}
bool operator<(const Person &lhs, const Person &rhs)
{
    return lhs.age < rhs.age;
};

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << "[" << person.name << ": " << person.age << "]";
    return os;
}

void fill_data(std::vector<int> &vec, int N)
{
    srand(time(0));
    for (int i = 0; i < N; ++i)
    {
        int r = (rand() % 10) + 1;
        vec.push_back(r);
    }
}
void print(std::vector<int> &vec)
{
    std::cout << "[ ";
    for (const auto &val : vec)
        std::cout << val << " ";
    std::cout << "]\n";
}
int main(int argc, char const *argv[])
{
    Person love{"Love", 23};
    Person joe{"Joe", 27};
    Person lara{"Lara", 30};
    Person james{"James", 34};
    Person alex{"Alex", 21};

    std::vector<Person> team;
    team.push_back(love);
    team.push_back(joe);
    team.push_back(lara);
    team.push_back(james);
    team.push_back(alex);

    // Find algorithm applied on a vector <Person>
    auto loc = std::find(team.begin(), team.end(), Person{"Soul", 44});
    if (loc != team.end())
        std::cout << "Soul is in the team.\n";
    else
        std::cout << "Soul is not in the team.\n";

    // Find algorithm applied on a list <Person>

    std::list<Person> group = {
        Person{"Adam", 20},
        Person{"Ali", 18},
        Person{"Micky", 31}};

    for (auto it = group.begin(); it != group.end(); ++it)
        std::cout << *it << std::endl;

    // Count: the number of elements in a container
    std::vector<int> numbers;
    fill_data(numbers, 20);
    std::cout << "size (numbers): " << numbers.size() << std::endl;

    int N = std::count(numbers.begin(), numbers.end(), 1);
    std::cout << "1 occurrences: " << N << std::endl;

    print(numbers);

    // Sort algorithm
    // Ascending order
    std::sort(numbers.begin(), numbers.end());
    print(numbers);

    // Descending order: greater function puts greater elements first
    std::sort(numbers.begin(), numbers.end(), std::greater<>());
    print(numbers);
    return 0;
}
