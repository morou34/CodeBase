#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Dynamic memory allocation: serves to allocate memory
// at run time.
int main(int argc, char const *argv[])
{
	// signle value allocation
	int *ptr {nullptr};
	ptr = new int;
	cout << "Enter a value: ";
	cin >> *ptr;
	cout << "Your value is: " << *ptr << endl;
	delete ptr;

	// dynamic array allocation
	string *array_ptr {nullptr};
	size_t size{0};

	cout << "Array Size: ";
	cin >> size;
	fflush(stdin);
	cin.clear();
	array_ptr = new string[size];

	// filling the array
	for(int i{0}; i<size; ++i)
	{
		printf("\nArray[%d]: ", i);
		getline(cin, *(array_ptr+i));
		
		fflush(stdin);
		cin.clear();
	}
	cout << "Insertion is finished.\n";
	cout << "Displaying values:\n";

	for(int i{0}; i<size; ++i)
		cout << *(array_ptr+i) << " |";

	delete [] array_ptr;

	return 0;
}