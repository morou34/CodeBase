#include <iostream>
#include <omp.h>
// The omp critical directive identifies a section of code 
// that must be executed by a single thread at a time.
// used to avoid race conditions.

int main(int argc, char const *argv[])
{
	omp_set_num_threads(4);
    #pragma omp parallel
    {
    	#pragma omp critical
    	{
    		for (int i = 0; i < 5; ++i)
    		{
    			int th = omp_get_thread_num();
    			printf("critical: %d\n", th);
    		}
    	}
    	int mythread = omp_get_thread_num();
		printf("outside critical: %d\n", mythread);

    }
    
    int array[100];
    for (int i = 0; i < 100; ++i)
    {
    	array[i] = i; 
    }


    std::cout << "\nSEQUENTIAL PROCESSING ----------\n";
    int sum_odd{0};
    std::cout << "Sum(odd) = ";
    for (int i = 0; i < 100; ++i)
    {
    	if(array[i] % 2 == 1)
    	{	
    		sum_odd+=array[i];
	    	printf("%d ", i, array[i]);
	    	if (array[i]!= 99)
	    		printf("+ ");
    	}

    }
    printf("= %d\n", sum_odd);

    std::cout << "\nPARALLEL PROCESSING ----------\n";

    int myArray[100];
    int my_sum{0};

    #pragma omp parallel
    {
    	#pragma omp for
    	for (int i = 0; i < 100; ++i)
    	{
    		myArray[i]=i;
    	}

    	#pragma omp for 
    	for (int i = 0; i < 100; ++i)
    	{
    		printf("%d | ", myArray[i]);
    	}

    	#pragma omp for reduction(+:my_sum)
    	for (int i = 0; i < 100; ++i)
    	{
    		if (myArray[i] % 2 != 0)
	    		my_sum+=myArray[i];
    	}

    }
    	std::cout << "\nSum(odd): "<< my_sum;

    return 0;
}