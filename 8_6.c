#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int stk[100];
	int minOfstk[100];
	int top = -1, min = 10000; 
	char x='q',y='q';
	do{
		scanf("%c%c",&x,&y);
		if(x == '+'){
			int value;
			scanf("%d",&value);
			if(value<min) min = value;
			minOfstk[++top] = min;
			stk[top] = value;
			//top += 1;
		}
		else if(x == '-'){
			if(top>=0) 	printf("popped=%d\n",stk[top]);
			else 		printf("empty stk");
			
			top -= 1;
			if(top<0) printf("Stk is now empty.");
			
		}
		else if(x == 'm'){
			printf("min=%d\n",minOfstk[top]);
		}
		
	}while(x!='\n' && y!='\n');
	
}
