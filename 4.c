#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
	int x,p,arr[2];

	p=pipe(arr);
	x=fork();
	
	if(p==0){

		if(x==0){
			printf("Value of x is 0 and this is child\n");

			char a[]="CSE";
			write(arr[1],a,4);
		}

		else{
			printf("Value of x is not 0 and this is parent\n");

			char b[4];
			read(arr[0],b,4);
			printf("I got the info as:%s\n",b);
		}
	}

	else{
		printf("The creation of pipe is unsuccessful");
	}

	return 0;
}
