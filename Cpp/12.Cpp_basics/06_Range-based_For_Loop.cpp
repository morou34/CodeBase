#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
	// Displaying an array using the ranged for loop
	int scores[] {100, 23, 34, 99};

	for(auto var:scores)
		std::cout << var << "|";

	// calculating the average of four tempetures
	std::vector<double> temperatures {37.5, 40.22, 29.5, 33.68};
	double average_temp{};
	double running_sum{};

	for(auto temp:temperatures)
	{
		running_sum+=temp;
	}
	average_temp = running_sum/temperatures.size();
	std::cout << "\nAverage Temperature is: " << average_temp 
	<< "`C" << std::endl;

	// iterating over a string
	std::string city {"London"};
	
	for(auto c:city)
		printf("%c.", c);

	return 0;
}