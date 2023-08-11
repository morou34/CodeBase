#include <iostream>
#include <vector>
#include <string>
// dynamic size
// elements can be access by their index
// []: square barakets, no checking to see if you are out of bounds.
// elements initilized to zero automatically

void display_vector(std::vector<double> &vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		std::cout << vec[i] << "\n";
	}
}
void line(){printf("--------------->\n");}

int main(int argc, char const *argv[])
{
	// Dynamic array 
	// Declaration
	std::vector<char> vowels (5); // constractor initilization, 5 elements
	std::vector<int> test_scores(10); // 10 elements initialized to 0
	std::vector<double> temperatures (14, 41.23);

	for (int i = 0; i < 10; ++i)
	{
		printf("Element: %d \n", test_scores[i]);
	}
	line();

	display_vector(temperatures);
	line();
	
	// Accessing vector elements.
	std::vector<std::string> names{"Alex", "Jhon"};
	std::cout << names.at(0) << std::endl;
	std::cout << names.at(1) << std::endl;

	// 2D Vector is a Vector of vectors
	std::vector<std::vector<int>> matrix{
		{1,2,3,4},
		{5,5,5,5},
		{6,7,8,9}
	};
	std::cout << matrix.at(0).at(0) << " | ";
	std::cout << matrix.at(0).at(1) << " | ";
	std::cout << matrix.at(0).at(2) << " | ";
	std::cout << matrix.at(0).at(3) << " | ";

	std::cout << "\n";
	display_vector(matrix.at(1));


	return 0;
}