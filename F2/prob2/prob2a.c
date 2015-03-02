#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char **argv){

	FILE *fp1, *fp2;
	char *buffer = malloc(sizeof(char));
	size_t result;

	if(argc < 3){
		printf("Usage %s <src> <dest>\n", argv[0]);
		exit(1);
	}

	if((fp1 = fopen(argv[1], "r")) == NULL){
		perror(argv[1]);
		exit(1);
	}
	if((fp2 = fopen(argv[2], "w")) == NULL){
		perror(argv[2]);
		exit(2);
	}

	while(result = fread(buffer, sizeof(char), 1, fp1))
		fwrite(buffer, sizeof(char), 1, fp2);

	fclose(fp1);
	fclose(fp2);

	return 0;
}
