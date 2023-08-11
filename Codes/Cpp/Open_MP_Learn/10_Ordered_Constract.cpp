#include <iostream>
#include <omp.h>
//The ordered construct is used to guarantee the code run in iteration order of loop. 
//In the example below, the first for loop is executed in parallel. however the second loop
// prints items in order, it executes only when next item in order is ready



int main(int argc, char const *argv[])
{
	int A[10];
    #pragma omp parallel for ordered
    	for (int i = 0; i < 10; ++i)
    	{
    		A[i]= i * 10;
 	   		
    		printf("Done >>> Value:%d\n",i, A[i]);
 	   		#pragma omp ordered
    		printf("Index:%d -> Value:%d\n",i, A[i]);
    	}
    
    return 0;
}