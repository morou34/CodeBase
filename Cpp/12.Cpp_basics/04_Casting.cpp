#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
	int products {5};
	int price{121};
	float average1{0}, average2{0};

	// products, and price: are integers, the compiler will return an int as well.
	// we need to cast the the price or products. using float(price)
	
	average1 = static_cast<float>(price)/products;
	average2 = float(price)/products;
	std::cout << "Average 1: " << average1 << std::endl;
	std::cout << "Average 2: " << average2  << std::endl;


	return 0;
}