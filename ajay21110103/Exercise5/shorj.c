#include <stdio.h>
#include <stdlib.h>

int min(int proc[][3],int start,int arrlen){
	int mins =proc[start][1];
	int i;
	int minidx;
	for(i=start;i<arrlen;i++){
		if(proc[i][1]<=mins){
			minidx=i;
			mins=proc[i][1];
		}
	}
	return minidx;

}
int is_vis(int *vis,int pid,int vislen){
	for(int i=0;i<vislen;i++){if(pid==vis[i]){return 1;}}
	return 0;
}


int main(){
	int num,bt,at,pid;
	printf("Enter the number of Processes:"); 
	scanf("%d",&num);
	int proctable[num][3];
	for(int i=0;i<num;i++){

		scanf("%d %d %d",&pid,&at ,&bt);

		proctable[i][0]=pid;
		proctable[i][1]=at;
		proctable[i][2]=bt;
	}

	int visited_pid[num],n;
	int min=proctable[0][1],v=0,ct=0,k=0,minidx;
	for(int j=0;j<num;j++){
			if(proctable[j][1]<=min&& is_vis(visited_pid,proctable[j][0],v)==0){
				min=proctable[j][1];

				minidx=j;
			}
		}
	visited_pid[v++]=proctable[minidx][0];
	ct+=proctable[minidx][2];
	
	//for(int i=0;i<num;i++){
	while(v<num){
		
		min=10000;
		for( n=0;n<num;n++){
			if(proctable[n][1]<ct&&is_vis(visited_pid,proctable[n][0],v)==0 ){
					if(proctable[n][2]<min){
						min=proctable[n][2];
						minidx=n;
					}
			}
		}
		visited_pid[v++]=proctable[minidx][0];
		ct+=proctable[minidx][2];
		/*
		min=10000;
		for(int j=0;j<num;j++){
			if(proctable[j][1]<=ct&& is_vis(visited_pid,proctable[j][0],v)==0){
				if(proctable[j][2]<min){
				min=proctable[j][2];

				minidx=j;
			}
			}
		}
		visited_pid[v++]=proctable[minidx][0];
		ct+=proctable[minidx][2];
		*/
	}
	//}

	for(int i=0;i<v;i++){
		printf("\n%d\t",visited_pid[i]);
	}
	printf("\n%d",ct);
}