#include "queue.h"                                                              
#include <stdlib.h>                                                             
#include <string.h>                                                             
#include <stdio.h>                                                              
                                                                                
#define MAXNM 20                                                                
                                                                                
typedef struct phone {                                                         
  char name[MAXNM];                                                             
  double price;                                                                 
                                                                                
}phone_t;

bool search(void* elementp, const void* keyp){
    phone_t *p=(phone_t*)elementp;                                                  
    if (strcmp(p->name,keyp)==0)      
        return true;
    double *pcheck = (double*)keyp;
    if (p->price == *pcheck)                                                        
      return true;                                                              
    return false;                                                                   
}

int main(void){                                                                 

// set up a new queue.

phone_t *phone1,*phone2;                                                   
phone1=malloc(sizeof(phone_t));                                             
strcpy(phone1->name,"Android");                                             
phone1->price=500.0;                                                          
                                                                                
phone2=malloc(sizeof(phone_t));                                             
strcpy(phone2->name,"iPhone");                                          
phone2->price=1000.0;                                                          
                                                                                
queue_t *phone=qopen();                                                                      
qput(phone,phone1);                                                        
qput(phone,phone2);                                                        
                                                                                
void *key="iPhone";

/* search a queue using a supplied boolean function                             
 * skeyp -- a key to search for                                                 
 * searchfn -- a function applied to every element of the queue                 
 *          -- elementp - a pointer to an element                               
 *          -- keyp - the key being searched for (i.e. will be                  
 *             set to skey at each step of the search                           
 *          -- returns TRUE or FALSE as defined in bool.h                       
 * returns a pointer to an element, or NULL if not found   
 * 
 * void* qsearch(queue_t *qp, 
							bool (*searchfn)(void* elementp,const void* keyp),
							const void* skeyp);

 */   

// non-empty test case using phone queue created above
void *result = qsearch(phone, search, key);
if (strcmp((char*)result,(char*)key) ==0 ){                                                                
    printf("SUCCESS: qsearch returned a pointer to element for non empty list\n");          
	qclose(phone);                                                               
}else{                                                                              
    printf("FAILURE: qsearch returned NULL for non empty list\n");                    
	qclose(phone);
	exit(EXIT_FAILURE);                                                               
}  

// empty queue test
queue_t *empty = qopen();
	void *empty_result = qsearch(empty,search,key);
	if (empty_result == NULL){
		printf("SUCCESS: qsearch returned NULL for empty list\n");
		qclose(empty);
	}else{
		printf("FAILURE: qsearch did not work for empty list\n");
		qclose(empty);
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);




}                                                                                       