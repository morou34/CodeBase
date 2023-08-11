#include <iostream>
#include <omp.h>

// The omp master directive identifies a section of code 
// that must be run only by the master thread.

int main(int argc, char const *argv[])
{
    #pragma omp parallel
    {
    	#pragma omp master
    	{
    		int master = omp_get_thread_num();
    		printf(" -------------\n", master);
    		printf(" Master -> :%d\n", master);
    		printf(" -------------\n", master);
    	}

    	int th = omp_get_thread_num();
    	printf("- Thread:%d\n", th);
    }
    
    return 0;
}