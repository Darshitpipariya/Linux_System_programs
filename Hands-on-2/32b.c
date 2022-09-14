// Question : Write a program to implement semaphore to protect any critical section - Rewrite the ticket number creation program using semaphore

#include <sys/ipc.h>   // Import for `ftok`, `semget`, `semctl`
#include <sys/sem.h>   // Import for `semget`, `semctl`
#include <sys/types.h> // Import for `open`, `lseek`, `ftok`, `semget`, `semctl`
#include <stdio.h>     // Import for `perror` & `printf`
#include <sys/shm.h>
#include<unistd.h>
void main()
{
    key_t shaKey=ftok(".",666);
    int shmid=shmget(shaKey,1024,IPC_CREAT|0744); // Semaphore Identifier
    char *shmPointer;
    shmPointer=shmat(shmid,(void *)0,0);
    key_t semKey;      // Semaphore Key
    int semIdentifier; // Semaphore Identifier
    int semctlStatus;  // Determines success of `semctl` call
    int semopStatus;   // Determines success of `semop` call


    // Defines a semaphore's structure
    union semun
    {
        int val;               // Value of the semaphore
        struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
        unsigned short *array; /* Array for GETALL, SETALL */
        struct seminfo *__buf; /* Buffer for IPC_INFO (Linux-specific) */
    } semSet;


    // semaphore key
    semKey = ftok(".", 332);
    if (semKey == -1)
    {
        perror("Error while computing key!");
        _exit(1);
    }

    semIdentifier = semget(semKey, 1, 0); // Get the semaphore if it exists
    if (semIdentifier == -1)
    {
        semIdentifier = semget(semKey, 1, IPC_CREAT | 0700); // Create a new semaphore
        if (semIdentifier == -1)
        {
            perror("Error while creating semaphore!");
            _exit(1);
        }

        semSet.val = 1; // Set a binary semaphore
        semctlStatus = semctl(semIdentifier, 0, SETVAL, semSet);
        if (semctlStatus == -1)
        {
            perror("Error while initializing a binary sempahore!");
            _exit(1);
        }
    }

    struct sembuf semOp; // Defines the operation on the semaphore
    semOp.sem_num = 0;
    semOp.sem_flg = 0;

    printf("Press enter to obtain lock on the critical section\n");
    // getchar();
    // Use semaphore to lock the critical section
    semOp.sem_op = -1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }

    printf("Obtained lock on critical section!\n");
    printf("Now entering critical section!\n");
    // =========== Start of Critical Section ===========
    
    printf("write in shared memory\n");
    scanf("%[^\n]", shmPointer);
    printf("data from shared memory : %s\n", shmPointer);
    printf("Press enter to exit from critical section!\n");

    // =========== End of Critical Section =============

    // Use semaphore to unlock the critical section
    semOp.sem_op = 1;
    semopStatus = semop(semIdentifier, &semOp, 1);
    if (semopStatus == -1)
    {
        perror("Error while operating on semaphore!");
        _exit(1);
    }
}