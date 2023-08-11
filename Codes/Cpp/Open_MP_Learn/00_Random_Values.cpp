#include <iostream>
#include <vector>
#include <string>
#include <time.h>

int main(int argc, char const *argv[])
{
	srand(time(0));
	for (int i = 0; i < 20; ++i)
	{
		/* code */
	int x = rand() % 5 + 1;
	std::cout << x << std::endl;
	
	}

	return 0;
}