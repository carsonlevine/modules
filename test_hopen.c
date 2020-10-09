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
		printf("success\n");
		hclose(hash);
		exit(EXIT_SUCCESS);
	} else {
		printf("failed\n");
		hclose(hash);
		exit(EXIT_FAILURE);
	}
}