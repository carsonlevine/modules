#include "queue.h"                                                                                           
#include <stdlib.h>                                                                                          
#include <stdio.h>                                                                                           
#include <string.h>                                                                                          
                                                                                                             
#define MAXNM 20

typedef struct cereal {                                                                                      
  char name[MAXNM];                                                                                          
  double price;                                                                                              

} cereal_t;                                                                                                   
                                                                                                             
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
                                                                                                             
  queue_t *cereal = qopen();                                                                                        //place into queue           
  qput(cereal,cereal1);                                                                                    
  qput(cereal,cereal2);

	//close the queue
	qclose(cereal);
  printf("SUCCESS: qclose worked for non empty list\n");
                                                                                                
	// printf("FAILURE: qclose did not work for non empty list\n");          

	queue_t *emptyC = qopen();
	qclose(emptyC);
	printf("SUCCESS: qclose worked for an empty list\n");
	exit(EXIT_SUCCESS);
	

	
}
