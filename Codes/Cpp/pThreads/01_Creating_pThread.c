#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

void *showThreads(void *thread)
{
	long *tid = (long *)thread;
	printf("Thread id = %ld\n", *tid);
	// print thread unique identifier
}
int main()
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, showThreads, (void *)&thread1);
	pthread_exit(NULL);
    
    
}
