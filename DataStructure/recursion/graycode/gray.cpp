// Using recursion to generate the Gray code. 

#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;


void  gray(int n,int a[1024])
{
	if(n==1) {
		a[0]=0;
		a[1]=1;
		return;
	}
	gray(n-1,a);
	int L=1<<(n-1);
	for(int i=0;i<L;i++)
	   a[L+L-i-1]=a[i]+L;
}

int main()
{
	int n=8;
	int a[1024];
	int b[n]={0};
	gray(n,a);
	for(int i=0;i<pow(2,n);i++){  // Transer the gray code to decimal number.
		for(int j=0;j<n;j++){
			int rem=a[i]%2;
			int q=a[i]/2;
			a[i]=q;
			b[j]=rem;
		}
		for(int k=n-1;k>=0;k--)
		{
			printf("%d",b[k]);
		}
		printf("\n");
		//printf("%d\n",a[i]);
	}

}
