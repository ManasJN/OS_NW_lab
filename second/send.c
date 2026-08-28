#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(){
	char *tmp="/tmp/big",a[10];
	int p,i;
	p=mkfifo(tmp,0666);
	printf("%d\n",p);
	if(p==0){
		i=open(tmp,O_WRONLY);
		printf("\n enter the string");
		scanf("%s",a);
		write(i,a,strlen(a));
	}
	else{
		printf("\nerror");
	}


	return 0;

}
