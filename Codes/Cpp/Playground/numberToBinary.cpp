#include <iostream>
#include <string>
#include <math.h>

void numberInBinary(int number)
{
    std::string binary{""};
    int n{1}, d{1}, c{1};
    n = number;
    d = log2(n) + 1;

    while (d > 0)
    {
        c = int(pow(2, d - 1));
        if (n / c)
        {
            n = n % c;
            binary += '1';
        }
        else
            binary += '0';
        d--;
    }
    std::cout << number << "|10 = " << binary << "|2" << std::endl;
};

int main(int argc, char const *argv[])
{
    for (size_t i = 134; i < 200; i++)
        numberInBinary(i);

    return 0;
}
