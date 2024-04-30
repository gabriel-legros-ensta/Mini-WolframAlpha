#include<stdio.h>
#include<ctype.h>
#include"utils.h"
#include<stdlib.h>
#include"syntax_analysis.h"
#include"lexical.h"


/*    J'utilise un algorithme basé sur une pile

je commence par initialiser une pile vide.
je parcours chaque élément de l'expression RPN
Si c'est un nombre, on le place sur la pile.
Si c'est un opérateur, on applique l'opération correspondante aux deux derniers éléments de la pile, puis on empile le résultat.
Une fois tous les éléments de l'expression traités, la pile ne contient qu'un seul élément, qui est le résultat de l'évaluation de l'expression.*/
    
double evaluation (TokenQueue queue){

TokenQueue nombre=CreateTokenQueue();

int k=0;
while(!IsEmptyTokenQueue(&queue)){
	Token token =PopTokenQueue(&queue);
	if(token.type==NUMBER){AppendTokenQueue(&nombre, token);}
	else{
			
			ReverseTokenQueue(&nombre);
			Token token1=PopTokenQueue(&nombre);
			Token token2=PopTokenQueue(&nombre);
			ReverseTokenQueue(&nombre);
	switch(token.type){
	case ADD:
		token1.value=token1.value+token2.value;
		
		AppendTokenQueue(&nombre, token1);
		
		break;
	case SUB:
		token1.value=token2.value-token1.value;
		
		AppendTokenQueue(&nombre, token1);
		
		break;
	case MUL:
		token1.value=token1.value*token2.value;
		
		AppendTokenQueue(&nombre, token1);
		
		break;
	case DIV:
		token1.value=token2.value/token1.value;
		
		AppendTokenQueue(&nombre, token1);
		
		break;
	case MOD:
		token1.value=token2.value % token1.value ;
		
		AppendTokenQueue(&nombre, token1);
		
		break;
	default:
		break;
	}}
	k=k+1;}
	
	Token tokenresult=PopTokenQueue(&nombre);
	
	return tokenresult.value;
	}
int main(){




char chaine[100];
fgets(chaine,sizeof(chaine), stdin);

TokenQueue AD=lexical(chaine);


 TokenQueue queue=syntax_analysis(&AD);

 //exemple ayant permis de vérifier toutes les fonction simultanément 






    
    /*Token token1 = {NUMBER, 5};
    Token token2 = {ADD, 0};
    Token token3 = {NUMBER, 3};
    Token token4 = {MUL, 0};
    Token token5 = {NUMBER, 2};
    Token token7 = {MOD, 0};
    Token token8 = {NUMBER, 4};
    //exemple (5+3*2)*4
    
    TokenQueue queue = CreateTokenQueue();
    
    
    AppendTokenQueue(&queue, token1);
    AppendTokenQueue(&queue, token3);
    AppendTokenQueue(&queue, token5);
    AppendTokenQueue(&queue, token4);
    AppendTokenQueue(&queue, token2);
    AppendTokenQueue(&queue, token8);
    AppendTokenQueue(&queue, token7);*/
    //532*+4%
    
    
    
    
    
    double x=evaluation(queue);
    printf("le resultat est %g \n",x);
    }
   
