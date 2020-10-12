/* test_hsearch.c --- 
 * 
 * 
 * Author: Sherrina Y. Hwang
 * Created: Sun Oct 11 13:21:05 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

#include <stdlib.h>
#include <string.h>                                                                  
#include <stdio.h>                                                                   
#include "queue.h"
#include "hash.h"
                                                                                     
#define MAXREG 10                                                                    
#define hsize 4

typedef struct muffin {                                                              
  char flavor[MAXREG];                                                               
  double price;                                                                      
  int expdate;                                                                       
} muffin_t;

// Search function: checks for muffin based on type
bool searchfn(void *element, const void* search){
    muffin_t *e = (muffin_t *)element;
    muffin_t *s = (muffin_t *)search;
    if (strcmp(e->flavor,s->flavor)==0){
        return true;
    }
    return false;
}

                                                                        
int main(void) {                                                                     
    // create a few muffins and add to hashtable                                                              
    muffin_t *muffin1=malloc(sizeof(muffin_t));                                        
    strcpy(muffin1->flavor,"blueberry");                                               
    muffin1->price=5.00;                                                               
    muffin1->expdate=202012;                                                           
                                                                                        
    muffin_t *muffin2=malloc(sizeof(muffin_t));                                        
    strcpy(muffin2->flavor,"pumpkin");                                                 
    muffin2->price=6.00;                                                               
    muffin2->expdate=202010;

    muffin_t *muffin3=malloc(sizeof(muffin_t));                                        
    strcpy(muffin3->flavor,"banana");                                                 
    muffin3->price=3.00;                                                               
    muffin3->expdate=202010;                                                             
	                                                                                 

    hashtable_t *muffintable=hopen(hsize);
    hput(muffintable,muffin1,"blueberry",9);
    hput(muffintable,muffin2,"pumpkin",7);
    hput(muffintable,muffin3,"banana",6);


/* hremove -- removes and returns an entry under a designated key                          
 * using a designated search fn -- returns a pointer to the entry or                       
 * NULL if not found                                                                       
 */

    void *key="pumpkin";
    void *result = hremove(muffintable, searchfn, key, 7);

    if (strcmp((char*)result, (char*)key)== 0){
        printf("SUCCESS: hremove returned a pointer to element\n");          
        hclose(muffintable);
        exit(EXIT_SUCCESS);
    }else{
        printf("FAILURE: hremove did not work\n");
        hclose(muffintable);
        exit(EXIT_FAILURE);
    }



    

                                                                          
}     
