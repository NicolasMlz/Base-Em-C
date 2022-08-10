#include <stdlib.h>
#include <stdio.h>

//Main
int main() {

    //Variaveis
    int n, i, dias, q, j, k=1, cont=1;
    int resultado[3000], precos[3000];

    //Scanear numero de lanchonetes
    scanf("%d", &n);

    //Scanear preco do cafe de cada lanchonete
    for(i=0; i<n; i++) {
        scanf("%d", &precos[i]);
    }

    //Scanear quantidade de dias que john comprara cafe
    scanf("%d", &dias);

    //Scanear possibilidades de compra com determinado preco por x dias
    for(j=0; j<dias; j++) {

        //Entrada do preco no dia
        scanf("%d", &q);

        //Analisar o poder de compra de john
        for(i=0; i<n; i++) {
            if(q >= precos[i]) {
                resultado[0] = cont;
                resultado[k] = i+1;
                k++; cont++;
            }
        }

        //Saida
        if(cont != 1) {
            for(i=0; i<k; i++) {
                printf("%d ", resultado[i]);
            } printf("\n");
        } else {
            printf("0\n");
        }
        resultado[0] = 0;
        k=1; cont=1;
    }

    //Retorno do main
    return 0;

}