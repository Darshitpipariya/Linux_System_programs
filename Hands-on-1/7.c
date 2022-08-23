// Pipariya Darshitkumar
// MT2022035
/*
7. Write a program to copy file1 into file2 ($cp file1 file2).
*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(int argv,char *argc[]){
	int fd1=open(argc[1],O_RDONLY);
	if(fd1==-1){
		printf("Error while opening source file");
		close(fd1);
	}
	int fd2=open(argc[2],O_WRONLY|O_CREAT,S_IRWXU);
	if(fd2==-1){
		printf("Error while opening or creating destination file");
		close(fd2);
	}
	char content;
//	read one char at time &  
	while(read(fd1,&content,1)){
		write(fd2,&content,1);
	}
	printf("file copied");
	close(fd1);
	close(fd2);
	return 0;
}
