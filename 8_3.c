#include<stdio.h>
#include<stdlib.h>
void sort(int * arr,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,n);
	int cnt  = 0;
	for(int i=0;i<n;i++){
		if(arr[i]<k){
			cnt += 1;
			arr[i] = arr[0] + 2*(arr[1]);
			arr[0] = k+1;
			arr[1] = k+1;
			sort(arr,n);
			i = -1;
		}
	}
	printf("%d",cnt);
}
