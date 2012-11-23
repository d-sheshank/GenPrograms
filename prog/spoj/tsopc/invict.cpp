
#include <stdio.h>
#include <iostream>

struct Node {
long val;
struct Node * n;

};

struct Node nodes[200000];
int ni;
int main(){

int T=0;
int num=0;
int inv=0;
int i=0;
struct Node *c,*h,*p;
ni = 0;
scanf("%d\n",&T);
scanf("\n");
while(T--){
	inv = 0;
	scanf("%d\n",&num);
	if(num--){
	scanf("%ld\n",&nodes[num].val);nodes[num].n=NULL;h=&nodes[num];
	for(i=num;i--;){
		scanf("%ld\n",&nodes[i].val);
		if(h->val < nodes[i].val){nodes[i].n=h;h=&nodes[i];continue;}
		for(p = h,c = h->n,inv++;c!=NULL && c->val > nodes[i].val;inv++){
			p=c;
			c=c->n;
		}
		
		p->n = &nodes[i];
		nodes[i].n = c;
		
	}
	}
	scanf("\n");	
	printf("%d\n",inv);
}
return 0;
} 

