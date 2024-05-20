#include "utils.h"

#include <stdio.h>
#include <stdlib.h>



int TokenPrecedence(Token token) {
    if (token.type == NUMBER) {
        fprintf(stderr, "Tried to get precedence of number\n");
        exit(1);
    }
    int precedences[] = {-1, 0, 0, 1, 1, 1, 3, 3, 2, 3, 3, 3, -1, -1, 3, 3, 3, 4, 4, 3, -1, 3, -1,3/*,-1*/,3,-1,3,-2};
    return precedences[token.type];
}

TokenStack CreateTokenStack(void) {
    TokenStack token_stack;
    for (int i = 0; i < MAX_TOKENS; i++) {
        Token token = {0, 0};
        token_stack.tokens[i] = token;
    }
    token_stack.length = 0;
    return token_stack;
}

void PushTokenStack(TokenStack *stack, Token token) {
    if (stack->length == MAX_TOKENS) {
        fprintf(stderr, "Tried to push to full stack\n");
        exit(1);
    }
    stack->tokens[stack->length++] = token;
}

Token PopTokenStack(TokenStack *stack) {
    if (stack->length == 0) {
        fprintf(stderr, "Tried to pop from empty stack\n");
        exit(1);
    }
    return stack->tokens[--stack->length];
}

Token PeekTokenStack(TokenStack *stack) {
    if (stack->length == 0) {
        fprintf(stderr, "Tried to peek from empty stack\n");
        exit(1);
    }
    return stack->tokens[stack->length - 1];
}

int IsEmptyTokenStack(TokenStack *stack) {
    return stack->length == 0;
}


TokenQueue CreateTokenQueue(void) {
    TokenQueue token_array;
    for (int i = 0; i < MAX_TOKENS; i++) {
        Token token = {0, 0};
        token_array.tokens[i] = token;
    }
    token_array.length = 0;
    return token_array;
}

void AppendTokenQueue(TokenQueue *array, Token token) {
    if (array->length == MAX_TOKENS) {
        fprintf(stderr, "Tried to append to full array\n");
        exit(1);
    }
    array->tokens[array->length++] = token;
}

/*void AppendTokenQueueQueue(TokenQueueQueue *array, TokenQueue token) {
    if (array->length == MAX_TOKENS) {
        fprintf(stderr, "Tried to append to full array\n");
        exit(1);
    }
    array->tokens[array->length++] = token;
}*/

Token PopTokenQueue(TokenQueue *array) {
    if (array->length == 0) {
        fprintf(stderr, "Tried to pop from empty array\n");
        exit(1);
    }
    Token res = array->tokens[0];
    for (int i = 0; i < array->length - 1; i++) {
        array->tokens[i] = array->tokens[i + 1];
    }
    array->length--;
    return res;
}

int IsEmptyTokenQueue(TokenQueue *array) {
    return array->length == 0;
}

void ReverseTokenQueue(TokenQueue *array) {
    for (int i = 0; i < array->length / 2; i++) {
        Token temp = array->tokens[i];
        array->tokens[i] = array->tokens[array->length - i - 1];
        array->tokens[array->length - i - 1] = temp;
    }
}

void PrintTokenQueue(TokenQueue *tokens) {
    const char *TokenTypeStrings[] = {
        "NUMBER", "+", "-", "*", "/", "%", "(", ")", "^", "SIN","COS","EXP", "PI", "e","TAN","LOG", "mat","," ,";", "INTGL","x","FTGAMMA","gamma","ZETA","CONJ","=","SOLVE","ASSIGNED",/*"i",*/
    };
    for (int i = 0; i < tokens->length; i++) {
        Token token = tokens->tokens[i];
        if (token.type == NUMBER) {
            printf("%.4f", token.value);

        } else if(token.type== VAR){
        
        
        
        
	    if(token.coeff==1){
            printf("%c",token.name);}
            else if(token.coeff==0){
            
            } else{
            printf("%f%c",token.coeff, token.name); }
            
            if(token.coeff2>0){printf("+");} 
             
            if(token.coeff2==1){
            printf("%s",token.name2);}
            else if(token.coeff2==0){
            
            }else{
            printf("%f%s",token.coeff2, token.name2); }
            
            if(token.coeff3>0){printf("+");} 
             
            if(token.coeff3==1){
            printf("%s",token.name3);}
            else if(token.coeff3==0){
            
            } else{
            printf("%f%s",token.coeff3, token.name3); }
            
            if(token.coeff4>0){printf("+");} 
             
            if(token.coeff4==1){
            printf("%s",token.name4);}
            else if(token.coeff4==0){
            
            } else{
            printf("%f%s",token.coeff4, token.name4); }
            
            if(token.coeff5>0){printf("+");} 
             
            if(token.coeff5==1){
            printf("%s",token.name5);}
            else if(token.coeff5==0){
            
            } else{
            printf("%f%s",token.coeff5, token.name5); }
            
                  
        }
          else {
            printf("%s", TokenTypeStrings[token.type]);
        }
    }
    printf("\n");
}

void PrintTokenQueueMat(TokenQueue *tokens) {

    for (int i = 0; i < tokens->length; i++) {
        Token token = tokens->tokens[i];
        if (token.type == NUMBER) {
            printf("%.4f", token.value);
        } 
        else if (token.type == V) {
            printf("  ");
        } 
	else if (token.type == PV) {
            printf("\n");
        }
         
}printf("\n");
}
void PrintTokenStack(TokenStack *stack) {
    const char *TokenTypeStrings[] = {
        "NUMBER", "+", "-", "*", "/", "%", "(", ")", "^", "SIN","COS","EXP", "PI" , "e","TAN","LOG", "mat","," ,";","INTGL",  "x","FTGAMMA","gamma","ZETA","CONJ","=","SOLVE","ASSIGNED",/*"i",*/
    };
    for (int i = stack->length - 1; i >= 0; i--) {
        Token token = stack->tokens[i];
        if (token.type == NUMBER) {
            printf("%.4f", token.value);

        } else if(token.type== VAR){
	    if(token.coeff==1){
            printf("%c",token.name);}
            else{
            printf("%f%c",token.coeff, token.name); }        
        } else {
            printf("%s", TokenTypeStrings[token.type]);
        }
    }
    printf("\n");
}
