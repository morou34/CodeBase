#include <iostream>
#include <omp.h>
// The single construct block of code is executed by only one of the threads 
// (not necessarily the master thread)

// The other threads do not execute their block, wait at an implicit barrier 
//at the end of the single construct unless a nowait clause is specified.

// Implicit barrier at the end of single block

// Usage: Good for initialization for example

int main(int argc, char const *argv[])
{
    #pragma omp parallel
    {
        printf("%c\n", 'A');
        #pragma omp single
        {
           printf("%s\n", "B: Single Thread.");
        }
        printf("%c\n", 'C');


    }
    
    return 0;
}