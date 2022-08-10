#include <stdlib.h>
#include <stdio.h>
 
//----------------------------------------------------------
// questao3.h
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
    int nBin[32];
    ApontadorCelula prox;
 
} Lista;
 
//Headers
int CriarListaVazia(ApontadorDescritor *d);
int InserirInicio(ApontadorDescritor *d, Lista lista);
int InserirFinal(ApontadorDescritor *d, Lista lista);
void Binario(ApontadorDescritor *d);
void Selecionou(ApontadorDescritor *d, ApontadorDescritor *conj);


//----------------------------------------------------------
// questao3.c
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

//Converter para binario
void Binario(ApontadorDescritor *d) {

    //Variaveis
    ApontadorCelula q;
    int i=32, aux;

    //Alocar
    q = malloc(sizeof(Lista));

    //Verificar se alocou
    if(q != NULL) {

        //Percorrer lista
        q = (*d)->p;
        while(q != NULL) {
            
            //Armazenar em uma auxiliar
            aux = q->n;

            //Transformar cada elemento em binario
            while(aux > 1) {

                //Armazenar 0s e 1s em um vetor de tras pra frente
                if(aux%2 == 0) {
                    q->nBin[i] = 0;
                } else {
                    q->nBin[i] = 1;
                }

                //Continuar dividindo
                aux = aux/2;
                i--;

                //Ultimo elemento
                if(aux == 1) {
                    q->nBin[i] = 1;
                }
            }


            //Continuar looping
            q = q->prox; i=32;
        }
    }
}

//Verificar se os binarios serao selecionados
void Selecionou(ApontadorDescritor *d, ApontadorDescritor *conj) {

    //Variaveis
    ApontadorCelula q, c;
    int cont=0, contNum=0;;

    //Alocar
    q = malloc(sizeof(Lista));
    c = malloc(sizeof(Lista));

    //Verificar se alocou
    if(q != NULL && c != NULL) {

        //Percorrer lista
        q = (*d)->p;
        c = (*conj)->p;

        while(q != NULL) {
            while(c != NULL) {

                //Contar quantos 1s aparecem de acordo com o conjunto
                if(q->nBin[32-(c->n)] == 1) {
                    cont++;
                }
                
                //Continuar looping
                c = c->prox;
            }

            //Saida
            if(cont == (*conj)->tamanho) {
                printf("%d ", q->n);
                contNum++;
            }

            //Continuar looping de fora
            q = q->prox;
            c = (*conj)->p;
            cont=0;
        }
        if(contNum != 0) {
            printf("\n");
        }
        else if(contNum == 0) {
            printf("-1\n");
        }
    }
}

//----------------------------------------------------------
// questao3.main
//----------------------------------------------------------
int main() {
 
    //Variaveis
    ApontadorDescritor d, conj;
    Lista lista;
    int aux, i;
 
    //Scanear lista desejada
    CriarListaVazia(&d);
    do {
 
        //Lista desejada
        scanf("%d", &lista.n);
 
        //Armazenar no final cada numeracao
        if(lista.n != -1) {
            aux = InserirFinal(&d, lista);
        }
 
    } while(lista.n != -1);

    //Scanear conjunto desejado
    CriarListaVazia(&conj);
    do {
 
        //Lista desejada
        scanf("%d", &lista.n);
 
        //Armazenar no final cada numeracao
        if(lista.n != -1) {
            aux = InserirFinal(&conj, lista);
        }
 
    } while(lista.n != -1);

    //Converter toda a lista 1 para binarios
    Binario(&d);

    //Verificar quais serao selecionados
    Selecionou(&d, &conj);
 
    //Retorno do main
    return 0;
 
}