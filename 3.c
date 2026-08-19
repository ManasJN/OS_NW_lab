#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int x,p,c;

	p=getpid();
	printf("The process id is %d \n",p);
	x=fork();
	
	if(x==0){
		printf("I got the value of x as 0\n");
	}

	else{
		wait(NULL);
		printf("I got the value of x as 1\n");
	}


	return 0;
}
