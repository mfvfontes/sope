#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Important note:

	Assuming every parameter is a number
*/

int main(int argc, char **argv){

	if(argc < 3){
		printf("Usage: ./prob8a n1 n2\n");
		exit(1);
	}	

	srand((unsigned int)time(NULL));

	int n1 = atoi(argv[1]), n2 = atoi(argv[2]);
	int i = 0, sort;

	while((sort = rand() % n1) != n2){
		i++;
		printf("Iter %d (Sort, N2): (%d, %d)\n", i, sort, n2);
	}

	printf("Last Iter (Sort, N2): (%d, %d)\n", sort, n2);

	return 0;
}
