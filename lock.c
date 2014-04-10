/* See LICENSE for licence details. */

#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char **argv){
	size_t pathlen, argvlen;
	char *path;

	if(argc != 2){
		fprintf(stderr, "Please supply one argument: the lock directory.\n");
		return EXIT_FAILURE;
	}

	if(access(argv[1], F_OK)){
		/* create lock */
		if(mkdir(argv[1], S_IRUSR | S_IXUSR)){
			fprintf(stderr, "Failed to create lock %s.\n", argv[1]);
			return EXIT_FAILURE;
		}
		return EXIT_SUCCESS;
	}
	
	/* prepare path */
	argvlen = strlen(argv[1]);
	pathlen = argvlen + sizeof("/..") + 1;
	path = malloc(pathlen);
	if(path == NULL) {
		fprintf(stderr, "Error: %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	
	memcpy(path, argv[1], argvlen);
	memcpy(path + argvlen, "/..\0", sizeof("/..") + 1);

	if(access(path, F_OK)){
		/* invalid lock */
		fprintf(stderr, "%s is not a lock directory.\n", argv[1]);
		free(path);
		return EXIT_FAILURE;
	}
	
	/* lock exists */
	for(; !access(path, F_OK) ;){
		sleep(1);
	}

	free(path);
	return EXIT_SUCCESS;
}
