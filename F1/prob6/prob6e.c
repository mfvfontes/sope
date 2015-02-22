#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_LENGTH 256

int main(void){

	FILE *src, *dst;
	char buf[BUF_LENGTH];

	if((src = fopen("infile.txt", "r")) == NULL){ //No such file or directory
		printf("[ERRNO %d]\n", errno); //printing errno variable (ENOENT = 2)
 		exit(1);
	}

	if((dst = fopen("outfile.txt", "w")) == NULL){ //No such file or directory
		printf("[ERRNO %d]\n", errno); //printing errno variable (ENOENT = 2)
		exit(2);
	} 

	while((fgets(buf, BUF_LENGTH, src)) != NULL)
		fputs(buf, dst);

	fclose(src);
	fclose(dst);

	exit(0); // zero é geralmente indicativo de "sucesso"
}

/*
For more information about errno codes:

	http://www.virtsync.com/c-error-codes-include-errno
*/
