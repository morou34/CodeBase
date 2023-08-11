#include <iostream>
#include <omp.h>

// Each thread executes a chunk of iterations and then 
// requests another chunk until there are no more chunks available.
// each thread requests new chunks when it's free.
// no thread stays idle.

int main(int argc, char const *argv[])
{
    #pragma omp parallel
    {
    	#pragma omp for schedule(dynamic, 5)
    	for (int i = 0; i < 100; ++i)
    	{
    		printf("Thread:%d, i=%d\n",omp_get_thread_num(), i);
    	}
    }
    
    return 0;
}