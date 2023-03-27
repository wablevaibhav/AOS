#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/stat.h>
#include<fcntl.h>
int main(int argc, char *argv[])
{
	int file = 0;
	struct stat fst;
	if((file = open(argv[1], O_RDONLY)) < -1) 
	{
		return 1;
	}
	if(fstat(file,&fst) < 0)
	{
		return 1;
	}
	printf("Inode Number = %d \n", fst.st_ino);
	printf("Size = %d \n", (long)fst.st_size);
	printf("Last file access = %s \n", ctime(&fst.st_atime));
	printf("Notification time = %s \n",ctime(&fst.st_mtime));
	printf("No of hardlink = %d \n", fst.st_nlink);
	printf("File permissions: \n");
	printf((fst.st_mode & S_IRUSR)?"r":"-");
	printf((fst.st_mode & S_IWUSR)?"w":"-");
	printf((fst.st_mode & S_IXUSR)?"x":"-");
	printf((fst.st_mode & S_IRGRP)?"r":"-");
	printf((fst.st_mode & S_IWGRP)?"w":"-");
	printf((fst.st_mode & S_IXGRP)?"x":"-");
	printf((fst.st_mode & S_IROTH)?"r":"-");
	printf((fst.st_mode & S_IWOTH)?"w":"-");
	printf((fst.st_mode & S_IXOTH)?"x":"-");
}
