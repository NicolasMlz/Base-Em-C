#include <stdlib.h>
#include <stdio.h>

//Main
int main() {

    //Variaveis
    int v[50000];
    int n, k, i, posicao=-1, passos=0, nAux;

    //Scanear tamanho do vetor e o elemento k a ser buscado nele
    scanf("%d %d", &n, &k);

    //Scanear os elementos do vetor em ordem crescente
    for(i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }

    //------------------//
    // PESQUISA BINARIA //
    //------------------//
    
    
    //Saida
        //Imprimir n e k
        printf("%d\n%d\n", n, k);
        
        //Imprimir vetor
        for(i=0; i<n; i++) {
            printf("%d ", v[i]);
            if(i%10==0 && i!=0) {
                printf("\n");
            }
        }
        if(i-1%10 != 0) {
            printf("\n");
        }

        //Imprimir a posicao de k
        if(posicao != -1) {
            printf("%d\n", posicao);
        } else {
            printf("-1\n");
        }

        //Imprimir o numero de passos para encontrar k
        printf("%d\n", passos);

    //Retorno do main
    return 0;

}