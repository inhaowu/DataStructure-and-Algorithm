#include<stdio.h>
#include<string.h>

const int maxn=1000001;
int pi[maxn];
char s[maxn];

char infilename[10]="0.in";
char outfilename[10]="0.out";
FILE * fin, * fout;

void pi_function(){
	int i=1,j=0;
	int m=strlen(s);
	while(i<m)
	{
		if(s[i]==s[j]) pi[++i] = ++j;
		else if (j == 0) pi[++i] = j;
		else j = pi[j];
	}
}

int main()
{
	for(int t=0;t<10;t++){
		printf("%d", t);
		
		infilename[0] = '0' + t;
		outfilename[0] = '0' + t;
		
		fin = fopen(infilename, "r");
		fout = fopen(outfilename, "w");

		fscanf(fin, "%s", s);
		pi_function();
		
		int Len = strlen(s);
		for(int j=1;j<=Len;j++)
		{
			if(pi[j]==0) fprintf(fout, "%d",j);
			else{
				 int k=j;
				 int flag=0;
				 while(k!=0 && flag<10)
				 {
				    fprintf(fout, "%d ",k);
				    k=pi[k];
				    flag++;
				}
			}
			fprintf(fout, "\n");
		}
		
		fclose(fin); fclose(fout);
	}
	return 0; 
}
