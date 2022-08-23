// Pipariya Darshitkumar
// MT2022035

/*
Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
*/
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
int main(int argv, char *argc[])
{
	int fd = open(argc[1], O_RDWR | O_CREAT, S_IRWXU);
	if (fd == -1)
	{
		perror("Error while opening file");
		close(fd);
		return 0;
	}
	char s[10] = "ABCDEFGHIJ";
	write(fd, s, 10);
	int o = lseek(fd, 10, SEEK_CUR);
	printf("%d\n", o);
	write(fd, s, 10);
	o = lseek(fd, 0, SEEK_CUR);
	printf("%d\n", o);
	return 0;
}
