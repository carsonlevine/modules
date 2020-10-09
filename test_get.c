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

	person_t *p;
	//testing on empty queue
	p = qget(qp);
	
	person_t *p1=malloc(sizeof(person_t));
	person_t *p2=malloc(sizeof(person_t));
	person_t *p3=malloc(sizeof(person_t));
	person_t *p4=malloc(sizeof(person_t));  
	strcpy(p1->name, "Sherrina");
	strcpy(p2->name, "Carson");
	strcpy(p3->name, "Elle");
	strcpy(p4->name, "Margot");
	p1->age = 20;
	p2->age = 21;
	p3->age = 22;
	p4->age = 23;
	p1->rate = 1.2;
	p2->rate = 3.4;
	p3->rate = 5.6;
	p4->rate = 7.8;
	//places p1 - p4 in this order in new queue 
	qput(qp, p1);
	qput(qp, p2);
	qput(qp, p3);
	qput(qp, p4);  

	//getting p1
	p = qget(qp);

	if (p->age != 20){
		printf("FAILURE: qget did not get the first element in the nonempty queue\n");
		exit(EXIT_FAILURE);
	}
	free(p);

	//getting p2
	p = qget(qp);                                              
  if (p->age != 21){                                           
    printf("FAILURE: qget did not get the first element in the nonempty queue\n"); 
    exit(EXIT_FAILURE);                                                            
	}
	free(p);
	//getting p3
	p = qget(qp);                                              
  if (p->rate != 5.6){                                           
    printf("FAILURE: qget did not get the first element in the nonempty queue\n"); 
    exit(EXIT_FAILURE);                                                            
  }
	free(p);
	//getting p4
	p = qget(qp);                                                        
  if (strcmp(p->name, "Margot") != 0){                                           
    printf("FAILURE: qget did not get the first element in the nonempty queue\n"); 
    exit(EXIT_FAILURE);                                                            
  }
	free(p);

	qclose(qp);
	printf("SUCCESS: qget was called on empty and nonempty queue. Got the first element in the nonempty queue\n");
	exit(EXIT_SUCCESS);
}
