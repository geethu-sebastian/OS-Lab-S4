#include<stdio.h>
#include<string.h>

int main(){
    char fn[10],pat[10],temp[1000];
    FILE*fp;
    printf("Enter file name");
    scanf("%s",fn);
    printf("Enter the pattern");
    scanf("%s",pat);
    fp=fopen(fn,"r");
    while(!feof(fp)){
        fgets(temp,1000,fp);
        if(strcmp(temp,pat))
          printf("%s",temp);
    }
    fclose(fp);
    return 1;
}