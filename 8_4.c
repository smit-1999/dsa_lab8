#include<stdio.h>
#include<stdlib.h>
int main(){
	char stk[100];
	for(int i=0;i<100;i++) stk[i] = 'p';
	int top = 1;
	char ch = 'p';
	do{
		scanf("%c",&ch);
		if(ch == '\n') break;
		if(stk[top-1] == '{' && ch == '}'){
			top-=1;
		}
		else if(stk[top-1] == '(' && ch == ')'){
			top-=1;
		}
		else if(stk[top-1] == '[' && ch == ']'){
			top-=1;
		}
		else{
			printf("new character added");
			stk[top] = ch;
			top += 1;	
		}
	printf("%d\n",top);			
	}while(ch!='\n');
	if(top == 1) printf("balanced");
	else printf("unbalanced");
	
}
