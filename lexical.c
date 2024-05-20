#include<stdio.h>
#include<ctype.h>
#include"utils.h"
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include <gtk/gtk.h>
#include <glib.h>



double puissance(int p){
if(p==0){return 1;}
else if(p>0){int r=1;
for(int q=0; q<p;q++){r=r*10;}
return r;}
else{int r=1;
for(int q=0; q<-p;q++){r=r/10;}
return r;}}






TokenQueue lexical(char * chaine){






TokenQueue queue=CreateTokenQueue();
Token token1;
// i PARCOURT LA CHAINE DE CARACTERE
int i=0;
// k COMPTEUR DES ENTIERS AVANT LA VIRGULE
int k=0;
// l COMPTEUR DES ENTIERS DERRIERE LA VIRGULE
int l=0;


//ON PARCOURT LA CHAINE DE CARACTERE



while(chaine[i]!='\0') {

	
	
	     if(isdigit(chaine[i])){
	     
		if(l!=0){
		//SI l!=0 ça veut dire qu'on a deja depassé la virgule donc on compte les entiers l
		l=l+1;
		
		
			
			if(chaine[i+1]=='\0'){
			
			double j=0;

				for(int y=0;y<l-1;y++){
				double f=chaine[i+y-l+2]-48;
				j=j+f/(puissance(1+y));
				}
				token1.value+=j;
				token1.type=NUMBER;
				AppendTokenQueue(&queue, token1);
				break;
					     }
			}
		
		
		else{
		//Si l=0 on compte les entiers avec k
		k=k+1;
		
			if(chaine[i+1]=='\0'){

				double j=0;
				for(int y=0;y<k;y++){j=j+(chaine[i+y-k+1]-48)*puissance(k-y-1);}
						token1.value=j;
						token1.type=NUMBER;
						AppendTokenQueue(&queue, token1);
					}
				}
		
		}
		
	else if(chaine[i]=='.' || chaine[i]==',' ){l=l+1;
		double j=0;
		for(int y=0;y<k;y++){j=j+(chaine[i-k+y]-48)*puissance(k-y-1);
					}
		token1.value=j;
		token1.type=NUMBER;
	
	}
	
	else {	
	
		
		
		if(k==0){Token token2;
			
			 
    			if (chaine[i] == '+') {
        			token2.type = ADD;
        			AppendTokenQueue(&queue, token2);
    			} else if (chaine[i] == '-') {
    			
    			//Tout ce qui suit pour mettre par exemple 0-2 dans le cas où l'utilisateur en -2
        			token2.type = SUB;
        			if(i==0){Token token_={NUMBER, 0};
    				AppendTokenQueue(&queue, token_);}
    				else{
        			int u=1;
        			while(chaine[i-u]==' '){u=u+1;}
        			if(!isdigit(chaine[i-u]) && chaine[i-u]!=')' && chaine[i-u]!='x' && chaine[i-u]!='i' && chaine[i-u]!='e' && chaine[i-u]!='I' && chaine[i-u]!='a'){Token token_={NUMBER,0};
    				AppendTokenQueue(&queue, token_);}}
        			AppendTokenQueue(&queue, token2);
        			
    			} else if (chaine[i] == '*') {
        			token2.type = MUL;
        			AppendTokenQueue(&queue, token2);
    			} else if (chaine[i] == '=') {
        			token2.type = EQUAL;
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
    			
    			} else if (chaine[i] == '^'){
    				token2.type = POW;
    				AppendTokenQueue(&queue, token2);
    				
    			} else if(chaine[i] == 'S' && chaine[i+1] == 'I' && chaine[i+2]=='N'){
    				token2.type= SIN;
    				AppendTokenQueue(&queue, token2);
    				
    			} else if(chaine[i] == 'C' && chaine[i+1] == 'O' && chaine[i+2] == 'S'){
    				token2.type= COS;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'E' && chaine[i+1] == 'X' && chaine[i+2] == 'P'){
    				token2.type= EXP;
    				AppendTokenQueue(&queue, token2);
    			}
    			 else if(chaine[i]=='P' && chaine[i+1]=='I'){
    				token2.type= PI;
    				token2.value=3.14159265358979323846;
    				AppendTokenQueue(&queue, token2);
    			
    			} else if(chaine[i]=='e'){
    				token2.type=E;
    				token2.value=2.71828;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'T' && chaine[i+1] == 'A' && chaine[i+2] == 'N'){
    				token2.type= TAN;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'L' && chaine[i+1] == 'O' && chaine[i+2] == 'G'){
    				token2.type= LOG;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'I' && chaine[i+1] == 'N' && chaine[i+2] == 'T' && chaine[i+3]=='G' && chaine[i+4]=='L'){
    				token2.type= INTEGRAL;
    				AppendTokenQueue(&queue, token2);
    			}  else if(chaine[i] == 'A' && chaine[i+1] == 'S' && chaine[i+2] == 'S' && chaine[i+3]=='I' && chaine[i+4]=='G'){
    				token2.type= ASS;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'S' && chaine[i+1] == 'O' && chaine[i+2] == 'L' && chaine[i+3]=='V' && chaine[i+4]=='E'){
    				token2.type= SOLV;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'x'){
    				token2.type= VAR ;
    				token2.value=0;
    				token2.coeff=1;
    				token2.name='x';
    				token2.name2="x²";
    				token2.name3="x³";
    				token2.name4="x⁴";
    				token2.name5="x⁵";
    				token2.estim=0;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'a'){
    				token2.type= VAR ;
    				token2.value=0;
    				token2.coeff=1;
    				token2.name='a';
    				token2.name2="a²";
    				token2.name3="a³";
    				token2.name4="a⁴";
    				token2.name5="a⁵";
    				token2.estim=0;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'b'){
    				token2.type= VAR ;
    				token2.value=0;
    				token2.coeff=1;
    				token2.name='b';
    				token2.name2="b²";
    				token2.name3="b³";
    				token2.name4="b⁴";
    				token2.name5="b⁵";
    				token2.estim=0;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'c'){
    				token2.type= VAR ;
    				token2.value=0;
    				token2.coeff=1;
    				token2.name='c';
    				token2.name2="c²";
    				token2.name3="c³";
    				token2.name4="c⁴";
    				token2.name5="c⁵";
    				token2.estim=0;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'i'){
    				token2.type= VAR ;
    				token2.value=0;
    				token2.coeff=1;
    				token2.name='i';
    				token2.name2="i²";
    				token2.name3="i³";
    				token2.name4="i⁴";
    				token2.name5="i⁵";
    				token2.estim=1;
    				AppendTokenQueue(&queue, token2);
    				
    			} else if(chaine[i]==';'){
    				token2.type= PV;
    				AppendTokenQueue(&queue, token2);
    				
    			} else if(chaine[i] == 'g' && chaine[i+1] == 'a' && chaine[i+2] == 'm' && chaine[i+3]=='m' && chaine[i+4]=='a'){
    				token2.type=GAM;
    				token2.value=0.577215664901532;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'F' && chaine[i+1] == 'T' && chaine[i+2] == 'G' && chaine[i+3]=='A' && chaine[i+4]=='M' && chaine[i+5]=='M' && chaine[i+6]=='A'){
    				token2.type=FTGAM;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'Z' && chaine[i+1] == 'E' && chaine[i+2] == 'T' && chaine[i+3]=='A'){
    				token2.type=ZET;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'C' && chaine[i+1] == 'O' && chaine[i+2] == 'N' && chaine[i+3]=='J'){
    				token2.type=CONJU;
    				AppendTokenQueue(&queue, token2);
    				} else if(chaine[i]=='m' && chaine[i+1]=='a' && chaine[i+2]=='t'){
    				token2.type= MAT;
    				AppendTokenQueue(&queue, token2);
      				Token token3={LEFT_PAREN,0};
    				AppendTokenQueue(&queue, token3);
    				int p=0;
    				int m=0;
    				int n=0;
    				int o=0;
    				int v=0;
    				int w=0;
    				Token token4;
    				while(chaine[i+4+p]!=')'){
    					
    				o=o+1;	
    					if(isdigit(chaine[i+4+p])){
						if(m!=0){
							m=m+1;
		
		
		
			if(chaine[i+4+p+1]==',' || chaine[i+4+p+1]==';' || chaine[i+4+p+1]==')' ){
			
			double j=0;

				for(int y=0;y<m-1;y++){
				double f=chaine[i+4+p+y-m+2]-48;
				j=j+f/(puissance(1+y));
				}
				token4.value+=j;
				token4.type=NUMBER;
				AppendTokenQueue(&queue, token4);
				m=0;
				n=0;
				
				if(chaine[i+4+p+1]==';'){
				Token token5={PV,0};
				AppendTokenQueue(&queue, token5);
				p=p+1;
				o=o+1;
				w=w+1;}
				else if(chaine[i+4+p+1]==','){
				Token token5={V,0};
				AppendTokenQueue(&queue, token5);
				p=p+1;
				o=o+1;
				v=v+1;}
				else{}
				}}
		
		
						else{
	
							n=n+1;
		
			if(chaine[i+4+p+1]==',' || chaine[i+4+p+1]==';' || chaine[i+4+p+1]==')'){

			
			
				double j=0;
				for(int y=0;y<n;y++){j=j+(chaine[i+4+p+y-n+1]-48)*puissance(n-y-1);
;}
						token4.value=j;
						token4.type=NUMBER;
						AppendTokenQueue(&queue, token4);
						m=0;
						n=0;
						if(chaine[i+4+p+1]==';'){
						Token token5={PV,0};
						AppendTokenQueue(&queue, token5);
						p=p+1;
						o=o+1;
						w=w+1;}
						else if(chaine[i+4+p+1]==','){
						Token token5={V,0};
						AppendTokenQueue(&queue, token5);
						p=p+1;
						o=o+1;
						v=v+1;}
						else{}
						
					}
				}
		
		}
		
	else if(chaine[i+4+p]=='.' ){m=m+1;
		double j=0;
		for(int y=0;y<n;y++){j=j+(chaine[i+4+p-n+y]-48)*puissance(n-y-1);}

		
		token4.value=j;
		token4.type=NUMBER;
	
	} else if(chaine[i+4+p]==' '){ 
	
	if(chaine[i+4+p+1]==')'){
	
		if(m!=0){
		double j=0;

				for(int y=0;y<m-1;y++){
				double f=chaine[i+4+p+y-m+2]-48;
				j=j+f/(puissance(1+y));
				
				}
				token4.value+=j;
				token4.type=NUMBER;
				AppendTokenQueue(&queue, token4);
				m=0;
				n=0;
				}
				
		else{
		
		double j=0;
				for(int y=0;y<n;y++){j=j+(chaine[i+4+p+y-n+1-1]-48)*puissance(n-y-1);
							
							}
						token4.value=j;
						token4.type=NUMBER;
						AppendTokenQueue(&queue, token4);
						m=0;
						n=0;}} }
	
	p=p+1;}
	Token token6={RIGHT_PAREN, 0};
	AppendTokenQueue(&queue, token6);
	i=i+o+4;
	token2.value=w+1+pow(10,-1)*(v/(w+1)+1);
	
	
    				   				
    				
    			} else {
        			
    			}}
		else{	
		
			if(l!=0){
			
			
				double j=0;
				for(int y=0;y<l-1;y++){
				double f=chaine[i+y-l+1]-48;
				j=j+f/(puissance(1+y));
				}
				token1.value+=j;
				token1.type=NUMBER;
				AppendTokenQueue(&queue, token1);
				l=0;
				k=0;
				}
				
			else{
			double j=0;
			
			for(int y=0;y<k;y++){j=j+(chaine[i+y-k]-48)*puissance(k-y-1);}
			token1.value=j;
			token1.type=NUMBER;
			AppendTokenQueue(&queue, token1);
			k=0;
			l=0;
			}

			Token token2;
			
			 

    			if (chaine[i] == '+') {
        			token2.type = ADD;
        			AppendTokenQueue(&queue, token2);
    			} else if (chaine[i] == '-') {
        			token2.type = SUB;
        			if(i==0){Token token_={NUMBER, 0};
    				AppendTokenQueue(&queue, token_);}
    				else{
        			int u=1;
        			while(chaine[i-u]==' '){u=u+1;}
        			if(!isdigit(chaine[i-u]) && chaine[i-u]!=')' && chaine[i-u]!='x' && chaine[i-u]!='i' && chaine[i-u]!='e' && chaine[i-u]!='I' && chaine[i-u]!='a'){Token token_={NUMBER, 0};
    				AppendTokenQueue(&queue, token_);}}
        			AppendTokenQueue(&queue, token2);
    			} else if (chaine[i] == '*') {
        			token2.type = MUL;
        			AppendTokenQueue
        			(&queue, token2);
    			} else if (chaine[i] == '=') {
        			token2.type = EQUAL;
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
    			
    			} else if (chaine[i] == '^'){
    				token2.type = POW;
    				AppendTokenQueue(&queue, token2);
    				
    			} else if(chaine[i] == 'S' && chaine[i+1] == 'I' && chaine[i+2]=='N'){
    				token2.type= SIN;
    				AppendTokenQueue(&queue, token2);
    				
    			} else if(chaine[i] == 'C' && chaine[i+1] == 'O' && chaine[i+2] == 'S'){
    				token2.type= COS;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'E' && chaine[i+1] == 'X' && chaine[i+2] == 'P'){
    				token2.type= EXP;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i]=='P' && chaine[i+1]=='I'){
    				token2.type= PI;
    				token2.value=3.14159265358979323846;
    				AppendTokenQueue(&queue, token2);
    			
    			} else if(chaine[i]=='e'){
    				token2.type=E;
    				token2.value=2.71828;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'T' && chaine[i+1] == 'A' && chaine[i+2] == 'N'){
    				token2.type= TAN;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'L' && chaine[i+1] == 'O' && chaine[i+2] == 'G'){
    				token2.type= LOG;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'I' && chaine[i+1] == 'N' && chaine[i+2] == 'T' && chaine[i+3]=='G' && chaine[i+4]=='L'){
    				token2.type= INTEGRAL;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'A' && chaine[i+1] == 'S' && chaine[i+2] == 'S' && chaine[i+3]=='I' && chaine[i+4]=='G'){
    				token2.type= ASS;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'S' && chaine[i+1] == 'O' && chaine[i+2] == 'L' && chaine[i+3]=='V' && chaine[i+4]=='E'){
    				token2.type= SOLV;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'x'){
    				token2.type= VAR ;
    				token2.value=0;
    				token2.coeff=1;
    				token2.name='x';
    				token2.name2="x²";
    				token2.name3="x³";
    				token2.name4="x⁴";
    				token2.name5="x⁵";
    				token2.estim=0;
    				AppendTokenQueue(&queue, token2);
    				
    			} else if(chaine[i] == 'a'){
    				token2.type= VAR ;
    				token2.value=0;
    				token2.coeff=1;
    				token2.name='a';
    				token2.name2="a²";
    				token2.name3="a³";
    				token2.name4="a⁴";
    				token2.name5="a⁵";
    				token2.estim=0;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'b'){
    				token2.type= VAR ;
    				token2.value=0;
    				token2.coeff=1;
    				token2.name='b';
    				token2.name2="b²";
    				token2.name3="b³";
    				token2.name4="b⁴";
    				token2.name5="b⁵";
    				token2.estim=0;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'c'){
    				token2.type= VAR ;
    				token2.value=0;
    				token2.coeff=1;
    				token2.name='c';
    				token2.name2="c²";
    				token2.name3="c³";
    				token2.name4="c⁴";
    				token2.name5="c⁵";
    				token2.estim=0;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'i'){
    				token2.type= VAR ;
    				token2.value=0;
    				token2.coeff=1;
    				token2.name='i';
    				token2.name2="i²";
    				token2.name3="i³";
    				token2.name4="i⁴";
    				token2.name5="i⁵";
    				token2.estim=1;
    				AppendTokenQueue(&queue, token2);
    				
    			} else if(chaine[i]==';'){
    				token2.type= PV;
    				AppendTokenQueue(&queue, token2);
    				
    			} else if(chaine[i] == 'g' && chaine[i+1] == 'a' && chaine[i+2] == 'm' && chaine[i+3]=='m' && chaine[i+4]=='a'){
    				token2.type=GAM;
    				token2.value=0.577215664901532;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'F' && chaine[i+1] == 'T' && chaine[i+2] == 'G' && chaine[i+3]=='A' && chaine[i+4]=='M' && chaine[i+5]=='M' && chaine[i+6]=='A'){
    				token2.type=FTGAM;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'Z' && chaine[i+1] == 'E' && chaine[i+2] == 'T' && chaine[i+3]=='A'){
    				token2.type=ZET;
    				AppendTokenQueue(&queue, token2);
    			} else if(chaine[i] == 'C' && chaine[i+1] == 'O' && chaine[i+2] == 'N' && chaine[i+3]=='J'){
    				token2.type=CONJU;
    				AppendTokenQueue(&queue, token2);
    				} else if(chaine[i]=='m' && chaine[i+1]=='a' && chaine[i+2]=='t'){
    				token2.type= MAT;
    				AppendTokenQueue(&queue, token2);
      				Token token3={LEFT_PAREN,0};
    				AppendTokenQueue(&queue, token3);
    				int p=0;
    				int m=0;
    				int n=0;
    				int o=0;
    				int w=0;
    				int v=0;
    				Token token4;
    				while(chaine[i+4+p]!=')'){
    					
    				o=o+1;	
    					if(isdigit(chaine[i+4+p])){
						if(m!=0){
							m=m+1;
		
		
		
			if(chaine[i+4+p+1]==',' || chaine[i+4+p+1]==';' || chaine[i+4+p+1]==')' ){
			
			double j=0;

				for(int y=0;y<m-1;y++){
				double f=chaine[i+4+p+y-m+2]-48;
				j=j+f/(puissance(1+y));
				}
				token4.value+=j;
				token4.type=NUMBER;
				AppendTokenQueue(&queue, token4);
				m=0;
				n=0;
				
				if(chaine[i+4+p+1]==';'){
				Token token5={PV,0};
				AppendTokenQueue(&queue, token5);
				p=p+1;
				o=o+1;
				w=w+1;}
				else if(chaine[i+4+p+1]==','){
				Token token5={V,0};
				AppendTokenQueue(&queue, token5);
				p=p+1;
				o=o+1;
				v=v+1;}
				else{}
				
				}}
		
		
						else{
	
							n=n+1;
		
			if(chaine[i+4+p+1]==',' || chaine[i+4+p+1]==';' || chaine[i+4+p+1]==')'){

			
			
				double j=0;
				for(int y=0;y<n;y++){j=j+(chaine[i+4+p+y-n+1]-48)*puissance(n-y-1);
							;}
						token4.value=j;
						token4.type=NUMBER;
						AppendTokenQueue(&queue, token4);
						m=0;
						n=0;
						if(chaine[i+4+p+1]==';'){
						Token token5={PV,0};
						AppendTokenQueue(&queue, token5);
						p=p+1;
						o=o+1;
						w=w+1;}
						else if(chaine[i+4+p+1]==','){
						Token token5={V,0};
						AppendTokenQueue(&queue, token5);
						p=p+1;
						o=o+1;
						v=v+1;}
						else{}
						
					}
				}
		
		}
		
	else if(chaine[i+4+p]=='.'){m=m+1;
		double j=0;
		for(int y=0;y<n;y++){j=j+(chaine[i+4+p-n+y]-48)*puissance(n-y-1);

					}
		
		token4.value=j;
		token4.type=NUMBER;
	
	} else if(chaine[i+4+p]==' '){ 
	
	if(chaine[i+4+p+1]==')'){
	
		if(m!=0){
		
		double j=0;

				for(int y=0;y<m-1;y++){
				double f=chaine[i+4+p+y-m+2]-48;
				j=j+f/(puissance(1+y));
				
				}
				token4.value+=j;
				token4.type=NUMBER;
				AppendTokenQueue(&queue, token4);
				m=0;
				n=0;
				}
				
		else{
		double j=0;
				for(int y=0;y<n;y++){j=j+(chaine[i+4+p+y-n+1-1]-48)*puissance(n-y-1);
							
							;}
						token4.value=j;
						token4.type=NUMBER;
						AppendTokenQueue(&queue, token4);
						m=0;
						n=0;}} }
	
	p=p+1;}
	Token token6={RIGHT_PAREN, 0};
	AppendTokenQueue(&queue, token6);
	i=i+o+4;
	token2.value=w+1+pow(10,-1)*(v/(w+1)+1);
	
	
    				
    				
    				
    				
    				
    				
    				
    				
    				
    				
    				
    				
    			} else {
        			
    			}


			
			
			}
	}i=i+1;}
return queue;
}



