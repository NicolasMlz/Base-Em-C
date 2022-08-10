#include <stdio.h>
#include <stdlib.h>
 
//-------------------------------------------------------------------------
// brancaDeNeve.H
//-------------------------------------------------------------------------
 
//Variaveis Globais
typedef struct Cor *ApontadorCelula;
typedef struct Cor {
    
    //Variaveis
    int chave;
    ApontadorCelula prox;
    
} Cor;

//Headers
void CriarListaVazia(ApontadorCelula *p);
int insInicio(ApontadorCelula *p, Cor cor);
int insFinal(ApontadorCelula *p, Cor cor);
void bonitaOuFeia(ApontadorCelula *p, int anaoComeco, int anaoFim);
 
//-------------------------------------------------------------------------
// brancaDeNeve.C
//-------------------------------------------------------------------------
 
//Criar lista vazia
void CriarListaVazia(ApontadorCelula *p) {
    (*p) = NULL;
}
 
//Inserir no inicio
int insInicio(ApontadorCelula *p, Cor cor) {
    
    //Variaveis
    ApontadorCelula q;
 
    //Inserir
    q = malloc(sizeof(Cor));
 
    if(q == NULL) {
        return 0;
    } else {
        q->chave = cor.chave;
        q->prox = (ApontadorCelula) *p;
        (*p) = q;
        return 1;
    }
}
 
//Inserir no final
int insFinal(ApontadorCelula *p, Cor cor) {
    ApontadorCelula q, r;
 
    if(*p == NULL) {
        return (insInicio(p, cor));
    } else {
        q = malloc(sizeof(Cor));
 
        if(q == NULL) {
            return 0;
        } else {
            q->chave = cor.chave;
            q->prox = NULL;
            r = (*p);
            while(r->prox != NULL) {
                r = r->prox;
            }
            r->prox = q;
            return 1;
        }
 
    }
}

//Verificar se a foto é bonita ou feia
void bonitaOuFeia(ApontadorCelula *p, int anaoComeco, int anaoFim) {

    //Variaveis
    ApontadorCelula q; 
    int cont=1, i=0, maior=0;
    int cores[2][1000];

    //Formar matriz que armazenara as repeticoes de cada cor
    //Primeira linha: cores de 0 a 1000;
    //Segunda linha: qtde de vezes que cada cor (mesma coluna, mas linha acima) repete;
    for(i=0; i<1000; i++) {
        cores[0][i] = i;
        cores[1][i] = 0;
    }

    //Alocar q
    q = malloc(sizeof(Cor)); 
    q = (*p);

    //Comecar no anao scaneado
    while(cont < anaoComeco) {
        q = q->prox;
        cont++;
    }

    //Ir ate o anao final scaneado
    while(cont <= anaoFim) {
        
        //Armazenar a repeticao na matriz de cores
        cores[1][q->chave] += 1;

        //Proxima celula
        q = q->prox;
        cont++;
    }

    //Verificar qual cor repete mais que a metade
    for(i=0; i<100; i++) {
        if(cores[1][i] > (anaoFim-anaoComeco+1)/2) {
            maior = cores[0][i];
        }
    }

    //Saida
    if(maior == 0) {
        printf("feia\n");
    } else {
        printf("bonita %d\n", maior);
    }

}

//-------------------------------------------------------------------------
// brancaDeNeve.main
//-------------------------------------------------------------------------
int main() {
 
    //Variaveis
    int n, qtdAnoes, qtdCores, i, aux, qtdeFotos, anaoComeco, anaoFim, j;
    ApontadorCelula p;
    Cor cor;
    char menu;
 
    //Qtde de casos de teste
    scanf("%d", &n);
    while(n--) {

        //Scanear quantidades
        scanf("%d %d", &qtdAnoes, &qtdCores);

        //Scanear lista de cores de toucas
        CriarListaVazia(&p);
        for(i=0; i<qtdAnoes; i++) {
            scanf("%d", &cor.chave);
            aux = insFinal(&p, cor);
        }

        //Casos de fotos a serem analisadas
        scanf("%d", &qtdeFotos);

        //Scanear de qual a qual anao a foto contera
        for(j=0; j<qtdeFotos; j++) {
            scanf("%d %d", &anaoComeco, &anaoFim);
            bonitaOuFeia(&p, anaoComeco, anaoFim);
        }
    }

    //Retorno
    return 0;
}