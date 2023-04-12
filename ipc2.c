#include<stdio.h>
#include<sys/shm.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

void read_shared(void*shared_memory){
printf("you wrote--%s\n",(char*)shared_memory);
}

int main(){
int shmid;
void *shared_memory;
shmid=shmget((key_t)2345,1024,0666|IPC_CREAT);
printf("key of shared memory: %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("process attached at shared memory: %p\n",shared_memory);

printf("reading from shared memory...\n");
read_shared(shared_memory);
}
