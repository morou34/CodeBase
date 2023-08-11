#include <iostream>
#include <vector>
#include <string>
using namespace std;

void display(const int array[], size_t size); // const to make the array read only

void display(const int array[], size_t size){
	for(int i=0; i<size; ++i)
		cout << array[i] << " | ";
}

int main(int argc, char const *argv[])
{
	// Passing an array to a function means we are passing the
	// original version, NO COPY IS MADEthe function does not know where the end is
	// we need to provide that as well.

	int values[] {1, 2, 3, 4, 5, 6, 7, 8 , 9, 10};
	display(values, 10);

	return 0;
}