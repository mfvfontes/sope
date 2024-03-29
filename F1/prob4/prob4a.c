#include <stdio.h>

int main(int argc, char **argv){
	
	if(argc < 2){ //program name and name(s)
		printf("Usages: \n ./prob4a <name>\n ./prob4a <name1> ... <namen>\n");		
		return 1;
	}
	else if(argc == 2) //if there is only one name/argument or the names are within inverted commas
		printf("Hello %s !\n", argv[1]);
	else{ //if there is more than one name/argument (many within inverted commas or not)
		int i;
			
		printf("Hello ");

		for(i = 1; i < argc; i++)
			printf("%s ", argv[i]);

		printf("!\n");
	}

	return 0;
}
