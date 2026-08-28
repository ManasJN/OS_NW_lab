#include<stdio.h>
#include <unistd.h>

int main(){
	int x,p,c;

	p=getpid();
	printf("The process id is %d ",p);
	x=fork();
	
	if(x==0){
		printf("I am child x = 0\n");
	}

	else{
		printf("I am parent x != 0\n");
	}


	return 0;
}
