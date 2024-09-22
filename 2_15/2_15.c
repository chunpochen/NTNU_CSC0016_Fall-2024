#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 512

int main() 
{
	char source[256], destination[256];
	int src, dest;
	ssize_t bytes_read, bytes_write;
	char buffer[BUFFER_SIZE];

	printf("Enter the source file name: ");
	scanf("%s", source);
	printf("Enter the destination file name: ");
	scanf("%s", destination);

	src = open(source, O_RDONLY);
	if(src < 0) 
	{
		perror("Error opening source file");
		exit(EXIT_FAILURE);
	}

	dest = open(destination, O_WRONLY | O_TRUNC, 0644);
	if(dest < 0) 
	{
		perror("Error opening/creating destination file");
		close(src);
		exit(EXIT_FAILURE);
	}

	while((bytes_read = read(src, buffer, BUFFER_SIZE)) > 0) 
	{
		bytes_write = write(dest, buffer, bytes_read);
		if(bytes_write != bytes_read)
		{
			perror("Error writing to destination file");
			close(src);
			close(dest);
			exit(EXIT_FAILURE);
		}	
	}

	printf("File copy completed.\n");
	return 0;
}
