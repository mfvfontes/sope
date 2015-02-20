#include <stdio.h>
#include <stdlib.h>

/*
To create an environment variable, use the following commands (on terminal):
	
	export VARIABLE_NAME=value

	source /etc/environment

To check if works:

	echo $VARIABLE_NAME
*/

int main(int argc, char **argv, char **envp){

	char *user = getenv("USER_NAME");

	if(user != NULL) //if the environment variable exists
		printf("Hello %s !\n", user);
	else
		return 1;

	return 0;

}

