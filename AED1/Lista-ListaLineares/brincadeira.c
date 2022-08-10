#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
//-------------------------------------------------------------------------
// Brincadeira.h
//-------------------------------------------------------------------------
 
//Ponteiro global
typedef struct Pessoas *ApontadorCelula;
 
//Struct global
typedef struct Pessoas {
    
    //Variaveis
    char nome[1000];
    char sentido[1000];
    ApontadorCelula prox;
    ApontadorCelula antes;
 
} Pessoas;
 
//Headers
void CriarListaVazia(ApontadorCelula *p);
int InsInicio(ApontadorCelula *p, Pessoas pessoa);
int InsFinal(ApontadorCelula *p, Pessoas pessoa);
int AchouHorario(ApontadorCelula *p, Pessoas pessoa);
int AchouAntiHorario(ApontadorCelula *p, Pessoas pessoa);
void RemoverElemento(ApontadorCelula *p, Pessoas pessoa);
void imprimirLista(ApontadorCelula *p);
 
//-------------------------------------------------------------------------
// Brincadeira.c
//-------------------------------------------------------------------------
 
//Criar Lista Vazia
void CriarListaVazia(ApontadorCelula *p) {
    (*p) = NULL;
}
 
int InsInicio(ApontadorCelula *p, Pessoas pessoa) {
 
    //Variaveis
    ApontadorCelula q;
    int i=0;
 
    //Inserir
    q = malloc(sizeof(Pessoas));
 
    if(q == NULL) {
        return 0;
    } 
    else {
        strcpy(q->nome, pessoa.nome);
        q->antes = NULL;
        q->prox = *p;
        *p = q;
        return 1;
    }
}
 
//Inserir no final
int InsFinal(ApontadorCelula *p, Pessoas pessoa) {
 
    //Variaveis
    ApontadorCelula q, r;
    int i=0;
 
    //Inserir
    if(*p == NULL) {
        return(InsInicio(p, pessoa));
    } else {
 
        //Criar celula a ser inserida no final
        q = malloc(sizeof(Pessoas));
        r = malloc(sizeof(Pessoas));
 
        if(q == NULL) {
            return 0;
        } 
        else {
 
            strcpy(q->nome, pessoa.nome);
            q->prox = NULL;
 
            //Looping pra inserir no final
            r = (*p);
            while(r->prox != NULL) {
                r = r->prox;
            }
            r->prox = q;
            q->antes = r;
            return 1;
        }
    }
}
 
//Verificar se o elemento esta na lista no sentido horario
int AchouHorario(ApontadorCelula *p, Pessoas pessoa) {
 
    //Variaveis
    ApontadorCelula q;
    int cont=0;
 
    q = malloc(sizeof(Pessoas));
    q = (*p);
 
    //Verificar
    while(strcmp(q->nome, pessoa.nome) != 0 && (q->prox!=NULL)) {
        q = q->prox;
        cont++;
    }
 
    //Achou de acordo com as regras
    if(cont<2) {
 
        RemoverElemento(p, pessoa);
        return 1;
    } else {
        return 0;
    }
}
 
//Verificar se o elemento esta na lista no sentido anti-horario
int AchouAntiHorario(ApontadorCelula *p, Pessoas pessoa) {
 
    //Variaveis
    ApontadorCelula q;
    int cont=0;
 
    q = malloc(sizeof(Pessoas));
    q = (*p);
 
    //Comecar do final
    while(q->prox != NULL) {
        q = q->prox;
    }
 
    //Verificar
    while(strcmp(q->nome, pessoa.nome) != 0 && (q->antes != NULL)) {
        q = q->antes;
        cont++;
    }
 
    //Achou de acordo com as regras
    if(cont<=2) {
 
        RemoverElemento(p, pessoa);
        return 1;
 
    } else {
        return 0;
    }
}
 
//Remover elemento da lista apos encontrar
void RemoverElemento(ApontadorCelula *p, Pessoas pessoa) {
 
    //Variaveis
    int i=0;
    ApontadorCelula q, s;
 
    //Localizar elemento
    q = malloc(sizeof(Pessoas));
    q = (*p);
    while((q->prox != NULL) && (strcmp(q->nome, pessoa.nome) != 0)) {
        s = q;
        q = q->prox;
        i++;
    }
    
    //Remover elemento
    if(i == 0) {
        q = q->prox;
        q->antes = NULL;
        *p = q;
    } else if(strcmp(q->nome, pessoa.nome) == 0 && q->prox != NULL) { 
        s->prox = q->prox;
        q->prox->antes = s->prox;
    } else if(q->prox == NULL && strcmp(q->nome, pessoa.nome) == 0){
        s->prox = NULL;
    }
}
 
//Imprimir lista
void imprimirLista(ApontadorCelula *p) {
 
    //Variaveis
    ApontadorCelula q;
    q = (*p);
 
    while(q->prox != NULL) {
        printf("%s\n", q->nome);
        q = q->prox;
    }
    printf("%s\n", q->nome);
}
 
 
//-------------------------------------------------------------------------
// Brincadeira.main
//-------------------------------------------------------------------------
int main() {
 
    //Variaveis
    ApontadorCelula p;
    int i, aux, cont=0, acertos=0;
    Pessoas pessoa;
 
 
    //Participantes do jogo
    CriarListaVazia(&p);
    while(strcmp(pessoa.nome, "FIM") != 0) {
 
        scanf("%s", pessoa.nome); 
 
        if(strcmp(pessoa.nome, "FIM") != 0) {
            aux = InsFinal(&p, pessoa);
        }
        cont++;
    }
    cont--;
 
    //Nomes escolhidos
    for(i=0; i<cont; i++) {
 
        //Scanear nomes
        scanf("%s%s", pessoa.nome, pessoa.sentido); getchar();
 
        if(strcmp(pessoa.sentido, "horario") == 0) {
 
            //Verificar se esta na lista
            aux = AchouHorario(&p, pessoa);
            if(aux == 1) {
                acertos++;
            }
        } 
        else if(strcmp(pessoa.sentido, "anti-horario") == 0) {
            
            //Verificar se esta na lista
            aux = AchouAntiHorario(&p, pessoa);
            if(aux == 1) {
                acertos++;
            } 
        } 
    }
 
    //Saida
    printf("%d\n", acertos);    
 
    //Retorno
    return 0;
}