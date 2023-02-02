#include <stdio.h>
#include <stdlib.h>

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
	int min=proctable[0][1],v=0,ct=0,k=0,minidx,tat,wt;
	float ct_avg=0.0,tat_avg=0.0,wt_avg=0.0;
	
	for(int j=0;j<num;j++){
			if(proctable[j][1]<=min&& is_vis(visited_pid,proctable[j][0],v)==0){
				min=proctable[j][1];

				minidx=j;
			}
		}
	visited_pid[v++]=proctable[minidx][0];
	ct+=proctable[minidx][2];
	tat=ct-proctable[minidx][1];
	wt=tat-proctable[minidx][2];
	ct_avg+=(float)ct;
	tat_avg+=(float)tat;
	wt_avg+=(float)wt;
	printf("PID:%d \t CT:%d\t TAT:%d\t WT:%d\n",proctable[minidx][0],ct,tat,wt);
	
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
		tat=ct-proctable[minidx][1];
		wt=tat-proctable[minidx][2];
		ct_avg+=(float)ct;
		tat_avg+=(float)tat;
		wt_avg+=(float)wt;
		printf("PID:%d \t CT:%d\t TAT:%d\t WT:%d\n",proctable[minidx][0],ct,tat,wt);
		
	}
	printf("Average CT :%.2f \t Average TAT:%.2f \t Average WT:%.2f \n",ct_avg/(float)num,tat_avg/(float)num,wt_avg/(float)num);
	//for(int i=0;i<v;i++){
	//	printf("\n%d\t",visited_pid[i]);
	//}
	
}