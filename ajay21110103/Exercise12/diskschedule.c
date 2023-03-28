#include <stdio.h>
#include <stdlib.h>
void swap(int *a1,int*a2){
	int tmp=*a1;
	*a2=*a1;
	*a2=tmp;

}
int seqlen;
int FIFO(int arr[seqlen],int diskarmpos){
	int seek_time=0;
	for(int i=0;i<seqlen;i++){
		seek_time+=abs(diskarmpos-arr[i]);
		diskarmpos=arr[i];
	}
	return seek_time;

}
void sort(int *arr,int seqlen)
{
	int tmp;
	for(int i=0;i<seqlen;i++){
		for(int j=0;j<seqlen;j++){
			if(arr[i]<arr[j]){
				tmp=arr[i];
				arr[i]=arr[j];
				arr[j]=tmp;
			}
		}
	}
}
int CSCAN(int arr[seqlen],int lb,int ub,int diskarmpos){
int dup[seqlen+3],i,seek_time=0;
	for( i=0;i<seqlen;i++){
		dup[i]=arr[i];
	}
	int diskidx;
	dup[i]=diskarmpos;
	dup[i+1]=lb;
	dup[i+2]=ub;
	sort(dup,seqlen+3);
	for(int j=0;j<seqlen+1;j++){
		if(dup[j]==diskarmpos){
			diskidx=j;
			break;
		}
	}
	int cpdi=diskidx;
	diskidx--;
//	printf("%d==\n",diskidx);

	for(int i=diskidx;i>=0;i--){
		seek_time+=abs(diskarmpos-dup[i]);
		diskarmpos=dup[i];
	}
	seek_time+=abs(diskarmpos-dup[seqlen+2]);
	diskarmpos=dup[seqlen+2];
	for(int j=seqlen+1;j>cpdi;j--){
//		printf("%d\n",dup[j]);
		seek_time+=abs(diskarmpos-dup[j]);
		diskarmpos=dup[j];
	}

	return seek_time;

}
int SCAN(int arr[seqlen],int lb,int ub,int diskarmpos ){
int dup[seqlen+3],i,seek_time=0;
	for( i=0;i<seqlen;i++){
		dup[i]=arr[i];
	}
	int diskidx;
	dup[i]=diskarmpos;
	dup[i+1]=lb;
	dup[i+2]=ub;
	sort(dup,seqlen+3);
	for(int j=0;j<seqlen+1;j++){
		if(dup[j]==diskarmpos){
			diskidx=j;
			break;
		}
	}
	int cpdi=diskidx;
	diskidx--;
//	printf("%d==\n",diskidx);

	for(int i=diskidx;i>=0;i--){
		seek_time+=abs(diskarmpos-dup[i]);
		diskarmpos=dup[i];
	}
	for(int j=cpdi+1;j<seqlen+2;j++){
		seek_time+=abs(diskarmpos-dup[j]);
		diskarmpos=dup[j];

//		printf("%d\n",dup[j]);

	}
	return seek_time;
}
int SSTF(int arr[seqlen],int diskarmpos){
	int dup[seqlen+1],i,seek_time=0;
	for( i=0;i<seqlen;i++){
		dup[i]=arr[i];
	}
	int diskidx;
	dup[i]=diskarmpos;
	sort(dup,seqlen+1);
	for(int j=0;j<seqlen+1;j++){
		if(dup[j]==diskarmpos){
			diskidx=j;
			break;
		}
	}
	int cpdi=diskidx;
	diskidx--;
//	printf("%d==\n",diskidx);
	for(int i=diskidx;i>=0;i--){
		seek_time+=abs(diskarmpos-dup[i]);
		diskarmpos=dup[i];
	}
	for(int j=cpdi+1;j<seqlen+1;j++){
		seek_time+=abs(diskarmpos-dup[j]);
		diskarmpos=dup[j];
	}

	return seek_time;
}




int main(){
int diskarmpos,tmp;
scanf("%d",&seqlen);
int arr[seqlen];
for(int i=0;i<seqlen;i++){
	scanf("%d",&tmp);
	arr[i]=tmp;
}
scanf("%d",&diskarmpos);

printf(" SCAN_MODE | SEEK TIME\n" );

printf(" FIFO      |%d\n",FIFO(arr,diskarmpos));

printf(" SSTF      |%d\n",SSTF(arr,diskarmpos));

printf(" SCAN      |%d\n",SCAN(arr,0,199,diskarmpos));
printf(" CSCAN     |%d\n",CSCAN(arr,0,199,diskarmpos));


}

