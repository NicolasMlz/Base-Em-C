#include <stdlib.h>
#include <stdio.h>

//----------------------------------------------------------
// parentesess.h
//----------------------------------------------------------

//Apontadores globais
typedef struct Descritor *ApontadorDescritor;
typedef struct Caracter *ApontadorCelula;

//Structs globais
typedef struct Descritor {

    //Variaveis
    ApontadorCelula p;
    int tamanho;
    ApontadorCelula f;
    
} Descritor;
typedef struct Caracter {

    //Variaveis
    ApontadorCelula ant;
    char c;
    ApontadorCelula prox;

} Caracter;

//Headers
int CriarListaVazia(ApontadorDescritor *d);
int InserirInicio(ApontadorDescritor *d, Caracter caracter);
int InserirFinal(ApontadorDescritor *d, Caracter caracter);
int Formatacao(ApontadorDescritor *d);
void removerElemento(ApontadorDescritor *d, Caracter caracter);

//----------------------------------------------------------
// parentesess.c
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
int InserirInicio(ApontadorDescritor *d, Caracter caracter) {

    //Variaveis
    ApontadorCelula q;
    q = malloc(sizeof(Caracter));

    //Verificar se alocou e criar celula
    if(q == NULL) {
        return 0;
    }
    else {

        //Criar celula que sera inserida na lista
        q->ant = NULL;
        q->c = caracter.c;
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
int InserirFinal(ApontadorDescritor *d, Caracter caracter) {

    //Variaveis
    ApontadorCelula q;

    //Caso em que a lista é vazia
    if((*d)->tamanho == 0) {

        //Inserir no inicio
        InserirInicio(d, caracter);

    }
    //Verificar se alocou e criar celula
    else{
        q = malloc(sizeof(Caracter));
        if(q == NULL) {
            return 0;
        }
        else {
            
            //Criar celula
            q->c = caracter.c;
            q->ant = (*d)->f;
            q->prox = NULL;

            //Remodelar ponteiros
            ((*d)->f)->prox = q;
            (*d)->tamanho++;
            (*d)->f = q;

            return 1;
        }
    }    
}

//Verificar se formatacao esta correta
int Formatacao(ApontadorDescritor *d) {

    //Variaveis
    int contAberto=0, contFechado=0, errado=0;
    ApontadorCelula q, s;
    Caracter caracter;
    q = malloc(sizeof(Caracter));
    s = malloc(sizeof(Caracter));

    //Percorrer a lista
    q = (*d)->p;
    while(q != NULL) {

        if(q->c == ')') {
            contFechado++;
        }

        //Achar parenteses aberto
        if(q->c == '(') {
            contAberto++;

            //Encontrar parenteses que fecha este
            s = (*d)->p;;
            while(s != NULL) {
                if(s->c == ')') {
                    contFechado++;
                    caracter.c = s->c;
                    removerElemento(d, caracter);
                    caracter.c = q->c;
                    removerElemento(d, caracter);
                    s = NULL;
                }
                if(s != NULL) {
                    s = s->prox;
                }
            }
        }


        //Verificar se o primeiro parenteses é fechado
        if((q->c == ')') && (contAberto == 0)) {
            contFechado++;
            errado++;
        }

        q = q->prox;
    }

    //Analisar se a expressao esta correta
    if(errado == 0) {
        if((contFechado == contAberto) || (contAberto == contFechado + 1)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }

}

//Remover elemento
void removerElemento(ApontadorDescritor *d, Caracter caracter) {
 
    //Variaveis
    ApontadorCelula q, s;
    int i=0;
 
    //Remover parenteses fechado ou aberto
    q = (*d)->p;
    while((q->prox != NULL) && (q->c != caracter.c)) {
        s = q;
        q = q->prox;
        i++;
    }
 
    //Mudar ponteiros para pular os excluidos
    if(i == 0) {
        (*d)->p = q->prox; 
    } else if(q->c == caracter.c) {
        s->prox = q->prox;
    } else if(q->prox == NULL && q->c == caracter.c){
        s->prox = NULL;
    }
}

//----------------------------------------------------------
// parentesess.main
//----------------------------------------------------------
int main() {

    //Variaveis
    ApontadorDescritor d;
    Caracter caracter;
    int i, aux;

    //Scanear caracter desejado
    CriarListaVazia(&d);
    do {

        //Caracter desejado
        scanf("%c", &caracter.c);

        //Armazenar no final para formar frase
        aux = InserirFinal(&d, caracter);

    } while(caracter.c != '\n');

    //Saida
    aux = Formatacao(&d);
    if(aux == 1) {
        printf("correta\n");
    }
    else {
        printf("incorreta\n");    
    }
}