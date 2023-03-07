#include <stdio.h>
int main(){
int n_res,tmp,n_proc;
scanf("%d %d",&n_res,&n_proc);
int given[1][n_res],m=0;
int allocation_matrix[n_proc][n_res],max[n_proc][n_res],available[n_proc][n_res],need[n_proc][n_res];
int vis[n_proc];
for(int i=0;i<n_res;i++){
	scanf("%d",&tmp);
	given[0][i]=tmp;
}
printf("Enter The Allocation Matrix\n");
for(int i=0;i<n_proc;i++){
	for(int j=0;j<n_res;j++){
		scanf("%d",&tmp);
		allocation_matrix[i][j]=tmp;
	}
}

printf("Enter The Maximum Matrix\n");


for(int i=0;i<n_proc;i++){
	for(int j=0;j<n_res;j++){
		scanf("%d",&tmp);
		max[i][j]=tmp;
	}
}

for(int i=0;i<n_proc;i++){
	for(int j=0;j<n_res;j++){
		need[i][j]=max[i][j]-allocation_matrix[i][j];
	}

}

for(int i=0;i<n_proc;i++){
	for(int j=0;j<n_res;j++){
		printf("%d\t",need[i][j]);
	}
	printf("\n");
}


for(int i=0;i<n_res;i++){
	scanf("%d",&tmp);
	available[0][i]=tmp;
}
int f1=0,f2=0,f3=0;
int avl_cp[1][n_res];
//for(int i=0;i<n_proc;i++){
while(m<n_proc){
	for(int j=0;j<n_proc;j++){
		for(int k=0;k<n_res;k++){
			if(available[0][k]>=need[j][k] ){f1++;}
			else{break;}
		}
		if(f1==3){
			f1=0;
			f2=1;
			for(int p=0;p<n_res;p++){
				need[j][p]=10203123;
			}
			for(int o=0;o<n_res;o++){
				avl_cp[0][o]=available[0][o];
			}
//			printf("%d\n",j);
			vis[m++]=j;
			for(int l=0;l<n_res;l++){
				available[0][l]=avl_cp[0][l]+allocation_matrix[j][l];
			}
		}
	}
	if(f2!=1){
		printf("No Safe Sequence Possible\n");
		return -1;
	}
}
printf("Safe Sequence :<");
for(int i=0;i<n_proc;i++){printf("%d\t",vis[i]);}
printf(">\n");
return 1;
}
















