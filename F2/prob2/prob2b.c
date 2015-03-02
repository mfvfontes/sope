#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char **argv){

	int result;
	int fd_src, fd_dst;
	char *buffer = malloc(sizeof(char));

	if(argc < 3){	
		write(STDOUT_FILENO, "Usage %s <src> <dest>\n", strlen(argv[0]) + 21);
		exit(1);
	}

	if((fd_src = open(argv[1], O_RDONLY)) == -1){
		perror(argv[1]);
		exit(1);
	}

	if((fd_dst = open(argv[2], O_WRONLY)) == -1){
		perror(argv[2]);
		exit(2);
	}

	while(result = read(fd_src, buffer, sizeof(char)))
		write(fd_dst, buffer, sizeof(char));

	close(fd_src);
	close(fd_dst);

	return 0;
}
