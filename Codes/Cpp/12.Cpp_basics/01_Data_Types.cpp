#include <iostream>
# include <climits>

void line()
{
    std::cout << "------------------------>" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << "Integer Types" << std::endl;

    long long earth_population {7'000'000'000};
    long mars_population = 4'111'111'111;
    // List initialization catches error on compile time.
    // mars_population: overflow
    std::cout << earth_population << std::endl;
    std::cout << mars_population << std::endl;
    line();

    std::cout << "Floating Point Types" << std::endl;

    float book_price{59.99};
    std::cout << "Book price = " << book_price << std::endl;

    const double pi{3.14159265};
    std::cout << "pi = " << pi << std::endl;

    long double distance{7.9e120};
    std::cout << "distance = " << distance << std::endl;
    line();

    std::cout << "Boolean Types" << std::endl;
    bool f{false}, v{true};
    std::cout << "ROS is hard to learn: " << v << std::endl;
    std::cout << "Arduino is hard to learn: " << f << std::endl;
    line();

    std::cout << "sizeof information" << std::endl;
    std::cout << "char        : " << sizeof(char) << " bytes." << std::endl;
    std::cout << "short       : " << sizeof(short) << " bytes." << std::endl;
    std::cout << "int         : " << sizeof(int) << " bytes." << std::endl;
    std::cout << "unsigned int: " << sizeof(unsigned int) << " bytes." << std::endl;
    std::cout << "long        : " << sizeof(long) << " bytes." << std::endl;
    std::cout << "float       : " << sizeof(float) << " bytes." << std::endl;
    std::cout << "long long   : " << sizeof(long long) << " bytes." << std::endl;
    std::cout << "double      : " << sizeof(double) << " bytes." << std::endl;
    std::cout << "long double : " << sizeof(long double) << " bytes." << std::endl;
    line();

    std::cout << "Types Range" << std::endl;

    std::cout << "char  : [" << CHAR_MIN <<" " << CHAR_MAX << "]" << std::endl;
    //std::cout << "short : [" << SHRT_MIN <<" " << SHRT_MAX << "]" << std::endl;
    //std::cout << "int   : [" << INT_MIN <<" " << INT_MAX << "]" << std::endl;





    return 0;
}