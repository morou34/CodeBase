#include <iostream>
using namespace std;

void *da(int *add)
{
	int *p{add};
	*p += 10;
	return p;
}

int main(int argc, char const *argv[])
{
	int a{1};
	int *ptr{nullptr};

	// You need a double pointer to store the address of a pointer
	// int *dp{&prt} >> Error
	int **dp{&ptr};
	// TypeCasting the void pointer to int pointer.
	// void pointers need to be typecasted before usage.
	ptr = (int *)da(&a);

	cout << "*ptr = " << *ptr << endl;
	cout << "*dp  = " << **dp << endl;
	cout << "a    = " << a << endl;

	return 0;
}