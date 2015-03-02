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

void show_tokens(char *tokens){

	while(tokens != NULL){
		printf("%s\n", tokens);
		tokens = strtok(NULL, SPACE);
	}

}

int main(int argc, char **argv){

	/* Maybe useful for next exercise */

	//char *s[] = {"ls", "ps", "cat", "find"};

	char *cmd = malloc(MAX_CHAR*sizeof(char));

	char *tokens;

	/* Read from command line */

	fgets(cmd, MAX_CHAR, stdin);

	/* Tokenize the command read */

	tokens = strtok(cmd, SPACE);

	/* Show the tokens */

	show_tokens(tokens);	

	return 0;
}
