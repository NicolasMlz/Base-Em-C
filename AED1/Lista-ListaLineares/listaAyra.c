#include <stdio.h>
#include <stdlib.h>
 
//-------------------------------------------------------------------------
// AyraList.H
//-------------------------------------------------------------------------
 
//Variaveis Globais
typedef struct Inimigos *ApontadorCelula;
typedef struct Inimigos {
    
    int chave;
    int p1, p2;
    ApontadorCelula prox;
    
} Inimigos;
 
void CriarListaVazia(ApontadorCelula *p);
int insInicio(ApontadorCelula *p, Inimigos inimigos);
int insFinal(ApontadorCelula *p, Inimigos inimigos);
int inserirElementoMeio(ApontadorCelula *p, Inimigos inimigos, int j);
int removerElemento(ApontadorCelula *p, Inimigos inimigos);
int quantidadeEntreElementos(ApontadorCelula *p, Inimigos inimigos);
void imprimirLista(ApontadorCelula *p);
 
//-------------------------------------------------------------------------
// AyraList.C
//-------------------------------------------------------------------------
 
//Criar lista vazia
void CriarListaVazia(ApontadorCelula *p) {
    (*p) = NULL;
}
 
//Inserir no inicio
int insInicio(ApontadorCelula *p, Inimigos inimigos) {
    
    //Variaveis
    ApontadorCelula q;
 
    //Inserir
    q = malloc(sizeof(Inimigos));
 
    if(q == NULL) {
        return 0;
    } else {
        q->chave = inimigos.chave;
        q->prox = (ApontadorCelula) *p;
        (*p) = q;
        return 1;
    }
}
 
//Inserir no final
int insFinal(ApontadorCelula *p, Inimigos inimigos) {
    ApontadorCelula q, r;
 
    if(*p == NULL) {
        return (insInicio(p, inimigos));
    } else {
        q = malloc(sizeof(Inimigos));
 
        if(q == NULL) {
            return 0;
        } else {
            q->chave = inimigos.chave;
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
 
//Inserir elemento no meio
int inserirElementoMeio(ApontadorCelula *p, Inimigos inimigos, int j) {
 
    ApontadorCelula q, r;
    r = malloc(sizeof(Inimigos));
 
    if(r == NULL) {
        return 0;
    } else{ 
 
        r->chave = inimigos.chave;
        if(*p == NULL) {
            return 0;
        } else {
            q = *p;
            while((q->prox != NULL) && (q->chave != j)) {
                q = q->prox;
            }
 
            if(q->chave == j && q->prox != NULL) {
                r->prox = q->prox;
                q->prox = r;
            } else if(q->prox == NULL && q->chave == j){
                r->prox = NULL;
                q->prox = r;
            }  
 
            printf("inserido %d\n", inimigos.chave);
            return 1;             
        }
    }
}
 
//Remover elemento
int removerElemento(ApontadorCelula *p, Inimigos inimigos) {
 
    //Variaveis
    ApontadorCelula q, s;
    int i=0;
 
    //Verificar se a chave do inimigo esta presente na lista original
    q = (*p);
    while((q->prox != NULL) && (q->chave != inimigos.chave)) {
        s = q;
        q = q->prox;
        i++;
    }
 
    //Mudar ponteiros para pular os excluidos
    if(i == 0) {
        *p = q->prox; 
    } else if(q->chave == inimigos.chave) {
        s->prox = q->prox;
    } else if(q->prox == NULL && q->chave == inimigos.chave){
        s->prox = NULL;
    }
 
    printf("removido %d\n", inimigos.chave);
    return 1;
}
 
//Quantidade entre 2 elementos
int quantidadeEntreElementos(ApontadorCelula *p, Inimigos inimigos) {
 
    //Variaveis
    ApontadorCelula r, s;
    int cont=0;
 
    //Contagem
    r = (*p);
    s = (*p);
    if(p != NULL) {
        while(r->chave != inimigos.p1 && s->chave != inimigos.p2) {
            r = r->prox;
            s = s->prox;
        }
 
        if(r->chave==inimigos.p1){
            while(s->chave!=inimigos.p2){
                cont++;
                s = s->prox;
            }
        }else{
            if(s->chave==inimigos.p2){
                while(r->chave!=inimigos.p1){
                    cont++;
                    r = r->prox;
                }
            }
        }
        printf("quantidade %d\n", cont-1);
        return(cont-1);
    }
    return 0;
}
 
//Imprimir lista
void imprimirLista(ApontadorCelula *p) {
 
    //Variaveis
    ApontadorCelula q;
    q = (*p);
 
    printf("lista ");
    while(q->prox != NULL) {
        printf("%d ", q->chave);
        q = q->prox;
    }
    printf("%d\n", q->chave);
}
 
//-------------------------------------------------------------------------
// AyraList.main
//-------------------------------------------------------------------------
int main() {
 
    //Variaveis
    ApontadorCelula prim;
    int i, j, n, m, aux;
    Inimigos inimigos;
    char menu;
 
    //Qtde de inimigos
    scanf("%d", &n);
    CriarListaVazia(&prim);
    for(i=0; i<n; i++) {
        scanf("%d", &inimigos.chave);
        aux = insFinal(&prim, inimigos);
    }
 
    //Operacoes na lista
    do {
 
        //Opcao do usuario
        scanf("%c", &menu);
 
        //Operacoes
        if(menu == 'I') {
            scanf("%d %d", &inimigos.chave, &j);
            aux = inserirElementoMeio(&prim, inimigos, j);
        } 
        else if(menu == 'R') {
            scanf("%d", &inimigos.chave);
            aux = removerElemento(&prim, inimigos);
        }
        else if(menu == 'C') {
            scanf("%d %d", &inimigos.p1, &inimigos.p2);
            aux = quantidadeEntreElementos(&prim, inimigos);
        }
        else if(menu == 'M') {
            imprimirLista(&prim);
        }
        else {}
        
    } while(menu != 'F');
 
    printf("fim\n");
}