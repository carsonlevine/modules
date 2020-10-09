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
    printf("SUCCESS: qconcat worked on nonempty queues\n");                                    
		queue_t *q3=qopen();
		qput(q1,muffin);
		qconcat(q1,q3);

		// testing concat for nonempty with empty
		muffin_t* m1=qget(q1);
		if (m1==muffin) 
			printf("SUCCESS: qconcat worked with one nonempty and one empty queue\n"); 
		else {
			printf("FAILURE: qconcat did not work with one nonempty and one empty\n");
			exit(EXIT_FAILURE);
		}
		
		queue_t *q4=qopen();
		qput(q4,muffin);
		qconcat(q1,q4);
		muffin_t* m2=qget(q1);
		if (m2==muffin) 
			printf("SUCCESS: qconcat worked with one empty and one nonempty queue\n"); 
		else {
			printf("FAILURE: qconcat did not work with one empty and one nonempty\n");
			exit(EXIT_FAILURE);
		}
		
		queue_t *qempty=qopen();
		qconcat(q1,qempty);
		printf("SUCCESS: qconcat worked on two empty queues\n");
	
		free(first);
		free(last);
		qclose(q1);
		exit(EXIT_SUCCESS);
	} else {                                                                      
		printf("FAILURE: qconcat did not work on a nonempty queue\n");                               
		free(first);
		free(last);
		qclose(q1);                                                                 
    exit(EXIT_FAILURE);                                                         
    }                                                                           
}       
