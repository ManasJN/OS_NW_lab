#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(){
	char *tmp1="/tmp/first",*tmp2="/tmp/second";
	int p,i,k,res;
	p=mkfifo(tmp1,0666);
	printf("%d\n",p);
		
	if(p==0){
		i=open(tmp1,O_WRONLY);
		int a[5]={1,2,3,4,5};
		write(i,a,20);
		
		k=open(tmp2,O_RDONLY);
		read(k,&res,4);

		printf("The recieved max value:%d\n",res);
	}

	else{
		printf("error\n");
	}
	return 0;

}
