// Pipariya Darshitkumar
// MT2022035

/*
Write a program to perform mandatory locking.
a. Implement write lock
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argv, char *argc[])
{
    int fd = open(argc[1], O_WRONLY);
    if (fd == -1)
    {
        printf("Error while opening file");
    }
    struct flock lock = {F_WRLCK,0,0,0,0}; // set write_lock type to flock instance lock.
    fcntl(fd, F_SETLKW, &lock);
    printf("File is locked.\npress enter to unlock file\n");
    getchar();
    lock.l_type = F_UNLCK; // change lock type to unlock to unlock file
    fcntl(fd, F_SETLKW, &lock);
    return 0; 
}