#include <stdio.h>
#include <stdlib.h>

//Funcao troca
void troca(int *x, int *y) {

    //Variaveis
    int aux;
    
    //Troca 
    aux=*x;
    *x=*y;
    *y=aux;
}

//Funcao bubblesort
void bubblesort(int vetor[], int iAux) {

    //Variaveis
    int i, j;
    
    //Para cada passada i, borbulhar o maior elemento daquela passada para a posicao i+1
    for(i=iAux-1; i>0; i--) {
        for(j=0; j<i; j++) {
            if(vetor[j] > vetor[j+1]) {
                //trocar v[j] com v[j+1]
                troca(&vetor[j], &vetor[j+1]);
            }
        }
    }
}

//Todos os numeros primos
void primos(int vetor[], int maiorPosicao) {

    //Variaveis
    int i, j, k=2, cont=0;
    vetor[1] = 2;

    //Armazenar primos no vetor
    for(i=3; i<50000; i++) {
        for(j=2; j<i; j++) {
            if(i%j==0) {
                cont++;
            }

            //Nao rodar o loop todo para economizar memoria
            if(k == maiorPosicao) {
                return;
            }
        }

        if(cont == 0) {
            vetor[k] = i;
            cont=0; k++;
        } else {
            cont = 0;
        }

        //Nao rodar o loop todo para economizar memoria
        if(k == maiorPosicao) {
            return;
        }
    }
}

//Main
int main() {
    
    //Variaveis
    int tam, i, j, k, soma=0;
    int vet[10000], primosVet[10000];

    //Tamanho do vetor
    scanf("%d", &tam);

    //Elementos do vetor
    for(i=0; i<tam; i++) {
        scanf("%d", &vet[i]);
    }

    //Ordenar soma de forma crescente
    bubblesort(vet, tam);

    //Armazenar primos no vetor
    primos(primosVet, vet[tam]);

    //Saida dos primos
    for(i=0; i<tam; i++) {
        printf("%d ", primosVet[vet[i]]);
    } printf("\n");

    //Saida da soma
    for(i=0; i<tam; i++) {
        soma = soma + primosVet[vet[i]];
    }
    printf("%d\n", soma);

    return 0;
}
