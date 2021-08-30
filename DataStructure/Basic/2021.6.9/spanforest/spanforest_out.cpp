#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
char infilename[10]="0.in";
char outfilename[10]="0.out";
FILE * fin, * fout;
const int maxn=5001;

int * A[maxn];
int * B[maxn];
bool visited[maxn];
int d[maxn], n, edges;

int dfs(int v){
	visited[v]=true;
	for(int i=1;i<=d[v];i++){
		int u=A[v][i];
		if(!visited[u]){
			B[v][i]=1;
			for (int k=1;k<=d[u];k++)
				if (A[u][k]==v) B[u][k]=1;
			edges++;
			dfs(u);
		}
	}
}
void readGraph()
{
	fin = fopen(infilename, "r");
	fscanf(fin,"%d",&n);
	memset(visited, 0, sizeof(visited));
	for(int i=1;i<=n;i++){
		fscanf(fin,"%d",&d[i]);
		A[i]=(int*)malloc(sizeof(int)*(d[i]+1));
		B[i]=(int*)malloc(sizeof(int)*(d[i]+1));
		for(int j=1;j<=d[i];j++){
			fscanf(fin,"%d", &A[i][j]);
			B[i][j]=0; 
		}
	}
	fclose(fin); 
}
void printAns(){
	fout = fopen(outfilename, "w");
	fprintf(fout,"%d\n",edges);
	for(int i=1;i<=n;i++){
		fprintf(fout,"%d",d[i]);
		for(int j=1;j<=d[i];j++) fprintf(fout," %d", B[i][j]);
		fprintf(fout,"\n");
	} 
	fclose(fout);
}
int main(){

	for(int t=0;t<10;t++){
		infilename[0] = '0' + t;
		outfilename[0] = '0' + t;
		readGraph();
		for(int i=1;i<=n;i++) 
		  if (!visited[i]) dfs(i);
		printAns();
		printf("%d ",t);
	}
	return 0;
}
