#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char filename[10] = "0.in";
const int L[10]={5,10,15,50,100,2000,5999,10000,50000,499999};

char getrandom_str(const int length,char * randomString){
	char seed_str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	int seed_str_len = strlen(seed_str);
	for(int i=0;i<length;i++)
		randomString[i]=seed_str[rand()%seed_str_len];
	randomString[length]='\0';
}

char S[1000000+1];

void swap(char &a,char &b) {
	char c;
	c = a; a = b; b = c;
}
	
char get_palindrome(char *T,int m){
	getrandom_str(m,S);
	strcpy(T,S);
	for(int i=0;i<m/2;i++) swap(S[i], S[m-1-i]); 
    strcat(T,"&");
	strcat(T,S);
}

int bigrand(){
	int x = rand();
	int y = rand();
	return x * 1000 + y % 1000;
}

char parlin[1000000+1];
	
int main()
{
	srand(0);
	for(int t=0;t<10;t++){
		int n=L[t];
		get_palindrome(parlin,n);
		filename[0] = '0' + t;
		printf("producing %s...\n", filename);

		if(t==0 || t == 4) swap(parlin[bigrand()%(2*n+1)],parlin[bigrand()%(2*n+1)]);
		if (t==1) strcat(parlin, "xyz");
		if (t==7) parlin[2*n-1] = '\0';
		if (t==3) swap(parlin[n], parlin[n+1]); 

		FILE* fout = fopen(filename, "w");
	    fprintf(fout,"%s@",parlin);
	    fclose(fout); 
    }
	
}

