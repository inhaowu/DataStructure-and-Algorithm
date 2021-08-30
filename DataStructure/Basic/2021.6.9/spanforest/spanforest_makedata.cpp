#include<stdio.h>
#include<stdlib.h>
const int maxn=1000;
int A[maxn][2];
int B[maxn][2];
int *C[maxn];
int n,m;
int d[maxn]={0};
void swap(int & a, int & b){
	int c = a; a = b; b = c;
}
int gendata(int n, int m){
	for(int i=1;i<=m;i++){
		int a,b;
		do{
			a=rand()%n+1;
			b=rand()%n+1;
		} while(a==b);
		if (a > b) swap(a, b);
		A[i][0]=a;
		A[i][1]=b; 
	}
	//进行排序操作 
	int i,j,k;
    int t;
    for(i=1;i<m;++i){
        k=i;
        for(j=i+1;j<m;++j){
            if(A[k][0]>A[j][0])
                k=j;
        }
        if(k!=i){
            for(j=0;j<2;++j){
				t=A[k][j];
                A[k][j]=A[i][j];
                A[i][j]=t;
            }
        }
    }
    //删去重复的边 
    for(int i=1;i<m;i++){ 
		if((A[i][0]==A[i+1][0]) && (A[i][1]==A[i+1][1])){
    		i++;
			B[i][0]=A[i][0]; B[i][1]=A[i][1];
		}
		else B[i][0]=A[i][0]; B[i][1]=A[i][1];
	} 
    for(int i=0;i<m;i++)  printf("%d %d\n",B[i][0],B[i][1]); //删除零边 

    printf("%d\n",n);
	for(int i=1;i<n;i++){
	    	//int ans=0;
	    	d[B[i][0]]++;
	    	d[B[i][1]]++;
		printf("%d\n",d[i]);
		//int ans=0;
		//for(int j=1;j<=n;j++){
		//	if((B[i][0])==(B[i+1][0])){
		//		ans++;
		//		A[i][j]=B[i][1];
		//	}
		//}
	} 
} 

int main()
{
	gendata(40,20);
}
