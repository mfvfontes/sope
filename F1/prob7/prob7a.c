#include <stdio.h>
#include <stdlib.h>

/*
	Handlers will be called from down to up.
	First the nth handler, and lastly the first handler.
*/


static void exithand1(){
	printf("Exiting exit handler 1\n");
}

static void exithand2(){
	printf("Exiting exit handler 2\n");
}

int main(void){

	atexit(exithand1); //Last thing to do

	printf("First thing to do\n");

	atexit(exithand2); //Fourth thing to do

	printf("Second thing to do\n");

	printf("Main done\n"); //Third thing to do

	return 0;
}
