#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

// Déclaration de la fonction is_operator
int is_operator(char c);

// Fonction pour le lexer
TokenQueue lexer(const char *input) {
    TokenQueue tokenQueue = CreateTokenQueue();
    int i = 0;

    while (input[i] != '\0') {
        if (isspace(input[i])) {
            // Ignorer les espaces
            i++;
            continue;
        } else if (isdigit(input[i])) {
            // Parser les nombres
            int value = 0;
            while (isdigit(input[i])) {
                value = value * 10 + (input[i] - '0');
                i++;
            }
            Token token = {NUMBER, value};
            AppendTokenQueue(&tokenQueue, token);
        } else if (is_operator(input[i])) {
            // Parser les opérateurs
            Token token;
            switch (input[i]) {
                case '+':
                    token.type = ADD;
                    break;
                case '-':
                    token.type = SUB;
                    break;
                case '*':
                 token.type = MUL;
                    break;
                case '/':
                    token.type = DIV;
                    break;
                case '%':
                    token.type = MOD;
                    break;
                default:
                    fprintf(stderr, "Invalid character: %c\n", input[i]);
                    exit(EXIT_FAILURE);
            }
            AppendTokenQueue(&tokenQueue, token);
            i++;
        } else if (input[i] == '(' || input[i] == ')') {
            // Parser les parenthèses
            Token token;
            if (input[i] == '(') {
                token.type = LEFT_PAREN;
            } else { // input[i] == ')'
                token.type = RIGHT_PAREN;
            }
            AppendTokenQueue(&tokenQueue, token);
            i++;
        } else {
            fprintf(stderr, "Unknown character: %c\n", input[i]);
            exit(EXIT_FAILURE);
        }
    }

    return tokenQueue;
}

// Fonction principale
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <expression>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *expression = argv[1];
    TokenQueue tokens = lexer(expression);
    PrintTokenQueue(&tokens);

    return EXIT_SUCCESS;
}

// Définition de la fonction is_operator
int is_operator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}