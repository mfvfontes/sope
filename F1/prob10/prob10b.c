#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 256

#define SPACE " "

/*
Notes:

	char * strtok (char * str, const char * delimiters);

	char * fgets (char *str, int num, FILE *stream);
*/

void show(char **a, unsigned int n){
	unsigned int i;

	for(i = 0; i < n; i++)
		printf("%s\n", a[i]);
}

unsigned int save_tokens(char *tokens, char **stokens){

	unsigned int n = 0;

	while(tokens != NULL){
		stokens = realloc(stokens, (n+1)*sizeof(char*));
		stokens[n] = malloc(MAX_CHAR*sizeof(char));

		strcpy(stokens[n], tokens);
		tokens = strtok(NULL, SPACE);

		n++;
	}

	show(stokens, n);

	return n;
}

int main(void){

	unsigned int n;

	char *cmd = malloc(MAX_CHAR*sizeof(char)), *tokens = NULL;

	char **atokens = malloc(5*sizeof(char*));

	/* Read from command line */

	fgets(cmd, MAX_CHAR, stdin);

	/* Tokenize the command read */

	tokens = strtok(cmd, SPACE);

	/* Show the tokens */

	n = save_tokens(tokens, atokens);

	/* Not working...why? */

	show(atokens, n);

	return 0;
}
