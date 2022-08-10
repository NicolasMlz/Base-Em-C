#include <stdlib.h>
#include <stdio.h>

//----------------------------------------------------------
// programmingS.h
//----------------------------------------------------------

//Apontadores globais
typedef struct Descritor *ApontadorDescritor;
typedef struct Questao *ApontadorCelula;

//Structs globais
typedef struct Descritor {

    //Variaveis
    ApontadorCelula p;
    int tamanho;
    ApontadorCelula f;
    
} Descritor;
typedef struct Questao {

    //Variaveis
    ApontadorCelula ant;
    int tempo;
    ApontadorCelula prox;

} Questao;

//Headers
int CriarListaVazia(ApontadorDescritor *d);
int InserirInicio(ApontadorDescritor *d, Questao questao);
int InserirFinal(ApontadorDescritor *d, Questao questao);
int InserirMeio(ApontadorDescritor *d, Questao questao);
int InserirEmOrdem(ApontadorDescritor *d, Questao questao);
void Vencedor(ApontadorDescritor *d, int tempo);

//----------------------------------------------------------
// programmingS.c
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
int InserirInicio(ApontadorDescritor *d, Questao questao) {

    //Variaveis
    ApontadorCelula q;
    q = malloc(sizeof(Questao));

    //Verificar se alocou e criar celula
    if(q == NULL) {
        return 0;
    }
    else {

        //Criar celula que sera inserida na lista
        q->ant = NULL;
        q->tempo = questao.tempo;
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
int InserirFinal(ApontadorDescritor *d, Questao questao) {

    //Variaveis
    ApontadorCelula q;

    //Caso em que a lista é vazia
    if((*d)->tamanho == 0) {

        //Inserir no inicio
        InserirInicio(d, questao);

    }
    //Verificar se alocou e criar celula
    else{
        q = malloc(sizeof(Questao));
        if(q == NULL) {
            return 0;
        }
        else {
            
            //Criar celula
            q->tempo = questao.tempo;
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

//Inserir no meio
int InserirMeio(ApontadorDescritor *d, Questao questao) {

    //Variaveis
    ApontadorCelula q, r;
    int cont=0;

    //Percorrer a lista ate encontrar o elemento maior
    r = (*d)->p;
    do {

        if(r->tempo > questao.tempo) {

            //Alocar
            q = malloc(sizeof(Questao));
            q->tempo = questao.tempo;

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
int InserirEmOrdem(ApontadorDescritor *d, Questao questao) {

    //Variaveis
    ApontadorCelula q, r;
    q = malloc(sizeof(Questao));
    int cont=0;

    //Verificar se alocou
    if(q == NULL) {
        return 0;
    }
    else{

        //Caso em que a lista é vazia
        if((*d)->p == NULL) {
            
            //INICIO
            InserirInicio(d, questao);

        }
        //Caso em que o elemento eh menor q o primeiro
        else if(questao.tempo < (*d)->p->tempo) {

            //INICIO
            InserirInicio(d, questao);

        }
        //Caso em que o ultimo elemento é maior
        else if(questao.tempo > (*d)->f->tempo) {
            InserirFinal(d, questao);
        }       
        //Caso em que é no meio da lista
        else {

            //Percorrer a lista ate encontrar elementos maiores 
            q = (*d)->p;     
            do {

                //MEIO
                if(q->tempo > questao.tempo && cont == 0) {
                    InserirMeio(d, questao);
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
void Vencedor(ApontadorDescritor *d, int tempo) {
 
    //Variaveis
    ApontadorCelula q;
    int pontos=0;
    q = malloc(sizeof(Questao));
    q = (*d)->p;
    
    while(q->prox != NULL) {
        printf("%d ", q->tempo);
        q = q->prox;
    }
    printf("%d\n", q->tempo);

}

//----------------------------------------------------------
// programmingS.main
//----------------------------------------------------------
int main() {

    //Variaveis
    int i, aux, n, tTotal, nQuestoes;
    ApontadorDescritor d;
    Questao questao;

    //Scanear qtde de casos de teste
    scanf("%d", &n);
    while(n--) {

        //Scanear duracao maxima da prova e numero de questoes
        scanf("%d %d", &tTotal, &nQuestoes);
        CriarListaVazia(&d);

        //Scanear quanto tempo demora pra resolver cada questao e colocar em uma lista
        for(i=0; i<nQuestoes; i++) {

            //Tempo por questao
            scanf("%d", &questao.tempo);

            //Armazenar em ordem crescente cada questao na lista
            aux = InserirEmOrdem(&d, questao);
        }

        //Saida
        Vencedor(&d, tTotal);
        free(d);
    }
}