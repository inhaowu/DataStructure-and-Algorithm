#include<stdio.h>
#include<string.h>
char infilename[10]="0.in";
char outfilename[10]="0.out";
FILE * fin, * fout;
using namespace std;
const int maxn=401;
int edge[maxn][maxn];  
int color[maxn];      
int n;
bool dfs(int u,int c)
{
    color[u]=c;     //��u�����Ⱦɫ
    for(int v=1;v<=n;v++)//������u�������ĵ�
    {
        if(edge[u][v]==1)//���i����u������
        {
            if(color[v]==c) return false;//i���Ⱦɫ�ظ������Ƕ���ͼ
            if(!color[v])
			   if(!dfs(v,-c)) return false;//�õ�δȾɫ��Ⱦ���෴����ɫ.dfs��������
        }
    }
    return true;  //���е�Ⱦɫ���֮�󣬲������ڶ���û��ͬɫ����Ϊ����ͼ
}
int main()
{
    for(int t=0;t<10;t++){
        infilename[0] = '0' + t;
		outfilename[0] = '0' + t;
		fout = fopen(outfilename, "w");
		fin = fopen(infilename, "r");
		printf("%d",t);
		int k;
		fscanf(fin,"%d",&k);
		for(int m=1;m<=k;m++){
			fscanf(fin,"%d",&n);
			memset(edge,0,sizeof(edge));
			memset(color,0,sizeof(color));
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					fscanf(fin,"%d",&edge[i][j]);
				}
			}
			bool flag=false;
			for(int i=1;i<=n;i++){
				if(!color[i]){
					if(!dfs(i,1)){
						fprintf(fout,"No\n");
						flag=true;
						break;
					}
				}
			}
			if(!flag) fprintf(fout,"Yes\n");
		}
	}
	return 0;
}



