#include<stdio.h>
#include<ctype.h>
#include"utils.h"
#include<stdlib.h>
#include"lexical.h"

TokenQueue syntax_analysis(TokenQueue *queue){
    TokenStack operation = CreateTokenStack();
TokenQueue queue2=CreateTokenQueue();
    while (!IsEmptyTokenQueue(queue)) {
        Token token = PopTokenQueue(queue);
        


        switch (token.type) {
            case NUMBER:
                AppendTokenQueue(&queue2,token);
		// on ajoute le token à la queue si c'est un nombre
                break;
            case SIN:
            	PushTokenStack(&operation,token);
            	break;
            case COS:
            	PushTokenStack(&operation,token);
            	break;
            case EXP:
            	PushTokenStack(&operation,token);
            	break;
            case PI:
            	AppendTokenQueue(&queue2,token);
            	break;
            case E:
            	AppendTokenQueue(&queue2,token);
            	break;
            case TAN:
            	PushTokenStack(&operation,token);
            	break;
            case LOG:
            	PushTokenStack(&operation,token);
            	break;
            case CONJU:
            	PushTokenStack(&operation,token);
            	break;
            case MAT:
            	PushTokenStack(&operation,token);
            	break;
            case PV:
            	while(PeekTokenStack(&operation).type!=LEFT_PAREN){
            	AppendTokenQueue(&queue2, PopTokenStack(&operation));
            	}
            
            	break;
            case INTEGRAL:
            	PushTokenStack(&operation,token);
            	break;
            case SOLV:
            	PushTokenStack(&operation,token);
            	break;
            case ASS:
            	PushTokenStack(&operation,token);
            	break;
            case FTGAM:
            	PushTokenStack(&operation,token);
            	break;
            case ZET:
            	PushTokenStack(&operation,token);
            	break;
            case GAM:
            	AppendTokenQueue(&queue2,token);
            	break;
            case VAR:
            	AppendTokenQueue(&queue2,token);
            	break;
            case EQUAL:
            case ADD:
            case SUB:
            case MUL:
            case DIV:
            case MOD:
            case POW:
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

