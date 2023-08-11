#include "MyString.h"
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<MyString> vec;
    MyString empty;
    MyString dragon{"Dragon"};

    MyString copilo{dragon};               // Copy constructor
    vec.push_back(MyString{"Black Bird"}); // Move constructor

    MyString monster;
    monster = dragon; // Copy assignment

    MyString lion;
    lion = MyString{"Lion..."}; // Move assignment

    std::cout << "__________" << std::endl;
    empty.display();
    dragon.display();
    copilo.display();
    monster.display();
    lion.display();

    std::cout << "__________" << std::endl;
    MyString lolo = dragon + " " + lion;
    lolo.display();

    std::cout << "__________" << std::endl;

    bool isSame = dragon == lion;
    std::cout << "dragon == lion => isSame = " << isSame << std::endl;

    std::cout << "__________" << std::endl;
    std::cout << "Display MyString Object: " << copilo << std::endl;

    std::cout << "__________" << std::endl;
    MyString newMyString;
    std::cout << "Enter a MyString: ";
    std::cin >> newMyString;
    std::cout << "Your MyString is: " << newMyString << std::endl;
    return 0;
}
