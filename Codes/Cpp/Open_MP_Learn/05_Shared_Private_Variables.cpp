#include <iostream>
#include <omp.h>
#include <time.h>


int main(int argc, char const *argv[])
{
	// shared variable: can be accessed by all threads.
	// private variable: all threads have their own copy or clone of that variable.
	// variables outside the parallel region are shared or public variables.
	// variables inside the parallel region are private variables.

    // Use current time as seed for random generator
	srand(time(0));

	int x; 
	x = rand() % 100 + 1; // Range [1, 100] 
	printf("Sequential -> x = %d \n", x);

	omp_set_num_threads(4);
    #pragma omp parallel
    {
    	int th = omp_get_thread_num();
    	printf("Thread:%d,  x = %d\n", th, x);
    }
    
    std::cout << "\nGENERATEING RANDOM NUMBERS IN THE PARALLEL REGION ------->" << std::endl;
	
	int y, z{99}; 
    #pragma omp parallel private(y,z) //shared(a)
    {
    	int a{0};
    	a++;
		y = rand() % 100 + 1;

    	int th = omp_get_thread_num();
    	printf("Thread:%d,  y = %d\n", th, y);
    	printf("Thread:%d,  z = %d\n", th, z);
    	printf("Thread:%d,  a = %d\n", th, a);

    }
    
    return 0;
}