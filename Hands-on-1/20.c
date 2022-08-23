// Pipariya Darshitkumar
// MT2022035
/*
Find out the priority of your running program. Modify the priority with nice command
*/
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/resource.h>
int main()
{
    int id ;
    scanf("%d",&id);
    printf("nice value = %d\n", getpriority(PRIO_PROCESS, id));
    printf("priority =%d\n", (20+getpriority(PRIO_PROCESS, id)));
    return 0;
}