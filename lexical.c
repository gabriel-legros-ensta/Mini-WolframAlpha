#include<stdio.h>
#include<ctype.h>
#include"utils.h"
#include<stdlib.h>



int puissance(int p){
if(p==0){return 1;}
else{int r=1;
for(int q=0; q<p;q++){r=r*10;}
return r;}}






TokenQueue lexical(char* chaine){
TokenQueue queue=CreateTokenQueue();
int i=0;
int k=0;
while(chaine[i]!='\0') {
	if(isdigit(chaine[i])){
	
		k=k+1;
		if(chaine[i+1]=='\0'){
		
		int j=0;
			for(int y=0;y<k;y++){j=j+(chaine[i+y-k+1]-48)*puissance(k-y-1);}
			Token token1={NUMBER,j };
			AppendTokenQueue(&queue, token1);}
		}
	else {
		if(k==0){Token token2;
			
			 
    if (chaine[i] == '+') {
        token2.type = ADD;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == '-') {
        token2.type = SUB;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == '*') {
        token2.type = MUL;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == '/') {
        token2.type = DIV;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == '%') {
        token2.type = MOD;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == '(') {
        token2.type = LEFT_PAREN;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == ')') {
        token2.type = RIGHT_PAREN;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == ' ') {
        
    } else {
        //printf("choix invalide\n");
    }}
		else{
			int j=0;
			for(int y=0;y<k;y++){j=j+(chaine[i+y-k]-48)*puissance(k-y-1);}
			Token token1={NUMBER,j };
			AppendTokenQueue(&queue, token1);
			k=0;
			Token token2;
			
			 

    if (chaine[i] == '+') {
        token2.type = ADD;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == '-') {
        token2.type = SUB;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == '*') {
        token2.type = MUL;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == '/') {
        token2.type = DIV;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == '%') {
        token2.type = MOD;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == '(') {
        token2.type = LEFT_PAREN;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == ')') {
        token2.type = RIGHT_PAREN;
        AppendTokenQueue(&queue, token2);
    } else if (chaine[i] == ' ') {
       
    } else {
        //printf("choix invalide\n");
    }


			
			
			}
	}i=i+1;}
return queue;
}

/*int main(){
char chaine[100];
fgets(chaine,sizeof(chaine), stdin);

TokenQueue AD=lexical(chaine);
PrintTokenQueue(&AD);}*/


