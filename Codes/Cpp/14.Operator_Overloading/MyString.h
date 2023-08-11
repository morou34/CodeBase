#ifndef _MySrtring_H_
#define _MyString_H_
#include <iostream>

class MyString
{
    // overloading operators as global functions.
    // declared as friends of the class to allow easy access to str pointer.
    friend bool operator==(const MyString &lhs, const MyString &rhs);
    friend MyString operator+(const MyString &lhs, const MyString &rhs);
    // insertion operator: two objects std::cout << MyString{"hello"}
    // to allow it to function in right/left side at the same time.
    friend std::ostream &operator<<(std::ostream &os, const MyString &obj);
    // obj is not const cause will be adding to it. as user types something.
    friend std::istream &operator>>(std::istream &is, MyString &obj);

private:
    char *str; // pointer to a char[] that holds c_style string.

public:
    MyString();                               // No args constructor
    MyString(const char *s);                  // overloaded constructor
    MyString(const MyString &source);         // copy constructor
    MyString(MyString &&source);              // Move constructor
    MyString &operator=(const MyString &rhs); // copy assignment
    MyString &operator=(MyString &&rhs);      // Move assignment
    ~MyString();                              // destructor
    void display() const;
    int get_legnth() const;
    const char *get_str() const;
};

#endif // !_MySrtring