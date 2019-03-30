#include<stdio.h>
#include<stdlib.h>
void sortPair(int * start,int * process,int n){
	//sort on basis of process time
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(process[i]>process[j]){
				int t = process[i];
				int u = start[i];
				start[i] = start[j];
				process[i] = process[j];
				start[j] = u;
				process[j] = t;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int start[n],process[n],visited[n];
	for(int i=0;i<n;i++){
		scanf("%d %d",&start[i],&process[i]);
		visited[i] = 0;
	}
	int currentTime = 0,waitTime = 0,ordersServed = 0;
	sortPair(start,process,n);
	/*for(int i=0;i<n;i++){
		printf("%d %d\n",start[i],process[i]);
	}
	printf("\n");*/
while(ordersServed != n){
	int flag  = 0;	
	for(int i=0;i<n;i++){
		if(visited[i] == 0 && start[i] <= currentTime){
			visited[i] = 1;
			currentTime += process[i];
			waitTime += currentTime - start[i];
			ordersServed += 1 ;
			flag  = 1;
			printf("ordersrved=%d waittime=%d orderno=%d currenttime=%d\n",ordersServed,waitTime,i,currentTime);			 
			break;
		}
	}
	if(flag == 0){
		//findNextorder
		int minTime= 100000,nextOrder;
		for(int i=0;i<n;i++){
			if(visited[i] == 0){
				if(start[i] >currentTime && start[i] < minTime){
					minTime = start[i];
					nextOrder = i;
				}
			}
		}
		currentTime = start[nextOrder] + process[nextOrder];
		waitTime += currentTime - start[nextOrder];
		visited[nextOrder] = 1;
		ordersServed += 1;
		printf("neworder,,,ordersrved=%d waittime=%d orderno=%d,currenttime=%d\n",ordersServed,waitTime,nextOrder,currentTime);		
	}
	
}
printf("%f",(float)waitTime/n);
}
/*
5
1 5
4 4
8 2
7 4
3 5

3
0 3
1 9
2 6
*/
