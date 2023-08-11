#include <iostream>
#include <vector>
#include <string>
using namespace std;

int days {7}; // Global variable visible everywhere in the program

void death(int health){
	static int lifes{5};
	if(health <=0)
		lifes--;
	cout << "Remaining lifes: " << lifes << endl;
}
// static variable: is a local variable accessible within its function only.
// it is declared just once the first time it is called.
// if its function is called its value = value it has at the end of
// previous call, 
int main(int argc, char const *argv[])
{
	std::cout << "Days: " << days << std::endl;

	for(size_t i{0}; i<10; ++i){
		cout << "i=" << i << " -> "; 
		
		if (i%2 != 0)
			death(0);
		else
			death(99);

	}
	death(100);
	death(100);
	death(100);
	return 0;
}