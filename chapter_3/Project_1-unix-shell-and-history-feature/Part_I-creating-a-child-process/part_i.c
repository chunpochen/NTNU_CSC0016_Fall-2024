#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maxium length command */

void execute_command(char **args, int background) {
	pid_t pid = fork();
	
	if(pid < 0) {
		perror("Fork failed");
	}
	else if(pid == 0) {
		if(execvp(args[0], args) == -1) {
			perror("Execution failed");
		}
		exit(1);
	}
	else {
		if(!background) {
			wait(NULL);
			printf("Command completed.\n");
		}
		else {
			printf("Background process started with PID: %d\n", pid);
		}
	}
}

void parse_input(char *input, char **args, int *background) {
	char *token;	
	*background = 0;
	int i = 0;

	token = strtok(input, " \n");
	while(token != NULL) {
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	
	args[i] = NULL;
	if (i > 0 && strcmp(args[i-1], "&") == 0) {
		*background = 1;
		args[i-1] = NULL;
	}
}

int main(void) {
	char input[MAX_LINE];
	char *args[MAX_LINE/2 + 1];
	int should_run = 1;
	int background;

	while(should_run) {
		printf("osh>");
		fflush(stdout);

		if(fgets(input, MAX_LINE, stdin) == NULL) {
			perror("fgets failed");
			continue;
		}

		if(strcmp(input, "exit\n") == 0) {
			should_run = 0;
			continue;
		}

		parse_input(input, args, &background);

		if(args[0] != NULL) {
			execute_command(args, background);
		}
	}

	return 0;
}
