#include <stdio.h>
#include <stdlib.h>
#define SUCESSO 1 //Constantes−base para
#define FALHA -1 //Para controle de codigo−fonte
#define CHAVE_INVALIDA 0 //Lista vazia
#define TAMANHO_MAXIMO_LISTA 100 //Tamanho maximo da lista

//VARIAVEIS DA LISTA
    //Celula da lista
typedef struct {
    unsigned int chave;
    unsigned int dado;
} Celula;
    //Lista linear
    typedef struct {
    Celula celulas[TAMANHO_MAXIMO_LISTA];
    unsigned int tamanho;
} ListaLinear;

//Criar lista vazia
int criarListaVazia(ListaLinear *lista) {
    lista->tamanho = 0;
    return (SUCESSO);
}

//Criar lista com uma unica celula
int criarListaChave(ListaLinear *lista, Celula celula) {

    lista->celulas[0] = celula;
    lista->tamanho = 1;
    return (SUCESSO);
}

//Tamanho da lista
int tamanhoLista(ListaLinear lista) {
    if (lista.tamanho >= 0) {
        return(lista.tamanho);
    }
    else {
        return(FALHA);
    }
}

//Mostrar valores da celula
void mostrarCelula(Celula celula) {
    printf("Chave: %u\n", celula.chave);
    printf("Dado: %u\n", celula.dado);
}

//Mostrar toda a lista
void mostrarLista(ListaLinear lista) {
    
    int i;
    
    if(lista.tamanho == 0) {
        printf("Atencao: a lista esta vazia.\n");
    }
    else {
        printf("A lista linear possui %u elementos.\n\n", lista.tamanho);
        for (i=0; i<lista.tamanho; i++) {
            printf("Elemento numero: %u\n", (i+1));
            mostrarCelula(lista.celulas[i]);
        }
    }
}

//Consultar celula baseado na posicao
Celula consultaListaPosicao(ListaLinear lista, unsigned int intPosicao ) {
    
    Celula celulaResultado;
    
    if ((intPosicao > 0) && (intPosicao <= lista.tamanho)) {
        celulaResultado = lista.celulas[intPosicao-1];
    }
    else {
        celulaResultado.chave = CHAVE_INVALIDA;
    }
    return(celulaResultado);
}

//Consultar celula baseado na chave
Celula consultaListaChave(ListaLinear lista, Celula celula) {
    
    unsigned int i;
    
    for (i=0; i<lista.tamanho; i++) {
        if (lista.celulas[i].chave == celula.chave) {
            return(lista.celulas[i]);
        }
    }
    celula.chave = CHAVE_INVALIDA;
    return(celula);
}

//Inserir celula no inicio
int insInicio (ListaLinear *lista, Celula celula) {
    
    unsigned int i;
    
    if(lista->tamanho == TAMANHO_MAXIMO_LISTA) {
        return(FALHA); //A lista ja esta cheia: overflow
    }
    else {
        for (i=lista->tamanho; i>0; i--) {
            lista->celulas[i] = lista->celulas[i-1];
        }
        lista->celulas[0] = celula; //Insercao no inicio da lista
        lista->tamanho++;
        return(SUCESSO);
    }
}

//Inserir celula no final
int insFinal (ListaLinear *lista, Celula celula) {
    
    unsigned int i;
    Celula auxiliar;
    
    if (lista->tamanho == TAMANHO_MAXIMO_LISTA) {
        return(FALHA); // a lista esta cheia: overflow
    }
    else {
        lista->celulas[lista->tamanho] = celula; // insercao no final da lista
        lista->tamanho++;
        return(SUCESSO);
    }
}

//Inserir celula por chave (ascendente)
int insOrdem (ListaLinear *lista, Celula celula) {
    
    unsigned int i, j;

    if (lista->tamanho == TAMANHO_MAXIMO_LISTA) {
        return(FALHA); //A lista esta cheia: overflow
    }
    else {
        if (lista->tamanho == 0) {
            return (insInicio(lista, celula));
        }
        else {
            if (celula.chave < lista->celulas[0].chave) {
                return (insInicio(lista, celula));
            }
            else {
                if (celula.chave >= lista->celulas[lista->tamanho-1].chave) {
                    return (insFinal(lista, celula));
                }
                else {
                    i = 0;
                    while ((celula.chave >= lista->celulas[i].chave) && (i<lista->tamanho)) {
                       i++;
                    }
                    if (i == lista->tamanho) {
                        return(insFinal(lista, celula));
                    }
                    else {
                        for (j = lista->tamanho;(j > i); j--) {
                            lista->celulas[j] = lista->celulas[j-1];
                        }
                        lista->celulas[i] = celula;
                        lista->tamanho++;
                        return(SUCESSO);
                    }
                }
            }
        }
    }
}

//Remover celula no inicio
Celula remInicio (ListaLinear *lista) {
    
    unsigned int i;
    Celula celulaResultado;

    if (lista->tamanho == 0) {
        celulaResultado.chave = CHAVE_INVALIDA;
        return(celulaResultado);
    }
    else {
        celulaResultado = lista->celulas[0];
        for (i = 0; (i < lista->tamanho - 1); i++) {
            lista->celulas[i] = lista->celulas[i+1];
        }
        lista->tamanho--;
        return(celulaResultado);
    }
}

//Remover celula no final
Celula remFinal (ListaLinear *lista) {
    
    Celula celulaResultado;
    
    if (lista->tamanho == 0) {
        celulaResultado.chave = CHAVE_INVALIDA;
        return(celulaResultado);
    }
    else {
        celulaResultado = lista->celulas[lista->tamanho - 1];
        lista->tamanho--;
        return(celulaResultado);
    }
}

//Remover celula baseado na chave
Celula remChave (ListaLinear *lista, Celula celula) {

    unsigned int i, j, k;
    unsigned int intQuantidadeRemocoes;
    Celula celulaResultado;

    if (lista->tamanho == 0) {
        celulaResultado.chave = CHAVE_INVALIDA;
        return(celulaResultado);
    }
    else {
        if (celula.chave == lista->celulas[0].chave) {
            while (celula.chave == lista->celulas[0].chave) {
                celulaResultado = remInicio(lista);
                if (celulaResultado.chave == CHAVE_INVALIDA) {
                    return(celulaResultado);
                }
            }
        }
        else {
            if (celula.chave == lista->celulas[lista->tamanho - 1].chave) {
                while (celula.chave == lista->celulas[lista->tamanho - 1].chave) {
                    celulaResultado = remFinal(lista);
                    if (celulaResultado.chave == CHAVE_INVALIDA) {
                        return(celulaResultado);
                    }
                }
            }
            else {
                i = 0;
                while ((celula.chave > lista->celulas[i].chave) && (i < lista->tamanho)) {
                    i++;
                }
                if (i == lista->tamanho) {
                    celulaResultado.chave = CHAVE_INVALIDA;
                    return(celulaResultado);
                }
                else {
                    intQuantidadeRemocoes = 0;
                    j = i;
                    while ((celula.chave == lista->celulas[j].chave) && (j < lista->tamanho)) {
                        intQuantidadeRemocoes++;
                        j++;
                    }
                    if (intQuantidadeRemocoes == 0) {
                        celulaResultado.chave = CHAVE_INVALIDA;
                        return(celulaResultado);
                    }
                    else {
                        celulaResultado = lista->celulas[i];
                        for (j = i; (j < (lista->tamanho - intQuantidadeRemocoes)); j++) {
                            if (j + intQuantidadeRemocoes < lista->tamanho) {
                                lista->celulas[j] = lista->celulas[j + intQuantidadeRemocoes];
                            }
                        }
                        lista->tamanho -= intQuantidadeRemocoes;
                        return(celulaResultado);
                    }
                }
            }
        }
    }
}


//MAIN
int main() {

    //Variaveis
    int i, j, k, deuCerto, tamanho, indice, menu=1;
    ListaLinear lista, listaAux;
    Celula celula, celulaAux;

    //Adicionar elementos a celula
    printf("---------------------------------------------------------\n");
    printf("Digite a quantidade de celulas que voce deseja registrar.\n");
    scanf("%d", &lista.tamanho);
    printf("Digite respectivamente, a chave e o dado de cada celula.\n");
    for(i=0; i<lista.tamanho; i++) {
        scanf("%d %d", &lista.celulas[i].chave, &lista.celulas[i].dado);
    }

    //Menu
    do {

        //Opcoes
        printf("---------------------------------------------\n");
        printf("O que voce deseja fazer?\n");
        printf(" (0) - Encerrar o programa.\n");
        printf(" (1) - Criar lista vazia.\n");
        printf(" (2) - Criar lista com uma unica celula.\n");
        printf(" (3) - Exibir tamanho da lista.\n");
        printf(" (4) - Mostrar valores da celula.\n");
        printf(" (5) - Mostrar toda a lista.\n");
        printf(" (6) - Consultar celula baseado na posicao.\n");
        printf(" (7) - Consultar celula baseado na chave.\n");
        printf(" (8) - Inserir celula no inicio.\n");
        printf(" (9) - Inserir celula no final.\n");
        printf("(10) - Inserir celula por chave (ascendente).\n");
        printf("(11) - Remover celula no inicio.\n");
        printf("(12) - Remover celula no final.\n");
        printf("(13) - Remover celula baseado na chave.\n");
        printf("---------------------------------------------\n");

        //Opcao do usuario
        scanf("%d", &menu);

        //Criar lista vazia
        if(menu == 1) {
            deuCerto = criarListaVazia(&listaAux);
            printf("Lista vazia criada com sucesso!\n");
        }

        //Criar lista com uma unica celula
        else if(menu == 2) {
            printf("Digite a chave e o valor da celula a ser inserida no inicio.\n");
            scanf("%d %d", &celulaAux.chave, &celulaAux.dado);            
            deuCerto = criarListaChave(&listaAux, celulaAux);
            printf("Lista unitaria criada com sucesso!\n");
        }

        //Exibir tamanho da lista
        else if(menu == 3) {
            tamanho = tamanhoLista(lista);
            printf("Tamanho da lista = %d.\n", tamanho);
        }

        //Mostrar valores da celula
        else if(menu == 4) {
            printf("Digite qual celula voce deseja que seja mostrada.\n");
            scanf("%d", &indice);
            mostrarCelula(lista.celulas[indice]);
        }

        //Mostrar toda a lista
        else if(menu == 5) {
            mostrarLista(lista);
        }

        //Consultar celula baseado na posicao
        else if(menu == 6) {
            printf("Digite qual a posicao da celula a ser mostrada.\n");
            scanf("%d", &indice);
            celulaAux = consultaListaPosicao(lista, indice);
            printf("Chave: %d\nDado: %d\n", celulaAux.chave, celulaAux.dado);
        }

        //Consultar celula baseado na chave
        else if(menu == 7) {
            printf("Digite qual a chave da celula a ser mostrada.\n");
            scanf("%d", &celula.chave);
            celulaAux = consultaListaChave(lista, celula);
            printf("Chave: %d\nDado: %d\n", celulaAux.chave, celulaAux.dado);
        }

        //Inserir celula no inicio
        else if(menu == 8) {
            printf("Digite a chave e o valor da celula a ser inserida no inicio.\n");
            scanf("%d %d", &celula.chave, &celula.dado);
            deuCerto = insInicio(&lista, celula);
            if(deuCerto = 1) {
                printf("Celula inserida com sucesso!\nChave: %d\nDado: %d\n", lista.celulas[0].chave, lista.celulas[0].dado);
            }
        }

        //Inserir celula no final
        else if(menu == 9) {
            printf("Digite a chave e o valor da celula a ser inserida no final.\n");
            scanf("%d %d", &celula.chave, &celula.dado);
            deuCerto = insFinal(&lista, celula);
            if(deuCerto = 1) {
                printf("Celula inserida com sucesso!\nChave: %d\nDado: %d\n", lista.celulas[lista.tamanho-1].chave, lista.celulas[lista.tamanho-1].dado);
            }
        }

        //Inserir célula por chave (ascendente)
        else if(menu == 10) {
            printf("Digite a chave e o valor da celula a ser inserida de acordo com a chave.\n");
            scanf("%d %d", &celula.chave, &celula.dado);
            deuCerto = insOrdem(&lista, celula);
            if(deuCerto = 1) {
                mostrarLista(lista);
            }   
        }

        //Remover celula no inicio
        else if(menu == 11) {
            celula = remInicio(&lista);
            if(deuCerto = 1) {
                mostrarLista(lista);
            }   
        }

        //Remover celula no final
        else if(menu == 12) {
            celula = remFinal(&lista);
            if(deuCerto = 1) {
                mostrarLista(lista);
            }              
        }

        //Remover celula baseado na chave
        else if(menu == 13) {
            printf("Digite a chave que excluira a celula em questao.\n");
            scanf("%d", &celula.chave);
            celulaAux = remChave(&lista, celula);
            if(deuCerto = 1) {
                mostrarLista(lista);
            }              
        }

        //Opcao invalida
        else if(menu>13 || menu<0) {
            printf("Opcao invalida!\n");
        }


    } while(menu != 0);

    return 0;
}