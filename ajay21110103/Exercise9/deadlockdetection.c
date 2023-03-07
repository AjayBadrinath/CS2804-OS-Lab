#include <stdio.h>
int main(){
int n_res,tmp,n_proc;
scanf("%d %d",&n_res,&n_proc);
int m=0;
int allocation_matrix[n_proc][n_res],request[n_proc][n_res],available[n_proc][n_res];
printf("Enter The Allocation Matrix\n");
for(int i=0;i<n_proc;i++){
	for(int j=0;j<n_res;j++){
		scanf("%d",&tmp);
		allocation_matrix[i][j]=tmp;
	}
}
printf("Enter The Request Matrix\n");


for(int i=0;i<n_proc;i++){
	for(int j=0;j<n_res;j++){
		scanf("%d",&tmp);
		request[i][j]=tmp;
	}
}
printf("Enter Available instances of Resources: \n");
for(int i=0;i<n_res;i++){
	scanf("%d",&tmp);
	available[0][i]=tmp;
}
int f1=0,f2=0,f3=0;
int avl_cp[1][n_res];
while(m<n_proc){
	for(int j=0;j<n_proc;j++){
		for(int k=0;k<n_res;k++){
			if(available[0][k]>=request[j][k] ){f1++;}
			else{break;}
		}
		if(f1==3){
			f1=0;
			f2=1;
			for(int p=0;p<n_res;p++){
				request[j][p]=10203123;
			}
			for(int o=0;o<n_res;o++){
				avl_cp[0][o]=available[0][o];
			}
//			printf("%d\n",j);
			m++;
			for(int l=0;l<n_res;l++){
				available[0][l]=avl_cp[0][l]+allocation_matrix[j][l];
			}
		}
	}
	if(f2!=1){
		printf("[-]DeadLock Detected : No Safe Sequence Possible\n");
		return -1;
	}
	f2=0;
}
printf("[+]No Deadlocks Detected: Safe Sequence Possible\n");
return 1;
}
