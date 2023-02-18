#include <stdio.h>
int is_all_zero(int arr[][3],int len){
	int flag=0;
	for(int i=0;i<len;i++){
		if(arr[i][2]<=0){
			flag++;
		}
	}
	if(flag>=len){
		return 1;
	}
	return 0;
}
void swap(int *a ,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
void sort(int proc[][3],int len){
	int tmp_pid,tmp_at,tmp_bt;
	for(int i=0;i<len;i++){
		for(int j=0;j<len-i-1;j++){
			if(proc[j][1]>proc[j+1][1]){
				
				swap(&proc[j][0],&proc[j+1][0]);
				swap(&proc[j][1],&proc[j+1][1]);
				swap(&proc[j][2],&proc[j+1][2]);
			
			}
		}
	}
	 
}

int main(){
	int pid,tq;
	printf("Enter NO of procs and time quantum: ");
	scanf("%d %d",&pid,&tq);
	int vis[pid*2],ctr=0;
	int et=0,at,bt,pc_no,i=0;
	int ct[pid];
	int proctable[pid][3],dup[pid][3];
	printf("Enter pid,At,BT\n");
	for(int i=0;i<pid;i++){
		scanf("%d %d %d",&pc_no,&at,&bt);
		proctable[i][0]=pc_no;
		proctable[i][1]=at;
		proctable[i][2]=bt;
		dup[i][0]=pc_no;
		dup[i][1]=at;
		dup[i][2]=bt;
	}
	printf("\ndone\n");
	sort(proctable,pid);
	sort(dup,pid);
	while (1){
		if(is_all_zero(proctable,pid)==1){
			break;
		}
		if(i>=pid){
			i=0;
			continue;
		}
		if(proctable[i][2]<=0){
			i++;
			continue;
		}
		
		if(et+tq>=proctable[i][1]){
			vis[ctr++]=proctable[i][0];

			proctable[i][2]-=tq;
			et+=tq;
			ct[i]=et;
			i++;
			
		}
		else{
			i=0;
			vis[ctr++]=proctable[i][0];
			//printf("%d\t",proctable[i][0]);
			//et+=proctable[i][1];
			ct[i]=et;
			i++;
		}
		
	}
	float tat,wt;
	for(int i=0;i<pid;i++){
		printf("%d\t %d \t %d \n",proctable[i][0],ct[i]-proctable[i][1],ct[i]-dup[i][2]);
		tat+=ct[i]-proctable[i][1];
		wt+=ct[i]-dup[i][2];
	}
	printf("\nAverage TAT :%.2f\nAverage WT:%.2f",tat/(float)pid,wt/(float)pid);
	

}
