#include <stdio.h>                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include "queue.h"                                                              
#define MAXREG 10                                                               
                                                                                
typedef struct muffin {                                                         
  char flavor[MAXREG];                                                          
  double price;                                                                 
  int expdate;                                                                  
} muffin_t;                                                                     
                                                                                
int main(void) {                                                                
  // creating two muffins                                                       
  muffin_t *muffin=malloc(sizeof(muffin_t));                                    
  strcpy(muffin->flavor,"blueberry");                                           
  muffin->price=5.00;                                                           
  muffin->expdate=202012;                                                       
                                                                                
  muffin_t *muffin2=malloc(sizeof(muffin_t));                                   
  strcpy(muffin->flavor,"pumpkin");                                             
  muffin->price=6.00;                                                           
  muffin->expdate=202011;                                                       
                                                                                
  //creating two different queues and putting them in each one                  
  queue_t *q1=qopen();                                                          
  queue_t *q2=qopen();                                                          
  qput(q1,muffin);                                                              
  qput(q2,muffin2);                                                             
  qconcat(q1,q2); //combining queues and closing the last                       
                                                                                
  //see if they are in the right order and in the same queue                    
  muffin_t* first=qget(q1);                                                     
  muffin_t* last=qget(q1);                                                      
  if (first==muffin && last==muffin2) {                                         
    printf("SUCCESS: qconcat worked\n");                                        
    qclose(q2);                                                                 
    qclose(q1);                                                                 
    exit(EXIT_SUCCESS);                                                         
  } else {                                                                      
    printf("FAILURE: qconcat did not work\n");                                  
    qclose(q2);                                                                 
    qclose(q1);                                                                 
    exit(EXIT_FAILURE);                                                         
    }                                                                           
}       
