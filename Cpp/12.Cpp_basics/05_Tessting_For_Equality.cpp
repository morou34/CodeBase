#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
	bool A={true}, B={false};
	
	std::cout << "A=" << A << std::endl;
	std::cout << "B=" << B << std::endl;

	std::cout << std::boolalpha;
	std::cout << "A=" << A << std::endl;
	std::cout << "B=" << B << std::endl;

	std::cout << std::noboolalpha;
	std::cout << "A=" << A << std::endl;
	std::cout << "B=" << B << std::endl;

	return 0;

}