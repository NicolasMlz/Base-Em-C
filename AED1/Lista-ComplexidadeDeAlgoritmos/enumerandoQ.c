#include <stdlib.h>
#include <stdio.h>

//Maior divisor comum entre 2 numeros
int mdc(int i, int j) {

    //Variaveis
    int n, contDivisores=0, menorNumero;

    //Determinar o menor numero
    if(i < j) {
        menorNumero = i;
    } else {
        menorNumero = j;
    }

    //Determinar maior divisor comum
    for(n=1; n<=menorNumero; n++) {
        if((i%n==0) && (j%n==0)) {
            contDivisores++;
        }

        //Verificar se o 1 é o maior
        if(contDivisores > 1) {
            return 0;
        }
    }

    //Retorno
    return 1;
}

//Enumeracao racional de 0 a 1
void rationalsEnumeration(int n) {

    //Variaveis
    int i, j, cont=0;

    //Primeiro caso
    if(n == 1) {
        printf("0/1\n");
        return;
    } 
    else {
        n--;
    }

    //Looping para determinar lista de numeros racionais
    for(i=1; i<5000; i++) {
        for(j=1; j<=i; j++) {
            
            //Criar lista de racionais
            if(mdc(i,j) == 1) {
                cont++;
            }

            //Saida
            if(cont == n) {
                printf("%d/%d\n", j, i);
                return;
            }
        }
    }
}

//Main
int main() {

    //Variaveis
    int n=1;

    //Looping
    while(n != 0) {

        //Scanear indice da lista de numeros racionais de 0 a 1
        scanf("%d", &n);

        //Determinar lista
        if(n != 0) {
            rationalsEnumeration(n);
        }

    }

    //Retorno do main
    return 0;

}