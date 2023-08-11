#include <iostream>
#include <omp.h>


int main(int argc, char const *argv[])
{	
	int size{1000};
	int array[size];
	int sum{0};
    #pragma omp parallel
    {
    	#pragma omp for 
    	for (int i = 0; i < size; ++i)
    	{
			array[i]=i;    		
    	}

    	#pragma omp for
    	for (int i = 0; i < size; ++i)
    	{	
    		if(array[i] % 2 != 0)
    		{
    			#pragma omp critical
 		   		sum+=array[i];
    		}
    	}
    }
    std::cout << "Critical sum=" << sum << std::endl;
    
    return 0;
}