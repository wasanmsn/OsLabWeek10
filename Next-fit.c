#include<stdio.h>
#define max 25

int main()
{
	int bsize[max], psize[max], bno, pno, flags[max], allocation[max],fragm[max], i, j=0;
 
	for(i = 0; i < max; i++)
	{
		flags[i] = 0;
		allocation[i] = -1;
		fragm[i] = 0;
	}
	
	printf("Enter no. of blocks: ");
	scanf("%d", &bno);
	
	printf("\nEnter size of each block:-\n");
	for(i = 0; i < bno; i++){
		printf("Block %d: ",i);
		scanf("%d", &bsize[i]);
	}
	
	printf("\nEnter no. of processes: ");
	scanf("%d", &pno);
	
	printf("\nEnter size of each process:-\n");
	for(i = 0; i < pno; i++){
		printf("Process %d: ",i);
		scanf("%d", &psize[i]);
	}
	
	//Loop for all process
	for(i = 0 ; i < pno ; i++){  
		while(j < bno){
			
			//Detect the size of block is larger than the size of process.   
			if(bsize[j]>=psize[i])
			{
				
				//Allocate the process to block
				allocation[i] = j;
				
				flags[i] = 1;
				
				//Calculating Fragment
				bsize[j] -= psize[i];
				break;
			}
			j=(j+1)%bno;
		}
		
	}
	
	//display allocation details
	printf("\nBlock no.\t\tprocess no.\t\tPsize");
	for(i = 0; i < bno; i++)
	{
		printf("\n%d\t\t\t", i);
		if(flags[i] == 1)
			printf("%d\t\t\t%d",allocation[i],psize[allocation[i]]);
		else
			printf("Not allocated");
	}
	return 0;
}
