#include <iostream>
#include <vector>
#include <string>
using namespace std;
// The compiler is able to tell which function based on parameters.
// however return types is not considered.
// int circle_area() and double circle_area()

void display(int);
void display(double);
void display(string);
void display(string, int, float);


void display(int age) {cout << "Age = " << age << endl;}
void display(float salary) {cout << "Salary = $" << salary << endl;}
void display(string name) {cout << "Name = " << name << endl;}

void display(string name, int age, float salary) {
	cout << "Name = " << name 
	<< " | Age = " << age
	<< " | Salary = $" << salary << endl;
}
// ------------------------------------
void print(int=100);
void print(double);
void print(string);

void print(int number){ cout << number << endl;}
void print(double number){ cout << number << endl;}
void print(string txt){ cout << txt << endl;}



int main(int argc, char const *argv[])
{
	string name{"Adam Lee"};
	int age{32};
	float salary {70'000};

	display(name);
	display(age);
	display(salary);
	display(name, age, salary);

	// calls the version will the default argument
	// Warning: if 2 print functions have the default arg -> Error
	// which one to choose then ?
	print(); 
	print(433.33); // calls the double version of print
	print(34.44f); // promotes the float to a double.
	print(name);

	return 0;
}