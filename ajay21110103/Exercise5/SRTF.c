#include <stdio.h>
#include <stdlib.h>

void swap(int *a ,int *b){
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

int is_vis(int *vis,int pid,int vislen){
	for(int i=0;i<vislen;i++){if(pid==vis[i]){return 1;}}
	return 0;
}

void sort(int proc[][3],int len){
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


int min(int proc[][3],int start,int arrlen){
	int mins =proc[start][2];
	int i;
	int minidx;
	for(i=start;i<arrlen;i++){
		if(proc[i][2]<=mins){
			minidx=i;
			mins=proc[i][2];	
		}
	}
	return minidx;

}

int main(){
	int num,bt,at,pid;
	printf("Enter the number of Processes:"); 
	scanf("%d",&num);
	int proctable[num][3],n,min1=proctable[0][1],minidx;
	int dup[num][3];
	int vis[num];
	for(int i=0;i<num;i++){

		scanf("%d %d %d",&pid,&at ,&bt);
		dup[i][0]=pid;
		dup[i][1]=at;
		dup[i][2]=bt;
		proctable[i][0]=pid;
		proctable[i][1]=at;
		proctable[i][2]=bt;
	}
	sort(proctable,num);
	sort(dup,num);
	int proj_c=0;
	/*
	printf("\n");
	for(int i=0;i<num;i++){
		
			printf("%d %d %d \n",proctable[i][0],proctable[i][1],proctable[i][2]);

		
	}
	*/
	
	int v=0;
	int arr[num*num];
	int i=0,f=0,m;
	int ct=0,c_proj=0;
	int g=0;
	int zc=0;
	int ct1[num*num],mn;
	/*
	while(zc<num){
		printf("\n%d\n",ct);
		if(proctable[i][2]==0){
			zc++;i++;
			continue;
		}
		if(i==num){
			i=0;
			continue;
		}
		if(is_vis(vis,proctable[i][0],v)==0){
			vis[v++]=proctable[i][0];

			arr[g++]=proctable[i][0];
			
			if(proctable[i+1][2]<proctable[i][2]){
				ct+=proctable[i+1][1]-proctable[i][1];
				vis[v++]=proctable[i+1][0];
				proctable[i][2]-=(ct-proctable[i][1]);
				arr[g++]=proctable[i+1][0];

			}/*
			else{
				m=min(proctable,i+1,i+3);
				vis[v++]=proctable[m][0];
				ct+=proctable[m][1];
				arr[g++]=proctable[m][0];
			}*/
//		}
//		if(v==num){
//			ct+=proctable[i][2];
//			arr[g++]=proctable[i][0];
//			proctable[i][2]=0;
//		}
//		i++;

//	printf("%d",ct);
	//for(int i=0;i<g;i++){
		//printf("PID:%d \t CT :%d \t TAT:%d\t WT:%d \n",arr[i],ct1[i],ct1[i]-dup[arr[i]][1],(ct1[i]-dup[arr[i]][1])-dup[arr[i]][2]);
		//printf("%d\n",arr[i]);//
	//}
//
//}
	
	while(zc<num){
		//printf("\n%d\n",ct);
		//printf("PID:%d \t CT :%d \t TAT:%d\t WT:%d \n",proctable[i][0],ct-proctable[i][1]);
		if(proctable[i][2]==0){
			ct1[f++]=ct;
			zc++;
			i++;
			continue;
		}
		if(i==num){
			i=0;
			continue;
		}
		if(is_vis(vis,proctable[i][0],v)==1){
			ct1[f++]=ct;
			ct+=proctable[i][2];
			proctable[i][2]=0;

			arr[g++]=proctable[i][0];		
			i++;
			continue;
		}
		if(proctable[i+1][2]<proctable[i][2]){
			ct+=proctable[i+1][1]-proctable[i][1];
			proctable[i][2]--;
			arr[g++]=proctable[i][0];
			vis[v++]=proctable[i][0];
		}
		else{
			ct1[f++]=ct;
			ct+=proctable[i][2];
			arr[g++]=proctable[i][0];
			proctable[i][2]=0;
		}
		i++;
	}
	//printf("%d",ct);


	for(int i=0;i<g;i++){
		printf("PID:%d \t CT :%d \t TAT:%d\t WT:%d \n",arr[i],ct1[i],ct1[i]-dup[arr[i]][1],(ct1[i]-dup[arr[i]][1])-dup[arr[i]][2]);
		
	}


}
