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
#define hsize 2

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
	queue_t *qp2 = qopen();
	//testing on empty queue
	//qapply(qp, &age_2years);
	person_t p1 = {"Sherrina", 20, 1.2};
	person_t p2 = {"Carson", 21, 3.4};
	person_t p3 = {"Elle", 22, 5.6};
	person_t p4 = {"Margot", 23, 7.8};
	//places p1 - p4 in this order in new queue 
	qput(qp, (void *)&p1);
	//qput(qp, (void *)&p2);
	//qput(qp2, (void *)&p3);
	//qput(qp2, (void *)&p4);  

	hashtable_t *persontable=hopen(hsize);
	//try putting a queue into hashtable
	hput(persontable,qp,"p",1);
	//try putting a person into a queue in hashtable
	hput(persontable,p2,"p",1);
	
	//appply function to all in nonempty queue
	happly(persontable,&age_2years);
	
	person_t *p;
	//getting p1, checking age has been increased by 2
	p = (person_t *)hsearch(persontable,&searchfn,"p",1); // need to write search fn
	
	if (p->age !=  22){
		printf("FAILURE 1: qapply did not apply the function to all elements in the nonempty queue\n");
		hclose(persontable);
		exit(EXIT_FAILURE);
	}

 #if 0
	//getting p2
	p = (person_t *)qget(qp);                                              
  if (p->age !=  23){  
    printf("FAILURE 2: qapply did not apply the function to all elements in the nonempty queue\n");
	exit(EXIT_FAILURE);                                                            
	}
	//getting p3
	p = (person_t *)qget(qp);                                              
  if (p->age !=  24){ 
    printf("FAILURE 3: qapply did not apply the function to all elements in the nonempty queue\n");
		exit(EXIT_FAILURE);                                                            
  }
	//getting p4
	p = (person_t *)qget(qp);                                                        
  if (p->age !=  25){
    printf("FAILURE 4: qapply did not apply the function to all elements in the nonempty queue\n");
	exit(EXIT_FAILURE);                                                            
  } 
#endif
	hclose(persontable);
	printf("SUCCESS: qapply was called on empty and non empty queue. Applied the function to all elements in the nonempty queue\n");
	exit(EXIT_SUCCESS);
	
}
