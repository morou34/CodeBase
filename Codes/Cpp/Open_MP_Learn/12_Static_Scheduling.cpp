#include <iostream>
#include <omp.h>

// The schedule(static, chunk-size): The default chuck-size is divided to balance the load
// between the threads.

int main(int argc, char const *argv[])
{

    #pragma omp parallel
    {
    	#pragma omp for 
    	for (int i = 0; i < 16; ++i)
    	{
    		printf("Thread:%d -> i = %d\n",omp_get_thread_num(), i);
    	}
    
    	#pragma omp single
    		printf("-------------THREAD:%d--------------\n", omp_get_thread_num());

	
	   	#pragma omp for schedule(static, 4)
    	for (int i = 0; i < 16; ++i)
    	{
    		printf("Thread:%d -> i = %d\n",omp_get_thread_num(), i);
    	}
    }
    
    return 0;
}