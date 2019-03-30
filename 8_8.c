#include<stdio.h>
#include<stdlib.h>
int main(){
	int n;
	scanf("%d",&n);
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	int ans  = 0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			for(int k=0;k<n;k++){
				for(int l=k;l<n;l++){
					int cnt = 0;
					for(int m=i;m<=j;m++){
						for(int n=k;n<=l;n++){
							if(arr[m][n] == 1) cnt+=1;
						}
					}
					if(cnt == 1) ans+=1;
				}
			}
		}
	}
	printf("%d",ans);
}
