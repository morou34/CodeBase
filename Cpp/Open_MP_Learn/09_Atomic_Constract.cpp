#include <iostream>
#include <omp.h>

// The omp atomic directive identifies a specific memory location 
// that must be updated atomically and not be exposed to multiple, 
// simultaneous writing threads.

// Used only with simple arithmetic operation like ++x, x+=value; 

int main(int argc, char const *argv[])
{
	int data[10]={1,3,2,5,8,7,2,9,2,4}, sum=0;
    #pragma omp parallel
    {
    	#pragma omp for 
    	for (int i = 0; i < 10; ++i)
    	{
    		if(data[i] % 2 != 0){
    			#pragma omp critical
    			sum+=data[i];
    		}
    	}
    }
    printf("sum = %d\n", sum);
    
    return 0;
}