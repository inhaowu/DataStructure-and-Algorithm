#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
using namespace std;
ifstream fin, fout, fstd;
ofstream fscore, freport;

int score;
const int maxn = 5001;
int map[maxn][maxn];
int mark[maxn][maxn];
int d[maxn];
int n; //������� 
int edges;
int ans;
int *A[maxn];
int *B[maxn];
//int flag[maxn];
int f[maxn];
int rank[maxn];
int find(int x){
	if (f[x] != x) 
		f[x] = find(f[x]);
	return f[x];
}
void unionroot(int ra, int rb){
	if (rank[ra] < rank[rb])
		f[ra] = rb;
	else if (rank[rb] < rank[ra])
		f[rb] = ra;
	else{
		f[ra] = rb; rank[rb] ++;
	}
}

void judge(){
	fin>>n;
	for(int i=1;i<=n;i++){
		f[i]=i;rank[i]=0;
	} 
	//������������
	for(int i=1;i<=n;i++){
		fin>>d[i];
		A[i]=(int*)malloc(sizeof(int)*(d[i]+1));
		for(int j=1;i<=n;j++){
			for(int j=1;j<=d[i];j++){
				fin>>A[i][j];
			}
		}
	}
    //����������� 
    fout>>edges;
	for(int i=1;i<=n;i++){
		fout>>d[i];
		B[i]=(int*)malloc(sizeof(int)*(d[i]+1));
		for(int j=1;j<=d[i];j++){
			fout>>B[i][j];
		}
	}
	fstd>>ans;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d[i];j++){
			if(B[i][j]){
				unionroot(i,A[i][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d[i];j++){
			if (B[i][j] && (find(i)!=find(A[i][j]))){
				fscore<<0<<endl;
				freport<<"Invalid Result!"<<endl;
			} 
			else if(ans!=edges){
				fscore<<0<<endl;
				freport<<"Invalid Result!"<<endl;
			}
			else{
				fscore<<score<<endl;
				freport<<"Success!"<<endl;
			}
		}
	} 
	
}
	
int main(int argc, char* argv[])
{

	
	//put something to fstreams...
/*
argv[1]:�����ļ�
argv[2]:ѡ������ļ�
argv[3]:��׼����ļ�
argv[4]:�������Ե��ֵ
argv[5]:������յ÷ֵ��ļ�
argv[6]:������󱨸���ļ�
*/
	fin.open(argv[1]);
	fout.open(argv[2]);
	fstd.open(argv[3]);
	fscore.open(argv[5]);
	freport.open(argv[6]);

	score = atoi(argv[4]);

	judge();

	fin.close();
	fout.close();
	fstd.close();
	fscore.close();
	freport.close();
	return 0;
}
