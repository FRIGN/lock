/* See LICENSE for licence details. */
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char **argv){
	if(argc != 2){
		fprintf(stderr, "Please supply one argument: the lock directory.\n");
		return EXIT_FAILURE;
	}

	/* create lock */
	if(mkdir(argv[1], S_IRUSR)){
		if(errno && errno != EEXIST) {
			fprintf(stderr, "Failed to create lock %s.\n", argv[1]);
			return EXIT_FAILURE;
		}
		/* lock exists */
		for(; mkdir(argv[1], S_IRUSR); ){
			sleep(1);
		}
	}	
	return EXIT_SUCCESS;
}
