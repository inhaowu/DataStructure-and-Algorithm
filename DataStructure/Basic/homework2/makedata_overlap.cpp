#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char filename[10] = "0.in";
const int L[10]={5,8,15,50,100,1000,20000,200000,400000,600000};
const int maxn=1000000+1;

char getrandom_str(const int length,char * randomString){
	char seed_str[] = "abcdefghijklmnopqrstuvwxyz";
	int seed_str_len = strlen(seed_str);
	for(int i=0;i<length;i++)
		randomString[i]=seed_str[rand()%seed_str_len];
	randomString[length]='\0';	
}

char S[maxn];

int bigrand(){
	int x = rand(), y = rand();
	return x * 1000 + y % 1000;
}

void get_string(int m,char*T)  //生成数据 
{
	getrandom_str(5,T);
	while(strlen(T)<m){
	   int Len=bigrand()% strlen(T) + 1;
	   if (Len + strlen(T) > m) Len = m - strlen(T);
	   strncpy(S,T,Len); S[Len] = '\0';
	   strcat(S,T);
	   strcpy(T,S); 
	}	
}

void get_exstring(int m,char*T)  //极端数据 
{
	getrandom_str(15,T);
	while(strlen(T)*2<=m){
		strcpy(S,T);
		strcat(T,S);
	}
}

char T[maxn];

int main(){
	srand(0);
	for(int t=0;t<10;t++){
		int n= L[t];
		printf("producing %d...\n", t);
		
		if(t%4==0) get_exstring(n,T);
		else get_string(n,T);
		
		filename[0] = '0' + t;
		FILE* fout = fopen(filename, "w");
		fprintf(fout,"%s",T);
		fclose(fout); 
	}
	return 0; 
}

