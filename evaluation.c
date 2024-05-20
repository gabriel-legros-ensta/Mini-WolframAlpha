#include<stdio.h>
#include<ctype.h>
#include"utils.h"
#include<stdlib.h>
#include"syntax_analysis.h"
#include"lexical.h"
#include <math.h>
#include <gtk/gtk.h>
#include <string.h>
#include <glib.h>



static GtkWidget *entry;


//FONCTION POUR SI UN NOMBRE EST ENTIER
int estentier(double nombre) {
    return nombre == (int)nombre;
}




//FONCTION QUI ASSIGNE UNE VALEUR A UNE VARIABLE

TokenQueue ASSIGNED(TokenQueue nombre){

Token token=PopTokenQueue(&nombre);

Token token2=PopTokenQueue(&nombre);
token.value=token2.value;
token.coeff=0;
token.type=NUMBER;

AppendTokenQueue(&nombre,token);

return nombre;
}





//FONCTION QUI RESOUT DES EQUATIONS LINEAIRES ET QUADRATIQUES

TokenQueue SOLVE(TokenQueue queue){


Token token =PopTokenQueue(&queue);
Token token2 =PopTokenQueue(&queue);
Token token3 =PopTokenQueue(&queue);

if(IsEmptyTokenQueue(&queue)){
	if(token.coeff==0){
	} else {
	token3.value=(token2.value-token.value)/token.coeff;
	token3.type=NUMBER;
	token3.coeff=0;
	AppendTokenQueue(&queue,token3);
	}
}
else {
	Token token4=PopTokenQueue(&queue);
	if(IsEmptyTokenQueue(&queue)){
	double delta=token.coeff*token.coeff-4*token.coeff2*(token.value-token2.value);
	if(delta<0){printf("pas de solutions\n");
	
	} else if(delta==0){
	
	token3.value=-token.coeff/(2*token.coeff2);
	token3.type=NUMBER;
	token3.coeff=0;
	AppendTokenQueue(&queue,token3);
	
	
	} else {
	token3.value=(-token.coeff-sqrt(delta))/(2*token.coeff2);
	token4.value=(-token.coeff+sqrt(delta))/(2*token.coeff2);
	token3.type=NUMBER;
	token3.coeff=0;
	AppendTokenQueue(&queue,token3);
	token4.type=NUMBER;
	token4.coeff=0;
	AppendTokenQueue(&queue,token4);
	} 
	}
	else{}
}

Token token1;
token1.type=SOLV;
AppendTokenQueue(&queue, token1);
return queue;

}




//FONCTION CONJUGUEE D'UN NOMBRE COMPLEXE

Token CONJ(Token token){
token.coeff=-1*token.coeff;
return token;
}


//FONCTION GAMMA

double FTGAMMA(double z){


double gamma=-0.577215664901532;
if(z==1){return 1;


} else if(floor(z)==z){

double y=1;
for(int i=1;i<z;i++){
y=y*i;}
return y;


} else{
int n=1000000;
double j=1;
for(int k=1;k<=n;k++){
j=j*(exp(z/k)/(1+z/k));
}
j=j*exp(gamma*z)/z;
return j;
}
}


//FONCTION ZETA

double ZETA(double x){
int n=10000000;
if(x>1){
double j=1;
for(int k=2;k<=n;k++){
j=j+1/(pow(k,x));
}
return j;
}
else{printf("impossible de calculer zeta pour cette valeur\n");
return 0;}
}






//CALCUL D'INTEGRALE
//ON UTILISE LA FORMULE DE RIEMANN AVEC LES SOMME POUR LE CALCUL

double INTGL(TokenQueue queue){


ReverseTokenQueue(&queue);

Token tokene=PopTokenQueue(&queue);

//CE QUI VIENT JUSTE APRES POUR ETRE SÛR DE BIEN PRENDRE LES BORNES

if(tokene.type==SUB){tokene=PopTokenQueue(&queue);
			Token tokenu=PopTokenQueue(&queue);
			tokene.value=0-tokene.value;}
Token tokenee=PopTokenQueue(&queue);
if(tokenee.type==SUB){tokenee=PopTokenQueue(&queue);
			Token tokenv=PopTokenQueue(&queue);
			tokenee.value=0-tokenee.value;}

ReverseTokenQueue(&queue);

int n=1000000;
double j=0;
for(int i=1;i<=n;i++){

TokenQueue nombre=CreateTokenQueue();
TokenQueue queue1=queue;

while(!IsEmptyTokenQueue(&queue1)){
	
	Token token=PopTokenQueue(&queue1);
	
	
	  if(token.type==NUMBER){AppendTokenQueue(&nombre, token);
	} else if(token.type==VAR){
	token.value=tokenee.value+i*(tokene.value-tokenee.value)/n;
	
	AppendTokenQueue(&nombre, token);
	
	} else if(token.type==PI){AppendTokenQueue(&nombre, token);
	} else if(token.type==E){AppendTokenQueue(&nombre, token);
	} else if(token.type==GAM){AppendTokenQueue(&nombre, token);
	} else {
	
		if(token.type==SIN){
		ReverseTokenQueue(&nombre);
		
		Token token1=PopTokenQueue(&nombre);
		
		ReverseTokenQueue(&nombre);
		token1.value= sin(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		else if(token.type==COS){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= cos(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		
		else if(token.type==EXP){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= exp(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		else if(token.type==TAN){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= tan(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		
		else if(token.type==FTGAM){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= FTGAMMA(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		
		else if(token.type==ZET){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= ZETA(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		
		else if(token.type==LOG){
		ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= log(token1.value);
		
		AppendTokenQueue(&nombre, token1);}

		 else {
		ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		Token token2;
		token2.value=0;
		if(!IsEmptyTokenQueue(&nombre)){
		token2=PopTokenQueue(&nombre);}
		else{}
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

		
		if(token1.value!=0){
		token1.value=token2.value/token1.value;
		
		AppendTokenQueue(&nombre, token1);}
		else{printf("on ne peut diviser un nombre par zero\n");}
		
		break;
	case MOD:

		
		if(estentier(token1.value) && estentier(token2.value))
		{int x=(int)(token1.value);
		int y=(int)(token2.value);
		token1.value=y%x ;}
		else{printf("division euclidienne seulement sur des entiers\n");}
		
		
		AppendTokenQueue(&nombre, token1);
		
		break;
	case POW:



		token1.value=pow(token2.value,token1.value);

		
		AppendTokenQueue(&nombre, token1);

	default:
		break;
	}
	
	
	
	
	}


}}

Token tokenresult=PopTokenQueue(&nombre);

	
	j=j+tokenresult.value;



}
j=(tokene.value-tokenee.value)*j/n;
printf("%.2f\n",j);

return j;
}




/*JUSTE EN BAS ON A ESSAYÉ D'IMPLEMENTER LE CALCUL MATRICIEL, ON N'A PAS EU LE TEMPS DE LA FINIR*/



/*
int calcmat(TokenQueue queue){
int k=0;
while(!IsEmptyTokenQueue(&queue)){
Token token =PopTokenQueue(&queue);
if(token.type==MAT){return 0;
break;}
else{if(IsEmptyTokenQueue(&queue)){ return 1;}}

k=k+1;
}}



 


TokenQueue summat(TokenQueue queue1, TokenQueue queue2) {

TokenQueue queue;
ReverseTokenQueue(&queue1);
Token token1=PopTokenQueue(&queue1);
ReverseTokenQueue(&queue1);

ReverseTokenQueue(&queue2);
Token token2=PopTokenQueue(&queue2);
ReverseTokenQueue(&queue2);
//if(token1.value == token2.value){
int k=0;
while(!IsEmptyTokenQueue(&queue)){
Token tokena1=PopTokenQueue(&queue1);
Token tokena2=PopTokenQueue(&queue2);
if(tokena1.type!=V && tokena1.type!=PV){
tokena1.value=tokena1.value+tokena2.value;
printf("%f\n",tokena1.value);}
else{}
AppendTokenQueue(&queue, tokena1);
PrintTokenQueue(&queue);
k=k+1;}
return queue;
//}
//else{printf("impossible de faire la somme de ces matrices, %f ,%f \n", token2.value, token1.value);}

}









TokenQueue evaluationmat (TokenQueue queue){
int j=0;

TokenQueue queue2;
TokenQueue queue3;
while(!IsEmptyTokenQueue(&queue)){
Token token =PopTokenQueue(&queue);
	if(token.type==MAT){AppendTokenQueue(&queue2, token);
	break;}
	else{AppendTokenQueue(&queue2, token);}
j=j+1;}


ReverseTokenQueue(&queue);
Token token2 =PopTokenQueue(&queue);
ReverseTokenQueue(&queue);

Token token4 =PopTokenQueue(&queue2);


switch(token2.type){
case ADD:
	queue3=summat(queue, queue2);	
	PrintTokenQueue(&queue3);
	break;
	
	
}	
return 	queue3;


}*/






/*    J'utilise un algorithme basé sur une pile

je commence par initialiser une pile vide.
je parcours chaque élément de l'expression RPN
Si c'est un nombre, on le place sur la pile.
Si c'est un opérateur, on applique l'opération correspondante aux deux derniers éléments de la pile, puis on empile le résultat.
Une fois tous les éléments de l'expression traités, la pile ne contient qu'un seul élément, qui est le résultat de l'évaluation de l'expression.*/






TokenQueue evaluation (TokenQueue queue){

TokenQueue nombre=CreateTokenQueue();

int k=0;
	ReverseTokenQueue(&queue);
	Token tokeno=PopTokenQueue(&queue);
	ReverseTokenQueue(&queue);
	
	//ON EFFECTUE LE CALCUL INTEGRAL SEPAREMENT
if(tokeno.type==INTEGRAL){
	double x=INTGL(queue);
	
	Token token;
	token.type=NUMBER;
	token.value=x;
	AppendTokenQueue(&nombre, token);
	Token token1;
	AppendTokenQueue(&nombre, token1);
	return nombre;}
 else{


	
	
	AppendTokenQueue(&queue, tokeno);
	
	

while(!IsEmptyTokenQueue(&queue)){

	
	
	Token token =PopTokenQueue(&queue);
	
	
	if(token.coeff==0 && token.coeff2==0 && token.coeff3==0 && token.coeff4==0 && token.coeff5==0){
	if(token.type==VAR){token.type=NUMBER;
	token.estim=0;}}
	
	
	
	if(token.type==NUMBER){AppendTokenQueue(&nombre, token);
	} else if(token.type==PI){AppendTokenQueue(&nombre, token);
	} else if(token.type==E){AppendTokenQueue(&nombre, token);
	} else if(token.type==GAM){AppendTokenQueue(&nombre, token);
	} else {
	
		if(token.type==SIN){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= sin(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		else if(token.type==COS){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= cos(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		
		else if(token.type==EXP){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		
		ReverseTokenQueue(&nombre);
		
		//POUR IMPLEMENTER LA FONCTION EXPONANTIELLE SUR LES NOMBRES COMPLEXES
		if(token1.estim==1){
		token1.coeff=token1.coeff-token1.coeff3+token1.coeff5;
            token1.value=token1.value-token1.coeff2+token1.coeff4;
            token1.coeff2=0;
            token1.coeff3=0;
            token1.coeff4=0;
            token1.coeff5=0;
            double x=token1.value;
            token1.value=exp(x)*cos(token1.coeff);
            token1.coeff=exp(x)*sin(token1.coeff);
            AppendTokenQueue(&nombre, token1);
		}
		
		else{
		token1.value= exp(token1.value);
		AppendTokenQueue(&nombre, token1);}
		
		}
		else if(token.type==TAN){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= tan(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		else if(token.type==LOG){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= log(token1.value);
		
		AppendTokenQueue(&nombre, token1);}

		else if(token.type==FTGAM){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= FTGAMMA(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		
		else if(token.type==ZET){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1.value= ZETA(token1.value);
		
		AppendTokenQueue(&nombre, token1);}
		else if(token.type==CONJU){
				ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		ReverseTokenQueue(&nombre);
		token1= CONJ(token1);
		
		AppendTokenQueue(&nombre, token1);}
		
		else if(token.type==VAR){
		AppendTokenQueue(&nombre, token);
		
		
		
		} else if(token.type==EQUAL){
		
		
		Token token4=PopTokenQueue(&queue);
		
		
		//ON AVAIT VOULU RESOUDRE DES EQUATIONS DE DEGREE AU PLUS 2 MAIS TANT PIS
		
		if(token4.type==ASS){
		
		
		nombre=ASSIGNED(nombre);
		
		}
		else{
		AppendTokenQueue(&nombre, token4);
		Token token5=PopTokenQueue(&queue);
			if(token5.type==SOLV){
			nombre=SOLVE(nombre);
			
			} else {
				AppendTokenQueue(&nombre, token5);
				Token token6=PopTokenQueue(&queue);
				if(token6.type==SOLV){
				nombre=SOLVE(nombre);
				} else {
					AppendTokenQueue(&nombre, token6);
					Token token7=PopTokenQueue(&queue);
					if(token7.type==SOLV){
					} else {
						AppendTokenQueue(&nombre, token7);
					}
				}
			}
			
			
			
		}
		
		
		
		
		
		
		} else {
		
		ReverseTokenQueue(&nombre);
		Token token1=PopTokenQueue(&nombre);
		Token token2;
		token2.value=0;
		if(!IsEmptyTokenQueue(&nombre)){	
		
		token2=PopTokenQueue(&nombre);
		}
		
		else{
		}
		ReverseTokenQueue(&nombre);
		
	switch(token.type){
	
	
	//OPERATION EN VARIABLE ET REEL POSSIBLE POUR CERTAINES OPERATIONS
	
	case ADD:
		
		if(token1.type==VAR && token2.type==VAR){
		token1.value=token1.value+token2.value;
		token1.coeff=token1.coeff+token2.coeff;
		token1.coeff2=token1.coeff2+token2.coeff2;
		token1.coeff3=token1.coeff3+token2.coeff3;
		token1.coeff4=token1.coeff4+token2.coeff4;
		token1.coeff5=token1.coeff5+token2.coeff5;
		AppendTokenQueue(&nombre, token1);
		}
		
		else if((token1.type==VAR && (token2.type==NUMBER || token2.type==PI || token2.type==E || token2.type==GAM ))){
		token1.value=token1.value+token2.value;
		AppendTokenQueue(&nombre, token1);
		}
		else if((token2.type==VAR && (token1.type==NUMBER || token1.type==PI || token1.type==E || token1.type==GAM ))){
		token2.value=token1.value+token2.value;
		AppendTokenQueue(&nombre, token2);
		}
		else{
		
		
		token1.value=token1.value+token2.value;
		AppendTokenQueue(&nombre, token1);
		
		}
		
		break;
		
		
		
		
		
		
	
		
		
		
		
		
	case SUB:

		if(token1.type==VAR && token2.type==VAR){
		token1.value=0-token1.value+token2.value;
		token1.coeff=0-token1.coeff+token2.coeff;
		token1.coeff2=0-token1.coeff2+token2.coeff2;
		token1.coeff3=0-token1.coeff3+token2.coeff3;
		token1.coeff4=0-token1.coeff4+token2.coeff4;
		token1.coeff5=0-token1.coeff5+token2.coeff5;
		AppendTokenQueue(&nombre, token1);
		
		}
		
		
		else if((token1.type==VAR && (token2.type==NUMBER || token2.type==PI || token2.type==E || token2.type==GAM )) ){
		token1.value=token2.value-token1.value;
		token1.coeff=0-token1.coeff;
		token1.coeff2=0-token1.coeff2;
		token1.coeff3=0-token1.coeff3;
		token1.coeff4=0-token1.coeff4;
		token1.coeff5=0-token1.coeff5;
		AppendTokenQueue(&nombre, token1);
		
		
		}
		else if((token2.type==VAR && (token1.type==NUMBER || token1.type==PI || token1.type==E || token1.type==GAM ))){
		token2.value=token2.value-token1.value;
		
		AppendTokenQueue(&nombre, token2);
		
		}
		else{
		
		
		token1.value=0-token1.value+token2.value;
		AppendTokenQueue(&nombre, token1);
		
		}
		
		break;
	case MUL:

		if(token1.type==VAR && token2.type==VAR){
		
		
		token1.coeff4= (token2.coeff2)*(token1.coeff2);
		
		token1.coeff3=(token2.coeff2)*(token1.coeff) + 		(token2.coeff)*(token1.coeff2);
		
		token1.coeff2= (token2.coeff2)*(token1.value) + 		(token2.value)*(token1.coeff2) + (token2.coeff)*(token1.coeff);
		
		token1.coeff= (token2.coeff)*(token1.value) + 		(token2.value)*(token1.coeff);
		
		token1.value= (token1.value)*(token2.value);
		
		
		// PERMET D'APPLIQUER LA CONDITION FONDAMENTALE DES NOMBRES COMPLEXES
		
		
		if(token1.estim==1){
		token1.coeff=token1.coeff-token1.coeff3+token1.coeff5;
            token1.value=token1.value-token1.coeff2+token1.coeff4;
            token1.coeff2=0;
            token1.coeff3=0;
            token1.coeff4=0;
            token1.coeff5=0;}
            
		AppendTokenQueue(&nombre, token1);
		}



		else if((token1.type==VAR && (token2.type==NUMBER || token2.type==PI || token2.type==E || token2.type==GAM )) ){
		token1.coeff=token2.value*token1.coeff;
		token1.coeff2=token2.value*token1.coeff2;
		token1.coeff3=token2.value*token1.coeff3;
		token1.coeff4=token2.value*token1.coeff4;
		token1.coeff5=token2.value*token1.coeff5;
		token1.value=token2.value*token1.value;
	
		AppendTokenQueue(&nombre, token1);
		}
		else if((token2.type==VAR && (token1.type==NUMBER || token1.type==PI || token1.type==E || token1.type==GAM ))){
		token2.coeff=token1.value*token2.coeff;
		token2.coeff2=token1.value*token2.coeff2;
		token2.coeff3=token1.value*token2.coeff3;
		token2.coeff4=token1.value*token2.coeff4;
		token2.coeff5=token1.value*token2.coeff5;
		token2.value=token1.value*token2.value;
		
		AppendTokenQueue(&nombre, token2);
		}
		else{
		
		token1.value=token1.value*token2.value;
		
		AppendTokenQueue(&nombre, token1);
		
		}
		
		break;
	case DIV:

		
		if(token1.estim==1){
		token1.coeff=token1.coeff-token1.coeff3+token1.coeff5;
            token1.value=token1.value-token1.coeff2+token1.coeff4;
            token1.coeff2=0;
            token1.coeff3=0;
            token1.coeff4=0;
            token1.coeff5=0;}
            
            if(token2.estim==1){
		token2.coeff=token2.coeff-token2.coeff3+token2.coeff5;
            token2.value=token2.value-token2.coeff2+token2.coeff4;
            token2.coeff2=0;
            token2.coeff3=0;
            token2.coeff4=0;
            token2.coeff5=0;}
		
		
		if(token1.value!=0 || token1.coeff!=0  || token1.coeff2!=0 || token1.coeff3!=0 || token1.coeff4!=0 || token1.coeff5!=0){
		
		token2.value=token2.value/((token1.value)*(token1.value)+(token1.coeff)*(token1.coeff));
		token2.coeff=token2.coeff/((token1.value)*(token1.value)+(token1.coeff)*(token1.coeff));
		
		token1=CONJ(token1);
		AppendTokenQueue(&nombre, token2);
		AppendTokenQueue(&nombre, token1);
		
		Token tokenb;
		tokenb.type=MUL;
		ReverseTokenQueue(&queue);
		AppendTokenQueue(&queue, tokenb);
		
		ReverseTokenQueue(&queue);
		
		
		}
		else{printf("on ne peut diviser un nombre par zero\n");}
		
		break;
	case MOD:
		
		//MODULO POSSIBLE ENTRE DEUX ENTIERS
		
		if(estentier(token1.value) && estentier(token2.value))
		{int x=(int)(token1.value);
		int y=(int)(token2.value);
		token1.value=y%x ;}
		else{printf("division euclidienne seulement sur des entiers\n");}
		
		
		AppendTokenQueue(&nombre, token1);
		
		break;
	case POW:
		
		//POSSIBLE D'ELEVER LES VARIABLES A DES PUISSANCES INFERIEURES À 5 SAUF POUR LES NOMBRES COMPLEXES OÙ TOUTES LES PUISSANCES ENTIERES SONT POSSIBLE
		if(token1.type==VAR && token2.type==VAR){
		printf("impossible de faire cette puissance pour le moment\n");
		}
		
		else if((token1.type==VAR && (token2.type==NUMBER || token2.type==PI || token2.type==E || token2.type==GAM ))){
		 printf("impossible de faire cette puissance pour le moment\n");
	
		}
		else if((token2.type==VAR && (token1.type==NUMBER || token1.type==PI || token1.type==E || token1.type==GAM ))){
		
		
		
		
		if(floor(token1.value)==token1.value){
		
		Token tokenp=token2;
		for(int i=0;i<token1.value-1;i++){
	
		tokenp.coeff4= (tokenp.coeff2)*(token2.coeff2);
		
		tokenp.coeff3=(tokenp.coeff2)*(token2.coeff) + 	(tokenp.coeff)*(token2.coeff2);
		
		tokenp.coeff2= (tokenp.coeff2)*(token2.value) + (tokenp.value)*(token2.coeff2)+ (tokenp.coeff)*(token2.coeff);
		
		tokenp.coeff = (tokenp.coeff)*(token2.value) + 	(tokenp.value)*(token2.coeff);
		
		tokenp.value= (tokenp.value)*(token2.value);
		
		if(tokenp.estim==1){
		tokenp.coeff=tokenp.coeff-tokenp.coeff3+tokenp.coeff5;
            tokenp.value=tokenp.value-tokenp.coeff2+tokenp.coeff4;
            tokenp.coeff2=0;
            tokenp.coeff3=0;
            tokenp.coeff4=0;
            tokenp.coeff5=0;}}
		
		
		AppendTokenQueue(&nombre, tokenp);}
		
		else{printf("impossible de faire cette puissance pour le moment\n");}}
		
		
		
		else{
		
		
		token1.value=pow(token2.value,token1.value);
		
		
		AppendTokenQueue(&nombre, token1);
		}
		

	default:
		break;
	}}}
	k=k+1;}
	
	
	return nombre;
	}
	
	}
	
	
	
	
	
	
	
//	INTERFACE GRAPHIQUE




// Fonction appelée lorsqu'un bouton est cliqué
static void on_button_clicked(GtkWidget *widget, gpointer data) {
    const gchar *button_label = gtk_button_get_label(GTK_BUTTON(widget));
    const gchar *current_text = gtk_entry_get_text(GTK_ENTRY(entry));
    gchar *new_text = g_strconcat(current_text, button_label, NULL);
    gtk_entry_set_text(GTK_ENTRY(entry), new_text);
    g_free(new_text);
}

// Fonction appelée lorsqu'on clique sur le bouton "="
static void on_equal_clicked(GtkWidget *widget, gpointer data) {
  
  

Token too;
Token boo;
Token oo; 
oo.coeff=0;
boo.coeff=0;
too.coeff=0;

    const gchar *expression1 = gtk_entry_get_text(GTK_ENTRY(entry));
    
//ON TRANSFERT LA CHAINE REÇU (EN CONST GCHAR*) EN UNE CHAINE CHAR*


char* expression = malloc(strlen(expression1) + 1); 
if (expression == NULL) {
    fprintf(stderr, "Erreur d'allocation de mémoire\n");
    exit(1);
}

expression = g_strdup(expression1);


   TokenQueue AD=lexical(expression);

Token to=PopTokenQueue(&AD);

//SERT A RECONNAITRE LE CARACTERE ENTRÉE DANS LE CADRE DE L'ASSIGNATION

if(to.type==ASS) {
Token paren=PopTokenQueue(&AD);
Token tooo=PopTokenQueue(&AD);
too.name=tooo.name;
Token egal=PopTokenQueue(&AD);
Token toooo=PopTokenQueue(&AD);
too.value=toooo.value;
Token paren2=PopTokenQueue(&AD);


AppendTokenQueue(&AD, to);
AppendTokenQueue(&AD, paren);
AppendTokenQueue(&AD, tooo);
AppendTokenQueue(&AD, egal);
AppendTokenQueue(&AD, toooo);
AppendTokenQueue(&AD, paren2);


} else { 

ReverseTokenQueue(&AD);
AppendTokenQueue(&AD, to);
ReverseTokenQueue(&AD);	
}
	

	
	
	
	
	
	
TokenQueue queue=syntax_analysis(&AD);

TokenQueue result = evaluation(queue);
  
   
   
    
     
    
    
    ReverseTokenQueue(&result);
   Token t=PopTokenQueue(&result);
   ReverseTokenQueue(&result);
   
   // ON RETOURNE LES SOLUTIONS D'UNE EQUATION LINEAIRE ET QUADRATIQUE
   
   
   if(t.type==SOLV){
   
   gchar *result_text=g_strdup("") ;
   
   

   
   //PREMIERE SOLUTION
   
   if(!IsEmptyTokenQueue(&result)){
   Token token=PopTokenQueue(&result);
   boo.name=token.name;
   boo.value=token.value;
   
   
 
    	    gchar *new_text=g_strdup("") ;
    	    new_text =g_strdup_printf("%.3f",token.value);
            result_text = g_strdup_printf("%s%s", result_text,new_text);
            g_free(new_text);
		
    	    
   	    
   	    new_text =g_strdup_printf("  ");
            result_text = g_strdup_printf("%s%s", result_text,new_text);
	    g_free(new_text);
   
   
  }
 
 
 
 
 
 //DEUXIEME SOLUTION
 
 
 if(!IsEmptyTokenQueue(&result)){
 Token tokenà=PopTokenQueue(&result);
   oo.name=tokenà.name;
   oo.value=tokenà.value;
   
 
    	    gchar *new_text=g_strdup("") ;
    	    new_text =g_strdup_printf("%.3f",tokenà.value);
            
		result_text = g_strdup_printf("%s%s", result_text,new_text);
		g_free(new_text);
		
		
    
 }
 
 
 
 
 gtk_entry_set_text(GTK_ENTRY(entry), result_text);
    g_free(result_text);
    free(expression);

 
 
 
	}
	
	
	
	
	
	
	
   else{
   
   AppendTokenQueue(&result, t);
 
   
   gchar *result_text=g_strdup("") ;
   gchar *new_text=g_strdup("");
    
    Token token=PopTokenQueue(&result);
    if(IsEmptyTokenQueue(&result)){
 
 
//CE QUI SUIT POUR DONNER UNE VALEUR A UNE VARIABLE À LAQUALLE ON A ASSIGNER UNE VALEUR   


    if(token.name==too.name){
    
    token.value=token.value+token.coeff*too.value+token.coeff2*too.value*too.value+token.coeff3*too.value*too.value*too.value+token.coeff4*too.value*too.value*too.value*too.value+token.coeff5*too.value*too.value*too.value*too.value*too.value;
    
    token.coeff=0;
    token.coeff2=0;
    token.coeff3=0;
    token.coeff4=0;
    token.coeff5=0;
    token.type=NUMBER;
    
    
    }
    
    
    if(token.name==boo.name){
    
    token.value=token.value+token.coeff*boo.value+token.coeff2*boo.value*boo.value+token.coeff3*boo.value*boo.value*boo.value+token.coeff4*boo.value*boo.value*boo.value*boo.value+token.coeff5*boo.value*boo.value*boo.value*boo.value*boo.value;
    
    token.coeff=0;
    token.coeff2=0;
    token.coeff3=0;
    token.coeff4=0;
    token.coeff5=0;
    token.type=NUMBER;
    
    
    }
    
    if(token.name==oo.name){
    
    token.value=token.value+token.coeff*oo.value+token.coeff2*oo.value*oo.value+token.coeff3*oo.value*oo.value*oo.value+token.coeff4*oo.value*oo.value*oo.value*oo.value+token.coeff5*oo.value*oo.value*oo.value*oo.value*oo.value;
    
    token.coeff=0;
    token.coeff2=0;
    token.coeff3=0;
    token.coeff4=0;
    token.coeff5=0;
    token.type=NUMBER;
    
    
    }
    
     
	if(token.estim==0){
    
    	    if(token.value==0){
    	    	if(token.coeff==0 && token.coeff2==0 && token.coeff3==0 && token.coeff4==0 && token.coeff5==0){
    	    	new_text =g_strdup_printf("%.3f",token.value);
                
		result_text = g_strdup_printf("%s%s", result_text,new_text);
		g_free(new_text);
    	    	}
    	    } else {
    	    
    	    new_text =g_strdup_printf("%.3f",token.value);
            
		result_text = g_strdup_printf("%s%s", result_text,new_text);
		g_free(new_text);
		
		
    	    }
    	    
    	    if(token.coeff>0 && token.value!=0){
    	    
    	    new_text =g_strdup_printf("+");
    	  
		result_text = g_strdup_printf("%s%s", result_text, new_text);
		g_free(new_text);
    	    } 
    	    
    	    if(token.coeff==1){
    	    
            new_text =g_strdup_printf("%c",token.name);
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
		g_free(new_text);
            }
            else if(token.coeff==0){
            
            } else{
            
            new_text =g_strdup_printf("%.3f%c",token.coeff, token.name); 
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
		g_free(new_text);
           }
            
            if(token.coeff2>0 && (token.coeff!=0 || token.value!=0)){
            
            new_text=g_strdup_printf("+");
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);} 
             
            if(token.coeff2==1){
            
            new_text=g_strdup_printf("%s",token.name2);
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);}
            else if(token.coeff2==0){
            
            }else{
            
            new_text=g_strdup_printf("%.3f%s",token.coeff2, token.name2);
             
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);}
            
            if(token.coeff3>0 && (token.coeff2!=0 || token.coeff!=0 || token.value!=0)){
            
            new_text=g_strdup_printf("+");
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            
            g_free(new_text);} 
             
            if(token.coeff3==1){
           
            new_text=g_strdup_printf("%s",token.name3);
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);}
            else if(token.coeff3==0){
            
            } else {
            
            new_text=g_strdup_printf("%.3f%s",token.coeff3, token.name3);
          
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);}
            
            if(token.coeff4>0 && (token.coeff3!=0 || token.coeff2!=0 || token.coeff!=0 || token.value!=0)){
            
            new_text=g_strdup_printf("+");
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);} 
             
            if(token.coeff4==1){
            
            new_text=g_strdup_printf("%s",token.name4);
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);}
            else if(token.coeff4==0){
            
            } else{
            
            new_text=g_strdup_printf("%.3f%s",token.coeff4, token.name4); 
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);}
            
            if(token.coeff5>0 && (token.coeff4!=0 || token.coeff3!=0 || token.coeff2!=0 || token.coeff!=0 || token.value!=0)){
            
            new_text=g_strdup_printf("+");
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);} 
             
            if(token.coeff5==1){
            
            new_text=g_strdup_printf("%s",token.name5);
            
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);}
            else if(token.coeff5==0){
            
            } else{
            
            new_text=g_strdup_printf("%.3f%s",token.coeff5, token.name5);
            
		result_text = g_strdup_printf("%s%s", result_text, new_text); 
            g_free(new_text);}

            }

            
            
            else{
            
            
            if(token.value==0){
    	    } else {
    	    
    	    new_text=g_strdup_printf("%.3f",token.value);
    	   
		result_text = g_strdup_printf("%s%s", result_text, new_text);
    	    g_free(new_text);
    	    }
    	    
    	    if(token.coeff>0 && token.value!=0 ){
    	    
    	    new_text=g_strdup_printf("+");
    	   
		result_text = g_strdup_printf("%s%s", result_text, new_text);
    	    g_free(new_text);} 
    	    
    	    if(token.coeff==1){
    	    
            new_text=g_strdup_printf("%c",token.name);
           
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text);}
            else if(token.coeff==0){
            
            } else{
            
            new_text=g_strdup_printf("%.3f%c",token.coeff, token.name);
           
		result_text = g_strdup_printf("%s%s", result_text, new_text);
            g_free(new_text); }
            

            }
    
   
   
   }
   else{
   
   
   new_text =g_strdup_printf("%.3f",token.value);

		result_text = g_strdup_printf("%s%s", result_text,new_text);
		g_free(new_text);
   }
   
   
   gtk_entry_set_text(GTK_ENTRY(entry), result_text);
    g_free(result_text);

    free(expression);


   
   } 
    


}
// FONCTION APPELÉE LORSQU'ON CLIQUE SUR LE BOUTON "C"
static void on_clear_clicked(GtkWidget *widget, gpointer data) {
    gtk_entry_set_text(GTK_ENTRY(entry), "");
}




// FONCTION APPELÉE LORSQU'ON CLIQUE SUR LE BOUTON "SUPPRIMER"
static void on_delete_clicked(GtkWidget *widget, gpointer data) {
    const gchar *text = gtk_entry_get_text(GTK_ENTRY(entry));
    if (g_utf8_strlen(text, -1) > 0) {
        gchar *new_text = g_strndup(text, g_utf8_strlen(text, -1) - 1);
        gtk_entry_set_text(GTK_ENTRY(entry), new_text);
        g_free(new_text);
    }
}




// FONCTION POUR CRÉER UN BOUTON ET L'AJOUTER À LA GRILLE
static GtkWidget* create_button(GtkWidget *grid, const gchar *label, int row, int col, int rowspan, int colspan) {
    GtkWidget *button = gtk_button_new_with_label(label);
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, col, row, colspan, rowspan);
    return button;
}

// FONCTION APPELÉE LORSQUE L'APPLICATION EST ACTIVÉE
static void on_activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *delete_button;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Calculatrice Scientifique pour TurtleSmoke");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 700);

    grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 0, 0, 10, 7);

    // CRÉER LES BOUTONS DE LA CALCULATRICE
    create_button(grid, "7", 9, 0, 1, 1);
    create_button(grid, "8", 9, 1, 1, 1);
    create_button(grid, "9", 9, 2, 1, 1);
    create_button(grid, "/", 9, 4, 1, 1);
    create_button(grid, "SIN(", 9, 5, 1, 1);

    create_button(grid, "4", 10, 0, 1, 1);
    create_button(grid, "5", 10, 1, 1, 1);
    create_button(grid, "6", 10, 2, 1, 1);
    create_button(grid, "*", 9, 3, 1, 1);
    create_button(grid, "%", 11, 3, 1, 1);
    create_button(grid, "gamma", 13, 0, 1, 1);
    create_button(grid, "COS(", 9, 6, 1, 1);

    create_button(grid, "1", 11, 0, 1, 1);
    create_button(grid, "2", 11, 1, 1, 1);
    create_button(grid, "3", 11, 2, 1, 1);
    create_button(grid, "-", 10, 4, 1, 1);
    create_button(grid, "TAN(", 10, 5, 1, 1);
    create_button(grid, "EXP(", 11, 5, 1, 1);
    create_button(grid, "CONJ(", 11, 6, 1, 1);
    create_button(grid, "INTGL(", 12, 5, 1, 1);
    create_button(grid, "FTGAMMA(", 12, 6, 1, 1);
    create_button(grid, "SOLVE(", 13, 6, 1, 1);
    create_button(grid, "ASSIGNED(", 14, 6, 1, 1);
    create_button(grid, "=", 13, 1, 1, 1);
    create_button(grid, "ZETA(", 13, 5, 1, 1);

    create_button(grid, "0", 12, 0, 1, 1);
    create_button(grid, "^", 11, 4, 1, 1);
    create_button(grid, ")", 12, 4, 1, 1);
    create_button(grid, "(", 12, 3, 1, 1);
    create_button(grid, ".", 12, 1, 1, 1);
    create_button(grid, "PI", 12, 2, 1, 1);
    create_button(grid, "e", 13, 2, 1, 1);
    create_button(grid, "x", 13, 3, 1, 1);
    create_button(grid, "i", 13, 4, 1, 1);
     // AJOUT DU BOUTON "=" À LA GRILLE
    GtkWidget *equal_button = gtk_button_new_with_label("=");
    g_signal_connect(equal_button, "clicked", G_CALLBACK(on_equal_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), equal_button, 20, 0, 5, 7);
    create_button(grid, "+", 10, 3, 1, 1);
    create_button(grid, "LOG(", 10, 6, 1, 1);


    // CRÉER LE BOUTON "SUPPRIMER" ET L'AJOUTER À LA GRILLE
    delete_button = gtk_button_new_with_label("Supp");
    gtk_grid_attach(GTK_GRID(grid), delete_button, 10, 3, 1, 3);
    g_signal_connect(delete_button, "clicked", G_CALLBACK(on_delete_clicked), NULL);
    
    
    
    
    // AJOUT DU BOUTON "C"
    GtkWidget *clear_button = gtk_button_new_with_label("C");
    g_signal_connect(clear_button, "clicked", G_CALLBACK(on_clear_clicked), NULL);
    gtk_grid_attach(GTK_GRID(grid), clear_button, 10, 0, 1, 3);

    gtk_widget_show_all(window);
}

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("com.example.ScientificCalculator", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(on_activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    printf("%d\n", status);

    return status;
}
