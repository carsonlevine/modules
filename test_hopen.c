/* test_hopen.c --- 
 * 
 * 
 * Author: Sherrina Y. Hwang
 * Created: Fri Oct  9 17:47:47 2020 (-0400)
 * Version: 
 * 
 * Description: 
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main(void) {
	hashtable_t *hash=hopen(10);
	if (hash!=NULL) {
		printf("SUCCESS:hopen worked for empty list\n");
		hclose(hash);
		printf("SUCCESS: hclose worked for empty list\n");
		exit(EXIT_SUCCESS);
	} else {
		printf("FAILED:hopen did not work for empty list\n");
		hclose(hash);
		printf("FAILED: hclose did not work for empty list\n");
		exit(EXIT_FAILURE);
	}
}
