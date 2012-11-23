#include <stdio.h>

int main(){
    int T=0;
	int C,NumItems;
	int P[2001]; //price of all the items in store
	int I[2001];
	int i1=0,i2=0;
	scanf("%d",&T);
	for(int tCase=1;tCase<=T;tCase++){
    scanf("%d",&C);	    scanf("%d",&NumItems);
	//store all the prices in P[NumItems]
	for (int i=0;i<NumItems;i++){
        scanf("%d",P+i);
	}
	//set all index to 0
	for(int i=0;i<2001;i++){
		I[i]=0;
	}
	
	//Loop
	//for each price check I[P[i]] != 0 : if so terminate
	for(int i=0;i<NumItems;i++){
		if(I[P[i]] !=0){
			//found the pair
			if(i<I[P[i]]){i1 = i+1;i2=I[P[i]];}
			else{i2 = i+1;i1=I[P[i]];}
            
            break;
		}
		else{
		//else make I[C - P[i]] = i;
			I[C-P[i]] = i+1;
		}
	}
	printf("Case #%d: %d %d\n",tCase,i1,i2);
	}
	return 0;
}