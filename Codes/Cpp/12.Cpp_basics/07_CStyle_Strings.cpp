// #include<cctype>: to use the c-style strings functions.
// Functions for Testing characters: function_name(char)
// Expect a single character

// isalpha(c): c is a letter
// isdigit(c): c is a digit
// isalnum(c): c is a letter or digit
// islower(c): c is a lowercase letter
// isupper(c): c is an uppercase letter
// isspace(c): c is a whitespace

// Functions for Converting characters: function_name(char)
// tolower(c): returns lowercase of c 
// toupper(c): returns uppercase of c

//CStyle strings are terminated with the NULL character


#include <iostream>
#include <cctype> // for character functions 
#include <cstring> // for c-style strings functions

int main(int argc, char const *argv[])
{
	char name[]{"Lee"}; 

	for(auto c:name)
		printf("%c ", c);

	// Changing the NULL char to 'A' => Problem
	// length=8: the function does not know where to stop
	// cz there is no NULL char to stop the count.
	name[3]='A'; 
	name[4]='B'; 
	printf("%c \n", name[3]);
	std::cout << name <<" length: " << strlen(name) << std::endl;


	// title="Robin"; // error
	char title[10];
	strcpy(title, "Robbin");
	std::cout << "Title: " << title << std::endl;


	// Display garbage, need initialization
	char myname[20];
	std::cout << myname << std::endl;

	char first_name[20]{};
	char last_name[20]{};
	char full_name[50]{};
	char temp[50]{};

	std::cout << "Enter your first name: ";
	std::cin >> first_name;

	std::cout << "Enter you last name: ";
	std::cin >> last_name;

	std::cout << "Length of (" << first_name << ") is: " 
	<< strlen(first_name) << std::endl;

	std::cout << "Length of (" << last_name << ") is: " 
	<< strlen(last_name) << std::endl;
	

	// Concatenating strings
	strcpy(full_name, last_name); // copy lastname to fullname
	strcat(full_name, " ");
	strcat(full_name, first_name);
	std::cout << "Your full name is: " << full_name << std::endl;

	std::cin.clear();
	fflush(stdin);

	// Reading an entire line.
	//  cin.getline (NAME, MAX_NAME_LENGTH);
	char fullName[50]{};
	std::cout << "Enter your full name: ";
	std::cin.getline(fullName, 50);
	std::cout << "Full name is: " << fullName << std::endl;

	// Comparing two strings
	// strcmp: returns 0 if the strings are the same
	// 
	strcpy(full_name, temp);
	if(strcmp(fullName, temp) == 0)
		std::cout << "The names are the same.\n";
	else
		std::cout << "The names are not the same.\n";

	// Turning the name to uppercase

	for (size_t i = 0; i < strlen(fullName); ++i)
		if(isalpha(fullName[i]))
			fullName[i]=toupper(fullName[i]);

	std::cout << "Full Name: " << fullName << std::endl;

	return 0;
}



