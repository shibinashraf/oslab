
#include<stdio.h>
 
void main()
{
int blocksize[10], processsize[10], bno, pno, flag[10], allocation[10], i,j;
 
for(i = 0; i < 10; i++)
{
flag[i] = 0;
allocation[i] = -1;
}
printf("Enter no. of blocks: ");
scanf("%d", &bno);
printf("\nEnter size of each block: ");
for(i = 0; i < bno; i++)
scanf("%d", &blocksize[i]);
 
printf("\nEnter no. of processes: ");
scanf("%d", &pno);
printf("\nEnter size of each process: ");
for(i = 0; i < pno; i++)
scanf("%d", &processsize[i]);
for(i = 0; i < pno; i++)        
for(j = 0; j < bno; j++)
if(flag[j] == 0 && blocksize[j] >= processsize[i])
{
allocation[j] = i;
flag[j] = 1;
break;
}
printf("\nBlock no.\tsize\t\tprocess no.\t\tsize");
for(i = 0; i < bno; i++)
{
printf("\n%d\t\t%d\t\t", i+1, blocksize[i]);
if(flag[i] == 1)
printf("%d\t\t\t%d",allocation[i]+1,processsize[allocation[i]]);
else
printf("Not allocated");
}
}
