// Pipariya Darshitkumar
// MT2022035

/*
hard link (link system call)
*/
#include<unistd.h>
#include<stdio.h>
int main(int argc,char *argv[]){
	//hardLink
	int o=link(argv[1],argv[2]);
	if(o==0)
	{	
		printf("HardLink created succesfully\n");
	}
	return 0;
}
