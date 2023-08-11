/*
The guided scheduling type is similar to the dynamic scheduling type. 
OpenMP again divides the iterations into chunks. Each thread executes 
a chunk of iterations and then requests another chunk until there are 
no more chunks available.

The difference with the dynamic scheduling type is in the size of chunks. 
The size of a chunk is proportional to the number of unassigned iterations 
divided by the number of the threads. Therefore the size of the chunks decreases. */

#include <iostream>
#include <omp.h>


int main(int argc, char const *argv[])
{
    #pragma omp parallel
    {
    	#pragma omp for schedule(guided)
    	for (int i = 0; i < count; ++i)
    	{
    		/* code */
    	}
    }
    
    return 0;
}