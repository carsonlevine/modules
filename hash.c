/* hash.c --- 
 * 
 * 
 * Author: Carson G. Levine
 * Created: Mon Oct  5 12:20:06 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */

/* 
 * hash.c -- implements a generic hash table as an indexed set of queues.
 *
 */
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "queue.h"
#include "hash.h"
#include "queue.c"
#include "SuperFastHash.c"

typedef struct hashtableStruct {
  queue_t **htable;
  uint32_t hsize;
} hashtableStruct_t;

/* hopen -- opens a hash table with initial size hsize */

hashtable_t *hopen (uint32_t hsize){
  hashtableStruct_t *htp;
	queue_t **htable;
	if ((htp=(hashtableStruct_t*)malloc(sizeof(hashtableStruct_t)))==NULL||(htable=(queue_t**)malloc(hsize*sizeof(queue_t*)))==NULL) // checks that malloc works
		return NULL;
	htp->htable=htable;
	if (hsize<1) // checks for appropriate 
		return NULL;
	htp->hsize=hsize;
	for (int i=0;i<htp->hsize;i++) {
		queue_t *qp;
		if ((qp=qopen())==NULL)
			return NULL;
		htp->htable[i]=qp; // can't assume qopen doesn't return NULL- need to check that all aren't null and if one is then need to backtrack and free everything
  }
	return (hashtable_t*)htp;
}

/* hclose -- closes a hash table */                                                       
void hclose(hashtable_t *htp) {
	hashtableStruct_t *htsp;
	if (htp!=NULL) {
		htsp=(hashtableStruct_t*)htp;
		for (int i=0;i<htsp->hsize;i++)
			qclose(htsp->htable[i]);
		free(htsp->htable);
		free(htsp);
	}
}

/* hput -- puts an entry into a hash table under designated key                            
 * returns 0 for success; non-zero otherwise                                               
 */                                                                                        
int32_t hput(hashtable_t *htp, void *ep, const char *key, int keylen) {                     
  hashtableStruct_t *htsp;
	if (htp==NULL||ep==NULL||strcmp(key,"")==0||keylen<1)
		return -1;
	htsp=(hashtableStruct_t*)htp;
	uint32_t index=SuperFastHash(key,keylen,htsp->hsize);
  queue_t *qp= htsp->htable[index];
	if (qput(qp,ep)==0)
		return 0;
  return -1;                                                                         
}
		
/* happly -- applies a function to every entry in hash table */                            
void happly(hashtable_t *htp, void (*fn)(void* ep)){
	hashtableStruct_t *htsp;
	if (htp!=NULL||fn!=NULL) {
		htsp=(hashtableStruct_t*)htp;
		for (int i=0;i<htsp->hsize;i++)
			qapply(htsp->htable[i],fn);
	}
}

                                                                                           
/* hsearch -- searchs for an entry under a designated key using a                          
 * designated search fn -- returns a pointer to the entry or NULL if                       
 * not found                                                                               
 */



void *hsearch(hashtable_t *htp,bool (*searchfn)(void* elementp, const void* searchkeyp),const char *key,int32_t keylen){
	hashtableStruct_t *htsp;
	if (htp==NULL||searchfn==NULL||strcmp(key,"")==0||keylen<1)
		return NULL;
	htsp=(hashtableStruct_t*)htp;
	uint32_t index=SuperFastHash(key, keylen, htsp->hsize);
	if (index<0||index>=htsp->hsize)
		return NULL;
	void *target=qsearch(htsp->htable[index], searchfn, key);
	return (target);
}                                                                
                                                                                           
/* hremove -- removes and returns an entry under a designated key                          
 * using a designated search fn -- returns a pointer to the entry or                       
 * NULL if not found                                                                       
 */


void *hremove(hashtable_t *htp,bool (*searchfn)(void* elementp, const void* searchkeyp),const char *key,int32_t keylen) {
	hashtableStruct_t *htsp;
	if (htp==NULL||searchfn==NULL||strcmp(key,"")==0||keylen<1)
		return NULL;
	htsp=(hashtableStruct_t*)htp;
	uint32_t index=SuperFastHash(key,keylen,htsp->hsize);
	if (index<0||index>=htsp->hsize)
		return NULL;
	void *target=qremove(htsp->htable[index],searchfn,key);
	if (target!=NULL)
		return (target);
	else 
		return NULL;
}
	
     
