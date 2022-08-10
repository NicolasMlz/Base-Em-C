#include <stdlib.h>
#include <stdio.h>

//-----------------------------------------------------------------
//ARQUIVO.HEADER
//-----------------------------------------------------------------
//Strcut do NODE
typedef struct No{
    double chave;
    struct No *esq;
    struct No *dir;
}No;

//Headers
No* inserir(No *raiz, double valor);
int tamanho(No *raiz);
void imprimir(No *raiz);
int buscaBinaria(No *raiz, double valor); 
No* remover(No *raiz, double valor);


//-----------------------------------------------------------------
//ARQUIVO.C
//-----------------------------------------------------------------
No* inserir(No *raiz, double valor) {
    if(raiz == NULL) {
        No *novo = (No*) malloc(sizeof(No));
        novo->chave = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    } 
    else {
        if(valor < raiz->chave)
            raiz->esq = inserir(raiz->esq, valor);
        else if(valor > raiz->chave)
            raiz->dir = inserir(raiz->dir, valor);
        return raiz;
    } 
}

int tamanho(No *raiz) {
    if(raiz == NULL) 
        return 0;
    else 
        return 1 + tamanho(raiz->dir) + tamanho(raiz->esq);
}

void imprimir(No *raiz) {
    if(raiz != NULL) {
        imprimir(raiz->esq);
        printf("%.1lf ", raiz->chave);
        imprimir(raiz->dir);
    }
}

int buscaBinaria(No *raiz, double valor) {
    if(raiz == NULL) 
        return 0; 
    else if(valor < raiz->chave) 
        return buscaBinaria(raiz->esq, valor);
    else if(valor > raiz->chave) 
        return buscaBinaria(raiz->dir, valor);
    else if(valor == raiz->chave) {
        return 1;
    }
}

No* remover(No *raiz, double valor) {
    if(raiz == NULL) {
        printf("Elemento nao encontrado!\n");
        return NULL;
    }
    else {
        if(raiz->chave == valor) {
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                printf("Elemento removido com sucesso!\n"); 
                return NULL; 
            }
            else if(raiz->esq != NULL && raiz->dir == NULL) {
                No *aux = raiz->esq;
                free(raiz);
                printf("Elemento removido com sucesso!\n");
                return aux;
            }
            else if(raiz->esq == NULL && raiz->dir != NULL) {
                No *aux = raiz->dir;
                free(raiz);
                printf("Elemento removido com sucesso!\n");
                return aux;
            }
            else if(raiz->esq != NULL && raiz->dir != NULL) {
                No *aux = raiz->dir;
                while(aux->esq != NULL) 
                    aux = aux->esq;
                raiz->chave = aux->chave;
                aux->chave = valor;
                raiz->dir = remover(raiz->dir, valor);
                return raiz;
            }
        }
        else {
            if(valor < raiz->chave)
                raiz->esq = remover(raiz->esq, valor);
            else
                raiz->dir = remover(raiz->dir, valor);
            return raiz;
        }
    } 
}


//-----------------------------------------------------------------
//ARQUIVO.MAIN
//-----------------------------------------------------------------
int main() {

    //Variaveis
    No *raiz = NULL;
    int op;
    double valor;

    //MENU
    do {
        printf("-------------------\n");
        printf("O que deseja fazer?\n");
        printf("0 - Sair\n");
        printf("1 - Inserir\n");
        printf("2 - Imprimir\n");
        printf("3 - Buscar elemento\n");
        printf("4 - Remover\n");
        printf("-------------------\n");

        //Escolha do usuario
        scanf("%d", &op);

        //Opcoes do menu
        if(op == 0) {
            break;
        }
        else if(op == 1) {
            printf("Digite o valor a ser inserido: ");
            scanf("%lf", &valor);
            raiz = inserir(raiz, valor);
            printf("Elemento inserido com sucesso!\n");
        }
        else if(op == 2) {
            printf("Arvore binaria em ordem: \n"); 
            imprimir(raiz);
            printf("\nTamanho: %d\n", tamanho(raiz)); 
        }
        else if(op == 3) {
            printf("Digite o valor a ser buscado: ");
            scanf("%lf", &valor);
            if(buscaBinaria(raiz, valor) == 1)
                printf("Elemento presente na arvore!\n");
            else 
                printf("Elemento nao encontrado!\n");
        }
        else if(op == 4) {
            printf("Digite o valor a ser removido: ");
            scanf("%lf", &valor);
            raiz = remover(raiz, valor);
        } else {
            printf("Digite uma opcao valida!\n");
        }
    } while(op != 0);

return 0;
}