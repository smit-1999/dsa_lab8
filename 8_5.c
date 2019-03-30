#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int arr[100];
	char ch = 'y';
	int g = 0;
	int freq[10];
	for(int i=0;i<10;i++) freq[i] = 0;
	do	
	{		
		scanf("%d%c",&arr[g],&ch);
		freq[arr[g]] += 1;
		g+=1; 
	}while(ch != '\n');
	
	int firstNumber[g];
	int secondNumber[g];
	int ind1 = 0,ind2 = 0;
	for(int i=0;i<g-1;i++){
		for(int j=i+1;j<g;j++){
			if(arr[i]>arr[j]){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for(int i=0;i<g;i+=2) firstNumber[ind1++] = arr[i];	
	for(int i=1;i<g;i+=2) secondNumber[ind2++] = arr[i];
	
	int num1 = 0;
	for(int i=ind1-1;i>=0;i--){
		num1 += firstNumber[i]*pow(10,ind1-1-i);
	}
	int num2 = 0;
	for(int i=ind2-1;i>=0;i--){
		num2 += secondNumber[i]*pow(10,ind2-1-i);
	}
	printf("%d",num1+num2); 
	
}
