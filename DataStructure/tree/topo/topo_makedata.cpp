#include<iostream>
#include<stdlib.h> 
using namespace std;
const int maxN = 50000;
const int N[10] = { 5, 10, 20,  50, 2000, 9000, 20000, 30000,  40000, 50000 };
const int M[10] = { 6, 15, 30, 210, 5000, 30000, 100000, 230000, 399999, 499999 };
int n, m;
char filename[10] = "0.in";
int a[maxN];

void swap(int &a,int &b) {
	int c;
	c = a;
	a = b;
	b = c;
}
void rand_n() //生成1-n的随机排列
{
	for (int i = 1; i <= n; i++) 
		a[i] = i;
	for (int i = n; i >= 1; i--) 
	{
		int j = rand()% i +1;
		swap(a[i], a[j]);
	}
}
void printgraph()
{
	FILE* fout = fopen(filename, "w");
	fprintf(fout,"%d %d\n",n,m);
	for (int i = 1; i<=m; i++) 
	{
		int x = 1, y = 1;
		while (x >= y) {
			x = rand() % n + 1;
			y = rand() % n + 1;
		}
		fprintf(fout,"%d %d\n", a[x], a[y]);
	}
}
int main()
{

	srand(0);	
	for (int t = 0; t < 10; t++)
	{
		n = N[t];
		m = M[t];
		filename[0] = '0' + t;
		printf("producing %s...\n", filename);
		rand_n();
		printgraph();
	}
	
	
	return 0;
}
