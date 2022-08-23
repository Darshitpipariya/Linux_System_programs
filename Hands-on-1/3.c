// Pipariya Darshitkumar
// MT2022035

/*
Write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/
#include<stdio.h>
#include<sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc,char *argv[]){
	int o=creat(argv[1],S_IRWXU);
	printf("%d\n",o);
	return 0;
}
