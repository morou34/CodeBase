#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

void *display(void *t)
{
    long *myid = (long *)t;
    printf("Thread id %ld\n", *myid);
}

int main()
{
    pthread_t thread1, thread2, thread3;
    pthread_t *threads[]= {&thread1, &thread2, &thread3};
    
    for(int i=0; i<3; ++i){
        pthread_create(threads[i], NULL, display, (void *)threads[i]);
        printf("i = %d\n", i);
    }
        
    
    pthread_exit(NULL);
    
}