#include <iostream>
#include <vector>
#include <string>
using namespace std;

// function prototypes
float salary(int);
float salary(int days){	return 89.99 * days;}

void display_a(int a){
	cout << a << endl;
};\

void change_a(int &a){
	a = 99;
	cout << a << endl;
}

int main(int argc, char const *argv[])
{
	int days{23};
	float payment {};
	payment = salary(days);

	cout << "Working days = " << days 
	<< " | payment = $" << payment << endl;

	// ____________________________________________

	int a {100};
	cout << "a = " << a << endl;
	display_a(a);
	change_a(a);
	cout << "original a : " << a << endl;

	return 0;
}