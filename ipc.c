#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>


void write_shared(void*shared_memory){
char buf[100];
printf("Enter data to be written..\n");
scanf("%[^\n]%*c",buf);
strcpy(shared_memory,buf);
}


int main(){
int shmid;
void *shared_memory;
shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
printf("key of shared memory: %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("process attached at shared memory: %p\n",shared_memory);
printf("writing into shared memory...\n");
write_shared(shared_memory);

}
