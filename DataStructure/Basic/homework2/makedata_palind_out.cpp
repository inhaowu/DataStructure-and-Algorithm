#include<stdio.h>
#include<stdlib.h>

const int maxn=1000000;
char Q[maxn+1];
char infilename[10]="0.in";
char outfilename[10]="0.out";

FILE * fin, * fout;
 
int checkP(){
	char s;
	int top=0;
	fscanf(fin,"%c",&s);
	while(s!='&'){
		Q[top++]=s;
		fscanf(fin,"%c",&s);
	}

	fscanf(fin,"%c",&s);
	while(s!='@'&& top>0)
		if(s==Q[--top]) fscanf(fin,"%c",&s);
		else return 0;
	if (top == 0 && s == '@') return 1;
	else return 0;
}

int main()
{
	for(int m=0;m<10;m++){
		printf("%d", m);
		infilename[0] = '0' + m;
		outfilename[0] = '0' + m;
		fin = fopen(infilename, "r");
		fout = fopen(outfilename, "w");
		fprintf(fout, "%d", checkP());
		fclose(fin);
		fclose(fout); 
	}
	return 0;	
}
