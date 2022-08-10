#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------------------------------------
// filaSus.H
//-------------------------------------------------------------------------

//Variaveis Globais
typedef struct Horario {

    //Variaveis
    int hora;
    int minuto;
    
} Horario;
typedef struct Paciente *ApontadorCelula;
typedef struct Paciente {

    //Variaveis
    int hora;
    int minuto;
    int tRestante;
    
} Paciente;

//Headers
int morreuOuNao(Paciente paciente, Horario horario);

//-------------------------------------------------------------------------
// filaSus.C
//-------------------------------------------------------------------------

//Verificar se o paciente morrera ou nao
int morreuOuNao(Paciente paciente, Horario horario) {

    //Variaveis
    int viveu=0;

    //Chegou no horario em ponto?
    if(paciente.hora == horario.hora && paciente.minuto == horario.minuto) {
        viveu++;
    }

    //Esta adiantado?
    if(paciente.hora <= horario.hora) {

        //Esta na mesma hora mas com minutos adiantados?
        if(paciente.hora == horario.hora) {

            //O tempo restante é suficiente pra proxima sessao?
            if(paciente.tRestante >= horario.minuto - paciente.minuto) {
                viveu++;
            }
        }

        //Esta horas adiantado?
        if(paciente.hora < horario.hora) {

            //O tempo restante é suficiente para a proxima sessao?
            while(paciente.tRestante >= 0) {

                //Atualizar o horario maximo de atendimento de 1 em 1 minuto
                paciente.tRestante--;
                paciente.minuto++;
                if(paciente.minuto == 60) {
                    paciente.hora++;
                    paciente.minuto = 0;
                }

                //Atingiu a proxima sessao?
                if(paciente.hora == horario.hora && paciente.minuto == horario.minuto) {
                    viveu++;
                }
            }
        }
    }

    //Resultado da previsao
    if(viveu == 0) {

        //Morreu
        return 1;

    } else {

        //Viveu
        return 0;

    }
}

//-------------------------------------------------------------------------
// filaSus.main
//-------------------------------------------------------------------------
int main() {

    //Variaveis
    int i, n, aux, mortos=0;
    Paciente paciente;
    Horario horario;

    //Qtde de pacientes
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        
        //Scanear informacoes dos pacientes
        scanf("%d", &paciente.hora);
        scanf("%d", &paciente.minuto);
        scanf("%d", &paciente.tRestante);

        //Primeiro horario
        if(i == 0) {
            horario.hora = paciente.hora;

            if(paciente.minuto<=30 && paciente.minuto>0) {
                horario.minuto = 30;
            } else {
                horario.minuto = 0;
            }
        }

        //Morre ou nao   
        aux = morreuOuNao(paciente, horario);

        //Atualizar horario de atendimento
        horario.minuto += 30;
        if(horario.minuto == 60) {
            horario.hora++;
            horario.minuto = 0;
        }

        //Quantidade de mortes
        if(aux == 1) {
            mortos++;
        }
    }

    //Saida
    printf("%d\n", mortos);

    //Retorno
    return 0;
}