#include <iostream>
#include <omp.h>
/*The omp barrier directive identifies a synchronization point at which threads in a 
parallel region will wait until all other threads in that section reach the same point. 
Statement execution past the omp barrier point then continues in parallel*/

// Point of synchronization: Threads that finished their task will wait for the rest. 

int main(int argc, char const *argv[])
{
	omp_set_num_threads(4);
    #pragma omp parallel
    {
    	printf("Thread:%d | %c \n",omp_get_thread_num(), 'A');
    	printf("Thread:%d | %c \n",omp_get_thread_num(), 'B');

    	#pragma	omp barrier
    	printf("Thread:%d | %c \n",omp_get_thread_num(), 'C');
    }
    
    return 0;
}