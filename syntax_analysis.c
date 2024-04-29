#include<stdio.h>
#include<ctype.h>
#include"utils.h"
#include<stdlib.h>

TokenQueue syntax_analysis(TokenQueue *queue){
    TokenStack operation = CreateTokenStack();
TokenQueue queue2;
    while (!IsEmptyTokenQueue(queue)) {
        Token token = PopTokenQueue(queue);
        


        switch (token.type) {
            case NUMBER:
                AppendTokenQueue(&queue2,token);
		// on ajoute le token à la queue si c'est un nombre
                break;
            case ADD:
            case SUB:
            case MUL:
            case DIV:
            case MOD:
                while (!IsEmptyTokenStack(&operation) &&
                       (TokenPrecedence(token) <= TokenPrecedence(PeekTokenStack(&operation))))
                       {
                       if(PeekTokenStack(&operation).type != LEFT_PAREN){
                    AppendTokenQueue(&queue2, PopTokenStack(&operation));}
                    else{break;}
                    //on compare la providence du token et de l'element au sommet de la pile operation, s'il est plus faible que cet element on ajoute à la queue à condition qu'il soit différent de "(" parce que sinon on pourait se retrouver avec cette parenthese dans le resultat
                    
                }
                PushTokenStack(&operation, token);
                break;
            case LEFT_PAREN:
                PushTokenStack(&operation, token);
                break;
            case RIGHT_PAREN:
            
                while (!IsEmptyTokenStack(&operation) && PeekTokenStack(&operation).type != LEFT_PAREN) {
                    AppendTokenQueue(&queue2, PopTokenStack(&operation));
                }
                
                
                         if (IsEmptyTokenStack(&operation)) {
                     
                        printf("Mauvais parenthesage\n");
                        exit(1);
                    		}
                    	else{PopTokenStack(&operation);}
                    
                break;
            default:
                printf( "caractère invalide\n");
                exit(1);
        }
    }
    
    
    while (!IsEmptyTokenStack(&operation)) {

        AppendTokenQueue(&queue2, PopTokenStack(&operation));
    } 
    //on ajoute toutes les operations restantes 

return queue2;}

int main() {
    TokenQueue queue = CreateTokenQueue();
    
    
    Token token  = {LEFT_PAREN, 0};
    Token token1 = {NUMBER, 5};
    Token token2 = {ADD, 0};
    Token token3 = {NUMBER, 3};
    Token token4 = {MUL, 0};
    Token token5 = {NUMBER, 2};
    Token token6 = {RIGHT_PAREN, 0};
    Token token7 = {MOD, 0};
    Token token8 = {NUMBER, 4};
    //exemple: (5+3*2)%4
    
AppendTokenQueue(&queue, token);
    AppendTokenQueue(&queue, token1);
    AppendTokenQueue(&queue, token2);
    AppendTokenQueue(&queue, token3);
    AppendTokenQueue(&queue, token4);
    AppendTokenQueue(&queue, token5);
    AppendTokenQueue(&queue, token6);
    AppendTokenQueue(&queue, token7);
    AppendTokenQueue(&queue, token8);
    
    TokenQueue queue2=syntax_analysis(&queue);
    printf(" Queue2: ");
    PrintTokenQueue(&queue2);
    // resultat: 532*+4%, exact après vérification

    return 0;
}
