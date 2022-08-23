// Pipariya Darshitkumar
//  MT2022035

/*
write a program to execute ls -Rl by the following system calls
b. execlp
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
    // it will use environment variable PATH to run executable PATH .
    // it does not required entire file path as we did in execl().
    char *path = "ls";
    execlp(path, path, "-Rl", NULL);
    return 0;
}
