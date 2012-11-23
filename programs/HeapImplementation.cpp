
#include <stdio.h>

typedef struct {
	int *a;
	int len;
} Heap;	

Heap getMaxHeap(int*,int);
void buildMaxHeap(Heap);
void maxHeapify(Heap,int);
int getMax(Heap);

Heap getMaxHeap(int * a, int len){
	Heap maxHeap;
	//few input parameters checks.
	maxHeap.a = a;
	maxHeap.len = len;
	buildMaxHeap(maxHeap);
}

void buildMaxHeap(Heap maxHeap){
	for(int i=maxHeap.len/2;i>=0;i++){
		maxHeapify(a,i);
	}
}

//parent(i) 

void maxHeapify(Heap maxHeap, int i){
	int maxIndex = i;
	if(i<<1 < maxHeap.len && maxHeap.a[i]<maxHeap.a[i<<1]){maxIndex = i<<1;}
	if( (i<<1 + 1) < maxHeap.len && maxHeap.a[maxIndex] < maxHeap.a[i<<1+1]){maxIndex = i<<1+1;}
	if(maxIndex!=i){
		int temp = maxHeap.a[i];
		maxHeap.a[i] = maxHeap.a[maxIndex];
		maxHeap.a[maxIndex] = temp;
	}
	maxHeapify(maxHeap, maxIndex);
}

int getMax(Heap maxHeap){
	int max = maxHeap.a[0];
	maxHeap.a[0] = maxHeap.a[len-1];
	maxHeap.len--;
	maxHeapify(maxHeap,0);
}

int main(){
	int a[] = {10,11,23,1,2,33,8,9,5,6};
	Heap h = getMaxHeap(a,10);
	for(int i=0;i<10;i++){
		printf("%d\n",a[i]);
	}
	for(int i=0;i<10;i++){
		printf("%d\n",getMax(h));
	}
	return 0;
}
