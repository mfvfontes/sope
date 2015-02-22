#include <stdio.h>
#include <stdlib.h>

#define BUF_LENGTH 256

int main(void){

	FILE *src, *dst;
	char buf[BUF_LENGTH];

	if((src = fopen("infile.txt", "r")) == NULL)
 		exit(1); //missing semicolon

	if((dst = fopen("outfile.txt", "w")) == NULL)
		exit(2); //missing semicolon
	
	while((fgets(buf, BUF_LENGTH, src)) != NULL)
		fputs(buf, dst);

	fclose(src);
	fclose(dst);

	exit(0); // zero é geralmente indicativo de "sucesso"
}

/*
Errors (ERROR -> FIX):

	buf_length -> BUF_LENGTH
	MAX -> BUF_LENGTH

Note:

	include <stdlib.h> to clean every warning related to "incompatible implicit declaration of built-in function ‘exit’"
*/
