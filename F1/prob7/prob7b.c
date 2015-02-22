#include <stdio.h>
#include <stdlib.h>

/*
	Even if the handlers have an exit call at the end, the application will proceed to the next handler
*/

static void exithand1(){
	printf("Exiting exit handler 1\n");
	/* Using exit (uncomment please)
	
	exit(0);

	*/
	exit(1);
}

static void exithand2(){
	printf("Exiting exit handler 2\n");
	/* Using exit (uncomment please)
	
	exit(0);

	*/
}

int main(void){

	atexit(exithand1); //Last thing to do (if abort isn't used)

	printf("First thing to do\n");

	atexit(exithand2); //Fourth thing to do (if abort isn't used)

	printf("Second thing to do\n");

	/* Using abort (uncomment please)

	abort(); //Application aborts and handlers are not called

	*/

	printf("Main done\n"); //Third thing to do (if abort wasn't used)

	return 0;
}
