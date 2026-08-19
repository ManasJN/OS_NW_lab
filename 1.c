#include<stdio.h>
#include <unistd.h>

int main(){
	int x;

	x=fork();
	
	if(x==0){
		printf("I got the value of x as 0\n");
	}

	else{
		printf("I got the value of x as 1\n");
	}


	return 0;
}
