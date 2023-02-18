#include <stdio.h>

int  main()
{
	
	int pid,tq;
	printf("Enter NO of procs:");
	scanf("%d",&pid);
	int vis[pid],ctr=0;
	int et=0,at,bt,pc_no;
	int ct[pid],priority;
	int proctable[pid][4],dup[pid][3];
	printf("Enter pid,At,BT,priority\n");
	for(int i=0;i<pid;i++){
		scanf("%d %d %d %d",&pc_no,&at,&bt,&priority);
		proctable[i][0]=pc_no;
		proctable[i][1]=at;
		proctable[i][2]=bt;
		proctable[i][3]=priority;
	}
	printf("\ndone\n");
	int i=0,tt=0,j,j_pri;
	float tat=0,wt=0;
	for(int i=0;i<pid;i++){
		vis[i]=0;
	}
	for(i=0;i<pid;i++){
	    j=-2,j_pri=123123412;
		for(int k=0;k<pid;k++){
			/*find k index using priorty if not found and iff within total arr time*/
			if(proctable[k][1]<=tt && !vis[k]){
				if(proctable[k][3]<j_pri){
					j_pri=proctable[k][3];
					j=k;
				}
			}
		}
		tt+=proctable[i][2];
		printf("%d %d %d %d\n",proctable[i][0],tt,tt-proctable[i][1],tt-proctable[i][2]);
		tat+=tt-proctable[i][1];
		wt+=tt-proctable[i][2];
		vis[j]=1;
	}
	printf("Average TAT:%.2f\nAverage WT:%.2f\n",tat/(float)pid,wt/(float)pid);

}