// Pipariya Darshitkumar
// MT2022035

/*Write a program to open an existing file with read write mode. Try O_EXCL flag also.
 */
#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argv,char *argc[])
{
	int o=open(argc[1],O_RDWR);
	printf("%d \n",o);
	int e=open(argc[1],O_EXCL);
	printf("%d \n",e);
}
