#include <stdlib.h>
#include <string.h>
#include <stdio.h>
 
//----------------------------------------------------------
// questao4.h
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
    long long int n;
    ApontadorCelula prox;
 
} Lista;
 
//Headers
int CriarListaVazia(ApontadorDescritor *d);
int InserirInicio(ApontadorDescritor *d, Lista lista);
int InserirFinal(ApontadorDescritor *d, Lista lista);
void NumerosPrimos(int *vetor);
void Fatoracao(ApontadorDescritor *d);
 
//----------------------------------------------------------
// questao4.c
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
 
//Fatorar lista
void Fatoracao(ApontadorDescritor *d) {
 
    //Variaveis
    ApontadorCelula q;
    long long int i=2, aux;
 
    //Alocar
    q = malloc(sizeof(Lista));
 
    //Verificar se alocou
    if(q != NULL) {
        
        //Percorrer lista de tras pra frente
        q = (*d)->f;
        while(q != NULL) {
 
            //Fatorar numero
            while((q->n) != 1) {
 
                //Imprimir fator primo que divide n
                if((q->n)%i != 0) {
 
                    //Ir para o proximo "primo"
                    /*Na verdade nao é primo, mas se for por exemplo o 9, 
                    o numero em questao já terá sido dividido por 3 varias 
                    vezes, e assim por diante, assim, é possível uma resposta
                    mais rápida do programa, ao invés de criar um vetor de
                    primos e percorrê-lo junto à lista*/ 
 
                    //Continuar looping
                    i++;
 
                }
                else{            
                    
                    //Continuar looping
                    q->n = (q->n)/i;

                    //Saida
                    if((q->n) != 1) {
                        printf("%lld ", i);
                    } else {
                        printf("%lld\n", i);
                    }
                }
            }

            //Continuar looping
            q = q->ant; i=2;
        }
 
    }
}

//-----------------------------------------------------OBSERVACAO-------------------------------------------------------
/*
O caso do numero 9423891297239 nao passara no sharif pois
o "for" rodara mais de 9 trilhoes de vezes, teoricamente, tendo
uma quantidade de tempo grande, o programa sera executado 
perfeitamente, mas o sharif nao disponibiliza esse grande 
intervalo, logo, apesar do programa estar certo, o problema
se encontra no "pior caso" em que o numero em questao é grande
e é primo. Esse acabou sendo o O(n) da questão: o pior caso.
*/
//-----------------------------------------------------OBSERVACAO-------------------------------------------------------


//----------------------------------------------------------
// questao4.main
//----------------------------------------------------------
int main() {
 
    //Variaveis
    ApontadorDescritor d;
    Lista lista;
    int aux;
 
    //Scanear lista desejada
    CriarListaVazia(&d);
    do {
 
        //Lista desejada
        scanf("%lld", &lista.n);
 
        //Armazenar no final cada numeracao
        if(lista.n != -1) {
            aux = InserirFinal(&d, lista);
        }
 
    } while(lista.n != -1);
 
    //Fatorar cada elemento da lista de tras pra frente em fatores primos
    Fatoracao(&d);
 
    //Retorno do main
    return 0;
 
}