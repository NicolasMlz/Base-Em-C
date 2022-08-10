#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//----------------------------------------------------------
// micalateia.h
//----------------------------------------------------------

//Structs globais
typedef struct Descritor *ApontadorDescritor;
typedef struct Ligacao *ApontadorCelula;
typedef struct Descritor {

    //Varrriaveis
    ApontadorCelula prim;
    int tamanho;
    ApontadorCelula fim;

} Descritor;
typedef struct Ligacao {

    //Variaveis
    char nome[50];
    char telefone[50];
    int n;
    ApontadorCelula prox;

} Ligacao;

//Headers
void CriarListaVazia(ApontadorDescritor *d);
void InserirInicio(ApontadorDescritor *d, Ligacao ligacao);
void InserirFinal(ApontadorDescritor *d, Ligacao ligacao);
void InserirEmOrdem(ApontadorDescritor *d, Ligacao ligacao);
void AumentarLigacao(ApontadorDescritor *d, Ligacao ligacao);

//----------------------------------------------------------
// micalateia.c
//----------------------------------------------------------

//Criar uma lista vazia
void CriarListaVazia(ApontadorDescritor *d) {

    //Alocar
    (*d) = malloc(sizeof(Descritor));

    //Verificar se alocou
    if((*d) != NULL) {

        //Criar descritor
        (*d)->prim = NULL;
        (*d)->tamanho = 0;
        (*d)->fim = NULL;

    }
}

//Inserir no inicio
void InserirInicio(ApontadorDescritor *d, Ligacao ligacao) {

    //Variaveis
    ApontadorCelula q;

    //Alocar
    q = malloc(sizeof(Ligacao));

    //Verificar se alocou
    if(q != NULL) {

        //Armazenar dados em q
        strcpy(q->nome, ligacao.nome);
        strcpy(q->telefone, ligacao.telefone);
        q->n = ligacao.n;
        q->prox = (*d)->prim;

        //Caso em que a lista e vazia
        if((*d)->tamanho == 0) {
            (*d)->prim = q;
            (*d)->fim = q;
        }
        //Caso em que a lista n e vazia
        else {
            (*d)->prim = q;
        }
        (*d)->tamanho++;

    }
}

//Inserir no final
void InserirFinal(ApontadorDescritor *d, Ligacao ligacao) {

    //Variaveis
    ApontadorCelula q;

    //Caso em que a lista é vazia
    if((*d)->tamanho == 0) {

        //Inserir no inicio
        InserirInicio(d, ligacao);

    }
    //Verificar se alocou e criar celula
    else{

        //Alocar
        q = malloc(sizeof(Ligacao));
        if(q != NULL) {
            
            //Armazenar dados em q
            strcpy(q->nome, ligacao.nome);
            strcpy(q->telefone, ligacao.telefone);
            q->n = ligacao.n;
            q->prox = NULL;

            //Remodelar ponteiros
            ((*d)->fim)->prox = q;
            (*d)->fim = q;
            (*d)->tamanho++;
        }
    }      
}

//Inserir em ordem
void InserirEmOrdem(ApontadorDescritor *d, Ligacao ligacao) {

    //Variaveis
    ApontadorCelula q, r, s;
    q = malloc(sizeof(Ligacao));
    r = malloc(sizeof(Ligacao));
    int cont=0;

    //Criar celula que sera armazenada no meio
    if(r != NULL) {
        strcpy(r->nome, ligacao.nome);
        strcpy(r->telefone, ligacao.telefone);
        r->n = ligacao.n;
    }

    //Verificar se alocou
    if(q != NULL) {

        //Caso em que a lista é vazia
        if((*d)->prim == NULL) {
            
            //INICIO
            InserirInicio(d, ligacao);

        }
        //Caso em que o elemento eh maior q o primeiro
        else if(ligacao.n > (*d)->prim->n) {

            //INICIO
            InserirInicio(d, ligacao);

        }
        //Caso em que o elemento eh manor q o ultimo
        else if(ligacao.n < (*d)->fim->n) {
            InserirFinal(d, ligacao);
        }       
        //Caso em que é no meio da lista
        else {

            //Percorrer a lista ate encontrar elementos menores 
            q = (*d)->prim;     
            do {

                //MEIO
                if(q->n < ligacao.n && cont == 0) {
                    
                    //Modificar ponteiros para inserir no meio
                    s->prox = r;
                    r->prox = q;
                    (*d)->tamanho++;
                    cont++;

                }
                s = q;
                q = q->prox;

            } while(q != NULL);
        }
    }
}

//Remover elemento
void RemoverElemento(ApontadorDescritor *d, Ligacao ligacao) {
 
    //Variaveis
    ApontadorCelula q, s;
    q = malloc(sizeof(Ligacao));
    s = malloc(sizeof(Ligacao));
    int cont=0;
 
    //Alocar
    q = (*d)->prim;
 
    //Localizar elemento
    while(q->prox != NULL && strcmp(q->nome, ligacao.nome) != 0) {
        s = q;
        q = q->prox;
        cont++;
    }
 
    //Remover caso seja o primeiro elemento
    if(cont == 0) {
        (*d)->prim = q->prox;
    }
    //Remover no caso em que seja no meio da lista
    else if(strcmp(q->nome, ligacao.nome) == 0) {
        s = q->prox;
    }
    //Remover no caso em que seja no final da lista
    else if(q->prox == NULL && strcmp(q->nome, ligacao.nome) == 0) {
        s->prox = NULL;
    }

}

//Aumentar numero de ligacoes
void AumentarLigacao(ApontadorDescritor *d, Ligacao ligacao) {
 
    //Variaveis
    ApontadorCelula q;
 
    //Alocar
    q = malloc(sizeof(Ligacao)); 
    q = (*d)->prim;
 
    //Localizar elemento por nome
    while(q->prox != NULL && strcmp(q->nome, ligacao.nome) != 0) {
        q = q->prox;
    }
 
    //Aumentar numero de ligacoes
    q->n = q->n + 1;

}

//----------------------------------------------------------
// micalateia.main
//----------------------------------------------------------

//Main
int main() {

    //Variaveis
    ApontadorDescritor d;
    Ligacao ligacao;
    char nome1[20] = "Hermanoteu", telefone1[10] = "4523-2248", nome2[20] = "Ooloneia", telefone2[10] = "4523-4887"; 
    char menu;
 
    //Criar lista com inicialmente 2 elementos
    CriarListaVazia(&d); 
    strcpy(ligacao.nome, nome1);
    strcpy(ligacao.telefone, telefone1);
    ligacao.n = 300;
    InserirEmOrdem(&d, ligacao);
    strcpy(ligacao.nome, nome2);
    strcpy(ligacao.telefone, telefone2);
    ligacao.n = 299;
    InserirEmOrdem(&d, ligacao);

    //Entradas
    do {
 
        //Scanear opcao
        scanf("%c", &menu);
        getchar();
 
        //Opcoes do menu
        //Adicionar ligacao na lista
        if(menu == 'I') {
            scanf("%s", ligacao.nome);
            getchar();
            scanf("%s", ligacao.telefone); 
            scanf("%d", &ligacao.n);
            getchar();
            InserirEmOrdem(&d, ligacao);
        }
        //Remover ligacao na lista
        else if(menu == 'R') {
            scanf("%s", &ligacao.nome);
            getchar();
            RemoverElemento(&d, ligacao);
        }
        //Aumentar numero de ligacoes em 1
        else if(menu == 'L') {
            scanf("%s", ligacao.nome);
            getchar();
            AumentarLigacao(&d, ligacao); 
        }
 
    } while(menu != 'F');

    //Saida
    

    //Retorno
    return 0;
}