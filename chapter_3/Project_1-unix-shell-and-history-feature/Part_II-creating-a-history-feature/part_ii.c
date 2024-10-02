#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_LINE 80 /* The maxium length command */
#define MAX_HISTORY 10 /* The maxium history command */

char history[MAX_HISTORY][MAX_LINE];
int history_count = 0;

void parse_input(char *input, char **args, int *background);
void execute_command(char **args, int background);
void add_to_history(char *input);
void print_history(void);
int handle_history_command(char *input, char **args, int *background);

void print_history() 
{
	int start;
	if (history_count > MAX_HISTORY)
		start = history_count - MAX_HISTORY;
	else
		start = 0;
	
 	int i;   	
	for (i = start; i < history_count; i++)
        	printf("%d %s\n", i + 1, history[i % MAX_HISTORY]);
}


void add_to_history(char *input) 
{
	input[strcspn(input, "\n")] = 0;
	strcpy(history[history_count % MAX_HISTORY], input);
	history_count++;
}


int handle_history_command(char *input, char **args, int *background) 
{
	if (input[0] == '!') {
		if (input[1] == '!') {
			if (history_count == 0) {
				printf("No commands in history.\n");
				return 1;
            		}
			
			strcpy(input, history[(history_count - 1) % MAX_HISTORY]);
			printf("%s\n", input);
		} 
		else {
			int command_number = atoi(&input[1]);
			if (command_number < 1 || command_number > history_count) {
				printf("No such command in history.\n");
				return 1;
			}
			
			strcpy(input, history[(command_number - 1) % MAX_HISTORY]);
			printf("%s\n", input);
		}
		parse_input(input, args, background);
		return 0;
	}
	return 1;
}


void parse_input(char *input, char **args, int *background) {
	char *token;
	*background = 0;
	int i = 0;
    
	token = strtok(input, " \n");
	while (token != NULL) {
		args[i++] = token;
		token = strtok(NULL, " \n");
	}
	args[i] = NULL;

	if (i > 0 && strcmp(args[i-1], "&") == 0) {
		*background = 1;
		args[i-1] = NULL;
	}
}


void execute_command(char **args, int background) {
	pid_t pid = fork();

	if (pid < 0)
		perror("Fork failed"); 

	else if (pid == 0) {
		if (execvp(args[0], args) == -1)
			perror("Execution failed");
		exit(1);
	} 
	else {
		if (!background) 
			wait(NULL);
    	}
}

int main(void) 
{
	char input[MAX_LINE];
	char *args[MAX_LINE/2 + 1];
	int should_run = 1;
	int background;

	while (should_run) {
		printf("osh> ");
		fflush(stdout);
		
		if (fgets(input, MAX_LINE, stdin) == NULL) {
			perror("fgets failed");
			continue;
		}

		input[strcspn(input, "\n")] = 0;		

		if (strcmp(input, "history") == 0) {
			print_history();
			continue;
		}

		if(!handle_history_command(input, args, &background)) {
			execute_command(args, background);
			continue;
		}

		add_to_history(input);

		parse_input(input, args, &background);

		if(args[0] != NULL)
			execute_command(args, background);
	}
	return 0;
}
