#include <iostream>
#include <vector>
#include <string>
using namespace std;

unsigned long long factorial(int n){
	if (n==0)
		return 1;
	
	return n * factorial(n-1);
}


unsigned long long fibonacci(int n){
	if (n<=1)
		return n;

	return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, char const *argv[])
{
	int n{8};
	cout << "(" << n << ")! = " << factorial(n) << endl;

	int m{30};
	cout << "Fib(" << m << ") = " << fibonacci(m) << endl;
	return 0;
}