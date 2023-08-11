#include <iostream>
#include <omp.h>


int main(int argc, char const *argv[])
{

    printf("\n>> SEQUETIAL REGION ---------------\n");
    int n = 10;

    printf("\n>> PARALLEL REGION ---------------\n");
    #pragma omp parallel num_threads(4) if(n>3)
    {
        printf("Hello!\n");
    }
    
    return 0;
}