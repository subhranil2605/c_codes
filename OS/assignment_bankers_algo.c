/* ------------ Banker's Algorithm ------------ */ 
/* ------------ Subhranil Sarkar ------------ */ 
/* ------------ M.Sc. Data Science 1st Semester ------------ */ 
/* ------------ University of Kalyani ------------ */ 
/* ------------ 23rd March, 2022 ------------ */ 


#include<stdio.h>
void main() {
	int p, r;
	int i, j, k;
	int flag = 0;
	int c = 0;
	int m = 0;


	printf("\nNumber of Process:-\n");
	scanf("%d",&p);
	printf("\nNumber of Resource:-\n");
	scanf("%d",&r);

	int alloc[p][r];
	int max[p][r];
	int needed[p][r];
	int fin[p];
	int safep[p];
	int avail[r];
	int work[r];


	for(i = 0; i < p; i++) {
		fin[i] = 0;
		printf("\nEnter the Max allocation required by P %d:-\n", i);
		for(j = 0; j < r; j++) {
			printf("\n Resource R %d instances required are:- ", j);
			scanf("%d", &max[i][j]);
		}
	}


	for(i = 0; i < p; i++) {
		printf("\nEnter the Allocated resource of P %d:-\n",i);
		for(j = 0; j < r; j++)
		{
			printf("\n Resource R %d instances allocated are:- ",j);
			scanf("%d", &alloc[i][j]);
		}
	}
	printf("\nEnter the available resource left:-\n");

	for(j = 0; j < r; j++) {
		printf("\n Resource R %d :- ",j);
		scanf("%d", &avail[j]);
		work[j] = avail[j];
	}

	for(i = 0; i < p; i++) {
		for(j = 0; j < r; j++) {
			needed[i][j] = max[i][j]-alloc[i][j];
		}
	}

	for(k = 0; k < p; k++) {
		for(i = 0; i < p; i++) {
			if(fin[i] == 0) {
				for(j = 0; j < r; j++) {
					if(needed[i][j]<=work[j]) {
						c++;
					}
				}
				if(c == r) {
					safep[m] = i;
					m++;

					for(j = 0; j < r; j++){
						work[j] = work[j] + alloc[i][j];
					}

					fin[i]=1;
				}
				c = 0;
			}
		}
	}

	for(i = 0; i < p; i++) {
		if(fin[i] == 0) {
			flag = 1;
			break;
		}
	}

	
	if(flag != 1) {
		printf("\n The safe sequence of the entered system is:-\n");

		for(i = 0; i < p; i++) {
			printf("P%d ",safep[i]);
		}
	} else {
		printf("\nThe entered system is not safe\n");
	}
}