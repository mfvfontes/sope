#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **envp){

	char *user = getenv("USER");

	if(user != NULL) //eventually it will find but anyway...
		printf("Hello %s !\n", user);
	else
		return 1;

	return 0;

}

