#include <stdio.h>
#include <stdlib.h>
/*
Implementation of FCFS Scheduling 
Works for Even Delay Arrival Process
Usage Whatever you begin with is your serialised ordered process ie.. first one is P1 
you can give whatever burst time and arrival time it should be good to go
*/
void swap(int *a ,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}


int min(int proc[][2],int start,int arrlen){
	int mins =proc[start][0];
	int i;
	int minidx;
	for(i=start;i<arrlen;i++){
		if(proc[i][0]<=mins){
			minidx=i;
			mins=proc[i][0];	
		}
	}
	return minidx;

}



int main(){
	int num,bt,at;
	printf("Enter the number of Processes:"); 
	scanf("%d",&num);
	int proctable[num][2];
	int dup[num][2];
	for(int i=0;i<num;i++){

		scanf("%d %d",&at ,&bt);
		proctable[i][0]=at;
		proctable[i][1]=bt;
		dup[i][0]=at;
		dup[i][1]=bt;
	}
	int  idx;
	int idxarr[num];
	int ct=0;
	for (int i=0;i<num;i++){

		idx=min(proctable,i,num);
	
		idxarr[ct++]=idx;
		
		swap(&proctable[i][0],&proctable[idx][0]);
		swap(&proctable[i][1],&proctable[idx][1]);

	}
	int ct1=0,k;
	for(int i=0;i<num;i++){
		printf("%d %d\n",dup[idxarr[i]][0],dup[idxarr[i]][1]);
		if(dup[idxarr[i]][0]>ct){
			k=dup[idxarr[i]][0]-ct+dup[idxarr[i]][1];
			ct1+=k;
		}
		else{
			k=dup[idxarr[i]][1];
			ct1+=k;
		}
		printf( "Completion Time : %d\n",ct1);
		swap(&dup[i][0],&dup[idxarr[i]][0]);
		swap(&dup[i][1],&dup[idxarr[i]][1]);
	}
	
}
