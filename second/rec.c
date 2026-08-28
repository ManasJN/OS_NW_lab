#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(){
	char *tmp="/tmp/big",b[10];
	int p,i;
	p=mkfifo(tmp,0666);

	printf("%d\n",p);

	i=open(tmp,O_RDONLY);
	read(i,b,10);


	printf("recieved data:%s",b);

	return 0;

}
