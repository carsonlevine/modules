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
	/*                                                                                    
  muffin_t *muffin2=malloc(sizeof(muffin_t));                                        
  strcpy(muffin2->flavor,"pumpkin");                                                 
  muffin2->price=6.00;                                                               
  muffin2->expdate=202010;                                                           
	*/                                                                                 
  queue_t *q1=qopen();
  qput(q1,muffin1);// places into empty queue                     
  //qput(q1,muffin2);//places into nonempty queue

	hashtable_t *muffintable=hopen(hsize);
	int32_t hputresult=hput(muffintable,q1,"m",1);
	
  if (hputresult!=0) {                                               
    printf("FAILURE: hput did not work\n");                                          
    hclose(muffintable);
		free(muffintable);
		free(q1);
		free(muffin1);
    exit(EXIT_FAILURE);                                                              
  } else {                                                                           
    printf("SUCCESS: qput worked on both empty and nonempty queues\n");  
    hclose(muffintable);
		free(muffintable);
		free(q1);
		free(muffin1);
    exit(EXIT_SUCCESS);                                                              
  }                                                                                  
}     
