#include<stdio.h>
const int maxn=50;
int board[maxn+1];
int count;
int place(int row, int column){
	for(int i=1;i<=row-1;i++){
		int data=board[i]; 
		// Satisfying three restrictions: 
		if(data==column) return 0;  
		else if(i+data==row+column) return 0;
		else if(i-data==row-column) return 0;
	}
	return 1;
}
void queen(int row,int n){
	for(int column=1;column<=n;column++){
		if(place(row,column)){
			board[row]=column;
		    if(row==n) count++;
		    else queen(row+1,n);
		} 
	}
}
int main(){
	int n;
	scanf("%d",&n);
	queen(1,n);
	printf("%d",count);
	return 0;
}
