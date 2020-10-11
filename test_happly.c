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
#include "hash.h"

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

bool search(void* elementp, const void* keyp){
    person_t *p=(person_t*)elementp;
		char *ncheck = (char*)keyp;
		if (strcmp(p->name,ncheck)==0)
        return true;
    double *pcheck = (double*)keyp;
    if (p->rate == *pcheck)
      return true;
		int *agecheck = (int*)keyp;
		if(p->age == *agecheck)
			return true;
    return false;
}
int main(void){
	person_t *p1 = malloc(sizeof(person_t));
	strcpy(p1->name,"Sherrina");
	p1->age=20;
	p1->rate=1.2;
	
	person_t *p2 = malloc(sizeof(person_t));
	strcpy(p2->name,"Carson");
	p2->age=21;
	p2->rate=3.4;
	
	hashtable_t *persontable=hopen(hsize);
	// try apply on empty hash
	happly(persontable,age_2years);
	printf("SUCCESS: happly worked on an empty list\n");
	
	//try putting into hashtable
	hput(persontable,p1,"Sherrina",8);
	hput(persontable,p2,"Carson",6);
	
	//appply function to all in nonempty queue
	happly(persontable,age_2years);
	
	person_t *p;
	//getting p1, checking age has been increased by 2
	p = (person_t *)hsearch(persontable,search,"Sherrina",8);
	if (p->age !=  22){
		printf("FAILURE 1: happly did not apply the function to all elements in the nonempty hash\n");
		hclose(persontable);
		exit(EXIT_FAILURE);
	}
	//getting p2
	p = (person_t *)hsearch(persontable,search,"Carson",6); 
  if (p->age !=  23){  
    printf("FAILURE 2: happly did not apply the function to all elements in the nonempty hash\n");
		hclose(persontable);
		exit(EXIT_FAILURE);                                          
	}
	
	hclose(persontable);
	printf("SUCCESS: happly was called on empty and non empty hash. Applied the function to all elements in the nonempty hash\n");
	exit(EXIT_SUCCESS);
}
