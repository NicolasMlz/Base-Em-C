//==============================================================================
// Arquivo conjunto.h
//==============================================================================

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//Constantes
#define TRUE 1;
#define FALSE 0;
#define MENOR -1;
#define IGUAL 0;
#define MAIOR 1;
#define DOMINGO 1, SEGUNDA-FEIRA 2 TERÇA-FEIRA 3, QUARTA-FEIRA 4, QUINTA-FEIRA 5, SEXTA-FEIRA 6, SÁBADO 7;

//Conjunto.h
typedef struct c Data;

//Cabeçalhos das funções
void trocaElemento(unsigned int *x, unsigned int *y);
void bubbleSort(int vetor[], unsigned int tamanho);
Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano);
Data* copiaData(Data *c);
void destruirData(Data *c);
Data* somaDiasData(Data *c, unsigned int dias);
Data* subtrairDiasData(Data *c, unsigned int dias);
void atribuirData(Data *c, unsigned int dia, unsigned int mes, unsigned int ano);
unsigned int obtemDia(Data *c);
unsigned int obtemMes(Data *c);
unsigned int obtemAno(Data *c);
unsigned int bissextoData(Data *c);
int comparaData(Data *c, Data *d);
unsigned int numeroDiasDatas(Data *c, Data *d);
unsigned int numeroMesesDatas(Data *c, Data *d);
unsigned int numeroAnosDatas(Data *c, Data *d);
unsigned int obtemDiaSemanaData(Data *c);
char* imprimeData(Data *c, char *formato);

//==============================================================================
// Arquivo conjunto.c
//==============================================================================

//Variavel tipo conjunto
struct c {
    int dia;
    int mes;
    int ano;     
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

//BubbleSort crescente
void bubbleSort(int vetor[], unsigned int tamanho) {
    
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

//Criar uma data
Data* criaData(unsigned int dia, unsigned int mes, unsigned int ano) {

    //Variaveis
    int i=0;
    Data *c;

    //Alocar dinamicamente a data
    c = (Data*) malloc(sizeof(Data));

    //Verificar se alocou
    if(c != NULL) {
        c->dia = dia;
        c->mes = mes;
        c->ano = ano;
        return c;
    } else {
        printf("Falha ao criar data!\n");
        return NULL;
    }

}

//Copiar data
Data* copiaData(Data *c) {

    //Alocar dinamicamente espaco para copia
    Data* d = (Data*) malloc(sizeof(c));

    //Verificar se alocou
    if(d != NULL) {
        d->dia = c->dia;
        d->mes = c->mes;
        d->ano = c->ano;
        printf("Data copiada com sucesso!\n");
        return d;
    } else {
        printf("Falha ao copiar data!\n");
        return NULL;
    }
}

//Destruir data
void destruirData(Data *c) {
    if(c != NULL) {
        free(c);
        printf("Data destruida!\n");
    }
}

//Somar dias a data
Data* somaDiasData(Data *c, unsigned int dias) {

    //Variaveis
    int j=0, k=0, i=0, ehBissexto=0;

    //Verificar se o ano eh bissexto
    ehBissexto = bissextoData(c);

    //Somar um dia de cada vez
    for(i=1; i<=dias; i++) {

        //Somar
        c->dia = c->dia + 1;

        //Meses de 31
        if(c->mes==1 || c->mes==3 || c->mes==5 || c->mes==7 || c->mes==8 || c->mes==10 || c->mes==12) {
            if(c->dia > 31) {
                c->dia = 1;
                c->mes++;

                //Trocou de ano
                if(c->mes > 12) {
                    c->mes = 1;
                    c->ano++;

                    //Verificar se o novo ano e bissexto
                    ehBissexto = bissextoData(c);
                }
            }
        }
        //Meses de 30 
        else if(c->mes==4 || c->mes==6 || c->mes==8 || c->mes==9 || c->mes==11) {
            if(c->dia > 30) {
                c->dia = 1;
                c->mes++;
            }
        } 
        //Ano Bissexto
        else if(c->mes == 2 && ehBissexto!=0) {
            if(c->dia > 29) {
                c->dia = 1;
                c->mes++;
            }
        }
        //Fevereiro
        else if(c->mes == 2 && ehBissexto==0) {
            if(c->dia > 28) {
                c->dia = 1;
                c->mes++;
            }
        }
    }

    //Nova data
    return c;
}

//Subtrair dias a data
Data* subtrairDiasData(Data *c, unsigned int dias) {
    
    //Variaveis
    int j=0, k=0, i=0, ehBissexto=0;

    //Verificar se o ano eh bissexto
    ehBissexto = bissextoData(c);

    //Somar um dia de cada vez
    for(i=1; i<=dias; i++) {

        //Somar
        c->dia = c->dia - 1;

        //Meses de 31
        if(c->mes==1 || c->mes==2 || c->mes==4 || c->mes==6 || c->mes==8 || c->mes==9 || c->mes==11) {
            if(c->dia < 1) {
                c->dia = 31;
                c->mes--;

                //Trocou de ano
                if(c->mes < 1) {
                    c->mes = 12;
                    c->ano--;

                    //Verificar se o novo ano e bissexto
                    ehBissexto = bissextoData(c);
                }
            }
        }
        //Meses de 30 
        else if(c->mes==5 || c->mes==7 || c->mes==10 || c->mes==12) {
            if(c->dia < 1) {
                c->dia = 30;
                c->mes--;
            }
        } 
        //Ano Bissexto
        else if(c->mes == 3 && ehBissexto!=0) {
            if(c->dia < 1) {
                c->dia = 29;
                c->mes--;
            }
        }
        //Fevereiro
        else if(c->mes == 3 && ehBissexto==0) {
            if(c->dia < 1) {
                c->dia = 28;
                c->mes--;
            }
        }
    }

    //Nova data
    return c;    
}

//Atribuir data
void atribuirData(Data *c, unsigned int dia, unsigned int mes, unsigned int ano) {
    if(c != NULL) {
        c->dia = dia;
        c->mes = mes;
        c->ano = ano;
        printf("Nova data atribuida com sucesso!\n");
    }
}

//Obter dia
unsigned int obtemDia(Data *c) {
    
    //Variaveis
    int dia=0;

    //Retorno
    dia = c->dia;
    return dia;
}

//Obter mes
unsigned int obtemMes(Data *c) {
    
    //Variaveis
    int mes=0;

    //Retorno
    mes = c->mes;
    return mes;
}

//Obter ano
unsigned int obtemAno(Data *c) {

    //Variaveis
    int ano=0;

    //Retorno
    ano = c->ano;
    return ano;
}

//Ano bissexto
unsigned int bissextoData(Data *c) {

    int ehBissexto=0, i=0;

    //Verificar se eh bissexto
    for(i=1900; i<2200; i+=4) {
        if(c->ano==i || c->ano%400==0) {
            ehBissexto++;
        } 
    }

    if(ehBissexto > 0) {
        return TRUE;
    } else if(ehBissexto == 0) {
        return FALSE;
    }
}

//Comparar datas
int comparaData(Data *c, Data *d) {

    //Variaveis
    int d1;
    
    //Analise por ano
    if(c->ano < d->ano) {
        return MENOR;
    } else if(c->ano > d->ano) {
        return MAIOR;
    }
    else if(c->ano == d->ano) {
        
        //Analise por mes
        if(c->mes < d->mes) {
            return MENOR;
        } else if(c->mes > d->mes) {
            return MAIOR;
        }
        else if(c->mes == d->mes) {

            //Analise por dia
            if(c->dia < d->dia) {
                return MENOR;
            } else if(c->dia > d->dia) {
                return MAIOR;
            }
            else if(c->dia == d->dia) {
                return IGUAL;
            }      
        }
    }
}

//Dias entre as datas
unsigned int numeroDiasDatas(Data *c, Data *d) {

    //Variaveis
    int comparar=0, dia=0, ehBissexto=0;
    Data *e;
    e = malloc(sizeof(c));

    //Verificar qual data e maior
    comparar = comparaData(c, d);

    //Caso em que a data 1 e menor
    if(comparar == -1) {

        //Data auxiliar
        e->dia = c->dia;
        e->mes = c->mes;
        e->ano = c->ano;

        //Anos de diferenca 
        while(e->ano < d->ano) {
            ehBissexto = bissextoData(e);
            if(ehBissexto == 1) {
                dia = dia + 366;
            } else {
                dia = dia + 365;
            }
            e->ano++;
        }

        //Meses de diferenca
        while(e->mes < d->mes) {
            ehBissexto = bissextoData(e);
            if(e->mes==1 || e->mes==3 || e->mes==5 || e->mes==7 || e->mes==8 || e->mes==10 || e->mes==12) {
                dia = dia + 31;
            } 
            else if(e->mes==4 || e->mes==6 || e->mes==8 || e->mes==9 || e->mes==11) {
                dia = dia + 30;
            }
            else if(e->mes == 2 && ehBissexto!=0) {
                dia = dia + 29;
            }
            else if(e->mes == 2 && ehBissexto==0) {
                dia = dia + 28;
            }
            e->mes++;
        }

        //Dias de diferenca
        while(e->dia < d->dia) {
            e->dia++;
            dia++;
        }    
    }

    //Caso em que a data 2 e menor
    else if(comparar == 1) {

        //Data auxiliar
        e->dia = d->dia;
        e->mes = d->mes;
        e->ano = d->ano;

        //Anos de diferenca 
        while(e->ano < c->ano) {
            ehBissexto = bissextoData(e);
            if(ehBissexto == 1) {
                dia = dia + 366;
            } else {
                dia = dia + 365;
            }
            e->ano++;
        }

        //Meses de diferenca
        while(e->mes < c->mes) {
            ehBissexto = bissextoData(e);
            if(e->mes==1 || e->mes==3 || e->mes==5 || e->mes==7 || e->mes==8 || e->mes==10 || e->mes==12) {
                dia = dia + 31;
            } 
            else if(e->mes==4 || e->mes==6 || e->mes==8 || e->mes==9 || e->mes==11) {
                dia = dia + 30;
            }
            else if(e->mes == 2 && ehBissexto!=0) {
                dia = dia + 29;
            }
            else if(e->mes == 2 && ehBissexto==0) {
                dia = dia + 28;
            }
            e->mes++;
        }

        //Dias de diferenca
        while(e->dia < c->dia) {
            e->dia++;
            dia++;
        }    
    }
    
    //Caso em que as datas sao iguais
    else if(comparar == 0) {
        dia = 0;
    }

    //Retorno da funcao
    return dia;
}

//Meses entre as datas
unsigned int numeroMesesDatas(Data *c, Data *d) {

    //Variaveis
    int comparar=0, mes=0;
    Data *e;
    e = malloc(sizeof(c));

    //Verificar qual data e maior
    comparar = comparaData(c, d);

    //Caso em que a data 1 e menor
    if(comparar == -1) {

        //Data auxiliar
        e->dia = c->dia;
        e->mes = c->mes;
        e->ano = c->ano;

        //Anos de diferenca 
        while(e->ano < d->ano) {
            mes = mes + 12;
            e->ano++;
        }

        //Meses de diferenca
        while(e->mes < d->mes) {
            mes = mes + 1;
            e->mes++;
        }   
    }

    //Caso em que a data 2 e menor
    else if(comparar == 1) {

        //Data auxiliar
        e->dia = d->dia;
        e->mes = d->mes;
        e->ano = d->ano;

        //Anos de diferenca 
        while(e->ano < c->ano) {
            mes = mes + 12;
            e->ano++;
        }

        //Meses de diferenca
        while(e->mes < c->mes) {
            mes = mes + 1;
            e->mes++;
        }   
    }  
    
    //Caso em que as datas sao iguais
    else if(comparar == 0) {
        mes = 0;
    }

    //Retorno da funcao
    return mes;
}

//Anos entre as datas
unsigned int numeroAnosDatas(Data *c, Data *d) {

    //Variaveis
    int comparar=0, ano=0;
    Data *e;
    e = malloc(sizeof(c));

    //Verificar qual data e maior
    comparar = comparaData(c, d);

    //Caso em que a data 1 e menor
    if(comparar == -1) {
        
        //Data auxiliar
        e->ano = c->ano;

        //Anos de diferenca 
        while(e->ano < d->ano) {
            ano = ano + 1;
            e->ano++;
        }   
    }

    //Caso em que a data 2 e menor
    else if(comparar == 1) {

        //Data auxiliar
        e->ano = d->ano;

        //Anos de diferenca 
        while(e->ano < c->ano) {
            ano = ano + 1;
            e->ano++;
        }
    }  
    
    //Caso em que as datas sao iguais
    else if(comparar == 0) {
        ano = 0;
    }

    //Retorno da funcao
    return ano;    
}

//Dia da semana correspondente a data
unsigned int obtemDiaSemanaData(Data *c) {

    //Variaveis
    Data* dataInicial; dataInicial = malloc(sizeof(c));
    dataInicial->dia = 1; dataInicial->mes = 1; dataInicial->ano = 1900;
    unsigned int i=0, j=1, semana=0, qtdeDias=0, diaDaSemana=0;

    //Vetor que armazena todos os dias da semana em sequencia 
    unsigned int diaSemana[109939]; //Seu tamanho eh a quantidade de dias que existem entre 01/01/1900 ate 31/12/2200

    //Dia da semana no dia 1 de janeiro de 1900 (fonte: https://www.calendario-365.com.br/calendário-1900.html)
    semana = 2; //(SEGUNDA)
    
    //Armazenar todos os dias da semana das datas no vetor
    for(i=0; i<109939; i++) {
        diaSemana[j] = semana;
        semana++; j++;

        if(semana == 8) {
            semana = 1;
        }
    }

    //Calcular quantos dias existem entre a primeira data, e a data a ser analisada
    qtdeDias = numeroDiasDatas(dataInicial, c);

    //Dia da semana correspondente a data
    diaDaSemana = diaSemana[qtdeDias];

    //Retorno
    return diaDaSemana;
}

//Imprimir data
char* imprimeData(Data *c, char *formato) {

    //Variaveis
    int dia=c->dia, mes=c->mes, ano=c->ano;
    char *dataFormatada, diaFormatado[100], mesFormatado[100], anoFormatado[100];
    dataFormatada = malloc(sizeof(char)*100);

    //Formatar dia
    if(dia >= 10) {
        sprintf(diaFormatado, "%d/", dia);
    } else {
        sprintf(diaFormatado, "0%d/", dia);
    }
    //Formatar mes
    if(mes >= 10) {
        sprintf(mesFormatado, "%d/", mes);
    } else {
        sprintf(mesFormatado, "0%d/", mes);
    }
    //Formatar ano
    sprintf(anoFormatado, "%d", ano);

    //Casos de formatacao
    if(formato[0]=='d' && formato[2]=='m' && formato[4]=='a') {

        strcpy(dataFormatada, diaFormatado);
        strcat(dataFormatada, mesFormatado);
        strcat(dataFormatada, anoFormatado);

    } else if (formato[0]=='d' && formato[2]=='a' && formato[6]=='m') {

        //Formatar ano
        sprintf(anoFormatado, "%d/", ano);

        //Formatar mes
        if(mes >= 10) {
            sprintf(mesFormatado, "%d", mes);
        } else {
            sprintf(mesFormatado, "0%d", mes);
        }

        strcpy(dataFormatada, diaFormatado);
        strcat(dataFormatada, anoFormatado);
        strcat(dataFormatada, mesFormatado);

    } else if (formato[0]=='m' && formato[2]=='d' && formato[4]=='a') {

        strcpy(dataFormatada, mesFormatado);
        strcat(dataFormatada, diaFormatado);
        strcat(dataFormatada, anoFormatado);

    } else if (formato[0]=='m' && formato[2]=='a' && formato[6]=='d') {

        //Formatar ano
        sprintf(anoFormatado, "%d/", ano);
        //Formatar dia
        if(dia >= 10) {
            sprintf(diaFormatado, "%d", dia);
        } else {
            sprintf(diaFormatado, "0%d", dia);
        }

        strcpy(dataFormatada, mesFormatado);
        strcat(dataFormatada, anoFormatado);
        strcat(dataFormatada, diaFormatado);

    } else if (formato[0]=='a' && formato[4]=='d' && formato[6]=='m') {

        //Formatar ano
        sprintf(anoFormatado, "%d/", ano);
        //Formatar mes
        if(mes >= 10) {
            sprintf(mesFormatado, "%d", mes);
        } else {
            sprintf(mesFormatado, "0%d", mes);
        }

        strcpy(dataFormatada, anoFormatado);
        strcat(dataFormatada, diaFormatado);
        strcat(dataFormatada, mesFormatado);

    } else if (formato[0]=='a' && formato[4]=='m' && formato[6]=='d') {

        //Formatar ano
        sprintf(anoFormatado, "%d/", ano);
        //Formatar dia
        if(dia >= 10) {
            sprintf(diaFormatado, "%d", dia);
        } else {
            sprintf(diaFormatado, "0%d", dia);
        }

        strcpy(dataFormatada, anoFormatado);
        strcat(dataFormatada, mesFormatado);
        strcat(dataFormatada, diaFormatado);

    } else if (formato[0]=='d' && formato[2]=='m') {

        //Formatar mes
        if(mes >= 10) {
            sprintf(mesFormatado, "%d", mes);
        } else {
            sprintf(mesFormatado, "0%d", mes);
        }  

        strcpy(dataFormatada, diaFormatado);
        strcat(dataFormatada, mesFormatado);

    } else if (formato[0]=='m' && formato[2]=='d') {

        //Formatar mes
        if(dia >= 10) {
            sprintf(diaFormatado, "%d", dia);
        } else {
            sprintf(diaFormatado, "0%d", dia);
        }  

        strcpy(dataFormatada, mesFormatado);
        strcat(dataFormatada, diaFormatado);

    } else if (formato[0]=='d') {

        //Formatar dia
        if(dia >= 10) {
            sprintf(diaFormatado, "%d", dia);
        } else {
            sprintf(diaFormatado, "0%d", dia);
        }

        strcpy(dataFormatada, diaFormatado);

    } else if (formato[0]=='m') {

        //Formatar mes
        if(mes >= 10) {
            sprintf(mesFormatado, "%d", mes);
        } else {
            sprintf(mesFormatado, "0%d", mes);
        }

        strcpy(dataFormatada, mesFormatado);

    } else if (formato[0]=='a') {

        strcpy(dataFormatada, anoFormatado);

    } else {
        return NULL;
    }

    //Retorno
    return (dataFormatada);
}

//==============================================================================
// Corpo Principal 
//==============================================================================

//Main
int main() {
    
    //Variaveis
    Data *data1=NULL, *data2=NULL, *data3=NULL;
    int i=0, j=0, menu=0, x=0, qualData=0, comparar=0;
    unsigned int dia, mes, ano, qualDiaSemana=0;
    bool ehBissexto;
    char formato[9], *dataFormatada;

    //Introducao
    printf("Bem vindo ao programa de manipulacao de datas. Pressione 1 se deseja iniciar ou 0 se deseja sair: ");
    scanf("%d", &menu);
    printf("---------------------------------------------------------------------------------------------------\n");  
    if(menu == 1) {
        
        //Condicoes
        printf("Por favor, escolha datas entre 01/01/1900 a 31/12/2200!\n");

        //Criar data 1 
        printf("PRIMEIRA DATA.\n");
        printf("Dia: "); scanf("%ud", &dia);
        printf("Mes: "); scanf("%ud", &mes);
        printf("Ano: "); scanf("%ud", &ano);
        data1 = criaData(dia, mes, ano);
        
        //Criar data 2
        printf("SEGUNDA DATA.\n");
        printf("Dia: "); scanf("%ud", &dia); 
        printf("Mes: "); scanf("%ud", &mes); 
        printf("Ano: "); scanf("%ud", &ano); 
        data2 = criaData(dia, mes, ano);
        printf("---------------------------------------------------------------------------------------------------\n");
        
        //MENU
        do {

            //Opções
            menu = 1;
            printf("O que voce deseja fazer?\n");
            printf(" (0) - Encerrar o programa.\n");
            printf(" (1) - Fazer uma copia da data.\n");
            printf(" (2) - Destruir data digitada.\n");
            printf(" (3) - Somar dias a data.\n");
            printf(" (4) - Subtrair dias a data.\n");
            printf(" (5) - Atribuir nova data.\n");
            printf(" (6) - Obter somente o dia da data.\n");
            printf(" (7) - Obter somente o mes da data.\n");
            printf(" (8) - Obter somente o ano da data.\n");
            printf(" (9) - Verificar se a data pertence a um ano bissexto.\n");
            printf("(10) - Comparar as datas.\n");
            printf("(11) - Verificar quantos dias existem entre as datas.\n");
            printf("(12) - Verificar quantos meses existem entre as datas.\n");
            printf("(13) - Verificar quantos anos existem entre as datas\n");
            printf("(14) - Obter o dia da semana correspondente a data.\n");
            printf("(15) - Imprimir data em um formato especifico.\n");
            printf("-----------------------------------------------------------------\n");
            //....
            
            //Opção do usuário
            scanf("%d", &menu);

            //Copiar datas
/*MENU*/    if(menu == 1) {
                printf("Digite de qual data voce deseja criar uma copia.\n");
                printf("- Digite 1 para copiar a primeira.\n- Digite 2 para copiar a segunda.\n");
                scanf("%d", &qualData);

                //Copiar a primeira data
                if(qualData == 1) {
                    data3 = copiaData(data1);
                } 
                //Copiar a segunda data
                else if(qualData == 2) {
                    data3 = copiaData(data2);
                }
            }

            //Destruir data
            else if(menu == 2) {
                printf("Digite de qual data voce deseja destruir\n");
                printf("- Digite 1 para destruir a primeira.\n- Digite 2 para destruir a segunda.\n");
                scanf("%d", &qualData);

                //Destruir a primeira data
                if(qualData == 1) {
                    destruirData(data1);
                }
                //Destruir a segunda data
                else if(qualData == 2) {
                    destruirData(data2);
                }
            }

            //Somar dias a data
            else if(menu == 3) {
                printf("Digite de qual data voce deseja somar N dias\n");
                printf("- Digite 1 para somar a primeira.\n- Digite 2 para somar a segunda.\n");
                scanf("%d", &qualData);
                printf("Digite quantos dias voce deseja somar a data %d.\n", qualData);
                scanf("%d", &x);

                //Somar a primeira data
                if(qualData == 1) {
                   data1 = somaDiasData(data1, x);
                   printf("Nova data: %d/%d/%d.\n", data1->dia, data1->mes, data1->ano);
                }
                //Somar a segunda data
                else if(qualData == 2) {
                    data2 = somaDiasData(data2, x);
                    printf("Nova data: %d/%d/%d.\n", data2->dia, data2->mes, data2->ano);
                }
            }

            //Subtrair dias a data
            else if(menu == 4) {
                printf("Digite de qual data voce deseja subtrair N dias\n");
                printf("- Digite 1 para subtrair da primeira.\n- Digite 2 para subtrair da segunda.\n");
                scanf("%d", &qualData);
                printf("Digite quantos dias voce deseja subtrair da data %d.\n", qualData);
                scanf("%d", &x);

                //Somar a primeira data
                if(qualData == 1) {
                   data1 = subtrairDiasData(data1, x);
                   printf("Nova data: %d/%d/%d.\n", data1->dia, data1->mes, data1->ano);
                }
                //Somar a segunda data
                else if(qualData == 2) {
                    data2 = subtrairDiasData(data2, x);
                    printf("Nova data: %d/%d/%d.\n", data2->dia, data2->mes, data2->ano);
                }                
            }     

            //Atribuir nova data
            else if(menu == 5) {
                printf("Escolha qual data voce deseja atribuir novos valores\n");
                printf("- Digite 1 para atribuir a primeira.\n- Digite 2 para atribuir a segunda.\n");
                scanf("%d", &qualData);

                //Scanear nova data
                printf("NOVA DATA.\n");
                printf("Dia: "); scanf("%ud", &dia); 
                printf("Mes: "); scanf("%ud", &mes); 
                printf("Ano: "); scanf("%ud", &ano);                 

                //Atribuir a primeira data
                if(qualData == 1) {
                    atribuirData(data1, dia, mes, ano);
                }
                //Atribuir a segunda data
                else if(qualData == 2) {
                    atribuirData(data2, dia, mes, ano);
                }        
            }

            //Obter dia
            else if(menu == 6) {
                printf("Voce deseja acessar o dia de qual data?\n");
                printf("- Digite 1 para acessar a primeira.\n- Digite 2 para acessar a segunda.\n");
                scanf("%d", &qualData);
  
                //Acessar primeira data
                if(qualData == 1) {
                    dia = obtemDia(data1);
                    if(dia>=1 && dia<10) {
                        printf("Dia da data 1: 0%d.\n", dia);
                    } else {
                        printf("Dia da data 1: %d.\n", dia);
                    }
                }
                //Acessar a segunda data
                else if(qualData == 2) {
                    dia = obtemDia(data2);
                    if(dia>=1 && dia<10) {
                        printf("Dia da data 2: 0%d.\n", dia);
                    } else {
                        printf("Dia da data 2: %d.\n", dia);
                    }                    
                }     
            }

            //Obter mes
            else if(menu == 7) {
                printf("Voce deseja acessar o mes de qual data?\n");
                printf("- Digite 1 para acessar a primeira.\n- Digite 2 para acessar a segunda.\n");
                scanf("%d", &qualData);
  
                //Acessar primeira data
                if(qualData == 1) {
                    mes = obtemMes(data1);
                    if(mes>=1 && mes<10) {
                        printf("Mes da data 1: 0%d.\n", mes);
                    } else {
                        printf("Mes da data 1: %d.\n", mes);
                    }
                }
                //Acessar a segunda data
                else if(qualData == 2) {
                    mes = obtemMes(data2);
                    if(mes>=1 && mes<10) {
                        printf("Dia da data 2: 0%d.\n", mes);
                    } else {
                        printf("Dia da data 2: %d.\n", mes);
                    }                    
                }                 
            }

            //Obter ano
            else if(menu == 8) {
                printf("Voce deseja acessar o ano de qual data?\n");
                printf("- Digite 1 para acessar a primeira.\n- Digite 2 para acessar a segunda.\n");
                scanf("%d", &qualData);
  
                //Acessar primeira data
                if(qualData == 1) {
                    ano = obtemAno(data1);
                    printf("Ano da data 1: %d.\n", ano);
  
                }
                //Acessar a segunda data
                else if(qualData == 2) {
                    ano = obtemMes(data2);
                    printf("Ano da data 2: %d.\n", ano);
                }                   
            }

            //Verificar se o ano e bissexto
            else if(menu == 9) {
                printf("Qual ano voce deseja verificar se e bissexto?\n");
                printf("- Digite 1 para verificar o ano da primeira data.\n- Digite 2 para verificar o ano da segunda data.\n");
                scanf("%d", &qualData);
  
                //Acessar primeira data
                if(qualData == 1) {
                    ehBissexto = bissextoData(data1);
  
                    //Saida
                    if(ehBissexto == 1) {
                        printf("O ano de %d e bissexto!\n", data1->ano);
                    } else {
                        printf("O ano de %d nao e bissexto.\n", data1->ano);
                    }
                }
                //Acessar a segunda data
                else if(qualData == 2) {
                    ehBissexto = bissextoData(data2);
  
                    //Saida
                    if(ehBissexto == 1) {
                        printf("O ano de %d e bissexto!\n", data2->ano);
                    } else {
                        printf("O ano de %d nao e bissexto.\n", data2->ano);
                    }
                }   
            }

            //Comparar datas
            else if(menu == 10) {
                comparar = comparaData(data1, data2);

                //Saida
                if(comparar == -1) {
                    printf("A data 1 e menor que a data 2.\n");
                } else if(comparar == 0) {
                    printf("As duas datas sao iguais!\n");
                } else if(comparar == 1) {
                    printf("A data 1 e maior que a data 2.\n");
                }
            }

            //Dias entre as datas
            else if(menu == 11) {
                dia = numeroDiasDatas(data1, data2);
                
                if(dia == 0) {
                    printf("As 2 datas sao iguais. Ha 0 dias entre as datas.\n");
                } else {
                    printf("Ha %d dias entre as datas!\n", dia);
                }
            }            

            //Meses entre as datas
            else if(menu == 12) {
                mes = numeroMesesDatas(data1, data2);
                
                if(mes == 0) {
                    printf("As 2 datas sao iguais. Ha 0 meses entre as datas.\n");
                } else {
                    printf("Ha %d meses entre as datas!\n", mes);
                }                
            }

            //Anos entre as datas
            else if(menu == 13) {
                ano = numeroAnosDatas(data1, data2);
                
                if(ano == 0) {
                    printf("As 2 datas sao iguais. Ha 0 anos entre as datas.\n");
                } else {
                    printf("Ha %d anos entre as datas!\n", ano);
                }                  
            }

            //Dia da semana correspondente
            else if(menu == 14) {
                printf("Digite qual data voce deseja que seja mostrado o dia da semana correspondente.\n");
                printf("- Digite 1 para a primeira.\n- Digite 2 para a segunda.\n");
                scanf("%d", &qualData);

                //Dia da semana da primeira data
                if(qualData == 1) {

                    //Chamar funcao
                    qualDiaSemana = obtemDiaSemanaData(data1);

                    if(qualDiaSemana==1) {
                        printf("Dia da semana correspondente a data 1: DOMINGO.\n");
                    } else if(qualDiaSemana==2) {
                        printf("Dia da semana correspondente a data 1: SEGUNDA-FEIRA.\n");
                    } else if(qualDiaSemana==3) {
                        printf("Dia da semana correspondente a data 1: TERCA-FEIRA.\n");
                    } else if(qualDiaSemana==4) {
                        printf("Dia da semana correspondente a data 1: QUARTA-FEIRA.\n");
                    } else if(qualDiaSemana==5) {
                        printf("Dia da semana correspondente a data 1: QUINTA-FEIRA.\n");
                    } else if(qualDiaSemana==6) {
                        printf("Dia da semana correspondente a data 1: SEXTA-FEIRA.\n");
                    } else if(qualDiaSemana==7) {
                        printf("Dia da semana correspondente a data 1: SABADO.\n");
                    } else {
                        printf("Data invalida!\n");
                    }
                } 
                //Dia da semana da segunda data
                else if(qualData == 2) {
                    qualDiaSemana = obtemDiaSemanaData(data2);

                    if(qualDiaSemana==1) {
                        printf("Dia da semana correspondente a data 2: DOMINGO.\n");
                    } else if(qualDiaSemana==2) {
                        printf("Dia da semana correspondente a data 2: SEGUNDA-FEIRA.\n");
                    } else if(qualDiaSemana==3) {
                        printf("Dia da semana correspondente a data 2: TERCA-FEIRA.\n");
                    } else if(qualDiaSemana==4) {
                        printf("Dia da semana correspondente a data 2: QUARTA-FEIRA.\n");
                    } else if(qualDiaSemana==5) {
                        printf("Dia da semana correspondente a data 2: QUINTA-FEIRA.\n");
                    } else if(qualDiaSemana==6) {
                        printf("Dia da semana correspondente a data 2: SEXTA-FEIRA.\n");
                    } else if(qualDiaSemana==7) {
                        printf("Dia da semana correspondente a data 2: SABADO.\n");
                    } else {
                        printf("Data invalida!\n");
                    }
                }              
            }

            //Imprimir data no formato escolhido
            else if(menu == 15) {
                printf("Digite qual data voce deseja que seja mostrada.\n");
                printf("- Digite 1 para a primeira.\n- Digite 2 para a segunda.\n");
                scanf("%d", &qualData);
                printf("Digite o formato que voce deseja mostra-la (exemplo ddmmaaaa) : ");
                scanf("%s", formato);

                //Formatar a primeira data
                if(qualData == 1) {
                    dataFormatada = imprimeData(data1, formato);

                    //Saida
                    if(dataFormatada != NULL) {
                        printf("Data 1: %s.\n", dataFormatada);
                    } else {
                        printf("Formatacao de data invalida!.\n");
                    }
                } 
                //Formatar a segunda data
                else if(qualData == 2) {
                    dataFormatada = imprimeData(data2, formato);

                    //Saida
                    if(dataFormatada != NULL) {
                        printf("Data 1: %s.\n", dataFormatada);
                    } else {
                        printf("Formatacao de data invalida!.\n");
                    }
                }                
            }            

            //Recomeco do looping   
            printf("-----------------------------------------------------------------\n");
        } while(menu != 0);   
    }
    else {
        return (0);
    }    
}