#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#define BUF_SIZE 8192

int main(int argc, char *argv[]) {
	/* input and output file descriptors */
	int input_fd, output_fd;
	
	/* number of bytes return by read() and write() */
	ssize_t ret_in, ret_out;
	
	/* character buffer */
	char buffer[BUF_SIZE];

	/* check for number of arguments */
	if(argc != 3) {
		fprintf(stderr,
			"usage: cp src dest\n");
		return 1;
	}

	/* create input file descriptor */
	input_fd = open(argv[1], O_RDONLY);
	if(input_fd == -1) {
		perror("open");
		return 2;
	}

	/* create output file descriptor */
	output_fd = open(argv[2], O_WRONLY | O_CREAT, 0644);
	if(output_fd == -1) {
		perror("open");
		return 3;
	}

	/* copying process */
	while((ret_in = read(input_fd, &buffer, BUF_SIZE)) > 0) {
		ret_out = write(output_fd, &buffer, (ssize_t) ret_in);
		
		if(ret_out != ret_in) {
			perror("write");
			return 4;
		}
	}
	
	close(input_fd);
	close(output_fd);

	return EXIT_SUCCESS;
}
