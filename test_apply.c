                                                                                                                   
#include <stdio.h>                                                                                                 
#include <stdlib.h>                                                                                                
#include <stdint.h>                                                                                                
#include <string.h>                                                                                                
#include "queue.h"                                                                                                 
                                                                                                                   
#define MAXNM 50                                                                                                   
                                                                                                                   
typedef struct person{                                                                                             
  char name[MAXNM];                                                                                                
  int age;                                                                                                         
  double rate;                                                                                                     
} person_t;                                                                                                        
                                                                                                                   
void age_2years(void *elementp){                                                                                   
  person_t *p = (person_t *)elementp;                                                                              
  p->age = p->age + 2 ;                                                                                            
}                                                                                                                  
                                                                                                                   
int main(void){                                                                                                    
  queue_t *qp = qopen();                                                                                           
  // NEED TO MALLOC? or it happens in queue.c                                                                      
  person_t p1 = {"Sherrina", 20, 1.2};                                                                             
  person_t p2 = {"Carson", 21, 3.4};                                                                               
  person_t p3 = {"Elle", 22, 5.6};                                                                                 
  person_t p4 = {"Margot", 23, 7.8};                                                                               
  //places p1 - p4 in this order in new queue                                                                      
  qput(qp, (void *)&p1);                                                                                           
  qput(qp, (void *)&p2);                                                                                           
  qput(qp, (void *)&p3);                                                                                           
  qput(qp, (void *)&p4);                                                                                           
                                                                                                                   
  //appply function to all                                                                                         
  qapply(qp, &age_2years);                                                                                         
                                                                                                                   
  person_t *p;   
    //getting p1, checking age has been increased by 2                                                               
  p = (person_t *)qget(qp);                                                                                        
  if (p->age !=  22){                                                                                              
    printf("FAILURE: qapply did not apply the function to all elements in the nonempty queue\n");                  
    exit(EXIT_FAILURE);                                                                                            
  }                                                                                                                
  //getting p2                                                                                                     
  p = (person_t *)qget(qp);                                                                                        
  if (p->age !=  23){                                                                                              
    printf("FAILURE: qapply did not apply the function to all elements in the nonempty queue\n");                  
  exit(EXIT_FAILURE);                                                                                              
  }                                                                                                                
  //getting p3                                                                                                     
  p = (person_t *)qget(qp);                                                                                        
  if (p->age !=  24){                                                                                              
    printf("FAILURE: qapply did not apply the function to all elements in the nonempty queue\n");                  
    exit(EXIT_FAILURE);                                                                                            
  }                                                                                                                
  //getting p4                                                                                                     
  p = (person_t *)qget(qp);                                                                                        
  if (p->age !=  25){                                                                                              
    printf("FAILURE: qapply did not apply the function to all elements in the nonempty queue\n");                  
  exit(EXIT_FAILURE);                                                                                              
  } 
    qclose(qp);                                                                                                      
  printf("SUCCESS: qapply applied the functino to all elements in the nonempty queue\n");                          
  exit(EXIT_SUCCESS);                                                                                              
}    

