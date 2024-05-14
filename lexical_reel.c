#include<stdio.h>
#include<ctype.h>
#include"utils.h"
#include<stdlib.h>
#include<string.h>



float puissance(int p){
if(p==0){return 1;}
else if(p>0){int r=1;
for(int q=0; q<p;q++){r=r*10;}
return r;}
else{int r=1;
for(int q=0; q<-p;q++){r=r/10;}
return r;}}






TokenQueue lexical(char* chaine){
TokenQueue queue=CreateTokenQueue();
Token token1;
int i=0;
int k=0;
int l=0;
while(chaine[i]!='\0') {

	
	
	if(isdigit(chaine[i])){
		if(l!=0){
		l=l+1;
		
		
		
			if(chaine[i+1]=='\0'){
			
			float j=0;
		
			//for(int y=0;y<k-l;y++){j=j+(chaine[i+y-k-1]-48)*puissance(k-l-y-1);}
			
				//for(int y=0;y<l-1;y++){
				//float f=chaine[i+y-l+2]-48;
				//j=j+f/(puissance(1+y));}
				//token1.value=token1.value+j;
				//token1.type=NUMBER;
				AppendTokenQueue(&queue, token1);
				break;}}
		
		
		else{
	
		k=k+1;
		
		if(chaine[i+1]=='\0'){
		
		
			//for(int y=0;y<k-l;y++){j=j+(chaine[i+y-k-1]-48)*puissance(k-l-y-1);}
			
				//for(int y=0;y<l;y++){j=j+(chaine[i+y-l]-48)/(puissance(1+y));}
				//token1.value=j;
				//token1.type=NUMBER;
				//AppendTokenQueue(&queue, token1);
			
			
				float j=0;
				for(int y=0;y<k;y++){j=j+(chaine[i+y-k+1]-48)*puissance(k-y-1);
							printf("%f\n",j);}
						token1.value=j;
						printf("nombre %f\n",j);
						token1.type=NUMBER;
						AppendTokenQueue(&queue, token1);
					}
				}
		
		}
		
	else if(chaine[i]=='.' ){l=l+1;
		float j=0;
		for(int y=0;y<k;y++){j=j+(chaine[i+y-k]-48)*puissance(k-y-1);}
		//k=0;
		token1.value=j;
		token1.type=NUMBER;
	
	}
	
	else {	
	
	if (chaine[i] == ' '){ }
		
	else{
		
		
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
    			} //else if (chaine[i] == ' ') {}
    			 else {
        			//printf("choix invalide\n");
    			}}
		else{	
		
			if(l!=0){
				float j=0;
				for(int y=0;y<l-1;y++){j=j+(chaine[i+y-l+2]-48)/(puissance(1+y));}
				//token1.value=token1.value+j;
				//AppendTokenQueue(&queue, token1);
				}
				
			else{
			float j=0;
			
			for(int y=0;y<k;y++){j=j+(chaine[i+y-k]-48)*puissance(k-y-1);}
			token1.value=j;
			token1.type=NUMBER;
			AppendTokenQueue(&queue, token1);}
			k=0;
			l=0;
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
    			} //else if (chaine[i] == ' ') {}
    			
    			 else {
        			//printf("choix invalide\n");
    			}


			
			
			}
	}}i=i+1;}
return queue;
}

int main(){
//float x=1+0.1;
char chaine1[100];
//char chaine[]   /*malloc(sizeof(char)*200)*/;
fgets(chaine1,sizeof(chaine1), stdin);
//printf("yg %f, %f\n",x ,puissance(1));
int t=strlen(chaine1);
char *chaine = (char *)malloc((t + 1) 
* sizeof(char));
strcpy(chaine,chaine1);
TokenQueue AD=lexical(chaine);
printf("%s\n", chaine);
PrintTokenQueue(&AD);
//free(chaine);
}


