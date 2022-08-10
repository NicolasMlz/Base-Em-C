#include <stdlib.h>
#include <stdio.h>

//----------------------------------------------------------
// trem.h
//----------------------------------------------------------

//Apontadores globais
typedef struct Descritor *ApontadorDescritor;
typedef struct Ordem *ApontadorCelula;

//Structs globais
typedef struct Descritor {

    //Variaveis
    ApontadorCelula p;
    int tamanho;
    ApontadorCelula f;
    
} Descritor;
typedef struct Ordem {

    //Variaveis
    ApontadorCelula ant;
    int num;
    ApontadorCelula prox;

} Ordem;

//Headers
int CriarListaVazia(ApontadorDescritor *d);
int InserirInicio(ApontadorDescritor *d, Ordem ordem);
int InserirFinal(ApontadorDescritor *d, Ordem ordem);
int InserirMeio(ApontadorDescritor *d, Ordem ordem);
int InserirEmOrdem(ApontadorDescritor *d, Ordem ordem);
int Crescente(ApontadorDescritor *d, int num);
int Decrescente(ApontadorDescritor *d, int num);

//----------------------------------------------------------
// trem.c
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
int InserirInicio(ApontadorDescritor *d, Ordem ordem) {

    //Variaveis
    ApontadorCelula q;
    q = malloc(sizeof(Ordem));

    //Verificar se alocou e criar celula
    if(q == NULL) {
        return 0;
    }
    else {

        //Criar celula que sera inserida na lista
        q->ant = NULL;
        q->num = ordem.num;
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
int InserirFinal(ApontadorDescritor *d, Ordem ordem) {

    //Variaveis
    ApontadorCelula q;

    //Caso em que a lista é vazia
    if((*d)->tamanho == 0) {

        //Inserir no inicio
        InserirInicio(d, ordem);

    }
    //Verificar se alocou e criar celula
    else{
        q = malloc(sizeof(Ordem));
        if(q == NULL) {
            return 0;
        }
        else {
            
            //Criar celula
            q->num = ordem.num;
            q->ant = (*d)->f;
            q->prox = NULL;

            //Remodelar ponteiros
            ((*d)->f)->prox = q;
            (*d)->f = q;

            return 1;
        }
    }    
}

//Inserir no meio
int InserirMeio(ApontadorDescritor *d, Ordem ordem) {

    //Variaveis
    ApontadorCelula q, r;
    int cont=0;

    //Percorrer a lista ate encontrar o elemento maior
    r = (*d)->p;
    do {

        if(r->num > ordem.num) {

            //Alocar
            q = malloc(sizeof(Ordem));
            q->num = ordem.num;

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
}

//Inserir em ordem
int InserirEmOrdem(ApontadorDescritor *d, Ordem ordem) {

    //Variaveis
    ApontadorCelula q, r;
    q = malloc(sizeof(Ordem));
    int cont=0;

    //Verificar se alocou
    if(q == NULL) {
        return 0;
    }
    else{

        //Caso em que a lista é vazia
        if((*d)->p == NULL) {
            
            //INICIO
            InserirInicio(d, ordem);

        }
        //Caso em que o elemento eh menor q o primeiro
        else if(ordem.num < (*d)->p->num) {

            //INICIO
            InserirInicio(d, ordem);

        }
        //Caso em que o ultimo elemento é maior
        else if(ordem.num > (*d)->f->num) {
            InserirFinal(d, ordem);
        }       
        //Caso em que é no meio da lista
        else {

            //Percorrer a lista ate encontrar elementos maiores 
            q = (*d)->p;     
            do {

                //MEIO
                if(q->num > ordem.num && cont == 0) {
                    InserirMeio(d, ordem);
                    cont++;
                }
                q = q->prox;

            } while(q != NULL);
        }
    }

    //Retorno
    return 1;
}

//Verificar se é crescente
int Crescente(ApontadorDescritor *d, int num) {
 
    //Variaveis
    ApontadorCelula q;
    int cont=1;
    q = malloc(sizeof(Ordem));
    
    //Percorrer lista
    q = (*d)->p;
    while(cont <= num) {
        if((q->num == cont) || (q->num == cont+1) || (q->num == cont-1)) {
            q = q->prox;
            cont++;
        }
        else {
            cont = num+3;
        }
    }

    //Verificar se é igual a ordem desejada
    if(cont == num+1) {
        return 1;
    }
    else {
        return 0;
    }

}

//Verificar se é descrecente
int Decrescente(ApontadorDescritor *d, int num) {
 
    //Variaveis
    ApontadorCelula q;
    int cont=num;
    q = malloc(sizeof(Ordem));
    
    //Percorrer lista
    q = (*d)->p;
    while(cont >= 1) {
        if(q->num == cont) {
            q = q->prox;
            cont--;
        }
        else if(q->num != cont){
            cont = -1;
        }
    }

    //Verificar se é igual a ordem desejada
    if(cont == 0) {
        return 1;
    }
    else {
        return 0;
    }

}

//----------------------------------------------------------
// trem.main
//----------------------------------------------------------
int main() {

    //Variaveis
    int i, aux, aux2, n;
    ApontadorDescritor d;
    Ordem ordem;

    //Scanear qtde de vagoes
    scanf("%d", &n);

    //Scanear ordem desejada dos vagoes
    CriarListaVazia(&d);
    for(i=0; i<n; i++) {

        //Ordem desejada
        scanf("%d", &ordem.num);

        //Armazenar no final cada numeracao
        aux = InserirFinal(&d, ordem);
    }

    //Saida
    aux = Crescente(&d, n);
    aux2 = Decrescente(&d, n);
    if(aux == 1 || aux2 == 1) {
        printf("sim\n");
    }
    else {
        printf("nao\n");
    }
    free(d);
}