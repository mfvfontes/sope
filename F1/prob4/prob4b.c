#include <stdio.h>

int is_number(char *s);

int main(int argc, char **argv){
	
	//Let's assume the name is within inverted commas

	if(argc < 3){ //program name, name and repeats
		printf("Usages: \n ./prob4b <name> <repeats>\n");		
		return 1;
	} else{

		if(is_number(argv[2])){ //if it is number, then it's OK

			int i, n = atoi(argv[2]);

			for(i = 0; i < n; i++)
				printf("Hello %s !\n", argv[1]);
		} else {
			printf("[ERROR]: The specified repeats is not a number\n");
			return 1;
		}
	}

	return 0;
}

int is_number(char *s){
	int i;

	for(i = 0; s[i] != '\0'; i++)
		if(!isdigit(s[i]))
			return 0;

	return 1;
}
