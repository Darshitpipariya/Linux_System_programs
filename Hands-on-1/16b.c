// Pipariya Darshitkumar
// MT2022035

/*
Write a program to perform mandatory locking.
b. Implement read lock
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argv, char *argc[])
{
    int fd = open(argc[1], O_RDONLY);
    if (fd == -1)
    {
        printf("Error while opening file");
    }
    struct flock lock = {F_RDLCK, 0, 0, 0, 0}; // set read_lock type to flock instance lock.
    fcntl(fd, F_SETLKW, &lock);
    printf("File is locked.\npress enter to unlock file\n");
    getchar();
    lock.l_type = F_ULOCK; // change lock type to unlock to unlock file
    fcntl(fd, F_SETLKW, &lock);
    return 0;
}