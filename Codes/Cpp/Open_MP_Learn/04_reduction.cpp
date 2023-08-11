#include <iostream>
#include <vector>
#include <string>

int main(int argc, char const *argv[])
{
	int sum{0}, new_sum{0};
	int range = 1000;

	int x = 0;
	for (int i = 0; i < range+1; ++i)
	{
		x+=i;
	}
	printf("Sequential loop = %d\n", x);

	int y = (range*(range+1))/2;
	printf("Equations = %d\n", y);

	#pragma omp parallel 
	{	
		// Sum is random because there is no synchronization
		// between threads when adding a value to sum
		#pragma omp for 
			for (int i = 0; i < range+1; ++i)
			{
				sum+=i;
			}

		#pragma omp for reduction(+:new_sum)
			for (int i = 0; i < range+1; ++i)
			{
				new_sum+=i;
			}
	}
		printf("Paralle loop = %d\n", sum);
		printf("Paralle loop + Reduction = %d\n", new_sum);



	return 0;
}