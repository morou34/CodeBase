#include <iostream>

void line()
{
    std::cout << "\n------------------------>" << std::endl;
}

int main(int argc, char const *argv[])
{
	// Tables have fixed size, and cannot be changed.

	int scores[] {2,3,4,5}; // initialization
	float temps[7] {20,25.4}; // init to 20 and 25.4, All the remaining to 0
	int days[356]{0}; //init all to zero
	int notes[5];

	for (int i = 0; i < 4; ++i)
	{
		std::cout << "scores[" << i << "] = " << scores[i];	
	}
	line();

	for (int i = 0; i < 5; ++i)
	{	
		std::cout << "Element" << i+1 << ": ";
		std::cin >> notes[i];
	}

	for (int i = 0; i < 5; ++i)
	{
		std::cout << notes[i] << " | ";
	}
	return 0;
}