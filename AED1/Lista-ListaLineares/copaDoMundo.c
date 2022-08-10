#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------------------
// Copa.H
//-------------------------------------------------------------------------

//Variaveis Globais
typedef struct Torcedor *ApontadorCelula;
typedef struct Torcedor {
    
    int chave;
    ApontadorCelula prox;
    
} Torcedor;

void CriarListaVazia(ApontadorCelula *p);
int insInicio(ApontadorCelula *p, Torcedor torcedor);
int insFinal(ApontadorCelula *p, Torcedor torcedor);
int removerElemento(ApontadorCelula *p, Torcedor torcedor);
void imprimirLista(ApontadorCelula *p);

//-------------------------------------------------------------------------
// Copa.C
//-------------------------------------------------------------------------

//Criar lista vazia
void CriarListaVazia(ApontadorCelula *p) {
    (*p) = NULL;
}

//Inserir no inicio
int insInicio(ApontadorCelula *p, Torcedor torcedor) {
    
    //Variaveis
    ApontadorCelula q;

    //Inserir
    q = malloc(sizeof(Torcedor));

    if(q == NULL) {
        return 0;
    } else {
        q->chave = torcedor.chave;
        q->prox = (ApontadorCelula) *p;
        (*p) = q;
        return 1;
    }
}

//Inserir no final
int insFinal(ApontadorCelula *p, Torcedor torcedor) {
    ApontadorCelula q, r;

    if(*p == NULL) {
        return (insInicio(p, torcedor));
    } else {
        q = malloc(sizeof(Torcedor));

        if(q == NULL) {
            return 0;
        } else {
            q->chave = torcedor.chave;
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

//Remover elemento
int removerElemento(ApontadorCelula *p, Torcedor torcedor) {

    //Variaveis
    ApontadorCelula q, s;
    int i=0;

    //Verificar se a chave do torcedor esta presente na lista original
    q = (*p);
    while((q->prox != NULL) && (q->chave != torcedor.chave)) {
        s = q;
        q = q->prox;
        i++;
    }

    //Mudar ponteiros para pular os excluidos
    if(i == 0) {
        *p = q->prox; 
    } else if(q->chave == torcedor.chave) {
        s->prox = q->prox;
    } else if(q->prox == NULL && q->chave == torcedor.chave){
        s->prox = NULL;
    }

    return 1;
}

//Imprimir lista
void imprimirLista(ApontadorCelula *p) {

    //Variaveis
    ApontadorCelula q;
    q = (*p);

    while(q->prox != NULL) {
        printf("%d ", q->chave);
        q = q->prox;
    }
    printf("%d", q->chave);
}

//-------------------------------------------------------------------------
// Copa.main
//-------------------------------------------------------------------------
int main() {

    //Variaveis
    int i, j, n, m, aux;
    ApontadorCelula prim;
    Torcedor torcedor;

    //Qtde de torcedores que verão o jogo
    scanf("%d", &n);
    CriarListaVazia(&prim);
    for(i=0; i<n; i++) {
        scanf("%d", &torcedor.chave);
        aux = insFinal(&prim, torcedor);
    }

    //Qtde de torcedores que não verão o jogo
    scanf("%d", &m);
    for(i=0; i<m; i++) {
        scanf("%d", &torcedor.chave);
        aux = removerElemento(&prim, torcedor);
    }    

    //Saida
    imprimirLista(&prim);

    //Retorno
    return 0;
}