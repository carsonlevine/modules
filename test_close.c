#include "queue.h"                                                                                           
#include <stdlib.h>                                                                                          
#include <stdio.h>                                                                                           
#include <string.h>                                                                                          
                                                                                                             
#define MAXNM 20                                                                                             
typedef struct cereal {                                                                                      
  char name[MAXNM];                                                                                          
  double price;                                                                                              

}cereal_t;                                                                                                   
                                                                                                             
int main(void){                                                                                              
                                                                                                             
  //void qclose(queue_t *qp)                                                                                 
  //deallocate a queue, frees everything in it                                                               
                                                                                                             
  //create cereals to put in queue                                                                           
  cereal_t *cereal1,*cereal2;                                                                                
  cereal1=malloc(sizeof(cereal_t));                                                                          
  strcpy(cereal1->name,"Cheerios");                                                                          
  cereal1->price=5.99;                                                                                       
                                                                                                             
  cereal2=malloc(sizeof(cereal_t));                                                                          
  strcpy(cereal2->name,"Fruit Loops");                                                                       
  cereal2->price=4.99;                                                                                       
                                                                                                             
  queue_t *cereal = qopen();                                                                                                   
  qput(&cereal,&cereal1);                                                                                    
  qput(&cereal,&cereal2);                                                                                    
  qclose(cereal);                                                                                           
  void* result = qget(cereal1);
 
 if (result==NULL) {
    printf("SUCCESS: qclose returned a void pointer for non empty list\n");                                
    exit(EXIT_SUCCESS);                                                                                    
}
else{                                                                                                   
    printf("FAILURE: qclose returedn NULL for non empty list\n");                                          
    exit(EXIT_FAILURE);                                                                                    
}  

}
