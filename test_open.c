#include "queue.h"                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include <stdio.h>                                                              
                                                                                
#define MAXNM 20                                                                
                                                                                
typedef struct phone {                                                         
  char name[MAXNM];                                                             
  double price;                                                                 
                                                                                
}phone_t;


int main(void){                                                                 

    // set up a new queue.
    queue_t *q = qopen();

    // qopen should return queue_t *pointer to NULL
    if (q==NULL){
        printf("SUCCESS: qopen returned pointer to empty queue");
        qclose(q);
        exit(EXIT_SUCCESS);
    }else{
        printf("FAILURE: qopen did not return pointer to empty queue");
        free(q);
        exit(EXIT_FAILURE);
    }


}                                                                                       