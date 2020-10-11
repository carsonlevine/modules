/* test_hput.c --- 
 * 
 * 
 * Author: Sherrina Y. Hwang
 * Created: Sat Oct 10 08:42:37 2020 (-0400)
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
#define hsize 1

typedef struct muffin {                                                              
  char flavor[MAXREG];                                                               
  double price;                                                                      
  int expdate;                                                                       
} muffin_t;
                                                                                     
int main(void) {                                                                     
  // create a muffin                                                                 
  muffin_t *muffin1=malloc(sizeof(muffin_t));                                        
  strcpy(muffin1->flavor,"blueberry");                                               
  muffin1->price=5.00;                                                               
  muffin1->expdate=202012;                                                           
                                                                                    
  muffin_t *muffin2=malloc(sizeof(muffin_t));                                        
  strcpy(muffin2->flavor,"pumpkin");                                                 
  muffin2->price=6.00;                                                               
  muffin2->expdate=202010;                                                           
	                                                                                 

	hashtable_t *muffintable=hopen(hsize);
	int32_t hputresult=hput(muffintable,muffin1,"blueberry",9);
	int32_t hputresult2=hput(muffintable,muffin2,"pumpkin",7);
	
  if (hputresult!=0||hputresult2!=0) {                                               
    printf("FAILURE: hput did not work on empty and nonempty hash\n");                
    hclose(muffintable);
	  exit(EXIT_FAILURE);                                                              
  } else {                                                                           
    printf("SUCCESS: hput worked on empty and nonempty hash\n");  
		hclose(muffintable);
	  exit(EXIT_SUCCESS);                                                              
  }                                                                                  
}     
