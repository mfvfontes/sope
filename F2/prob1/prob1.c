#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_LENGTH 20

int main(){

	struct termios oldterm, newterm;

	char password[MAX_LENGTH + 1], ch, echo = '*';

	int i = 0;

	write(STDOUT_FILENO, "Password ?", strlen("Password ?"));

	tcgetattr(STDIN_FILENO, &oldterm);
	newterm = oldterm;
	newterm.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH,  &newterm);

	while(read(STDIN_FILENO, &ch, 1) > 0 && ch != '\n' && i < MAX_LENGTH){
		password[i] = ch;
		i++;
		write(STDOUT_FILENO, &echo, 1);
	}
	
	password[i] = '\0';

	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, password, strlen(password));
	write(STDOUT_FILENO, "\n", 1);

	tcsetattr(STDIN_FILENO, TCSAFLUSH, &oldterm);

	return 0;

}
