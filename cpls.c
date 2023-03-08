#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<errno.h>
#include<string.h>
#define BUFFER_SIZE 1024
int main(int argc,char*argv[]){
    if(argc >= 2 && strcmp(argv[1],"cp")==0){
        FILE*fp1,*fp2;
        char buf[BUFFER_SIZE];
        fp1=fopen(argv[2],"r");
        fp2=fopen(argv[3],"w");
        while(fgets(buf,BUFFER_SIZE,fp1)!=NULL)
           fputs(buf,fp2);
    }
    else if(argc >= 2 && strcmp(argv[1],"ls")==0){
        DIR*p;
        struct dirent*d;
        p=opendir(argv[2]);
        if(p==NULL){
            perror("cannot find directory");
            exit(0);
        }
        while(d=readdir(p))
          printf("%s",d->d_name);
        printf("\n");
    }
    
}