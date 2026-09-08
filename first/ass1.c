//THIS VERSION IS USING A SINGLE PIPE AND IT WILL NOT GIVE US THE DESIRED OUTPUT

#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<limits.h>

int main(){
	int x,p,arr[2];

	p=pipe(arr);
	x=fork();
	
	if(p==0){
			
		if(x==0){

			//THIS IS CHILD SECTION
			
			printf("Value of x=0 and this is child\n");

			int a[]={1,2,3,4,5},res;
			write(arr[1],a,20);

			read(arr[0],&res,4);\
			printf("The recieved result is %d\n",res);
		}

		else{
			//THIS IS PARENT SECTION

			printf("Value of x!=0 and this is parent\n");

			int i,max=INT_MIN,b[20];
			read(arr[0],b,20);
			for(i=0;i<5;i++){
				if(b[i]>max){
					max=b[i];
				}
			}

			printf("The max element is %d\n",max);

			write(arr[1],&max,4);
		}
	}

	else{
		printf("The creation of pipe is unsuccessful");
	}

	return 0;
}
