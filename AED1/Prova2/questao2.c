#include <stdlib.h>
#include <string.h>
#include <stdio.h>
 
//----------------------------------------------------------
// questao2.h
//----------------------------------------------------------
 
//Apontadores globais
typedef struct Descritor *ApontadorDescritor;
typedef struct Lista *ApontadorCelula;
 
//Structs globais
typedef struct Descritor {
 
    //Variaveis
    ApontadorCelula p;
    int tamanho;
    ApontadorCelula f;
    
} Descritor;
typedef struct Lista {
 
    //Variaveis
    ApontadorCelula ant;
    int n;
    ApontadorCelula prox;
 
} Lista;
 
//Headers
int CriarListaVazia(ApontadorDescritor *d);
int InserirInicio(ApontadorDescritor *d, Lista lista);
int InserirFinal(ApontadorDescritor *d, Lista lista);
int InserirMeio(ApontadorDescritor *d, Lista lista);
int InserirEmOrdem(ApontadorDescritor *d, Lista lista);
void ImprimirListaCrescente(ApontadorDescritor *d);
void ImprimirListaDecrescente(ApontadorDescritor *d);
 
//----------------------------------------------------------
// questao2.c
//----------------------------------------------------------
 
//Criar uma lista vazia
int CriarListaVazia(ApontadorDescritor *d) {
 
    //Alocar d
    (*d) = malloc(sizeof(Descritor));
 
    if((*d) == NULL ) {
        return 0;
    } else {
        (*d)->p = NULL;
        (*d)->tamanho = 0;
        (*d)->f = NULL;
        return 1;
    }
}
 
//Inserir no inicio
int InserirInicio(ApontadorDescritor *d, Lista lista) {
 
    //Variaveis
    ApontadorCelula q;
    q = malloc(sizeof(Lista));
 
    //Verificar se alocou e criar celula
    if(q == NULL) {
        return 0;
    }
    else {
 
        //Criar celula que sera inserida na lista
        q->ant = NULL;
        q->n = lista.n;
        q->prox = (*d)->p;
 
        //Caso em que a lista é vazia
        if((*d)->tamanho == 0) {
 
            //Modificar descritor
            (*d)->p = q;
            (*d)->tamanho++;
            (*d)->f = q;
 
            //Retorno
            return 1;
        }
        //Caso em que a lista não é vazia
        else {
 
            //Modificar descritor
            (*d)->p = q;
            (*d)->tamanho++;
            ((*d)->p)->ant = q;
                       
            //Retorno
            return 1;
        }
 
    }
 
}
 
//Inserir no final
int InserirFinal(ApontadorDescritor *d, Lista lista) {
 
    //Variaveis
    ApontadorCelula q;
 
    //Caso em que a lista é vazia
    if((*d)->tamanho == 0) {
 
        //Inserir no inicio
        InserirInicio(d, lista);
 
    }
    //Verificar se alocou e criar celula
    else{
        q = malloc(sizeof(Lista));
        if(q == NULL) {
            return 0;
        }
        else {
            
            //Criar celula
            q->n = lista.n;
            q->ant = (*d)->f;
            q->prox = NULL;
 
            //Remodelar ponteiros
            ((*d)->f)->prox = q;
            (*d)->f = q;
            (*d)->tamanho++;
 
            return 1;
        }
    }
 
    return 1;    
}
 
//Inserir no meio
int InserirMeio(ApontadorDescritor *d, Lista lista) {
 
    //Variaveis
    ApontadorCelula q, r;
    int cont=0;
 
    //Percorrer a lista ate encontrar o elemento maior
    r = (*d)->p;
    do {
 
        if(r->n > lista.n) {
 
            //Alocar
            q = malloc(sizeof(Lista));
            q->n = lista.n;
 
            //Colocar a celula no meio, mudando os ponteiros
            q->prox = r;
            (r->ant)->prox = q;
            q->ant = r->ant;
            r->ant = q;
            cont++;
            return 1;
        }
        
        r = r->prox;
 
    } while(r != NULL);
 
    return 1;
}
 
//Inserir em lista
int InserirEmOrdem(ApontadorDescritor *d, Lista lista) {
 
    //Variaveis
    ApontadorCelula q;
    q = malloc(sizeof(Lista));
    int cont=0;
 
    //Verificar se alocou
    if(q == NULL) {
        return 0;
    }
    else{
 
        //Caso em que a lista é vazia
        if((*d)->p == NULL) {
            
            //INICIO
            InserirInicio(d, lista);
 
        }
        //Caso em que o elemento eh menor q o primeiro
        else if(lista.n < (*d)->p->n) {
 
            //INICIO
            InserirInicio(d, lista);
 
        }
        //Caso em que o ultimo elemento é maior
        else if(lista.n >= (*d)->f->n) {
            InserirFinal(d, lista);
        }       
        //Caso em que é no meio da lista
        else {
 
            //Percorrer a lista ate encontrar elementos maiores 
            q = (*d)->p;     
            do {
 
                //MEIO
                if(q->n > lista.n && cont == 0) {
                    InserirMeio(d, lista);
                    cont++;
                }
                q = q->prox;
 
            } while(q != NULL);
        }
    }
 
    //Retorno
    return 1;
}
 
//Imprimir lista
void ImprimirListaCrescente(ApontadorDescritor *d) {
 
    //Variaveis
    ApontadorCelula q;
 
    //Percorrer e imprimir lista
    q = (*d)->p;
    while(q->prox != NULL) {
        
        //Saida
        printf("%d ", q->n);
 
        //Continuar looping
        q = q->prox;
 
    }
    printf("%d\n", q->n);
}
 
//Imprimir lista decrescente
void ImprimirListaDecrescente(ApontadorDescritor *d) {
 
    //Variaveis
    ApontadorCelula q;
 
    //Percorrer e imprimir lista
    q = (*d)->f;
    while(q->ant != NULL) {
        
        //Saida
        printf("%d ", q->n);
 
        //Continuar looping
        q = q->ant;
 
    }
    printf("%d\n", q->n);
}
 
//----------------------------------------------------------
// questao2.main
//----------------------------------------------------------
int main() {
 
    //Variaveis
    ApontadorDescritor d, dEmOrdem;
    Lista lista;
    char menu;
    int aux;
 
    //Scanear lista desejada
    CriarListaVazia(&dEmOrdem);
    CriarListaVazia(&d);
    do {
 
        //Lista desejada
        scanf("%d", &lista.n);
 
        //Armazenar no final cada numeracao
        if(lista.n > 0) {
            aux = InserirFinal(&d, lista);
            aux = InserirEmOrdem(&dEmOrdem, lista);
        }
 
    } while(lista.n != -1);
 
    //Menu
    do {
 
            //Scanear opcao do usuario
            scanf("%c", &menu);
 
            //Mostrar crescente
            if(menu == 'C') {
                ImprimirListaCrescente(&dEmOrdem);
                printf("\n");
            }
            //Mostrar decrescente
            else if(menu == 'D') {
                ImprimirListaDecrescente(&dEmOrdem);
                printf("\n");
            }
            //Mostrar em ordem scaneada
            else if(menu == 'L') {
                ImprimirListaCrescente(&d);
                printf("\n");
            }
            //Mostrar maior elemento da lista
            else if(menu == 'M') {
                printf("%d\n", dEmOrdem->f->n);
            }
            //Mostrar menor elemento da lista
            else if(menu == 'm') {
                printf("%d\n", dEmOrdem->p->n);
            }
 
    } while(menu != 'X');
    
    //Retorno do main
    return 0;
 
}