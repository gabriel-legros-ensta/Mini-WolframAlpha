#include<stdio.h>
#include<ctype.h>
#include"utils.h"
#include<stdlib.h>


/*    J'utilise un algorithme basé sur une pile

je commence par initialiser une pile vide.
je parcours chaque élément de l'expression RPN
Si c'est un nombre, on le place sur la pile.
Si c'est un opérateur, on applique l'opération correspondante aux deux derniers éléments de la pile, puis on empile le résultat.
Une fois tous les éléments de l'expression traités, la pile ne contient qu'un seul élément, qui est le résultat de l'évaluation de l'expression.*/
    
double evaluation (TokenQueue queue){

TokenQueue nombre=CreateTokenQueue();
TokenQueue tot=CreateTokenQueue();
int k=0;
while(!IsEmptyTokenQueue(&queue)){
	Token token =PopTokenQueue(&queue);
	if(token.type==NUMBER){AppendTokenQueue(&nombre, token);}
	else{
		if(IsEmptyTokenQueue(&tot)){
			ReverseTokenQueue(&nombre);
			Token token1=PopTokenQueue(&nombre);
			Token token2=PopTokenQueue(&nombre);
			ReverseTokenQueue(&nombre);
	switch(token.type){
	case ADD:
		token1.value=token1.value+token2.value;
		AppendTokenQueue(&tot, token1);
		break;
	case SUB:
		token1.value=token2.value-token1.value;
		AppendTokenQueue(&tot, token1);
		break;
	case MUL:
		token1.value=token1.value*token2.value;
		AppendTokenQueue(&tot, token1);
		break;
	case DIV:
		token1.value=token1.value/token2.value;
		AppendTokenQueue(&tot, token1);
		break;
	case MOD:
		token1.value=token1.value % token2.value;
		AppendTokenQueue(&tot, token1);
		break;}}
		
		
		
		
		
		else{
			
			Token token1=PopTokenQueue(&tot);
			Token token2=PopTokenQueue(&nombre);
	switch(token.type){
	case ADD:
		token1.value=token1.value+token2.value;
		AppendTokenQueue(&tot, token1);
		break;
	case SUB:
		token1.value=token1.value-token2.value;
		AppendTokenQueue(&tot, token1);
		break;
	case MUL:
		token1.value=token1.value*token2.value;
		AppendTokenQueue(&tot, token1);
		break;
	case DIV:
		token1.value=token1.value/token2.value;
		AppendTokenQueue(&tot, token1);
		break;
	case MOD:
		token1.value=(token1.value)%(token2.value);
		AppendTokenQueue(&tot, token1);
		break;
	}}}
	k=k+1;}
	Token tokenresult=PopTokenQueue(&tot);
	return tokenresult.value;
	}
int main(){
    
    Token token1 = {NUMBER, 5};
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
    AppendTokenQueue(&queue, token7);
    //532*+4%
    
    
    
    
    
    double x=evaluation(queue);
    printf("le resultat est %g \n",x);
    }
   
