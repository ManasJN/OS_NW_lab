//THIS VERSION IS USING A TWO PIPES

#include<stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include<limits.h>

int main(){
	int x,p1,p2,arr1[2],arr2[2];

	p1=pipe(arr1);
	p2=pipe(arr2);
	x=fork();
	
	if(p1==0 && p2==0){
			
		if(x==0){

			//THIS IS CHILD SECTION
			
			printf("Value of x=0 and this is child\n");

			int a[]={21,27,98,1,53},res;
			write(arr1[1],a,20);

			read(arr2[0],&res,4);\
			printf("The recieved result at child is %d\n",res);
		}

		else{
			//THIS IS PARENT SECTION

			printf("Value of x!=0 and this is parent\n");

			int i,max=INT_MIN,b[20];
			read(arr1[0],b,20);
			for(i=0;i<5;i++){
				if(b[i]>max){
					max=b[i];
				}
			}

			printf("The max element is %d(calculated in parent)\n",max);

			write(arr2[1],&max,4);
		}
	}

	else{
		printf("The creation of pipe is unsuccessful");
	}

	return 0;
}
