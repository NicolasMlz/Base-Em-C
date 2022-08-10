//====================================================================================
// Arquivo texto.h
//====================================================================================

//Includes
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

//Constantes
#define TRUE 1;
#define FALSE 0;
#define MENOR -1;
#define IGUAL 0;
#define MAIOR 1;

//Texto.h
typedef struct t Texto;

//Cabeçalhos das funções
void mostraMenu();
Texto* criarTexto (char *t);
void liberarTexto (Texto *t);
unsigned int tamanhoTexto (Texto *t);
char* obterTexto(Texto *t);
void mostrarTexto (Texto *t, unsigned int colunas);
Texto* copiarTexto (Texto *t);
void substituirTexto (Texto *t, char * alteracao);
Texto* ss (Texto *t1, Texto *t2);
char* obterSubtexto (Texto *t, unsigned int inicio, unsigned int tamanho);
unsigned int encontrarSubtexto (Texto *t, char *subTexto, unsigned int ocorrencia);
int compararTextos (Texto *t1, Texto *t2);

//====================================================================================
// Arquivo texto.c
//====================================================================================

//Variavel tipo texto
struct t {
    char *texto;
    unsigned int tamanho;    
};

//Mostrar menu
void mostraMenu() {

    //Saida de opcoes
    printf("O que voce deseja fazer?\n");
    printf(" (0) - Encerrar o programa.\n");
    printf(" (1) - Excluir o texto digitado (apenas libera a memoria).\n");
    printf(" (2) - Obter o tamanho do texto.\n");
    printf(" (3) - Obter o texto (apenas retorna o texto digitado para uma variavel).\n");
    printf(" (4) - Mostrar o texto.\n");
    printf(" (5) - Fazer uma copia do texto.\n");
    printf(" (6) - Substituir o texto digitado.\n");
    printf(" (7) - Concatenar textos.\n");
    printf(" (8) - Obter um subtexto.\n");
    printf(" (9) - Encontrar subtexto no texto.\n");
    printf("(10) - Comparar textos.\n");
    printf("-------------------------------------------------------------------------\n");
}

//Criar um texto
Texto* criarTexto(char *texto) {

    //Variaveis
    int tamanho=0;
    tamanho = strlen(texto);

    //Alocar espaco dinamicamente
    Texto *t = (Texto*) malloc(sizeof(Texto));

    //Criar variavel tipo texto
    if(t != NULL) {
        
        t->texto = texto;
        t->tamanho = tamanho;
        return t;

    } else {
        printf("Erro ao criar texto.\n");
        return NULL;
    }
}

//Destruir texto
void liberarTexto(Texto *t) {
    if(t!=NULL) {
        free(t);
        printf("Texto excluido com sucesso!\n");    
    }
}

//Tamanho do texto
unsigned int tamanhoTexto (Texto *t) {
    
    if(t!=NULL) {
        //Variaveis
        t->tamanho = strlen(t->texto);
        //Retorno
        return t->tamanho;
    } else {
        return 0;
    }
}

//Obter texto
char* obterTexto(Texto *t) {
    
    //Retorno
    if(t != NULL) {

        //Variaveis para retorno
        char *ponteiro = t->texto;

        //Saida
        printf("Texto armazenado em uma string com sucesso!\n");
        return ponteiro;
    } else {
        printf("Falha ao obter texto!\n");
        return NULL;
    }
}

//Mostrar texto
void mostrarTexto (Texto *t, unsigned int colunas) {

    //Variaveis
    unsigned int i=0, j=0, tamanho;

    //Saida
    if(t != NULL) {
        tamanho = t->tamanho;
        if(tamanho!=0) {
            t->tamanho = strlen(t->texto);
            for(i=0; i<colunas && j<t->tamanho; i++) {
                if(i < colunas-1) {
                    printf("%c", t->texto[j]);
                    j++;
                }
                if(i == colunas-1 && j!=t->tamanho-1) {
                    printf("%c\n", t->texto[j]);
                    j++;
                    i=-1;
                } else if(i == colunas-1 && j==t->tamanho-1) {
                    printf("%c", t->texto[j]);
                    j++;
                    i=-1;
                }
            }
            printf("\n");
        } else {
            printf("Texto nulo.\n");
        }
    } else {
        printf("Texto nulo.\n");
    }
}

//Copiar texto
Texto* copiarTexto (Texto *t) {    
    
    //Alocar dinamicamente espaco para copia
    Texto* d = (Texto*) malloc(sizeof(Texto));

    //Verificar se alocou
    if(t!=NULL) {
        if(d != NULL) {

            //Armazenar valores na copia
            if(t->tamanho != 0) {
                d->texto = t->texto;
                d->tamanho = t->tamanho;
            } else {
                d = NULL;
            }

            //Retorno
            return d;
        } else {

            //Retorno
            printf("Falha ao copiar o texto!\n");
            return NULL;
        }
    } else {
        printf("Nao ha texto para ser copiado.\n");
    }
}

//Substituir o texto
void substituirTexto (Texto *t, char *alteracao) {

    //Variaveis
    int tamanho=0;
    tamanho = strlen(alteracao);

    //Criar variavel tipo texto
    if(t != NULL) {
        
        t->texto = alteracao;
        t->tamanho = strlen(alteracao);
        printf("Texto substituido com sucesso!\n");
        printf("Novo texto: %s\n", t->texto);
        printf("Novo tamanho do texto: %d\n", t->tamanho);  

    } else {
        printf("Erro ao substituir texto.\n");
    }
}

//Concatenar textos
Texto* concatenarTextos(Texto *t1, Texto *t2) {

    if(t1!=NULL) {
        if(t1->tamanho!=0 && t2->tamanho!=0) {

            //Criar novo tamanho
            t1->tamanho = t1->tamanho + t2->tamanho;

            //Criar novo texto concatenado
            strcat(t1->texto, t2->texto);

            //Retorno
            printf("Texto concatenado: %s\n", t1->texto);
            return t1;

        } else if(t1->tamanho==0 && t2->tamanho!=0) {
            return t2;
        } else if(t1->tamanho!=0 && t2->tamanho==0) {
            return t1;
        } else if(t1->tamanho==0 && t2->tamanho==0) {
            return NULL;
        }
    } else {
        return t2;
    }
}

//Obter subtexto
char* obterSubtexto (Texto *t, unsigned int inicio, unsigned int tamanho) {

    //Variaveis
    char subTexto[10000];
    unsigned int i, j=0;
    char *ponteiro = malloc(sizeof(tamanho)*4);

    if(t != NULL) {
        if(inicio<=t->tamanho && inicio+tamanho<=t->tamanho) {

            //Armazenar uma parte do texto no subtexto
            for(i=inicio; i<inicio+tamanho; i++) {
                subTexto[j] = t->texto[i];
                j++;
            }

            ponteiro = subTexto;

            //Retorno
            return ponteiro;
        } else {
            printf("Nao foi possivel obter subtexto.\n");
            return NULL;
        }
    } else {
        printf("Nao foi possivel obter subtexto.\n");
        return NULL;
    }
}

//Encontrar subtexto no texto
unsigned int encontrarSubtexto (Texto *t, char *subTexto, unsigned int ocorrencia) {

    //Variaveis
    unsigned int i=0, j=0, cont=0, tamSub = strlen(subTexto);

    //Condicoes
    if(tamSub <= t->tamanho) {
        
        //Verificar se ha subtexto
        for(i=0; i<t->tamanho; i++) {
            if(t->texto[i] == subTexto[j]) {
                
                ocorrencia = i;
                while(t->texto[i]==subTexto[j] && j<tamSub) {
                    cont++; i++; j++;
                }

                if(cont == tamSub) {

                    //Saida caso haja
                    return ocorrencia;
                } else {
                    cont=0; i=ocorrencia; j=0; 
                }
            }
        }

        //Saida caso nao haja
        return 0;

    } else {
        printf("Subtexto invalido!\n");
        return 0;
    }
}

//Comparar textos
int compararTextos(Texto *t1, Texto *t2) {

    //Variaveis
    int comparar=0;

    //Comparacao
    if(t1!=NULL && t2!=NULL) {
        if(t1->tamanho < t2->tamanho) {
            return -1;
        } else if(t1->tamanho == t2->tamanho) {
            return 0;
        } else if(t1->tamanho > t2->tamanho) {
            return 1;
        }
    } else if(t1==NULL && t2!=NULL) {
        return -1;
    } else if(t1!=NULL && t2==NULL) {
        return 1;
    } else if(t1==NULL && t2==NULL) {
        return 0;
    }
}

//====================================================================================
// Corpo Principal 
//====================================================================================

//Main
int main() {
    
    //Variaveis
    unsigned int i=0, menu=0, x=0, colunas=0, posicao=0, tamanhoSub=0, ocorrencia=0;
    char textoScaneado[100000], textoScaneado2[100000], subTextoScaneado[100000];
    Texto *texto1=NULL, *texto2=NULL, *textoCopia=NULL;
    char *texto = 'iniciou', *subTexto = 'iniciou';
    int comparar=0;

    //Introducao
    printf("Bem vindo ao programa de manipulacao de texto. Pressione 1 se deseja iniciar ou 0 se deseja sair: ");
    scanf("%d", &menu); 
    printf("---------------------------------------------------------------------------------------------------\n");  
    if(menu == 1) {

        //Scanear texto
        getchar(); printf("Digite o texto: ");
        scanf("%[^\n]", &textoScaneado);
        texto = textoScaneado;

        //Criar variavel tipo texto
        texto1 = criarTexto(texto);

        printf("Texto criado com sucesso!\n");
        printf("-------------------------------------------------------------------------\n");

        //MENU
        do {

            //Mostrar Menu
            mostraMenu();
            
            //Opção do usuário
            scanf("%d", &menu);

            //Liberar texto
            if(menu == 1) {
                liberarTexto(texto1);
            }

            //Obter o tamanho do texto
            else if(menu == 2) {
                x = tamanhoTexto(texto1);
                printf("O tamanho do texto e: %u.\n", x);
            }

            //Obter o texto 
            else if(menu == 3) {
                texto = obterTexto(texto1);
            }

            //Mostrar o texto
            else if(menu == 4) {
                printf("Digite quantos caracteres aparecerao por linha: ");
                scanf("%d", &colunas);
                mostrarTexto(texto1, colunas);
            }

            //Fazer uma copia do texto
            else if(menu == 5) {
                textoCopia = copiarTexto(texto1);
                if(textoCopia != NULL) {
                    printf("Texto copiado para a variavel 'textoCopia' com sucesso!\n");
                }
            }

            //Substituir o texto digitado
            else if(menu == 6) {

                //Scanear texto
                getchar(); printf("Digite o novo texto: ");
                scanf("%[^\n]", &textoScaneado);
                texto = textoScaneado;
                substituirTexto(texto1, texto);
            }

            //Concatenar textos
            else if(menu == 7) {

                //Scanear segundo texto
                getchar(); printf("Digite o texto a ser concatenado: ");
                scanf("%[^\n]", &textoScaneado2);
                texto = textoScaneado2;
                texto2 = criarTexto(texto);
                texto1 = concatenarTextos(texto1, texto2);
            }

            //Obter um subtexto
            else if(menu == 8) {
                
                //Entrada
                printf("Digite em qual posicao no texto o subtexto se iniciara: ");
                scanf("%d", &posicao);
                printf("Digite quantos caracteres o subtexto tera: ");
                scanf("%d", &tamanhoSub);
                
                //Saida
                subTexto = obterSubtexto(texto1, posicao, tamanhoSub);
                if(subTexto != NULL) {
                    printf("Subtexto: %s\n", subTexto);
                }
            }

            //Encontrar subtextos
            else if(menu == 9) {
                
                //Scanear subTexto
                getchar(); printf("Digite o subtexto a ser encontrado: ");
                scanf("%[^\n]", &subTextoScaneado);
                texto = subTextoScaneado; 

                //Verificar numero de ocorrencias
                ocorrencia = encontrarSubtexto(texto1, texto, ocorrencia);

                //Saida
                if(ocorrencia != 0) {
                    printf("Subtexto encontrado a partir da posicao %u.\n", ocorrencia-1);
                } else {
                    printf("Subtexto nao encontrado!\n");
                }
            }

            //Comparar textos
            else if(menu == 10) {

                //Scanear segundo texto
                getchar(); printf("Digite o texto a ser comparado (texto 2): ");
                scanf("%[^\n]", &textoScaneado2);
                texto = textoScaneado2;
                texto2 = criarTexto(texto); 

                //Comparar textos
                comparar = compararTextos(texto1, texto2);

                //Saida
                if(comparar == -1) {
                    printf("O texto 1 e menor que o texto 2.\n");
                } else if(comparar == 0) {
                    printf("O texto 1 possui o mesmo tamanho do texto 2.\n");
                } else if(comparar == 1) {
                    printf("O texto 1 e maior que o texto 2.\n");
                }                
            }

            //Opcao invalida
            else {
                printf("Selecione uma opcao valida!\n");
            }
                     
            //Recomeco do looping 
            printf("-------------------------------------------------------------------------\n");
        } while(menu != 0);   
    }
    else {
        return (0);
    }    
}