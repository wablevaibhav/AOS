#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/stat.h>
int main(int argc, char *argv[])
{
	struct stat info;
	if(argc != 2) 
	{
		printf("Enter the filename \n");
		exit(EXIT_FAILURE);
	}
	if(stat(argv[1],&info) == -1)
	{
		printf("Stat error \n");
		exit(EXIT_FAILURE);
	}
	printf("Inode Number = %d \n", info.st_ino);
	printf("Size = %d \n", (long)info.st_size);
	printf("Last file access = %s \n", ctime(&info.st_atime));
	printf("Notification time = %s \n",ctime(&info.st_mtime));
	printf("No of hardlink = %d \n", info.st_nlink);
	printf("File permissions: \n");
	printf((info.st_mode & S_IRUSR)?"r":"-");
	printf((info.st_mode & S_IWUSR)?"w":"-");
	printf((info.st_mode & S_IXUSR)?"x":"-");
	printf((info.st_mode & S_IRGRP)?"r":"-");
	printf((info.st_mode & S_IWGRP)?"w":"-");
	printf((info.st_mode & S_IXGRP)?"x":"-");
	printf((info.st_mode & S_IROTH)?"r":"-");
	printf((info.st_mode & S_IWOTH)?"w":"-");
	printf((info.st_mode & S_IXOTH)?"x":"-");
}
