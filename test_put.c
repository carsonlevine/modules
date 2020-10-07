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
  muffin_t *muffin=malloc(sizeof(muffin_t));                                    
  strcpy(muffin->flavor,"blueberry");                                           
  muffin->price=5.00;                                                           
  muffin->expdate=202012;                                                       
                                                                                
  // place it into a queue                                                      
  queue_t *q1=qopen();                                                          
  int32_t qputresult=qput(&q1,(queue_t*)&muffin);                                 
  if (qputresult!=0) { //can just put qput in this if statement                 
    printf("FAILURE: qput did not work\n");                                     
    free(muffin);                                                               
    qclose(&q1);                                                                 
    exit(EXIT_FAILURE);                                                         
  } else {                                                                      
    printf("SUCCESS: qput worked\n");                                           
    free(muffin);                                                               
    qclose(&q1);                                                                 
    exit(EXIT_SUCCESS);                                                         
  }             
}                                                                