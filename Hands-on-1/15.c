// Pipariya Darshitkumar
// MT2022035

/*
Write a program to display the environmental variable of the user (use environ).
*/
#include <stdio.h>
#include <unistd.h>
extern char **environ;
void main()
{
    printf("%s\n", *environ);
    environ += 51;
    printf("%s\n", *environ);
}