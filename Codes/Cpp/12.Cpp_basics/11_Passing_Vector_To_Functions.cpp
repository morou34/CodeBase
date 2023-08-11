#include <iostream>
#include <vector>
#include <string>
using namespace std;

void display(const vector<int> &v)
{
	for(auto item:v)
		cout << item << " | ";
}

int main(int argc, char const *argv[])
{
	vector<int> v {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	display(v);

	return 0;
}