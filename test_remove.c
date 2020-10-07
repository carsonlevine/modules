#include "queue.h"                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include <stdio.h>                                                              
                                                                                
#define MAXNM 20                                                                
                                                                                
typedef struct cereal {                                                         
  char name[MAXNM];                                                             
  double price;                                                                 
                                                                                
}cereal_t;

bool search(void* elementp, const void* keyp){                                  
cereal_t *p=(cereal_t*)elementp;                                                
double* pcheck= (double*)keyp;                                                  
if (strcpy(p->name,keyp))                                                       
   return true;                                                                 
if (p->price == *pcheck)                                                        
      return true;                                                              
return false;                                                                   
}

int main(void){                                                                 
                                                                                
  cereal_t *cereal1,*cereal2;                                                   
  cereal1=malloc(sizeof(cereal_t));                                             
  strcpy(cereal1->name,"Cheerios");                                             
  cereal1->price=5.99;                                                          
                                                                                
  cereal2=malloc(sizeof(cereal_t));                                             
  strcpy(cereal2->name,"Fruit Loops");                                          
  cereal2->price=4.99;                                                          
                                                                                
  queue_t *cereal[2];                                                           
  qopen();                                                                      
  qput(&cereal,cereal1);                                                        
  qput(&cereal,cereal2);                                                        
                                                                                
  void *key="Fruit Loops";

  //void *qremove(queue_t *qp,bool (*searchfn)(void* elementp,const void* const void* sk\
eyp)                                                                                    
 /* search a queue using a supplied boolean function (as in qsearch),                   
 * removes the element from the queue and returns a pointer to it or                    
 * NULL if not found                                                                    
 */                                                                                     
                                                                                        
  void *result = qremove(&cereal,search,&key);                                          
    if (result == key ){                                                                
      printf("SUCCESS: qremove returned a void pointer for non empty list\n");          
      exit(EXIT_SUCCESS);                                                               
    }else{                                                                              
      printf("FAILURE: qremove returedn NULL for non empty list\n");                    
      exit(EXIT_FAILURE);                                                               
    }                                                                                   
                                                                                        
                                                                                        
}                                                                                       
  