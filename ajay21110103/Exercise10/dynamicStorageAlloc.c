#include <stdio.h>
#include <stdlib.h>
void FirstFit(int * mem,int n_blocks,int* seq,int n_seq){
	int count_alloc=0,flag=0;
	for (int i=0;i<n_seq;i++){
		for(int j=0;j<n_blocks;j++){
			if(*(seq+i)<=*(mem+j)){
				printf("%d request sequence allocated to %d block\n",seq[i],j);
				*(mem+j)-=*(seq+i);
				flag=1;
				break;
			}
		}
		if(flag==0){
			printf("%d request sequence has to wait\n",*(seq+i));
		}
		flag=0;
	}

}

void NextFit(int * mem,int n_blocks,int* seq,int n_seq){
	int count_alloc=0,flag=0,c=0;
	int mem_ptr=0;
	for (int i=0;i<n_seq;i++){
		c=0;
		while(c<n_blocks){
			if(*(seq+i)<=*(mem+mem_ptr)){
				printf("%d request sequence allocated to %d block\n",seq[i],mem_ptr);
				*(mem+mem_ptr)-=*(seq+i);
				flag=1;break;
			}
			mem_ptr++;
			c++;
			if(mem_ptr>n_blocks){mem_ptr=0;}
		}
		if(flag==0){
			printf("%d request sequence has to wait\n",*(seq+i));
		}
		flag=0;
	}

}



int * sort(int *mem_sq,int size){
	int * arr=(int*)malloc(sizeof(int)*size);
	int* mem_seq=(int*)malloc(sizeof(int)*size);
	for(int i=0;i<size;i++){
		*(mem_seq+i)=*(mem_sq+i);
	}
	int ctr=0,tmp;
	for(int i=0;i<size;i++){
		for(int j=i+1;j<size;j++){
			if(*(mem_seq+i)>=*(mem_seq+j)){
				//*(arr+(ctr))=i;
				tmp=*(mem_seq+i);
				*(mem_seq+i)=*(mem_seq+j);
				*(mem_seq+j)=tmp;
			}
		}
//		ctr++;
	}
	return mem_seq;
}


void BestFit(int *mem1 ,int n_blocks,int *seq,int n_seq){
	int *mem=mem1;
	int *arr=sort(mem1,n_blocks);
	int c=0,flag=0;
	int * arr1=(int*)malloc(sizeof(int)*n_blocks);
	for(int i=0;i<n_blocks;i++){
		for(int j=0;j<n_blocks;j++){
			if(*(mem+i)==*(arr+j)){
				*(arr1+(c++))=j;break;
			}
		}
	}
	//for(int i=0;i<n_blocks;i++){
//		printf("%d\t",mem[arr1[i]]);
	//}
	

	for(int i=0;i< n_seq;i++){
		for(int j=0;j<n_blocks;j++){
			if(*(seq+i)<=mem[*(arr1+j)]){
				printf("%d request sequence  allocated to %d block\n",*(seq+i),*(arr1+(n_blocks-j)));
				*(mem+*(arr1+j))-=*(seq+i);
				flag=1;
				break;
			}
		}
		if(flag==0){
			printf("%d request sequence has to wait\n",*(seq+i));
		}
		flag=0;
	}
		
}

void WorstFit(int *mem1 ,int n_blocks,int *seq,int n_seq){
	int *mem=mem1;
	int *arr=sort(mem1,n_blocks);
	int c=0,flag=0;
	int * arr1=(int*)malloc(sizeof(int)*n_blocks);
	
	for(int i=0;i<n_blocks;i++){
		for(int j=0;j<n_blocks;j++){
			if(*(mem+i)==*(arr+j)){
				*(arr1+(c++))=j;break;
			}
		}
	}
//	for(int i=0;i<n_blocks;i++){
//		printf("%d\t",mem[arr1[i]]);
//	}
	//for(int j=0;j<n_blocks;j++){printf("--%d--\n",mem[j]);}
	//printf("====\n");
	for(int i=0;i< n_seq;i++){
		for(int j=n_blocks-1;j>=0;j--){
			if(*(seq+i)<=mem[*(arr1+j)]){
				printf("%d request sequence  allocated to %d block\n",*(seq+i),*(arr1+j));
				mem[arr1[j]]-=*(seq+i);
				flag=1;
				break;
			}
			
		}
		if(flag==0){
			printf("%d request sequence has to wait\n",*(seq+i));
		}
		flag=0;
	}	
	//for(int j=0;j<n_blocks;j++){printf("--%d--\n",mem[arr1[j]]);}
	
}
void memSet(int *mem1,int*mem2,int size){
	for(int i=0;i<size;i++){
		*(mem1+i)=*(mem2+i);
	}
	

}

int main(){
	int n_blocks,n_seq,assign_blocks,seq1;
	scanf("%d %d",&n_blocks,&n_seq);
	int * mem=(int *)malloc(n_blocks*sizeof(int));
	int*mem1=(int*)malloc(sizeof(int)*n_blocks);
	int*mem2=(int*)malloc(sizeof(int)*n_blocks);
	int*mem3=(int*)malloc(sizeof(int)*n_blocks);
	int* seq=(int*)malloc(n_seq*sizeof(int));
	printf("Enter the memory block sequence\n");
	for(int i=0;i<n_blocks;i++){
		scanf("%d",&assign_blocks);
		*(mem+i)=assign_blocks;
	}
	memSet(mem1,mem,n_blocks);
	memSet(mem2,mem,n_blocks);
	memSet(mem3,mem,n_blocks);
	printf("Enter the memory request sequence\n");
	for(int i=0;i<n_seq;i++){
		scanf("%d",&seq1);
		*(seq+i)=seq1;
	}
	
	printf("First Fit: \n");
	FirstFit(mem,n_blocks,seq,n_seq);
	
	printf("Next Fit: \n");
	NextFit(mem1,n_blocks,seq,n_seq);
	
	printf("Best Fit: \n");
	BestFit(mem2,n_blocks,seq,n_seq);
	
	printf("Worst Fit: \n");
	WorstFit(mem3,n_blocks,seq,n_seq);
	
	//int *arr=sort(mem,n_blocks);
	//for(int i=0;i<n_blocks;i++){printf("%d\t",arr[i]);}

}
