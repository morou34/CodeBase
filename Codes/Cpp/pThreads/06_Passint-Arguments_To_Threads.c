#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 

void *display(void *t)
{
    // long *myid = (long *)t;
    int *data=(int*)t;
    printf("data: %d.\n", *data);

}

int main()
{
   int size = 10;
   pthread_t threads[size];
   int data [10]={1,2,3,4,5,6,7,8,9,10};
    
   for(int i=0; i<size; ++i)
      pthread_create(threads+i, NULL, &display,(void *)(data+i));
      
   for(int i=0; i<size; ++i)
      pthread_join(threads[i], NULL);
    
   pthread_exit(NULL);
}