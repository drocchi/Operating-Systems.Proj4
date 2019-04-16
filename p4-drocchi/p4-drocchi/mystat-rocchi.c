#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <sys/types.h>


int main( int argc, char **argv ) {

	struct stat staty;

	if(stat(argv[1], &staty) == -1){
		printf("bad filepath. exiting\n");
		exit(EXIT_FAILURE);
	}
	printf("%s\n", argv[1]);
	printf("file size: %ld\n", (long) staty.st_size);
	printf("number of blocks allocated: %lld\n", (long long)staty.st_blocks);
	printf("reference link count: %ld\n", (long) staty.st_nlink);
	printf("file permissions: UID=%ld, GID=%ld\n", (long) staty.st_uid, (long)staty.st_gid);
	printf("file inode: %ld\n", (long) staty.st_ino);

	return 0;
}
