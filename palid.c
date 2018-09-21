#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
                char item[21];
                int t1;
               } Regpilha;

void push(Regpilha *, char );
char pop(Regpilha *);
int Palindromo (char *, Regpilha *);

int main ()
{
    Regpilha *pilha;
    char palavra[21];
    int i=0;
	
     pilha = (Regpilha *) malloc(sizeof(Regpilha));
	 
	if (pilha == NULL)
		{	printf("Memoria insuficiente para esta operacao ...\n");
			return 2;
    	}

    pilha->t1 = -1;
    printf("Qual é a palavra?\n\n");
    gets(palavra);
	
	while(strcmp (palavra,"FIM") != 0)
	{
    while (palavra[i] != '\0') 
	{
      push(pilha, palavra[i]);
      i++;
    }
    if (Palindromo(palavra, pilha))
       printf("Palindromo.");
    else
        printf("Nao e palindromo");
	
	  return 0;
}
}
int Palindromo (char *palavra, Regpilha *pilha) {

    int palindromo, i;
	palindromo = 1;
    for (i=0; i<strlen(palavra); i++)
        if (palavra[i] != pop(pilha)) 
			palindromo = 0;
    return palindromo;
} 

void push(Regpilha *pilha, char c)
{
        if (pilha->t1 < 21-1) 
		{
         pilha->t1++;
         pilha->item[pilha->t1]=c; 
        }
        else 
	    printf("Pilha cheia.");
}
char pop(Regpilha *pilha ) 
{
     if (pilha->t1 == -1)
		 printf("Pilha vazia.");
     else 
		 return pilha->item[pilha->t1--];
}
