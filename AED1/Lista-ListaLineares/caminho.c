#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//----------------------------------------------------
// caminhos.h
//----------------------------------------------------

//Structs globais
typedef struct Descritor *ApontadorDescritor;
typedef struct Instrucao *ApontadorCelula;
typedef struct Descritor {

    //Variaveis do descritor
    ApontadorCelula prim;
    int tamanho;
    ApontadorCelula fim;

} Descritor;
typedef struct Instrucao {

    //Variaveis da instrucao
    ApontadorCelula ant;
    char direcao[20];
    char rua[20];
    ApontadorCelula prox;

} Instrucao;

//Headers
void CriarListaVazia(ApontadorDescritor *d);
void InserirInicio(ApontadorDescritor *d, Instrucao instrucao);
void InserirFinal(ApontadorDescritor *d, Instrucao instrucao);
void CaminhoInverso(ApontadorDescritor *d, ApontadorDescritor *e);
void ImprimirLista(ApontadorDescritor *e);


//----------------------------------------------------
// caminhos.c
//----------------------------------------------------

//Criar uma lista vazia
void CriarListaVazia(ApontadorDescritor *d) {

    //Variaveis
    (*d) = malloc(sizeof(Descritor));

    //Verificar se alocou
    if((*d) != NULL) {
        (*d)->prim = NULL;
        (*d)->tamanho = 0;
        (*d)->fim = NULL;
    }
}

//Inserir elemento no inicio
void InserirInicio(ApontadorDescritor *d, Instrucao instrucao) {

    //Variaveis
    ApontadorCelula q;
    
    //Alocar espaco dinamicamente
    q = malloc(sizeof(Instrucao));

    //Verificar se alocou
    if(q != NULL) {
        
        //Criar celula
        q->ant = NULL;
        strcpy(q->direcao, instrucao.direcao);
        strcpy(q->rua, instrucao.rua);
        q->prox = (*d)->prim;

        //Caso em que a lista é vazia
        if((*d)->tamanho == 0) {

            //Modificar descritor
            (*d)->prim = q;
            (*d)->tamanho++;
            (*d)->fim = q;

        }
        //Caso em que a lista possui celulas
        else {
            
            //Modificar descritor
            (*d)->prim = q;
            (*d)->tamanho++;
            ((*d)->prim)->ant = q;

        }
        

    }
}

//Inserir elemento no final
void InserirFinal(ApontadorDescritor *d, Instrucao instrucao) {

    //Variaveis
    ApontadorCelula q;

    //Alocar celula dinamicamente
    q = malloc(sizeof(Instrucao));

    //Verificar se alocou
    if(q != NULL) {

        //Caso que se insere no inicio
        if((*d)->tamanho == 0) {
            InserirInicio(d, instrucao);
        }
        //Caso que se insere no final
        else {

            //Criar celula a ser inserida no final
            q->ant = (*d)->fim;
            strcpy(q->direcao, instrucao.direcao);
            strcpy(q->rua, instrucao.rua);
            q->prox = NULL;

            //Modificar descritor e a penultima celula
            (*d)->fim->prox = q;
            (*d)->fim = q;

        }
    }
}

//Fazer o caminho para voltar para a casa
void CaminhoInverso(ApontadorDescritor *d, ApontadorDescritor *e) {
    
    //Variaveis
    ApontadorCelula q;
    Instrucao instrucao;
    char esquerda[50] = "ESQUERDA";
    char direita[50] = "DIREITA";
    
    //Percorrer a lista do fim ao inicio
    q = (*d)->fim->ant;
    while(q != NULL) {

        //Criar celula que sera armazenada em outra lista
        strcpy(instrucao.rua, q->rua);
        if(strcmp(q->direcao, esquerda) == 0) {
            strcpy(instrucao.direcao, direita);
        }
        else if(strcmp(q->direcao, direita) == 0){
            strcpy(instrucao.direcao, esquerda);
        }

        //Passar celula para a lista
        InserirFinal(e, instrucao);

        //Continuar looping
        q = q->ant;

    }
}

//Imprimir lista
void ImprimirLista(ApontadorDescritor *e) {

    //Variaveis
    ApontadorCelula q;

    //Percorrer e imprimir lista
    q = (*e)->prim;
    while(q != NULL) {
        
        //Saida
        printf("Vire a %s na rua %s.\n", q->direcao, q->rua);

        //Continuar looping
        q = q->prox;

    }

}

//----------------------------------------------------
// caminhos.main
//----------------------------------------------------

//Main
int main() {

    //Variaveis
    char esquerda[50] = "ESQUERDA";
    char direita[50] = "DIREITA";
    char escola[50] = "ESCOLA";
    char ultimaDirecao[50];
    ApontadorDescritor d, e;
    Instrucao instrucao;
    int n;

    //Scanear quantidade de casos de teste
    scanf("%d", &n);


    while(n--) {

        //Scanear primeira direcao a ser tomada
        scanf("%s", ultimaDirecao); 
        
        //Criar listas vazias
        CriarListaVazia(&d);
        CriarListaVazia(&e);   

        //Scanear direcoes ate a escola
        do {

            //Scanear uma instrucao por vez
            getchar();
            scanf("%s", instrucao.rua);
            getchar();
            if(strcmp(instrucao.rua, escola) != 0) {
                scanf("%s", instrucao.direcao);
            }

            //Forma a lista de instrucoes
            InserirFinal(&d, instrucao);
            
        } while(strcmp(instrucao.rua, escola) != 0);

        //Criar lista que reproduz o caminho de volta
        CaminhoInverso(&d, &e);

        //Saida
        ImprimirLista(&e);
        if(strcmp(ultimaDirecao, direita) == 0) {
            printf("Vire a %s na sua CASA.\n", esquerda);
        } else {
            printf("Vire a %s na sua CASA.\n", direita);
        }

        //Liberar lista
        free(d); free(e);
    }

    //Retorno
    return 0;
}