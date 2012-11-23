#include<stdio.h>

int cL[1000000];

int main(){
	int i;
	unsigned int num=0;
	int count =0 ;
	for(i=0;i<1000000;i++){
		num = i;
		count=0;
		while(num!=1){
			count++;
			if(num<1000000 && cL[num]!=0){
				count+=cL[num];num=1;
			}else if(num%2==0){
				num >>=1;
			}else {
				num = (num*3)+1;
			}
		}
		cL[i]=count;
	}
	int maxIndex=0,maxLen=0;
	for(i =0,maxIndex=0,maxLen=0;i<1000000;i++){
		if(cL[i]>maxLen){maxLen=cL[i];maxIndex=i;}
	}
	printf("%d:%d",maxLen,maxIndex);
}