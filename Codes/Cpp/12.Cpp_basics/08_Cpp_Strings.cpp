#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Dynamic size
int main(int argc, char const *argv[])
{
	// Concatenation
	string part1{"Cpp"};
	string part2{"is a powerful"};
	string sentence;
	sentence = part1 + " " + part2 + " language.\n";
	cout << sentence << endl;
	// sentence2= "hello" + "world";  -> Error

	// Accessing characters[] and at() method
	cout << part1[0] << " | " << part1.at(1) << endl;

	// Looping through a string
	for(char c:"Hello Wrold"){
		cout << "character: " << c;
		cout << " -> int value: " << int(c) << endl;
	}

	// substrings: substr(): extracts a substring from string
	// object.substr(start_index, length)

	string s1 {"This is a test"};
	cout << s1.substr(0,4) << endl; // This
	cout << s1.substr(5,2) << endl; // is
	cout << s1.substr(10,4) << endl;// test

	// find(): object.find(string) : case sensitive
	// returns the start index of string in object

	cout << s1.find("This") << endl; // 0
	cout << s1.find("is") << endl; // 2
	cout << s1.find("T") << endl; // 0
	cout << s1.find("t") << endl; // 10
	cout << s1.find("zzz") << endl; // string::npos

	if(s1.find("ZZZ") == string::npos)
		cout << "ZZZ is not found." << endl;


	// Removing characters: this change the strings itself
	// object.clear(): clears the object
	// object.erase(start_index, length)
	cout << "--------" << endl;
	cout << "s1:" << s1 << endl; 

	cout << s1.erase(0,5) << endl;
	cout << "s1:" << s1 << endl; 

	cout << s1.erase(5,4) << endl;
	cout << "s1: " << s1 << endl; 

	s1.clear();
	cout << "s1:" << s1 << endl;

	cout << "--------" << endl;
	// length: object.length()
	s1 += "Hello";
	cout << s1 << " length: ";
	cout << s1.length() << endl;

	// input >> getline
	string name;
	cout << "your name: ";
	cin >> name; // Mouaad RRR
	cout << "Your name is: " << name << endl; // Mouaad 

	std::cin.clear();
	fflush(stdin);
	// Read an entire line until \n
	cout << "Your name again: ";
	getline(cin, name);
	cout << "Your name is: " << name << endl; // Mouaad 


	





	return 0;
}