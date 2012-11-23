#include <stdio.h>
#include <malloc.h>

#define MAX_LEN 100

void printCombFromDenomination(int* a, int* d, int len, int i, int sum){
	//if(len < i+1 ) return;
	if(len == i+1){
		if(sum%d[i] == 0 ) {
			a[i] = sum/d[i];
			for(int j = 0;j <len;j++){printf("%d*%d ",a[j],d[j]);}
			printf("\n");
		}
	}else{
		for(a[i]=0;a[i]<sum/d[i];a[i]++){
			printCombFromDenomination(a,d,len,i+1,sum - a[i]*d[i]);
		}
	}
}



int main(){
	int T,sum,len,i;
	int a[MAX_LEN];
	int d[MAX_LEN];
	scanf("%d",&T);
	while(T--){
		scanf("%d %d",&sum,&len);
		for(i=0;i<len;i++){scanf("%d",&d[i]);}
		//qsort(&d,len);
		printCombFromDenomination(a,d,len,0,sum);
	}
	return 0;
}