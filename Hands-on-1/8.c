// Pipariya Darshitkumar
// MT2022035

/*
Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
int main(int argv,char *argc[]){
	int fd1=open(argc[1],O_RDONLY);
	if(fd1==-1){
		perror("Error while opening file");
		close(fd1);
	}
	char c,content[1024];
	int i=0;
	
	while(read(fd1,&content[i],1)){
		if(content[i]=='\n'){
			//content[i]='\n';
			printf("%s\n",content);
			memset(content, 0, i);
			i=0;
			
		}else{
		i++;
		}
	}
	close(fd1);
}
