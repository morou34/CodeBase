#include <iostream>
#include <omp.h>
void line(){printf("\n----------------------\n");}

int main(int argc, char const *argv[])
{
    printf("\n>> PARALLEL REGION ---------------\n");
    omp_set_num_threads(4);
    // The task is split between active threads 
    #pragma omp parallel for
        for (int i = 0; i < 20; ++i)
        {
            printf("looping %d\n", i);
        }

    printf("Number of threads: %d", omp_get_num_threads());
    line();

    #pragma omp parallel
    {
        // once a core finishes its task within the first loop, 
        // it start the next for loop task
        #pragma omp for nowait
        for (int i = 0; i < 10; ++i)
        {
            printf("%d\n", i);
        }

        #pragma omp for
        for (int j = 65; j < 77; ++j)
        {
            printf("%c\n", j);
        }
    }
    return 0;
}