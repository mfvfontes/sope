#include <stdio.h>

int main(int argc, char **argv, char **envp){

	char **vars = envp;

	while(vars != NULL){

		printf("%s\n", vars[0]);

		vars++;

	}

	return 0;

}
