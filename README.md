# [IN104] MiniWolfram Project
**LEGROS Gabriel & CAMARA Fodé Amadou & KOUASSI Franck Wilson**

## I) INTRODUCTION

Le projet "MiniWolfram" a pour objectif de créer une version simplifiée d'un calculateur mathématique de type Wolfram, capable d'effectuer des calculs arithmétiques de base, d'évaluer des fonctions mathématiques et de résoudre des expressions algébriques simples. Ce projet nous a permis de développer une calculatrice avec de nombreuses fonctionnalités que nous détaillerons ci-dessous, ainsi que les limites de certaines fonctionnalités.

## II) LES DIFFERENTS AXES DU PROJET

### 1) MANIPULATION ET ADAPTATION DES TOKENS DANS LE LEXER

Le rôle du lexer (analyseur lexical) est de convertir une chaîne de caractères en une séquence de tokens représentant des entiers, réels, opérateurs, variables, parenthèses, etc. Voici les détails concernant le traitement de différents types de tokens :

#### CAS DES ENTIERS
Le lexer identifie les séquences de chiffres comme des tokens d'entiers. Il lit chaque caractère un par un et lorsque l'analyse rencontre un caractère non numérique, il génère un token correspondant à un entier.

#### CAS DES REELS
Les réels sont traités de manière similaire aux entiers, avec une gestion supplémentaire des parties décimales. Le lexer lit la chaîne et, lorsqu'il rencontre un point ou une virgule, il reconstruit le nombre réel.

#### CAS DES VARIABLES
Nous avons étendu la gestion des tokens pour permettre la manipulation de variables. Le lexer prend en charge des variables nommées `name`, `name2`, `name3`, `name4`, et `name5`, chacune associée à un coefficient (par exemple, `name` correspond à la variable `x` et `Coeff` au coefficient de `x`).

#### CAS DES NOMBRES COMPLEXES
Nous avons choisi de traiter l'unité imaginaire `i` comme une variable, ce qui nous permet de gérer les nombres complexes à l'aide de la valeur `estim` dans le lexer.

### 2) FONCTIONNEMENT DU PARSER AVEC L'ALGO DE SHUNTING-YARD

L'algorithme de Shunting-Yard est utilisé pour convertir une expression infixée en une expression postfixée (notation polonaise inverse ou RPN). Ce processus permet de respecter les priorités des opérateurs et de gérer les parenthèses correctement.

Le parser utilise une pile pour les opérateurs et une queue pour l'expression postfixée. Il analyse chaque token un par un et décide de l'ajouter à la pile ou à la queue selon sa nature.

### 3) EVALUATION DE L'EXPRESSION RPN AVEC UN ALGO BASE SUR LES PILES

Une fois l'expression convertie en RPN, nous utilisons une pile pour évaluer l'expression :

1. On pousse les opérandes sur la pile.
2. Lorsqu'un opérateur est rencontré, on extrait les opérandes et on applique l'opération.
3. Le résultat est ensuite poussé sur la pile.
4. Après avoir traité tous les tokens, la pile contiendra le résultat final.

En plus, pour les intégrales, une vérification est effectuée pour détecter et calculer les expressions intégrales, comme expliqué dans le fichier `evaluation.c`.

## III) FONCTIONNALITES IMPLEMENTEES

Les fonctionnalités suivantes sont disponibles dans l'interface graphique :

1. **Cosinus** : Exemple : `COS(PI)`
2. **Sinus** : Exemple : `SIN(PI/2)`
3. **Tangente** : Exemple : `TAN(PI/4)`
4. **Logarithme** : Exemple : `LOG(e)`
5. **Exponentielle réelle** : Exemple : `EXPO(2)`
6. **Exponentielle complexe** : Exemple : `EXPO(i*PI)`
7. **Puissance** : Exemple : `0.1^2`, `4^0.5`
8. **Fonction Gamma** : Exemple : `FTGAMMA(4)` (résout la factorielle généralisée)
9. **Fonction Zêta de Riemann** : Exemple : `ZETA(2) = PI^2 / 6`
10. **Variables (x, a, b, c)** : Exemple : `(1-x)(1+x) = 1-x^2`
11. **Assigner une valeur à une variable** : Exemple : `ASSIGNED(x=4)`
12. **Nombres complexes** : Exemple : `(1+i)(1-i)`, `(1+i)^2`
13. **Conjugué d'un nombre complexe** : Exemple : `CONJ(5+6i)`
14. **Résolution d'équations** : Exemple : `SOLVE(4x-2=7 ;x)`
15. **Intégrale** : Exemple : `INTGL(1/(1+X^2) ;0 ;1) + 13`

### Remarques :
- Les variables `x`, `a`, `b`, et `c` ne doivent pas être mélangées dans une même expression.
- Les calculs sur les nombres complexes utilisent `i` comme unité imaginaire.
- La résolution d'équations est limitée à des équations linéaires et quadratiques.

## IV) INTERFACE GRAPHIQUE

Nous avons utilisé la bibliothèque GTK+ pour gérer l'interface graphique. Voici les commandes pour installer GTK+ sur différents systèmes d'exploitation :

- **Sous Linux** : 
- **Sous Windows** : Utilisez MSYS2 pour installer GTK+.

## V) COMMENT FAIRE MARCHER NOTRE CODE (MAKEFILE)

Pour automatiser la compilation, nous utilisons un fichier Makefile. Voici la commande pour exécuter le Makefile et compiler le programme :

```bash
make
