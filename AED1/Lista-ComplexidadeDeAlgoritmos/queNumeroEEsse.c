#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//Main
int main() {

    //Variaveis
    int tam, i, n=0, produto=1; 
    int vet[10000];

    //Scanear tamanho do vetor
    scanf("%d", &tam);

    //Scanear elementos do vetor
    for(i=0; i<tam; i++) {
        scanf("%d", &vet[i]);
    }

    //Encontrar produto de todos os elementos do vetor
    for(i=0; i<tam; i++) {
        produto = produto*vet[i];
    }

    //Encontrar menor elemento que satisfaca a condição
    while(pow(n, tam) <= produto) {
        n++;
    }

    //Saida
    for(i=0; i<tam; i++) {
        printf("%d ", n);
    } printf("\n");

    //Retorno do main
    return 0;

}