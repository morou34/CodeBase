#include "Mystring.h"
#include <cstring>
// No args constructor
MyString::MyString() : str{nullptr}
{
    str = new char[1];
    *str = '\0';
}

// overloaded constructor
MyString::MyString(const char *s) : str{nullptr}
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// copy constructor
MyString::MyString(const MyString &source) : str{nullptr}
{
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
    std::cout << "Copy constructor for: " << str << std::endl;
}

// move constructor
MyString::MyString(MyString &&source) : str{source.str}
{
    std::cout << "Move constructor for: " << str << std::endl;
    source.str = nullptr;
}
// copy assignment
MyString &MyString::operator=(const MyString &rhs)
{
    std::cout << "Copy assignment for: " << rhs.str << std::endl;
    if (this == &rhs)
        return *this;
    else
    {
        delete[] this->str;
        str = new char[std::strlen(rhs.str) + 1];
        std::strcpy(this->str, rhs.str);
        return *this;
    }
}

// Move assignment
MyString &MyString::operator=(MyString &&rhs)
{
    delete[] this->str; // freeing all data
    this->str = rhs.str;
    rhs.str = nullptr;
    std::cout << "Move assignment for: " << str << std::endl;
    return *this;
}
MyString::~MyString()
{
    delete[] str;
}

void MyString::display() const
{
    std::cout << str << " : " << std::strlen(str) << std::endl;
}

int MyString::get_legnth() const
{
    return std::strlen(str);
}

const char *MyString::get_str() const
{
    return str;
}

MyString operator+(const MyString &lhs, const MyString &rhs)
{
    size_t buff_size = std::strlen(lhs.str) + std::strlen(rhs.str) + 1;
    char *buff = new char[buff_size];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    MyString temp = MyString{buff};
    delete[] buff;
    return temp;
}

bool operator==(const MyString &lhs, const MyString &rhs)
{
    if (std::strcmp(lhs.str, rhs.str) == 0)
        return true;
    else
        return false;
}

std::ostream &operator<<(std::ostream &os, const MyString &obj)
{
    os << obj.str;
    return os;
}

std::istream &operator>>(std::istream &is, MyString &obj)
{
    char *buff = new char[1000];
    is >> buff;
    obj = MyString{buff}; // if you have a move assignment
    delete[] buff;
    return is;
}