#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/times.h>

/*
Important note:

	Assuming every parameter is a number
*/

int main(int argc, char **argv){
	
	struct tms timer;

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

	clock_t real_time = times(&timer);

	printf("Real time: %d\n", real_time);
	printf("CPU user mode time: %d\n", timer.tms_utime);
	printf("CPU system mode time: %d\n", timer.tms_stime);

	return 0;
}
