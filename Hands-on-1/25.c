//  Pipariya Darshitkumar
// MT2022035

/*
Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
*/

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main()
{
    int i = 0, cid[3];
    while (i < 3)
    {
        cid[i] = fork();
        if (cid[i] == 0)
        {
            //code executed by child
            pause();//wait for signal
        }
        else
        {
            printf("for parent %d chile %d's pid is %d \n", getpid(), i + 1, cid[i]);
            i++;
        }
    }

    int id, status;
    printf("select the child for which you want parent to wait from 1to 3: ");
    scanf("%d", &id);
    waitpid(cid[id - 1], &status, 0);
    printf("child %d is exited\n",cid[id-1]);
    return 0;
}

// int main()
// {

//     int c1id, c2id, c3id, c_id;
//     int wstatus;
//     printf("Enter child for you want to wait range 1 to 3\n");
//     // scanf("%d", &c_id);
//     c_id = 3;
//     c1id = fork();
//     if (c1id == 0)
//     {
//         printf("parent pid: %d\n", getppid());
//         printf("child pid c1 pid : %d\n", getpid());
//         c2id = fork();
//         if (c2id == 0)
//         {
//             printf("parent c1 pid: %d\n", getppid());
//             printf("child c2  pid: %d\n", getpid());
//             c3id = fork();
//             if (c3id == 0)
//             {
//                 printf("parent c2 pid: %d\n", getppid());
//                 printf("child c3 pid: %d\n", getpid());
//             }
//             else
//             {
//                 sleep(10);
//                 if (c_id == 1)
//                 {
//                     waitpid(c1id, &wstatus, 0);
//                 }
//                 if (c_id == 3)
//                 {
//                     waitpid(c3id, &wstatus, 0);
//                 }
//                 if (c_id == 2)
//                 {
//                     waitpid(c2id, &wstatus, 0);
//                 }

//                 printf("parent pid: %d\n", getpid());
//             }
//         }
//         else
//         {
//             sleep(10);

//             printf("parent pid: %d\n", getpid());
//         }
//     }
//     else
//     {
//         sleep(10);

//         printf("parent pid: %d\n", getpid());
//     }

//     return 0;
// }
