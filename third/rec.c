#include<stdio.h>
#include<sys/msg.h>
#include<string.h>

struct msgbuf{
	long m;
	char textmsg[20];
};

int main(){
	int x,k;
	key_t key=24419;
	x=msgget(key,IPC_CREAT|0666);	
	
	if(x>0){
		printf("\n Successfully Created");

		struct msgbuf s;
		s.m=34;
			
		k=msgrcv(x,(void *)&s,20,34,IPC_NOWAIT);	
		
		if(k>=0){
			printf("\nThe recieved msg is:%s",s.textmsg);
		}
	}
	else{
		printf("\n We have an error");
	}

	return 0;
}
