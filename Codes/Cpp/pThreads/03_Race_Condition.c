#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
int mails = 0;
void *incrument(void *t)
{
    long *myid = (long *)t;
    printf("thread %ld has started.\n", *myid);
    for (int i = 0; i<10000000; ++i)
    {
     mails++;   
    }

}

int main()
{
    pthread_t t1, t2, t3;
    pthread_t *threads[]= {&t1, &t2, &t3};
    
    for(int i=0; i<3; ++i)
    {
        printf("i=%d, thread=%ld\n", i, threads[i]);
        pthread_create(threads[i], NULL, incrument,(void *)threads[i]);
        //pthread_join(*threads[i], NULL); will make them run in series
    }
    // pthread_join - wait for thread termination
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    
    printf("mails: %d\n", mails);
    
    pthread_exit(NULL);
 /*   
i=0, thread=140733945861432
i=1, thread=140733945861440
thread 140064483161856 has started.
i=2, thread=140733945861448
thread 140064474769152 has started.
thread 140064466376448 has started.
mails: 13655743  >>> ?????
*/    
}