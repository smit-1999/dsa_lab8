#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	int min = 10000;
	for(int p=0;p<n;p++){
		scanf("%d",&arr[p]);
		if(arr[p]<min) min = arr[p];
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		int minOfSubarray = arr[i];
		for(int j=i;j<n;j++){
			if(arr[j] <= minOfSubarray) {				
				minOfSubarray = arr[j];
			}
			ans += minOfSubarray;
		}
	}
	printf("%d",ans);
}
