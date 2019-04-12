
#include <time.h>

#include <stdlib.h>
#include <sys/sysmacros.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

int main( int argc, char **argv ) {

	struct stat staty;
	char pathHolder[PATH_MAX] = "";

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
	if (getcwd(pathHolder, sizeof(pathHolder) != NULL)){
		printf("current dir: %S\n", pathHolder);
	}
	return 0;
}
