#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void *dice(void *t)
{
   unsigned long *myThread = (unsigned long *)t;
   printf("Starting Thread: %lu\n", *myThread);

   int randomv = rand() % 6 + 1;
   printf("Random Value: %d.\n", randomv);
   
   int *value = malloc(sizeof(int));
   *value = randomv;
   // value holds the Address of heap memory allocated.
   printf("Address of Dice pointer: %p\n", value);
   return (void*) value;
   
}
int main()
{
   pthread_t thread;
   srand(time(NULL));
   
   // pointer for the result: rolling the dice.
   int *result;
   
   pthread_create(&thread, NULL, dice, (void *) &thread);
   pthread_join(thread, (void **)&result);
   printf("Result: %d.\n", *result);
   printf("Address of Main Pointer: %p", result);
   // free heap memory allacated caused we cannot do it from the local function.
   free(result); 
   
   
   
}