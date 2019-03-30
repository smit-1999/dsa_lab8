#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void sort(int * tmp,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(tmp[i]>tmp[j]){
				int t = tmp[i];
				tmp[i] = tmp[j];
				tmp[j] = t;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	int tmp[n];
	int g =0;
	tmp[g] = arr[0];
	g+=1;
	int min = tmp[0];
	int ans  = 0;
	for(int i=1;i<n;i++){
		if(arr[i]>min){
			tmp[g] = arr[i];
			g+=1;
			ans += arr[i] - min;
			tmp[0] = 9999;
			sort(tmp,g);
			min = tmp[0];
		}
		else if(arr[i]<min){
			tmp[g]  = arr[i];
			g+=1;
			sort(tmp,g);
			min = tmp[0];			
		}
	}
	printf("%d",ans);
}
