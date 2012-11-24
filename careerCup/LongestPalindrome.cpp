//Find the longest palindrome in a given string
//LImits assumed
#include <stdio.h>
#include <malloc.h>


#define MAX_LENGTH 1000

char str[MAX_LENGTH]="sheshankknahsehsaaaaaaaaaaaaaaaa";
int* palindromes[MAX_LENGTH];

void populatePalindromesAt(int i){
	palindromes[i] = (int*) malloc((i+2)*sizeof(int));
	int j=0;
	palindromes[i][j++]=i;
	if(i==0){return;}
	if(str[i] == str[i-1])palindromes[i][j++]=i-1;
        for(int*k = palindromes[i-1];*k!=-1;k++){
		if((*k>0) && str[*k-1] == str[i]){
			palindromes[i][j++]=*k-1;
		}
        }
	palindromes[i][j]=-1;
	return;
}

void freePalindromes(){for(int i=0;str[i]!=0;i++)free(palindromes[i]);return;}

int main(){
	int start=0,end=0;
	//scanf("%s",str);
	
	for(int i=0;str[i]!=0;i++){populatePalindromesAt(i);}
	for(int i=0;str[i]!=0;i++){
		for(int* j=palindromes[i];*j!=-1;j++){
			if((i-*j) > end-start){
				start=*j;end=i;
			}
		}
	}
	printf("%d %d\n",start,end);
	printf("%s\n",str+start);

	freePalindromes();
	return 0;
}
