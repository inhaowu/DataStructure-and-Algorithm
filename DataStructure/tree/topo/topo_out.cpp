#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
const int maxn=50001;
const int maxm=500001;
int n,m;
int a[maxm + 1]; 
int indegree[maxm+1];
int b[maxm + 1];
int p[maxn + 2];
int linkto[2 * maxm + 1];
char infilename[10]="0.in";
char outfilename[10]="0.out";
FILE * fin, * fout;
void input_data() {
	fin = fopen(infilename, "r");
	fscanf(fin,"%d %d", &n, &m);
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(p,0,sizeof(p)); 
	for (int i = 1; i <= m; i++) {
		fscanf(fin,"%d %d", &a[i], &b[i]);
	}
	for (int i = 1; i <= m; i++) {//indegree[i]保存每个顶点的入度
		p[a[i]]++;
		indegree[b[i]]++;	
	}
	for (int i = 1; i <= n; i++) p[i] = p[i] + p[i - 1];//相当于指针，方便遍历
	p[n + 1] = p[n];//trick 多一个指针指向最后一个元素
	for (int i = 1; i <= m; i++) {//构建邻接链表
		linkto[p[a[i]]] = b[i];
		p[a[i]]--;
	}
	fclose(fin);
}

void topo_sort()
{
	fout = fopen(outfilename, "w");
	int count=0;
	while(true){
		for(int i=1;i<=n;i++){
			if(indegree[i]==0){
				fprintf(fout,"%d ",i);
				count++;
				indegree[i]=-1;
				for(int j=p[i]+1;j<=p[i+1];j++){
				   int u=linkto[j];
				   indegree[u]--;
				}
			} 
		}
		if(count==n) break;
	}
	fclose(fout);
} 
int main()
{
	for(int t=0;t<10;t++){
		printf("%d ", t);
		infilename[0] = '0' + t;
		outfilename[0] = '0' + t;
		memset(indegree,0,sizeof(indegree));
		input_data();
		topo_sort();
	}
	return 0;
}
