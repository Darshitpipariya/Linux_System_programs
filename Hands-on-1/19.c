// Pipariya Darshitkumar
//  MT2022035

/*
Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

// using time stamp counter
unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc": "=A"(dst));
    return dst;
}

void main()
{
    long long int start, end;

    start = rdtsc();

    printf("Process id: %d\n", getpid());

    end = rdtsc();

    printf("Difference is : %llu\n", end - start);
}

// without time stamp counter
/*

#include<stdio.h>
#include<sys/time.h>
void main(){
    struct timeval start , end;
    gettimeofday(&start,0);//second arg is time zone code but as we need time interval it doesn't matter

    printf("Process id: %d\n",getpid());

    gettimeofday(&end,0);

    long second=end.tv_sec-start.tv_sec;
    long microsecond=end.tv_usec-start.tv_usec;
    double time_interval= second + microsecond*1e-6;

    printf("Difference is : %.3f\n",time_interval);

}

*/