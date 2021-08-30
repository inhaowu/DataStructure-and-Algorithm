//The typical recursion problem in computer science.
#include<stdio.h>
void move(char x,char y){
	printf("%c----->%c \n",x,y);
} 
 void tower(int n,char x,char y,char z){
    if(n==1) move(x,z);
 	else{
 		tower(n-1,x,z,y);
 		move(x,z);
 		tower(n-1,y,x,z);
	 }
 }
int main(){
 	int n;
 	scanf("%d",&n);
 	tower(n,'A','B','C');
 	return 0;
 }
