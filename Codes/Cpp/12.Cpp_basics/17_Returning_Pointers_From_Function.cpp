#include <iostream>
#include <vector>
#include <string>
using namespace std;

int *compare(int *a, int *b)
{
	if (*a >= *b)
		return a;
	else
		return b;
}
int main(int argc, char const *argv[])
{
 int a{200}, b{300};
 int *ptr{nullptr};
 ptr = compare(&a, &b);
 cout << "The lager number is: " << *ptr << endl;
	return 0;
}