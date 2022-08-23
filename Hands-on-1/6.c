// Pipariya Darshitkumar
// MT2022035

/*
Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
*/
#include<stdio.h>
#include<unistd.h>
int main(){
	char input_buffer[50];
	//0 is file descriptor for STDIN 
	// n will be the size of input that is read from STDIN
	int n=read(0,input_buffer,50);
	//1 is file descriptor for STDOUT
	write(1,input_buffer,n);
}
