#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Criar matriz moldura
void moldura(int n, int x, int y) {

    //Variavies
    int lin=0, col=0, i, qtde=n/2, cont;
    int matriz[100][100];

    //Criar matriz de forma iterativa
    ceil(qtde);
    for(cont=0; cont<=qtde; cont++) {

        if(cont%2 == 0) {
            for(i=cont; i<n-cont; i++) {
                matriz[lin][i] = x;
                matriz[i][col] = x;
                matriz[n-1-lin][i] = x;
                matriz[i][n-1-col] = x;
            }
        } else {
            for(i=cont; i<n-cont; i++) {
                matriz[lin][i] = y;
                matriz[i][col] = y;
                matriz[n-lin-1][i] = y;
                matriz[i][n-col-1] = y;
            }            
        }

        lin++; col++;
    }

    //Saida
    for(lin=0; lin<n; lin++) {
        for(col=0; col<n; col++) {
            printf("%d ", matriz[lin][col]);
        } printf("\n");
    }
}

//Main
int main() {
    
    //Variaveis
    int n, x, y, lin, col;
    int matriz[100][100];

    //Scanear composicoes da matriz moldura
    scanf("%d %d %d", &n, &x, &y);

    //Chamar funcao
    if(x!=y) {
        moldura(n, x, y);
    }
    return 0;
}