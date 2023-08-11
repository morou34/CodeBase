#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
int mails = 0;
pthread_mutex_t mutex;

void *incrument(void *t)
{
    unsigned long*myid = (unsigned long*)t;
    printf("thread %lu has started.\n", *myid);
    for (int i = 0; i<10000000; ++i)
    {
      // the mutex will protect the variable from being accessed 
      // or modified by more than one thread at the same time
      pthread_mutex_lock(&mutex); 
      mails++;   
      pthread_mutex_unlock(&mutex);
    }

}

int main()
{
   size_t size=3;
   pthread_t threads[size];
   pthread_mutex_init(&mutex, NULL);
    
   for(int i=0; i<size; ++i)
      pthread_create(threads+i, NULL, incrument,(void *)(threads+i));
    
    // pthread_join - wait for thread termination
   for(int i=0; i<size; ++i){
      pthread_join(threads[i], NULL);
      printf("thread %lu has finished.\n", threads[i]);
   }

    pthread_mutex_destroy(&mutex);
    printf("mails: %d\n", mails);
    
    pthread_exit(NULL);
  
}