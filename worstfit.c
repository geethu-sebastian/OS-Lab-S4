#include <stdio.h>
void implimentWorstFit(int blockSize[],int blocks,int processSize[],int processes)
{
    int allocation[processes];
    for(int i=0;i<processes;i++){
        allocation[i]=-1;
    }
    for(int i=0;i<processes;i++)
    {
      int indexPlaced=-1;
      for(int j=0;j<blocks;j++) 
      { 
        if(blockSize[j]>=processSize[i])
        {
           if(indexPlaced==-1)
             indexPlaced=j;
           else if(blockSize[indexPlaced]<blockSize[j])
                    indexPlaced=j;
        }
      }
      if(indexPlaced!=-1)
      {
        allocation[i]=indexPlaced;
        blockSize[indexPlaced]-=processSize[i];
      }
    }
 
    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for(int i=0;i<processes;i++)
    {
        printf("%d \t\t\t %d \t\t\t",i+1,processSize[i]);
        if(allocation[i]!= -1)
            printf("%d\n",allocation[i]+1);
        else
            printf("Not Allocated\n");
    }
}
int main()
{
    int blocks,processes;
    printf("Enter no.of blocks\n");
    scanf("%d",&blocks);
    int blockSize[blocks];
    printf("Enter size of blocks\n");
    for(int i=0;i<blocks;i++){
      scanf("%d",&blockSize[i]);
    }
    printf("Enter no.of processes\n");
    scanf("%d",&processes);
    int processSize[processes];
    printf("Enter size of processes\n");
    for(int i=0;i<processes;i++){
      scanf("%d",&processSize[i]);
    }
    implimentWorstFit(blockSize, blocks, processSize, processes);
    return 0 ;
}
