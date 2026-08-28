#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(){
	char *tmp1="/tmp/first",*tmp2="/tmp/second";
	int i,k,b[5],p;

	p=mkfifo(tmp2,0666);

	if(p==0){
		i=open(tmp1,O_RDONLY);
		read(i,b,20);
	
		int j,max=b[0];
		for(j=0;j<5;j++){
			if(max<b[j]){
				max=b[j];
			}	
		}

		printf("maximum data:%d",max);
	
		k=open(tmp2,O_WRONLY);
		write(k,&max,4);
	}

	else{
		printf("error\n");
	}

	return 0;

}
