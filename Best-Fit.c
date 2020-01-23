#include<stdio.h>
#define max 25

int main()
{
	int bsize[max], psize[max], bno, pno, flags[max], allocation[max],parray[max],fragm[max], i, j, temp,lowest=9999;
 
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
	
	for(i = 0; i < pno; i++){         
		for(j = 0; j < bno; j++){
			
			//Detect the size of block is larger than the size of process.
			if(bsize[j]>psize[i])
			{
				//Calculate the size between block and process
				temp=bsize[j]-psize[i];
				
				
				if(temp>=0){ 
					if(lowest>temp)
					{
						//Assign the current block
						
						parray[i]=j;
							printf("\nIt is %d",parray[i]);
						
						lowest=temp;
					}
				}
			}
		}
		//Allocate the current process to block
		allocation[parray[i]]= i;
		
		flags[parray[i]] = 1;
		
		//Calculating Fragment
		fragm[i]=bsize[parray[i]]-psize[i];
		lowest=9999;
	}
	
	//display allocation details
	printf("\nBlock no.\tBsize\t\tprocess no.\t\tPsize\tFragment");
	for(i = 0; i < bno; i++)
	{
		printf("\n%d\t\t%d\t\t", i, bsize[i]);
		if(flags[i] == 1)
			printf("%d\t\t\t%d\t%d",allocation[i],psize[allocation[i]],fragm[i]);
		else
			printf("Not allocated");
	}
	return 0;
}
