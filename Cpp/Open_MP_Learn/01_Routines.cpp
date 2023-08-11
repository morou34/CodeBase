#include <iostream>
#include <omp.h>


int main(int argc, char const *argv[])
{
    printf("\n>> SEQUETIAL REGION ---------------\n");

    int x = omp_get_num_threads();
    std::cout << "Threads: "<< x << std::endl;

    int max_th = omp_get_max_threads();
    std::cout << "Max Threads: "<< max_th << std::endl;

    omp_set_num_threads(5);
    x = omp_get_max_threads();
    std::cout << "Set Threads: "<< x << std::endl;

    int procs = omp_get_num_procs();
    std::cout << "Processors: "<< procs << std::endl;

//------------------------------------------------------------------

    printf("\n>> PARALLEL REGION ---------------\n");
    #pragma omp parallel
    {
        int x = omp_get_num_threads();
        printf("Threads:%d \n", x );
    }
    
    printf("\n>> THREAD NUMBER ---------------\n");
    
    #pragma omp parallel
    {
        int th = omp_get_thread_num();
        printf("Thread : %d\n",th );
    }
    return 0;


}