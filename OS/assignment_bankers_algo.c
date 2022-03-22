//Banker's Algorithm

#include<stdio.h>
void main()
{
	int nop,nor,i,j,flag=0,k,m=0,count=0;
	printf("\nPlease enter the number of PROCESS:-\n");
	scanf("%d",&nop);
	printf("\nPlease enter the number of RESOURCE:-\n");
	scanf("%d",&nor);
	int alloc[nop][nor];
	int max[nop][nor];
	int needed[nop][nor];
	int fin[nop];
	int safep[nop];
	int avail[nor];
	int work[nor];
	for(i=0;i<nop;i++)
	{
		fin[i]=0;
		printf("\nEnter the Max allocation required by P %d:-\n",i);
		for(j=0;j<nor;j++)
		{
			printf("\n Resource R %d instances required are:- ",j);
			scanf("%d",&max[i][j]);
		}
	}
	for(i=0;i<nop;i++)
	{
		printf("\nEnter the Allocated resource of P %d:-\n",i);
		for(j=0;j<nor;j++)
		{
			printf("\n Resource R %d instances allocated are:- ",j);
			scanf("%d",&alloc[i][j]);
		}
	}
	printf("\nEnter the available resource left:-\n");
	for(j=0;j<nor;j++)
	{
		printf("\n Resource R %d :- ",j);
		scanf("%d",&avail[j]);
		work[j] = avail[j];
	}
	for(i=0;i<nop;i++)
	{
		for(j=0;j<nor;j++)
		{
			needed[i][j] = max[i][j]-alloc[i][j];
		}
	}
	for(k=0;k<nop;k++)
	{
		for(i=0;i<nop;i++)
		{
			if(fin[i] == 0)
			{
				for(j = 0; j<nor;j++)
				{
					if(needed[i][j]<=work[j])
					{
						count=count+1;
					}
				}
				if(count == nor)
				{
					safep[m] = i;
					m++;
					for(j = 0; j<nor;j++)
					{
						work[j] = work[j] + alloc[i][j];
					}
					fin[i]=1;
				}
				count = 0;
			}
		}
	}
	for(i=0;i<nop;i++)
	{
		if(fin[i] == 0)
		{
			flag=1;
			break;
		}
	}
	if(flag != 1)
	{
		printf("\n The safe sequence of the entered system is:-\n");
		for(i=0;i<nop;i++)
		{
			printf("P%d ",safep[i]);
		}
	}
	else
	{
		printf("\nThe entered system is not safe\n");
	}
	
}