#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	// pointers basic manipulatoins
	int *p {nullptr}, a{3};
	cout << p << endl;
	cout << &p << endl;
	p = &a;
	cout << a << endl; 
	cout << *p << endl; 
	cout << p << endl; 
	cout << &a << endl; 

	//
	vector<string> names{"Leo", "Henry", "Ali", "Meo"};
	vector<string> *ptr{nullptr};
	ptr = &names;

	cout << "First Name: " << (*ptr).at(2) << endl;

	// what is the collection, it is not ptr
	// it is what ptr is poiting to
	// vectors # array: address of the vector is not 
	// the address of first element 
	for(auto name: *ptr)
		cout << "Name: " << name << endl;

	cout << "names: " << &names << endl;
	cout << &(names.at(0)) << " | element 0: " << names.at(0) << endl;
	cout << &(names.at(1)) << " | element 1: " << names.at(1) << endl;
	cout << &(names.at(2)) << " | element 2: " << names.at(2) << endl;
	cout << &(names.at(3)) << " | element 3: " << names.at(3) << endl;
	cout << "ptr: " << ptr << endl;


	return 0;
}