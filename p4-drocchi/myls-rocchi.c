
#include <time.h>
#include <dirent.h>
#include <stdlib.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <string.h> 

int main( int argc, char **argv ) {

	struct stat staty;
	char pathHolder[PATH_MAX] = "";
	char path[PATH_MAX] = "";
	int printInfo = 0;

  DIR *current;
  struct dirent *dir;
	getcwd( pathHolder, PATH_MAX );
	//Establishes file to be read + whether or not to read file details
	switch(argc){
		case 1:
			current = opendir(".");
			break;
		case 2:
			if(strcmp( argv[1], "-1") == 0){
				printInfo = 1;
				current = opendir(".");
			} else{
				current = opendir(argv[1]);
			}
			break;
		case 3:
			if(strcmp( argv[1], "-1") == 0){
				printInfo = 1;
			}
			current = opendir(argv[2]);
			break;
	}

	//Print all files in a directory without extra information
  if (printInfo == 0){
		printf("All files in directory: \n");
		while ((dir = readdir(current)) != NULL){
				printf("%s\n", dir->d_name);
		}
		closedir(current);

	//Print all files in a directory with extra information
	} else{
		printf("All files in directory: \n");
		while ((dir = readdir(current)) != NULL){	

			printf("file name: %s\n", dir->d_name);

			if(stat(dir->d_name, &staty) == -1){
				printf("bad filepath. exiting\n");
				exit(EXIT_FAILURE);
			}

			
			printf("file size: %ld\n", (long) staty.st_size);
			printf("number of blocks allocated: %lld\n", (long long)staty.st_blocks);
			printf("reference link count: %ld\n", (long) staty.st_nlink);
			printf("file permissions: UID=%ld, GID=%ld\n", (long) staty.st_uid, (long)staty.st_gid);
			printf("file inode: %ld\n", (long) staty.st_ino);
			printf("file size in bytes: %ld\n\n", (long) dir->d_reclen);
		}

	}

	getcwd( pathHolder, PATH_MAX );
  printf("Current working dir: %s\n", pathHolder);


	return 0;
}
