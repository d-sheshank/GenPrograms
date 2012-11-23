#include <stdio.h>

bool is_alph(char ch){
	return (ch<='z' && ch >= 'a');
}

bool is_digit(char ch){
	return (ch<='9' && ch >= '0');
}

void error(){
	printf("ERROR!!");
}
void printAlternateForm(char* a){
	char *alp=a,*digit=a;
	while(*digit!=0 && !is_digit(*(++digit)));
	for(alp=a;*alp!=0;alp++){
		if(is_alph(*alp)){
			if(*digit ==0 ){error();return;}
			printf("%c%c",*alp,*digit);
			while(*digit!=0 && !is_digit(*(++digit)));
		}	
		if(alp > digit){ error(); return;}
	}

}

int main(){
	char *a= "abc123def456";
	printAlternateForm(a);
	printf("\n");
	a = "abcdef1235";
	printAlternateForm(a);
	
	return 0;
}
	