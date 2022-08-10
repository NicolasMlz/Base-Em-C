#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//----------------------------------------------------------
// questao1.h
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
void ImprimirListaCrescente(ApontadorDescritor *d);
void Intercalar1(ApontadorDescritor *d, ApontadorDescritor *d2, ApontadorDescritor *s);
void Intercalar2(ApontadorDescritor *d, ApontadorDescritor *d2, ApontadorDescritor *s);
void Intercalar3(ApontadorDescritor *d, ApontadorDescritor *d2, ApontadorDescritor *s);


//----------------------------------------------------------
// questao1.c
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

//Imprimir lista
void ImprimirListaCrescente(ApontadorDescritor *d) {

    //Variaveis
    ApontadorCelula q;

    //Percorrer e imprimir lista
    q = (*d)->p;
    while(q != NULL) {
        
        //Saida
        printf("%d ", q->n);

        //Continuar looping
        q = q->prox;

    }
}

//Intercalar 1
void Intercalar1(ApontadorDescritor *d, ApontadorDescritor *d2, ApontadorDescritor *s) {

    //Variaveis
    ApontadorCelula q, q2;
    Lista lista;
    q = malloc(sizeof(Lista));
    q2 = malloc(sizeof(Lista));

    //Verificar se alocou
    if(q != NULL && q2 != NULL) {

        //Iniciar 2 listas do comeco
        q = (*d)->p;
        q2 = (*d2)->p;

        //Percorrer as 2 listas
        while(q2 != NULL) {
            while(q != NULL) {
                if(q->n >= q2->n) {
                    lista.n = q->n;
                    InserirFinal(s, lista);
                }

                //Continuar looping
                q = q->prox;
            }

            //Armazenar elemento da lista 2 na nova lista
            lista.n = q2->n;
            InserirFinal(s, lista);

            //Continuar looping da lista 2
            q2 = q2->prox;
            q = (*d)->p;
        }
    }
}

//Intercalar 2
void Intercalar2(ApontadorDescritor *d, ApontadorDescritor *d2, ApontadorDescritor *s) {

    //Variaveis
    ApontadorCelula q, q2;
    Lista lista;
    q = malloc(sizeof(Lista));
    q2 = malloc(sizeof(Lista));

    //Verificar se alocou
    if(q != NULL && q2 != NULL) {

        //Iniciar 2 listas do comeco
        q = (*d)->p;
        q2 = (*d2)->p;

        //Percorrer as 2 listas
        while(q != NULL) {
            while(q2 != NULL) {
                if(q2->n <= q->n) {
                    lista.n = q2->n;
                    InserirFinal(s, lista);
                }

                //Continuar looping
                q2 = q2->prox;
            }

            //Armazenar elemento da lista 2 na nova lista
            lista.n = q->n;
            InserirFinal(s, lista);

            //Continuar looping da lista 2
            q = q->prox;
            q2 = (*d2)->p;
        }
    }  
}

//Intercalar 3
void Intercalar3(ApontadorDescritor *d, ApontadorDescritor *d2, ApontadorDescritor *s) {

    //Variaveis
    ApontadorCelula q, q2;
    Lista lista;
    int cont=0;
    q = malloc(sizeof(Lista));
    q2 = malloc(sizeof(Lista));

    //Verificar se alocou
    if(q != NULL && q2 != NULL) {

        //Iniciar 2 listas do comeco
        q = (*d)->p;
        q2 = (*d2)->p;

        //Percorrer as 2 listas
        while(q2 != NULL) {

            //Armazenar intercalado
            if(cont%2 == 0) {
                lista.n = q->n;
                InserirFinal(s, lista);

                //Continuar looping
                q = q->prox;            
            }
            else {
                lista.n = q2->n;
                InserirFinal(s, lista);
                
                //Copntinuar looping
                q2 = q2->prox;
            }

            cont++;
        }
    }
}

//----------------------------------------------------------
// questao1.main
//----------------------------------------------------------
int main() {

    //Variaveis
    ApontadorDescritor d, d2, s;
    Lista lista;
    int aux;

    //Criar lista 3
    CriarListaVazia(&s);

    //Scanear lista 1
    CriarListaVazia(&d);
    do {

        //Lista desejada
        scanf("%d", &lista.n);

        //Armazenar no final cada numeracao
        if(lista.n != -1) {
            aux = InserirFinal(&d, lista);
        }

    } while(lista.n != -1);

    //Scanear lista 2
    CriarListaVazia(&d2);
    do {

        //Lista desejada
        scanf("%d", &lista.n);

        //Armazenar no final cada numeracao
        if(lista.n != -1) {
            aux = InserirFinal(&d2, lista);
        }

    } while(lista.n != -1);    

    //Intercalar listas + saidas
    if((d->tamanho == 0) && (d2->tamanho == 0)) {
        CriarListaVazia(&s);
        printf("-1\n");
    }
    else if((d->tamanho != 0) && (d2->tamanho == 0)) {
        ImprimirListaCrescente(&d);
        printf("-1\n");
    }
    else if((d->tamanho == 0) && (d2->tamanho != 0)) {
        ImprimirListaCrescente(&d2);
        printf("-1\n");
    }
    else if(d->tamanho > d2->tamanho) {
        Intercalar1(&d, &d2, &s);
        ImprimirListaCrescente(&s);
        printf("-1\n");
    }
    else if(d->tamanho < d2->tamanho) {
        Intercalar2(&d, &d2, &s);
        ImprimirListaCrescente(&s);
        printf("-1\n");
    }
    else if(d->tamanho == d2->tamanho) {
        Intercalar3(&d, &d2, &s);
        ImprimirListaCrescente(&s);
        printf("-1\n");
    } 

    //Retorno do main
    return 0;

}