#include <string>
#include <iostream>

class Person
{
    friend bool operator>(const Person &lhs, const Person &rhs);
    friend std::ostream &operator<<(std::ostream &os, const Person &person);

private:
    std::string name;
    int age;

public:
    Person();
    Person(std::string name, int age);
    ~Person();
};

Person::Person() : Person{"Unknown", 20} {}
Person::Person(std::string name, int age) : name{name}, age{age} {}
Person::~Person() {}

std::ostream &operator<<(std::ostream &os, const Person &person)
{
    os << person.name << "(" << person.age << ")";
    return os;
}

bool operator>(const Person &lhs, const Person &rhs)
{
    return lhs.age > rhs.age;
}

template <typename T>
T older(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
void get_ingo(T1 par1, T2 par2)
{
    std::cout << par1 << " | " << par2 << std::endl;
}

int main(int argc, char const *argv[])
{
    Person mary{"Mary", 24};
    Person adam{"Adam", 27};
    Person oldPerson;

    oldPerson = older<Person>(mary, adam);
    std::cout << oldPerson << " is older." << std::endl;
    get_ingo("Moe", 23);
    return 0;
}
