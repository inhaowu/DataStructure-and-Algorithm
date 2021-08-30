
//This program is to generate permutation of 1~n , mainly use backtrack method. 

#include<stdio.h>
const int maxn= 100;
int n;
int a[maxn+1];
bool mark[maxn+1];
void printlist(int a[]){
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	printf("\n");
} 
void searchpermutation(int i){
	if(i==0) printlist(a);
	else{
		for(int j=1;j<=n;j++){
			if(!mark[j]){
				mark[j]=true;
				a[i]=j;
				searchpermutation(i-1);
				mark[j]=false;
			}
		}
	}
}
int main(){
	n=6;
	searchpermutation(n);
	return 0;
}
