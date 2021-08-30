#include<stdio.h>
#include<stdlib.h>
const int maxn=50000;
const int maxm=500000;
int n,m;

int a[maxm + 1]; 
int indegree[maxm+1];
int b[maxm + 1];
int p[maxn + 2];
int linkto[2 * maxm + 1];
void input_data() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a[i], &b[i]);
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
}

void topo_sort()
{
	int count=0;
	while(true){
		for(int i=1;i<=n;i++){
			if(indegree[i]==0){
				printf("%d ",i);
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
} 
int main()
{
	input_data();
	topo_sort();
	return 0;
}






