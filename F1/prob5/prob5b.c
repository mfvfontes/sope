#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 20

int main(int argc, char **argv, char **envp){

	char **vars = envp;

	while(1){ //eventually it will find the USER environment variable

		if(strncmp(vars[0], "USER=", 5) == 0){
			char *user = (char *) malloc(sizeof(char*)*MAX_CHARS);
			
			/*

			Description:
				Move strlen(vars[0])-5 bits, starting in vars[0]+5, to user
			
			Explanation:
	
				strlen(vars[0])-5 - username's length (number of bytes)
				vars[0]+5 = fifth character of vars[0] = vars[0][4]
			
			memmove(char *dest, const char *src, int num);

				Copies the values of num bytes from the location pointed by src to the memory block pointed by dest.
			
			*/

			memmove(user, vars[0] + 5, strlen(vars[0]) - 5);
			
			printf("Hello %s !\n", user);

			break;
			
		}

		vars++;

	}

	return 0;

}
