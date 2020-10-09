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
  if (strcmp(p->name,keyp)==0)      
    return true;
  double *pcheck = (double*)keyp;
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
                                                                                
  queue_t *cereal=qopen();                                                                      
  qput(cereal,cereal1);                                                        
  qput(cereal,cereal2);                                                        
                                                                                
  void *key="Cheerios";

 //void *qremove(queue_t *qp,bool (*searchfn)(void* elementp,const void* const void* skeyp)
 /* search a queue using a supplied boolean function (as in qsearch),                   
 * removes the element from the queue and returns a pointer to it or                    
 * NULL if not found                                                                    
 */                                                                                     
                                                                                        
  void *result = qremove(cereal,search,key);                                          
	if (strcmp((char*)result,(char*)key) ==0 ){                                                                
      printf("SUCCESS: qremove returned a void pointer for non empty list\n");          
			//free(result);
			qclose(cereal);                                                               
    }else{                                                                              
      printf("FAILURE: qremove returned NULL for non empty list\n");                    
			//free(result);
			qclose(cereal);
			exit(EXIT_FAILURE);                                                               
    }                                                                                   

	queue_t *emptyC = qopen();
	void *EVAL = qremove(emptyC,search,key);
	if (EVAL == NULL){
		printf("SUCESS: qremove returned NULL for empty list\n");
		//free(EVAL);
		qclose(emptyC);
	}else{
		printf("FAILURE: qremove did not work for empty list\n");
		//free(EVAL);
		qclose(emptyC);
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
                                                                                        
}                                                                                       
  
