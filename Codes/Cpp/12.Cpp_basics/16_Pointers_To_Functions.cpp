#include <iostream>
#include <vector>
#include <string>
using namespace std;

int show(int *val){	return *val + 10; }
// display expects the address of some vector. aka pointer.
void display(vector<double> *p){
	for(auto item: *p)
		cout << item << " | ";
	cout << "\n";
}
// displaying an Array
void display(int *p){
	for(int i{0}; i<5; ++i)
		cout << *(p+i) << " | ";
}

int main(int argc, char const *argv[])
{
	int a {23};
	int *p {&a};
	cout << show(p) << endl;
	cout << show(&a) << endl;

	vector<double> temps {34.3, 40.43, 35.43, 32.34, 48.99};
	vector<double> *ptr{&temps};
	display(ptr);

	int scores[] {2234, 4303, 343, 3234, 4899};
	int *q {scores};
	display(q);
	return 0;
}