#include "queue.h"                                                              
#include <stdlib.h>                                                             
#include <stdio.h>                                                              
                                                                                
// create a struct for front and back pointers that has a next                  
typedef struct node {                                                           
  void *data;                                                                   
  struct node *next;                                                            
} node_t;                                                                       
                                                                                
typedef struct queueStruct {                                                    
  struct node *front;                                                           
  struct node *back;                                                            
} queueStruct_t;                                                                
                                                                                
/* create an empty queue */                                                     
queue_t* qopen(void) {                                                          
  queueStruct_t *qp = malloc(sizeof(queueStruct_t));                            
  qp->front=NULL;                                                               
  qp->back=NULL;                                                                
  return (queue_t*)qp;                                                          
}                                                                               
                                                                                
  // to be safe check that the nodes we are working with are not null- esp when\
 freeing!!                                                                      
                                                                                
/* deallocate a queue, frees everything in it */                                
void qclose(queue_t *qp) { // need to free data within every node-- only if it \
has data to free- order matters! get the data in the nodes first and then       
  queueStruct_t *qsp=(queueStruct_t*)qp;                                        
  node_t *f=qsp->front;                                                         
  for (node_t *p=qsp->front;p!=NULL;) {                                         
    if (p!=NULL)                                                                
      free(p->data);                                                            
    f=p->next;                                                                  
    free(p);                                                                    
    p=f;                                                                        
  }                                                                             
  free(qsp);                                                                    
}                                                                               
                                                                                
/* put element at the end of the queue                                          
 * returns 0 is successful; nonzero otherwise                                   
 */                                                                             
                                                                                
int32_t qput(queue_t *qp, void *elementp) { // need to malloc for each node     
  queueStruct_t *qsp=(queueStruct_t*)qp;                                        
  node_t *np=malloc(sizeof(node_t));                                            
  if (np!=NULL) {                                                               
    np->data=elementp;                                                          
    np->next=NULL;                                                              
  }                                                                             
  if (qsp->front==NULL) {                                                       
    qsp->front=np;                                                              
    qsp->back=np;                                                               
    return 0;                                                                   
  } else {                                                                      
    qsp->back->next=np;                                                         
    qsp->back=np;                                                               
    return 0;                                                                   
    }                                                                           
 return -1;                                                                     
}                                                                               
                                                                                
/* get the first first element from queue, removing it from the queue */        
void* qget(queue_t *qp) {                                                       
  queueStruct_t *qsp=(queueStruct_t*)qp;                                        
  void* first=qsp->front->data;                                                 
  free(qsp->front);                                                             
  qsp->front=qsp->front->next;                                                  
  return first;                                                                 
}                                                                               
                                                                                
/* apply a function to every element of the queue */                            
void qapply(queue_t *qp, void (*fn)(void* elementp)) {                          
  queueStruct_t *qsp=(queueStruct_t*)qp;                                        
  for (node_t *p=qsp->front;p!=NULL;p=p->next) {                                
    fn(p);                                                                      
  }                                                                             
}                                                                               
// we create the searchfn- it's indiviidual to each test case                  \
                                                                                
/* search a queue using a supplied boolean function                             
 * skeyp -- a key to search for                                                 
 * searchfn -- a function applied to every element of the queue                 
 *          -- elementp - a pointer to an element                               
 *          -- keyp - the key being searched for (i.e. will be                  
 *             set to skey at each step of the search                           
 *          -- returns TRUE or FALSE as defined in bool.h                       
 * returns a pointer to an element, or NULL if not found                        
 */                                                                             
                                                                                
void* qsearch(queue_t *qp,                                                      
              bool (*searchfn)(void* elementp,const void* keyp),                
              const void* skeyp) {                                              
  queueStruct_t *qsp=(queueStruct_t*)qp;                                        
  for (node_t *p=qsp->front;p!=NULL;p=p->next) {                                
    bool found=searchfn(p->data,skeyp);                                         
    if (found)                                                                  
      return p->data;                                                           
  }                                                                             
  return NULL;                                                                  
}                                                                               
                                                                                
/* search a queue using a supplied boolean function (as in qsearch),            
 * removes the element from the queue and returns a pointer to it or            
 * NULL if not found                                                            
 */                                                                            \
                                                                                
void* qremove(queue_t *qp,                                                      
              bool (*searchfn)(void* elementp,const void* keyp),                
              const void* skeyp) {                                              
  queueStruct_t *qsp=(queueStruct_t*)qp;                                        
  node_t *f=qsp->front;                                                         
  for (node_t *p=qsp->front;p!=NULL;p=p->next) {                                
    bool found=searchfn(p->data,skeyp);                                         
    if (found) {                                                                
      void* tmp=p->data;                                                        
      f->next=p->next;                                                          
      free(p);                                                                  
      return(tmp);                                                              
    }                                                                           
    f=p;                                                                        
  }                                                                             
  return NULL;                                                                  
}                                                                               
                                                                                
/* concatenatenates elements of q2 into q1                                     \
 * q2 is dealocated, closed, and unusable upon completion                       
 */                                                                             
void qconcat(queue_t *q1p, queue_t *q2p) {                                      
  queueStruct_t *q1sp=(queueStruct_t*)q1p;                                      
  queueStruct_t *q2sp=(queueStruct_t*)q2p;                                      
  q1sp->back->next=q2sp->front;                                                 
  q1sp->back=q2sp->back;                                                        
  free(q2sp); //might only need to free the queue memory not each node since we\
 are reassigning- experiment w this!                                            
}                                                                               
               
