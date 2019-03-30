#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int min(int a,int b){
	if(a>b) return b;
	else return a;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	char signal[n];
	char enter;
	scanf("%c",&enter);
	for(int i=0;i<n;i++){
		scanf("%c%c",&signal[i],&enter);
	}
	//for(int i=0;i<n;i++) printf("%c ",signal[i]);
	printf("\n");
	int cnt = 0;
	for(int i=0;i<n;i++){
		if(signal[i] == 'G'){
			//
		}
		else if(signal[i] == 'R'){
			cnt += 2;					
			for(int j=i;j<min(i+k,n);j++){
				if(signal[j] == 'R') signal[j] = 'G';
				else if(signal[j] == 'Y') signal[j] = 'R';
				else signal[j] = 'Y';
			}
		}
		else if(signal[i] == 'Y'){
			cnt += 1;
			for(int j=i;j<min(i+k,n);j++){
				if(signal[j] == 'R') signal[j] = 'Y';
				else if(signal[j] == 'Y') signal[j] = 'G';
				else signal[j] = 'R';
			}
		}
		printf("index=%d cnt=%d\n",i,cnt);
		for(int k =0;k<n;k++) printf("%c ",signal[k]);	
		printf("\n");	
	}
	printf("%d",cnt);
}
