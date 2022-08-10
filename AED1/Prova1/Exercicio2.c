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
            if(vetor[j] < vetor[j+1]) {
                //trocar v[j] com v[j+1]
                troca(&vetor[j], &vetor[j+1]);
            }
        }
    }
}
 
//Main
int main() {
    
    //Variaveis
    int nTestes, tam, testesAux, i, j, k=0, qtde=0;
    int vet[10000], soma[10000];
 
    //Casos de teste
    scanf("%d", &nTestes);
    for(testesAux=0; testesAux<nTestes; testesAux++) {
        
        //Tamanho do vetor
        scanf("%d", &tam);
 
        //Elementos do vetor
        for(i=0; i<tam; i++) {
            scanf("%d", &vet[i]);
        }
 
        //Determinar pares e suas respectivas somas
        for(i=0; i<tam; i++) {
            for(j=i+1; j<tam; j++) {
                soma[k] = vet[i] + vet[j];
                k++;
            }
        }
 
        //Ordenar soma de forma descrescente
        bubblesort(soma, k); i=0;
 
        //Analisar quantas vezes o maior elemento se repete
        while(soma[i] == soma[i+1] && i<k-1) {
            if(soma[i] == soma[i+1]) {
                i++; qtde++;
            }
        } 
        if(qtde == 0) {
            qtde = 1;
        }
 
        //Saida
        if(tam > 0) {
            printf("%d\n", qtde);
        } 
 
        //Zerar vetores e variaveis
        for(i=0; i<k; i++) {
            soma[i] = 0;
        }
        qtde=0; k=0;
    }
 
    return 0;
}