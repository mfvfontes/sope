#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_LENGTH 256

int main(void){

	FILE *src, *dst;
	char buf[BUF_LENGTH];

	if((src = fopen("infile.txt", "r")) == NULL){
		perror("Couldn't open infile.txt file");
		//printf("Couldn't open infile.txt file: %s\n", strerror(errno));
 		exit(1);
	}

	if((dst = fopen("outfile.txt", "w")) == NULL){
		perror("Couldn't open outfile.txt file");
		//printf("Couldn't open outfile.txt file: %s", strerror(errno));		
		exit(2);
	} 

	while((fgets(buf, BUF_LENGTH, src)) != NULL)
		fputs(buf, dst);

	fclose(src);
	fclose(dst);

	exit(0); // zero é geralmente indicativo de "sucesso"
}

/*
Notes:

	void perror(const char *str)
		Interprets the value of errno as an error message, 
		and prints it to stderr (the standard error output stream, usually the console), 
		optionally preceding it with the custom message specified in str.

	char* strerror(int errnum)
		Interprets the value of errnum, generating a string with a message 
		that describes the error condition as if set to errno by a function of the library.

Important note:

	The perror calls show the same message as the printf calls using strerror!
*/
