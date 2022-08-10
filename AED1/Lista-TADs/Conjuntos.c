#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

//==============================================================================
// Arquivo conjunto.h
//==============================================================================

//Conjunto.h
typedef struct c Conjunto;

//Cabeçalhos das funções
void trocaElemento(int *x, int *y);
void bubbleSort(int vetor[], int tamanho);
void bubbleSortInverso(int vetor[], int tamanho);
int combinacao(int tamanho, int x);
Conjunto* criaConjunto(Conjunto *c);
int conjuntoVazio(Conjunto *c);
int insereElmentoConjunto(int x, Conjunto *c);
int excluirElementoConjunto(int x, Conjunto *c);
int tamanhoConjunto(Conjunto *c);
int maior(int x, Conjunto *c);
int menor(int x, Conjunto *c);
bool pertenceConjunto(int x, Conjunto *c);
bool conjuntosIdenticos(Conjunto *c, Conjunto *d);
int subconjunto(Conjunto *c, Conjunto *d);
Conjunto* complemento(Conjunto *c, Conjunto *d);
Conjunto* uniao(Conjunto *c, Conjunto *d);
Conjunto* interseccao(Conjunto *c, Conjunto *d);
Conjunto* diferenca(Conjunto *c, Conjunto *d);
Conjunto* conjuntoPartes(Conjunto *c);
void mostraConjunto(Conjunto *c, int x);
bool copiarConjunto(Conjunto *c, Conjunto *d);
bool destruirConjunto(Conjunto *c);

//==============================================================================
// Arquivo conjunto.c
//==============================================================================

//Variavel tipo conjunto
struct c {
    int valores[100000];
    int tamanho;
    int partes[10000][10000];
};

//Troca 
void troca(int *x, int *y) {
    //Variaveis
    int aux;
    
    //Troca 
    aux=*x;
    *x=*y;
    *y=aux;
}

//BubbleSort Crescente
void bubbleSort(int vetor[], int tamanho) {
    
    //Variaveis
    int i, j;
    
    //Para cada passada i, borbulhar o maior elemento daquela passada para a posicao i + 1
    for(i=tamanho-1; i>0; i--) {
        for(j=0; j<i; j++) {
            if(vetor[j] > vetor[j+1]) {
                //trocar v[j] com v[j+1]
                troca(&vetor[j], &vetor[j+1]);
            }
        }
    }
}

//BubbleSort Decrescente
void bubbleSortInverso(int vetor[], int tamanho) {
    
    //Variaveis
    int i, j;
    
    //Para cada passada i, borbulhar o maior elemento daquela passada para a posicao i + 1
    for(i=tamanho-1; i>0; i--) {
        for(j=0; j<i; j++) {
            if(vetor[j] < vetor[j+1]) {
                //trocar v[j] com v[j+1]
                troca(&vetor[j], &vetor[j+1]);
            }
        }
    }
}

//Combinacao (calcular subconjuntos)
int combinacao(int tamanho, int x) {
    
    //Variaveis
    int combinacao=1, fatTamanho=1, fatX=1, fatTamanhoMenosX=1, i=0;

    //Calcular tamanho fatorial, x fatorial e o resto fatorial
    if(x != 0) {
        for(i=1; i<=tamanho; i++) {
            fatTamanho = fatTamanho*i;
        }
        for(i=1; i<=x; i++) {
            fatX = fatX*i;
        }
        for(i=1; i<=tamanho-x; i++) {
            fatTamanhoMenosX = fatTamanhoMenosX*i;
        }
    } else {
        fatTamanho = 1;
        fatX = 1;
        fatTamanhoMenosX = 1;
    }

    //Resultado
    combinacao = (fatTamanho)/(fatX*fatTamanhoMenosX);
    return(combinacao);

}

//Criar um conjunto
Conjunto* criaConjunto(Conjunto *c) {

    //Variaveis
    int tam1=0, i=0, tam2=0;
    int c1[100000], aux[100000];

    //Scanear conjunto 
    scanf("%d",&tam1);
    if(tam1 > 0) {
    printf("----------------------------------------------------\n");
        
        //Elemento 0 recebe o tamanho do conjunto
        printf("Digite os valores do conjunto: ");
        for(i=0; i<tam1; i++) {
            scanf("%d",&aux[i]);
        }
        printf("----------------------------------------------------\n");
        
        //Ordenar conjunto
        bubbleSort(aux, tam1);
        
        //Retirar elementos repetidos
        for(i=0; i<tam1; i++) {
            while(aux[i] == aux[i+1]) {
                i++;
            }
            
            c1[tam2] = aux[i];
            tam2++;
        }
        
        //Alocar espaço para criação do conjunto
        c = (Conjunto*) malloc(4*sizeof(c1));
        if (c != NULL) {
            
            //Armazenar tamanho
            c->tamanho = tam2;
            
            //Criar conjunto 
            for(i=0; i<tam2; i++) {
                c->valores[i] = c1[i];
            }
            return(c);
        }
        else {
            printf("Falha ao criar conjunto, verifique se este e vazio ou grande demais\n");
            return NULL;
        }
    } else  {
        printf("Este conjunto e vazio.\n");
        printf("----------------------------------------------------\n");
        
        c = NULL;
        return NULL;
    }
}

//Verificar se o conjunto C é vazio
int conjuntoVazio (Conjunto *p) {
    
    if(p != NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

//Incluir o elemento x no conjunto C
int insereElmentoConjunto(int x, Conjunto *c) {
    
    //Verificaremento já está no conjunto se o el 
    int estaPresente=0, j=0;
    
    for(j=0; j<c->tamanho; j++) {
        if(x == c->valores[j]) {
            estaPresente++;
        }
    }
    
    //Retorno
    if(estaPresente == 0) {
        
        //Acrescentar elemento
        c->valores[c->tamanho] = x;
        return 1;
    }
    else {
        return 0;
    }
}

//Excluir o elemento x no conjunto C 
int excluirElementoConjunto(int x, Conjunto *c) {
    
    //Variaveis
    int estaPresente=0, j=0, i=0;
    
    //Verificar se o elemento já está no conjunto 
    for(j=0; j<c->tamanho; j++) {
        if(x == c->valores[j]) {
            estaPresente++;
        }
    }
    
    //Retorno
    if(estaPresente != 0) {
        
        //Retirar elemento
        for(j=0; j<c->tamanho; j++) {
            if(c->valores[j] != x) {
                c->valores[i] = c->valores[j];
                i++;
            }
        }
        
        return 1;
    }
    else {
        return 0;
    }    
}

//Calcular tamanho do conjunto 
int tamanhoConjunto(Conjunto *c) {
    
    if(c == NULL) {
        return 0;
    } else {
        return 1;
    }
}

//Calcular quantos elementos são maiores que X 
int maior(int x, Conjunto *c) {
   
    int i=0, maiores=0;
    for(i=0; i<c->tamanho; i++) {
        if(c->valores[i] > x) {
            maiores++;
        }
    }
    
    if(maiores == c->tamanho-1) {
        printf("Todos os elementos deste conjunto sao maiores que %d.\n", x);
    }
    
    return(maiores);
}

//Calcular quantos elementos são menores que X 
int menor(int x, Conjunto *c) {
   
    int i=0, menores=0;
    for(i=0; i<c->tamanho; i++) {
        if(c->valores[i] < x) {
            menores++;
        }
    }
    
    if(menores == c->tamanho-1) {
        printf("Todos os elementos deste conjunto sao menores que %d.\n", x);
    }    
    return(menores);
}

//Verificar se X pertence ao conjunto C
bool pertenceConjunto(int x, Conjunto *c) {
    int i, pertence=0;
    for(i=0; i<c->tamanho; i++) {
        if(c->valores[i] == x) {
            pertence++;
        }
    }

    if(pertence > 0) {
        return 1;
    } else {
        return 0;
    }
}

//Verificar se C1 e igual a C2
bool conjuntosIdenticos(Conjunto *c, Conjunto *d) {
    int i, cont=0;

    for(i=0; i<d->tamanho; i++) {
        if(c->valores[i] != d->valores[i]) {
            cont++;
        }
    }

    if(cont != 0 || c->valores != d->valores) {
        return 0;
    } else {
        return 1;
    }
}

//Verificar se C1 e subconjunto de C2
int subconjunto(Conjunto *c, Conjunto *d) {

    int i, cont=0, sub=0, j;

    //Verificar se sao subconjuntos
    for(i=0; i<c->tamanho; i++) {
        for(j=0; j<-d->tamanho; j++) {
            if(c->valores[i] == d->valores[j]) {
                cont++;        
            }
        }

        if(cont > 0) {
            sub++;
        }
        cont = 0;
    }

    //Retorno
    if(sub == c->tamanho) {
        return 1;
    } else {
        return 0;
    }
}

//Gerar complemento do C1 em relacao a C2
Conjunto* complemento(Conjunto *c, Conjunto *d) {

    //Variaveis
    int i, j=0, k, cont=0;
    int aux[100000];
    Conjunto *e;

    //Verificar se sao subconjuntos
    for(k=0; k<d->tamanho; k++) {
        for(i=0; i<c->tamanho; i++) {
            if(d->valores[k] == c->valores[i]) {
                cont++;
            }
        }

        if(cont == 0) {
            aux[j] = d->valores[k];
            j++;
        }
        cont = 0;
    }
    e = (Conjunto*) malloc(4*sizeof(aux));

    //Retorno
    if(e != NULL) {
        e->tamanho = j;
        for(i=0; i<j; i++) {
            e->valores[i] = aux[i];
        }
        return(e);

    } else {
        return NULL;
    }
}

//Gera uniao dos conjuntos
Conjunto* uniao(Conjunto *c, Conjunto *d) {

    //Variaveis
    int i=0, j=0, tam2=0;
    int e[100000]; 
    Conjunto *f;

    //Gerar uniao dos conjuntos
    for(i=0; i<c->tamanho; i++) {
        e[j] = c->valores[i];
        j++;
    }
    for(i=0; i<d->tamanho; i++) {
        e[j] = d->valores[i];
        j++;
    }
    
    //Ordenar conjunto
    bubbleSort(e, j);
        
    //Alocar espaço para criação do conjunto
    f = (Conjunto*) malloc(4*sizeof(e));

    //Saida
    if(f != NULL) {
        //Retirar elementos repetidos
        for(i=0; i<j; i++) {
            while(e[i] == e[i+1]) {
                i++;
            }
            
            f->valores[tam2] = e[i];
            tam2++;
        }
        f->tamanho = tam2;

        return(f);
    } else {
        return NULL;
    }
}

//Gera intersecao dos conjuntos
Conjunto* interseccao(Conjunto *c, Conjunto *d) {

    //Variaveis
    int i=0, j=0, k=0, cont=0;
    int e[100000]; 
    Conjunto *f;

    //Intercessao
    for(i=0; i<c->tamanho; i++) {
        for(j=0; j<d->tamanho; j++) {
            if(c->valores[i] == d->valores[j]) {
                cont++;
            }
        }

        if(cont!=0) {
            e[k] = c->valores[i];
            k++;
        }
        cont=0;
    }
        
    //Alocar espaço para criação do conjunto
    f = (Conjunto*) malloc(4*sizeof(e));

    //Saida
    if(f != NULL) {
        
        f->tamanho = k;
        for(i=0; i<f->tamanho; i++) {
            f->valores[i] = e[i];
        }
        return(f);
    } else {
        return NULL;
    }
}

//Gera diferença entre C1 e C2
Conjunto* diferenca(Conjunto *c, Conjunto *d) {

    //Variaveis
    int i, j=0, k, cont=0;
    int aux[100000];
    Conjunto *e;

    //Verificar elementos q pertencem ao C1 e nao ao C2
    for(i=0; i<c->tamanho; i++) {
        for(k=0; k<d->tamanho; k++) {
            if(c->valores[i] == d->valores[k]) {
                cont++;
            }
        }

        if(cont == 0) {
            aux[j] = c->valores[i];
            j++;
        }
        cont = 0;
    }
    e = (Conjunto*) malloc(4*sizeof(aux));

    //Retorno
    if(e != NULL) {
        e->tamanho = j;
        for(i=0; i<j; i++) {
            e->valores[i] = aux[i];
        }
        return(e);

    } else {
        return NULL;
    }  
}

//Gera conjunto das partes
Conjunto* conjuntoPartes(Conjunto *c) {

    //Variaveis
    int qtdeDeSubconj=0, i, l, col, element=0, j, k, repetiu=0, aumenta=0, iAux=0;;

    //Calcular subconjuntos com n elementos por vez
    for(i=0; i<=c->tamanho; i++) {
        
        //Quantidade de subconjuntos com n elementos que havera na matriz
        qtdeDeSubconj = combinacao(c->tamanho, i);

        //Gerar os elementos que compoem a quantidade de subconjuntos com n elementos na matriz (REESCREVE A MATRIZ CADA VEZ QUE AUMENTA O NUMERO DELE ELEMENTOS DO SUBCONJUNTO)
        for(l=0; l<qtdeDeSubconj; l++) {

            //Primeiro subconjunto com n elementos (SERVIRA COMO BASE)
            if(l==0) {
                element = 0;
                for(col=0; col<i; col++) {
                    c->partes[l][col] = c->valores[element];
                    element++;  
                }
            } 
            //Segundo subconjunto em diante
            else {
                
                //Armazena o proximo valor depois do elemento do subconjunto anterior (na mesma posicao)
                for(col=0; col<i; col++) {
                    for(j=0; j<c->tamanho; j++) {
                        if(c->valores[j] > c->partes[l-1][col]) {
                            c->partes[l][col] = c->valores[j];
                            j = c->tamanho;
                        } else if(c->valores[j]==c->partes[l-1][col] && j==c->tamanho-1) {
                            c->partes[l][col] = c->valores[0];
                            j = c->tamanho;
                        }
                    }
                }

                //Verificar se o ciclo de adicionar o proximo elemento se repetiu, e modifica-lo para que conclua todas as combinacoes
                for(col=0; col<i; col++) {
                    if(c->partes[l][col] == c->partes[0][col]) {
                        repetiu++;
                    }
                    if(repetiu == i) {
                        c->partes[l][col] = c->valores[i+aumenta];
                        aumenta++;
                    } 
                }
                repetiu = 0;
            }

            //Saida do subconjunto de i elementos
            for(col=0; col<i; col++) {
                if(col!=i-1) {
                    printf("%d, ", c->partes[l][col]);
                } else if(col == i-1) {
                    printf("%d", c->partes[l][col]);
                }
            }
            
            //Mudar de subconjunto com n elementos
            if(i!=c->tamanho) {
                printf("};\n{");
            }
        }
        aumenta = 0;
    }
    //Fechar subconjunto
    printf("}}.\n");

    //Retorno
    return(c);
}

//Mostra conjunto
void mostraConjunto(Conjunto *c, int x) {
    
    if(x == 1) {
        bubbleSort(c->valores, c->tamanho);
    } else if (x == 2) {
        bubbleSortInverso(c->valores, c->tamanho);
    }
}

//Copiar C1 para C2
bool copiarConjunto(Conjunto *c, Conjunto *d) {
    
    //Variaveis
    int i=0;

    //Verificar se alocou ou nao
    if(d->tamanho == 0) {
        d = (Conjunto*) malloc(4*sizeof(c));
        d->tamanho = c->tamanho;
    }

    if(d != NULL) {

        //Copiar os elementos de C1 para C2
        for(i=0; i<c->tamanho; i++) {
            d->valores[i] = c->valores[i];
        } 
        d->tamanho = c->tamanho;

        return 1;

    } else {
        return 0;
    }
}

//Destruir conjunto
bool destruirConjunto(Conjunto *c) {

    //Excluir conjunto c
    free(c);
    c = NULL;

    if(c == NULL) {
        return (1);
    } else {
        return (0);
    }
}

//==============================================================================
// Corpo Principal
//==============================================================================

//Main
int main() {
    
    //Variaveis
    int i, menu=0, qualConj, qtdeAddElemento, addElemento, elementoPresente, excElemento, cardinal, x,
    qtdeElemMaiores, qtdeElemMenores, subconj;
       
    bool pertence, conjsIguais, copiou, destruiu;

    char sn;

    Conjunto *conj1=NULL, *conj2=NULL, *conj3=NULL;

    //Introducao
    printf("Bem vindo ao Calculo de Conjuntos. Pressione 1 se deseja iniciar ou 0 se deseja sair: ");
    scanf("%d", &menu);
    printf("----------------------------------------------------------------------------------------\n");  
    if(menu == 1) {
     
        //Criar conjunto 1 
        printf("Digite o tamanho do conjunto 1: ");
        conj1 = criaConjunto(conj1);
        
        //Scanear conjunto 2
        printf("Digite o tamanho do conjunto 2: ");
        conj2 = criaConjunto(conj2);
        
        
        //MENU
        do {
            
            //Organizar conjuntos antes do looping
            bubbleSort(conj1->valores, conj1->tamanho);
            bubbleSort(conj2->valores, conj2->tamanho);

            //Opções
            menu = 1;
            printf("O que voce deseja fazer?\n");
            printf(" (0) - Encerrar o programa.\n");
            printf(" (1) - Adicionar elementos ao conjunto.\n");
            printf(" (2) - Exluir elementos do conjunto.\n");
            printf(" (3) - Calcular a cardinalidade do conjunto.\n");
            printf(" (4) - Calcular quantos elementos sao maiores que X.\n");
            printf(" (5) - Calcular quantos elementos sao menores que X.\n");
            printf(" (6) - Verificar se X pertence ao conjunto.\n");
            printf(" (7) - Verificar se os 2 conjuntos sao identicos.\n");
            printf(" (8) - Verificar se o conjunto 1 e subconjunto do conjunto 2.\n");
            printf(" (9) - Gerar o complemento do conjunto 1 em relacao ao conjunto 2.\n");
            printf("(10) - Gerar a uniao entre os conjuntos.\n");
            printf("(11) - Gerar a interseccao entre os conjuntos.\n");
            printf("(12) - Gerar a diferenca entre o conjunto 1 e o conjunto 2.\n");
            printf("(13) - Gerar os conjuntos das partes.\n");
            printf("(14) - Mostrar conjunto em ordem crescente ou descrescente.\n");
            printf("(15) - Copiar o conjunto 1 para o conjunto 2.\n");
            printf("(16) - Destruir conjunto.\n");
            printf("-----------------------------------------------------------------\n");
            //....
            
            //Opção do usuário
            scanf("%d", &menu);
            
            //Adicionar elementos 
            if(menu == 1) {
                
                printf("Digite qual conjunto voce deseja adicionar elementos.\n");
                printf("- Digite 1 para adicionar ao primeiro.\n- Digite 2 para adicionar ao segundo.\n");
                scanf("%d", &qualConj);
                printf("Digite a quantidade de elementos a serem adicionados.\n");
                scanf("%d", &qtdeAddElemento);
                printf("Digite os elementos a serem adicionados: \n");
                
                if(qualConj == 1) {
                    for(i=0; i<qtdeAddElemento; i++) {
                        scanf("%d", &addElemento);
                        if(conj1 == NULL) {
                            conj1 = (Conjunto*) malloc(4*sizeof(conj1->valores));
                            conj1->tamanho = 1;
                            conj1->valores[0] = addElemento;
                        } else {   
                            elementoPresente = insereElmentoConjunto(addElemento, conj1);
                            if(elementoPresente == 1) {
                                conj1->tamanho++;
                            }
                            else {
                                printf("Este elemento ja pertence ao conjunto 1\n");
                            }
                        }
                    }
                    
                    bubbleSort(conj1->valores, conj1->tamanho);
                    printf("Novo conjunto 1 = {");
                    for(i=0; i<conj1->tamanho; i++) {
                        if(i!=conj1->tamanho-1) {
                            printf("%d,", conj1->valores[i]);
                        } else {
                            printf("%d}\n", conj1->valores[i]);
                        }
                    }
                }    
                else if(qualConj == 2) {
                    
                    for(i=0; i<qtdeAddElemento; i++) {
                        scanf("%d", &addElemento);
                        if(conj2 == NULL) {
                            conj2 = (Conjunto*) malloc(4*sizeof(conj2->valores));
                            conj2->tamanho = 1;
                            conj2->valores[0] = addElemento;
                        } else {   
                            elementoPresente = insereElmentoConjunto(addElemento, conj2);
                            if(elementoPresente == 1) {
                                conj2->tamanho++;
                            }
                            else {
                                printf("Este elemento ja pertence ao conjunto 2\n");
                            }
                        }   
                    }
                    
                    bubbleSort(conj2->valores, conj2->tamanho);
                    printf("Novo conjunto 2 = {");
                    for(i=0; i<conj2->tamanho; i++) {
                        if(i!=conj2->tamanho-1) {
                            printf("%d,", conj2->valores[i]);
                        } else {
                            printf("%d}\n", conj2->valores[i]);
                        }
                    }
                }
                
            }
            
            //Excluir elementos
            if(menu == 2) {
                printf("Digite qual conjunto voce deseja excluir elementos.\n");
                printf("- Digite 1 para excluir do primeiro.\n- Digite 2 para excluir do segundo.\n");
                scanf("%d", &qualConj);
                if(qualConj == 1 && conj1 != NULL) {
                    printf("Digite a quantidade de elementos a serem excluidos.\n");
                    scanf("%d", &qtdeAddElemento);
                    printf("Digite o elemento a ser excluido: \n");
                    printf("Pressione a tecla ENTER para cada valor excluido:\n");
                    for(i=0; i<qtdeAddElemento; i++) {
                        scanf("%d", &excElemento);
                        elementoPresente = excluirElementoConjunto(excElemento, conj1);
                        if(elementoPresente == 1) {
                            conj1->tamanho--;
                        }
                        else {
                            printf("Este elemento nao pertence ao conjunto 1\n");
                        }
                    }
                    
                    //Saida
                    printf("Novo conjunto 1 = {");
                    for(i=0; i<conj1->tamanho; i++) {
                        if(i!=conj1->tamanho-1) {
                            printf("%d,", conj1->valores[i]);
                        } else {
                            printf("%d}\n", conj1->valores[i]);
                        }
                    }  
                }    
                else if(qualConj==2 && conj2 != NULL) {
                    printf("Digite a quantidade de elementos a serem excluidos.\n");
                    scanf("%d", &qtdeAddElemento);
                    printf("Digite o elemento a ser excluido: \n");
                    printf("Pressione a tecla ENTER para cada valor excluido:\n");
                    for(i=0; i<qtdeAddElemento; i++) {
                        scanf("%d", &excElemento);
                        elementoPresente = excluirElementoConjunto(excElemento, conj2);
                        if(elementoPresente == 1) {
                            conj2->tamanho--;
                        }
                        else {
                            printf("Este elemento não pertence ao conjunto 2\n");
                        }
                    }
                    
                    printf("Novo conjunto 2 = {");
                    for(i=0; i<conj2->tamanho; i++) {
                        if(i!=conj2->tamanho-1) {
                            printf("%d,", conj2->valores[i]);
                        } else {
                            printf("%d}\n", conj2->valores[i]);
                        }
                    }
                } 
                else if(qualConj==1 && conj1==NULL) {
                    printf("Este conjunto e vazio.\n");
                }
                else if(qualConj==2 && conj2==NULL) {
                    printf("Este conjunto e vazio.\n");
                }
            }
            
            //Cardinalidade do conjunto
            if(menu == 3) {
                printf("Digite qual conjunto você deseja calcular a cardinalidade.\n");
                printf("- Digite 1 para calcular a do primeiro.\n- Digite 2 para calcular a do segundo.\n");
                scanf("%d", &qualConj);  
                
                if(qualConj == 1) {
                    cardinal = tamanhoConjunto(conj1);
                    
                    if(cardinal == 1) {
                        printf("Tamanho do conjunto 1: %d.\n", conj1->tamanho);
                    } else {
                        printf("Tamanho do conjunto 1: 0.\n");
                    }
                }
                else {
                    cardinal = tamanhoConjunto(conj2);
                    
                    if(cardinal == 1) {
                        printf("Tamanho do conjunto 2: %d.\n", conj2->tamanho);
                    } else {
                        printf("Tamanho do conjunto 2: 0.\n");
                    }                    
                }
            }
            
            //Maiores que X
            if(menu == 4) {
                
                printf("Voce deseja analisar os elementos maiores que X de qual conjunto?\n");
                printf("- Digite 1 para o primeiro.\n- Digite 2 para o segundo.\n");
                scanf("%d", &qualConj);
                if(qualConj == 1 && conj1 != NULL) {
                    printf("Digite o valor de X: ");
                    scanf("%d", &x);
                    qtdeElemMaiores = maior(x, conj1);
                    if(qtdeElemMaiores == 0) {
                        printf("Nao ha elementos maiores que %d\n", x);
                    } else if(qtdeElemMaiores == conj1->tamanho) {
                        printf("Todos os elementos sao maiores que %d.\n", x);
                    } else if(qtdeElemMaiores > 1) {
                        printf("Ha %d elementos maiores que %d.\n", qtdeElemMaiores, x);
                    }
                } else if(qualConj == 2 && conj2 != NULL) {
                    printf("Digite o valor de X: ");
                    scanf("%d", &x);
                    qtdeElemMaiores = maior(x, conj2);
                    if(qtdeElemMaiores == 0) {
                        printf("Não ha elementos maiores que %d\n", x);
                    } else if(qtdeElemMaiores == conj2->tamanho) {
                        printf("Todos os elementos sao maiores que %d.\n", x);
                    } else if(qtdeElemMaiores > 1) {
                        printf("Ha %d elementos maiores que %d.\n", qtdeElemMaiores, x);
                    }
                } else if(qualConj == 1 && conj1 == NULL) {
                    printf("Não ha elementos para comparacao pois o conjunto 1 e vazio.\n");
                } else if(qualConj == 2 && conj2 == NULL) {
                    printf("Não ha elementos para comparacao pois o conjunto 2 e vazio.\n");
                }
            }
            
            //Menores que X 
            if(menu == 5) {
                
                printf("Voce deseja analisar os elementos menores que X de qual conjunto?\n");
                printf("- Digite 1 para o primeiro.\n- Digite 2 para o segundo.\n");
                scanf("%d", &qualConj);
                if(qualConj == 1 && conj1 != NULL) {
                    printf("Digite o valor de X: ");
                    scanf("%d", &x);
                    qtdeElemMenores = menor(x, conj1);
                    if(qtdeElemMenores == 0) {
                        printf("Nao ha elementos menores que %d\n", x);
                    } else if(qtdeElemMenores == conj1->tamanho) {
                        printf("Todos os elementos sao maiores que %d.\n", x);
                    } else if(qtdeElemMenores > 1) {
                        printf("Ha %d elementos menores que %d.\n", qtdeElemMenores, x);
                    } 
                } else if(qualConj == 2 && conj2 != NULL) {
                    printf("Digite o valor de X: ");
                    scanf("%d", &x);
                    qtdeElemMenores = menor(x, conj2);
                    if(qtdeElemMenores == 0) {
                        printf("Nao ha elementos menores que %d\n", x);
                    } else if(qtdeElemMenores == conj2->tamanho) {
                        printf("Todos os elementos sao menores que %d.\n", x);
                    } else if(qtdeElemMenores > 1) {
                        printf("Ha %d elementos menores que %d.\n", qtdeElemMenores, x);
                    } 
                } else if(qualConj == 1 && conj1 == NULL) {
                    printf("Nao ha elementos para comparacao pois o conjunto 1 e vazio.\n");
                } else if(qualConj == 2 && conj2 == NULL) {
                    printf("Nao ha elementos para comparacao pois o conjunto 2 e vazio.\n");
                }
            }
            
            //Se X esta no conjunto
            if(menu == 6) {
                printf("Digite qual conjunto você deseja verificar se contem X.\n");
                printf("- Digite 1 para analisar o primeiro.\n- Digite 2 para analisar o segundo.\n");
                scanf("%d", &qualConj); 
                printf("Digite o elemento a ser verificado: ");
                scanf("%d", &x); 
                
                if(qualConj == 1) {
                    pertence = pertenceConjunto(x, conj1);
                    
                    if(pertence == 1) {
                        printf("O elemento %d pertence ao conjunto %d.\n", x, qualConj);
                    } else {
                        printf("O elemento %d nao pertence ao conjunto %d.\n", x, qualConj);
                    }
                }
                else {
                    pertence = pertenceConjunto(x, conj2);
                    
                    if(pertence == 1) {
                        printf("O elemento %d pertence ao conjunto %d.\n", x, qualConj);
                    } else {
                        printf("O elemento %d nao pertence ao conjunto %d.\n", x, qualConj);
                    }                  
                }
            }

            //Se C1 e igual a C2
            if(menu == 7) {
                conjsIguais = conjuntosIdenticos(conj1, conj2);

                if(conjsIguais == 1) {
                    printf("Os conjuntos 1 e 2 sao iguais!\n");
                } else {
                    printf("Os conjuntos 1 e 2 nao sao iguais!\n");
                }
            }
            
            //Se C1 e subconjunto de C2
            if(menu == 8) {
                subconj = subconjunto(conj1, conj2);

                if(subconj == 0) {
                    printf("O conjunto 1 nao e subconjunto do conjunto 2.\n");
                } else if(subconj == 1) {
                    printf("O conjunto 1 e subconjunto do conjunto 2.\n");
                }
            }
            
            //Complemento de C1 em relacao a C2
            if(menu == 9) {

                if(conj1!=NULL && conj2!=NULL) {
                    conj3 = complemento(conj1, conj2);
                    if(conj3 != NULL && conj3->tamanho!=0) {
                        //Saida
                        printf("Complemento de C1 em relacao a C2 = {");
                        for(i=0; i<conj3->tamanho; i++) {
                            if(i!=conj3->tamanho-1) {
                                printf("%d,", conj3->valores[i]);
                            } else {
                                printf("%d}\n", conj3->valores[i]);
                            }
                        } 
                    } else if(conj3 == NULL) {
                        printf("Complemento de C1 em relacao a C2 e vazio: {}.\n");
                    }
                } else if(conj1==NULL && conj2!=NULL) {
                    //Saida
                    printf("Complemento de C1 em relacao a C2 = {");
                    for(i=0; i<conj2->tamanho; i++) {
                        if(i!=conj2->tamanho-1) {
                            printf("%d,", conj2->valores[i]);
                        } else {
                            printf("%d}\n", conj2->valores[i]);
                        }
                    } 
                } else if(conj1!=NULL && conj2==NULL) {
                    printf("Complemento de C1 em relacao a C2 e vazio: {}.\n");
                } else if(conj1==NULL && conj2==NULL) {
                    printf("Complemento de C1 em relacao a C2 e vazio: {}.\n");
                }
            }
                        
            //Uniao entre C1 e C2
            if(menu == 10) {

                conj3 = uniao(conj1, conj2);

                if(conj3 != NULL) {

                    //Saida
                    if(conj3->tamanho != 0) {
                        printf("Uniao de C1 e C2 = {");
                        for(i=0; i<conj3->tamanho; i++) {
                            if(i!=conj3->tamanho-1) {
                                printf("%d,", conj3->valores[i]);
                            } else {
                                printf("%d}\n", conj3->valores[i]);
                            }
                        }
                    } else {
                        printf("Uniao de C1 e C2 = { } (vazio).\n");
                    }
                } else if(conj3 == NULL) {
                    printf("Uniao de C1 e C2 = { } (vazio).\n");
                }
            }
                        
            //Interseccao entre C1 e C2
            if(menu == 11) {
                
                if(conj1!=NULL && conj2!=NULL) {
                    conj3 = interseccao(conj1, conj2);
                    if(conj3 != NULL && conj3->tamanho!=0) {
    
                        //Saida
                        if(conj3->tamanho != 0) {
                            printf("Interseccao de C1 e C2 = {");
                            for(i=0; i<conj3->tamanho; i++) {
                                if(i!=conj3->tamanho-1) {
                                    printf("%d,", conj3->valores[i]);
                                } else {
                                    printf("%d}\n", conj3->valores[i]);
                                }
                            }
                        } else {
                            printf("Interseccao de C1 e C2 = { } (vazio).\n");
                        }
                    } else if(conj3 == NULL) {
                        printf("Interseccao de C1 e C2 = { } (vazio).\n");
                    }
                } else if((conj1!=NULL && conj2==NULL) || (conj1==NULL && conj2!=NULL)) {
                    printf("Interseccao de C1 e C2 = { } (vazio).\n");
                } else if (conj1==NULL && conj2==NULL) {
                    printf("Interseccao de C1 e C2 = { } (vazio).\n");      
                }
            }

            //Diferenca entre C1 e C2
            if(menu == 12) {

                if(conj1!=NULL && conj2!=NULL) {
                    conj3 = diferenca(conj1, conj2);
                    if(conj3!=NULL && conj3->tamanho!=0) {

                        //Saida
                        printf("Diferenca entre C1 e C2 = {");
                        for(i=0; i<conj3->tamanho; i++) {
                            if(i!=conj3->tamanho-1) {
                                printf("%d,", conj3->valores[i]);
                            } else {
                                printf("%d}\n", conj3->valores[i]);
                            }
                        } 
                    } else if(conj3 == NULL) {
                        printf("Diferenca entre C1 e C2 e vazio: { }. Os conjuntos sao iguais!\n");
                    }
                } else if(conj1!=NULL && conj2==NULL) {

                    //Saida
                    printf("Diferenca entre C1 e C2 = {");
                    for(i=0; i<conj1->tamanho; i++) {
                        if(i!=conj1->tamanho-1) {
                            printf("%d,", conj1->valores[i]);
                        } else {
                            printf("%d}\n", conj1->valores[i]);
                        }
                    } 
                } else if(conj1!=NULL && conj2==NULL) {
                    printf("Diferenca entre C1 e C2 e vazio: { }.\n");
                } else if(conj1==NULL && conj2==NULL) {
                    printf("Ambos os conjuntos sao nulos, nao ha diferenca.\n");
                }
            }

            //Conjunto das partes
            if(menu == 13) {
                printf("Digite de qual conjunto voce deseja gerar o conjunto das partes.\n");
                printf("- Digite 1 para gerar do primeiro.\n- Digite 2 para gerar do segundo.\n");
                scanf("%d", &qualConj);

                if(qualConj == 1) {

                    //Chamar a funcao para gerar conjunto das partes
                    printf("Quantidade de subconjuntos do conjunto 1 = \n{{");
                    conj3 = conjuntoPartes(conj1);

                } else if(qualConj == 2) {

                    //Chamar a funcao para gerar conjunto das partes
                    printf("Quantidade de subconjuntos do conjunto 2 = \n{{");
                    conj3 = conjuntoPartes(conj2);

                }
            }

            //Ordem crescente ou decrescente
            if(menu == 14) {
                printf("Digite de qual conjunto voce deseja que seja mostrado.\n");
                printf("- Digite 1 para mostrar a ordem do primeiro.\n- Digite 2 para mostrar a ordem do segundo.\n");
                scanf("%d", &qualConj);

                if(qualConj == 1) {

                    //Saida
                    if(conj1->tamanho != 0) {
                        printf("- Digite 1 para ordem crescente. \n- Digite 2 para ordem decrescente.\n");
                        scanf("%d", &x);
                        mostraConjunto(conj1, x);
                        printf("Conjunto 1 = {");
                        for(i=0; i<conj1->tamanho; i++) {
                            if(i!=conj1->tamanho-1) {
                                printf("%d,", conj1->valores[i]);
                            } else {
                                printf("%d}\n", conj1->valores[i]);
                            }
                        }
                    } else {
                        printf("Conjunto 1 = { } (vazio).\n");
                    }
                } else if(qualConj == 2) {

                    //Saida
                    if(conj2->tamanho != 0) {
                        printf("- Digite 1 para ordem crescente. \n- Digite 2 para ordem decrescente.\n");
                        scanf("%d", &x);
                        mostraConjunto(conj2, x);
                        printf("Conjunto 2 = {");
                        for(i=0; i<conj2->tamanho; i++) {
                            if(i!=conj2->tamanho-1) {
                                printf("%d,", conj2->valores[i]);
                            } else {
                                printf("%d}\n", conj2->valores[i]);
                            }
                        }
                    } else {
                        printf("Conjunto 2 = { } (vazio).\n");
                    }
                }
            }            

            //Copiar C1 para C2
            if(menu == 15) {

                if(conj1->tamanho>0 && conj2->tamanho>0) {
                    copiou = copiarConjunto(conj1, conj2);
                    
                    if(copiou == 1) {
                        //Saida
                        printf("Novo conjunto 2 = {");
                        for(i=0; i<conj2->tamanho; i++) {
                            if(i!=conj2->tamanho-1) {
                                printf("%d,", conj2->valores[i]);
                            } else {
                                printf("%d}", conj2->valores[i]);
                            }
                        }
                        printf("\n");
                    } else if(copiou == 0) {
                        printf("Nao foi possivel copiar o conjunto 1 para o conjunto 2!\n");
                    }
                } else if(conj1->tamanho == 0) {
                    conj2 = NULL;
                    printf("Novo conjunto 2 = { }.\n");
                } else if(conj1->tamanho>0 && conj2->tamanho==0) {
                    conj2 = (Conjunto*) malloc(4*sizeof(conj1));
                    conj2->tamanho = conj1->tamanho;

                    for(i=0; i<conj1->tamanho; i++) {
                        conj2->valores[i] = conj1->valores[i];
                    }

                    if(conj2 != NULL) {
                        //Saida
                        printf("Novo conjunto 2 = {");
                        for(i=0; i<conj2->tamanho; i++) {
                            if(i!=conj2->tamanho-1) {
                                printf("%d,", conj2->valores[i]);
                            } else {
                                printf("%d}", conj2->valores[i]);
                            }
                        }
                        printf("\n");
                    } else if(conj2 == NULL) {
                        printf("Nao foi possivel copiar o conjunto 1 para o conjunto 2!\n");
                    }
                }
            }

            //Destruir conjunto C
            if(menu == 16) {

                //Afirmar escolha
                printf("Seu conjunto se tornara um conjunto vazio. Deseja prosseguir? (Y/N): ");
                getchar();
                scanf("%c", &sn);
                if(sn == 'Y') {
                    
                    //Escolher conjunto
                    printf("Digite qual conjunto voce deseja excluir\n");
                    printf("- Digite 1 para excluir o primeiro.\n- Digite 2 para excluir o segundo.\n");
                    scanf("%d", &qualConj);

                    if(qualConj == 1) {
                        destruiu = destruirConjunto(conj1);
                        conj1 = NULL;

                        if(destruiu == 1) {
                            printf("Seu conjunto foi excluido com sucesso!\n");
                        } else if(destruiu == 0) {
                            printf("Nao foi possivel excluir seu conjunto!\n");
                        }
                    } else if(qualConj == 2) {
                        destruiu = destruirConjunto(conj2);
                        conj2 = NULL;

                        if(destruiu == 1) {
                            printf("Seu conjunto foi excluido com sucesso!\n");
                        } else if(destruiu == 0) {
                            printf("Nao foi possivel excluir seu conjunto!\n");
                        }
                    }
                } else {
                    printf("Seu conjunto nao foi excluido.\n");
                }
            } 

            printf("-----------------------------------------------------------------\n");
        } while(menu != 0);
        
    }
    else {
        return (0);
    }    
}