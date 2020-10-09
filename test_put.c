#include <stdlib.h>                                                             
#include <string.h>                                                             
#include <stdio.h>                                                              
#include "queue.h"                                                              
                                                                                
#define MAXREG 10                                                               
                                                                                
typedef struct muffin {                                                         
  char flavor[MAXREG];                                                          
  double price;                                                                 
  int expdate;                                                                  
} muffin_t;                                                                     
                                                                                
int main(void) {                                                                
  // create a muffin                                                            
  muffin_t *muffin1=malloc(sizeof(muffin_t));                                   
  strcpy(muffin1->flavor,"blueberry");                                          
  muffin1->price=5.00;                                                          
  muffin1->expdate=202012;                                                      

	muffin_t *muffin2=malloc(sizeof(muffin_t));                                   
  strcpy(muffin2->flavor,"pumpkin");                                          
  muffin2->price=6.00;                                                          
  muffin2->expdate=202010;                                                      

  // place it into a queue                                                      
  queue_t *q1=qopen();                                                          
  int32_t qputresult=qput(q1,muffin1);// places into empty queue
	int32_t qputresult2=qput(q1,muffin2);//places into nonempty queue
  if (qputresult!=0||qputresult2!=0) {                 
    printf("FAILURE: qput did not work\n");                                     
    qclose(q1);                                                                 
    exit(EXIT_FAILURE);                                                         
  } else {                                                                      
    printf("SUCCESS: qput worked on both empty and nonempty queues\n");                     
    qclose(q1);                                                                 
    exit(EXIT_SUCCESS);                                                         
	}                                                                           
}                                                                               
         
