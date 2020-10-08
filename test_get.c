/* test_get.c --- 
 * 
 * 
 * Author: Marguerite Genereux
 * Created: Wed Oct  7 10:22:57 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

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

	person_t *p;
	//getting p1
	p = (person_t *)qget(qp);
	if (strcmp(p->name, "Sherrina") != 0){
		printf("FAILURE: qget did not get the first element in the nonempty queue\n");
		exit(EXIT_FAILURE);
	}
	//getting p2
	p = (person_t *)qget(qp);                                              
  if (p->age != 21){                                           
    printf("FAILURE: qget did not get the first element in the nonempty queue\n"); 
    exit(EXIT_FAILURE);                                                            
	}
	//getting p3
	p = (person_t *)qget(qp);                                              
  if (p->rate != 5.6){                                           
    printf("FAILURE: qget did not get the first element in the nonempty queue\n"); 
    exit(EXIT_FAILURE);                                                            
  }
	//getting p4
	p = (person_t *)qget(qp);                                                        
  if (strcmp(p->name, "Margot") != 0){                                           
    printf("FAILURE: qget did not get the first element in the nonempty queue\n"); 
    exit(EXIT_FAILURE);                                                            
  } 

	qclose(qp);
	printf("SUCCESS: qget got the first element in the nonempty queue\n");
	exit(EXIT_SUCCESS);
}
