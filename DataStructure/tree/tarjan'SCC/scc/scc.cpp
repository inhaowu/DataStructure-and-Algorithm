#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
const int maxn=50000;
const int maxm=500000;
int n,m;
int nums=0,ans=0;
int t=0;
int s[maxn];
int min(int a,int b){
	return a<b ? a:b; 
}
int a[maxm + 1]; 
int b[maxm + 1];
int p[maxn + 2];
int linkto[2 * maxm + 1];
void input_data() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &a[i], &b[i]);
	}
	for (int i = 1; i <= m; i++) {//保存每个顶点的度
		p[a[i]]++;	
	}
	for (int i = 1; i <= n; i++) p[i] = p[i] + p[i - 1];//相当于指针，方便遍历
	p[n + 1] = p[n];//trick 多一个指针指向最后一个元素
	for (int i = 1; i <= m; i++) {//构建邻接链表
		linkto[p[a[i]]] = b[i];
		p[a[i]]--;
	}
}
int index[maxn];
int low[maxn];
int stack[maxn],top=0;
int in_stack[maxn];
int count=0;
void tarjan_scc(int v){
	index[v]=low[v]=++count;
	stack[++top]=v;
	in_stack[v]=1;
	for(int i=p[v]+1;i<=p[v+1];i++){
		int u=linkto[i];
		if(!index[u]){
			tarjan_scc(u);
			low[v]=min(low[v],low[u]); 
		}
		else if(in_stack[u]) low[v]=min(low[v],index[u]);
	}
	if(index[v]==low[v]){
		while(true){
			int j=stack[top--];
			nums++;
			s[ans]=nums;
			//printf("%d ",j);
			in_stack[j]=0;
			if(j==v){
				t++;
				ans++; 
				nums=0;
				break;
			}
		} 
		//printf("\n");
	}
}
//快速排序 从大到小排序 
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) {
    if (array[j] >pivot){
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int k = partition(array, low, high);
    quickSort(array, low, k - 1);
    quickSort(array, k + 1, high);
  } 
}
int main(){
	input_data();
	memset(index,0,sizeof(index));
	memset(low,0,sizeof(low));
	memset(stack,0,sizeof(stack));
	memset(in_stack,0,sizeof(in_stack));
	for(int i=1;i<=n;i++){
		if(!index[i]) tarjan_scc(i);
	}
	quickSort(s,0,t-1);
    for(int i=0;i<t;i++) printf("%d ",s[i]);
	return 0;
} 

