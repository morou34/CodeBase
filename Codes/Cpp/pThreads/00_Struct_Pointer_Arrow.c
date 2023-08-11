#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct student
	{
		char name[20];
		int age;
	};

	struct student alex = {"Alex", 20};
	struct student *ptr = &alex;

	printf("%s:%d\n",ptr->name, ptr->age);


}