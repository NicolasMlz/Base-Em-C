#include <stdlib.h>
#include <stdio.h>

//Main
int main() {
    
    //Variaveis
    int t, a, b, c, k, x=0, achou=1;

    //Scanear quantidade de casos de teste
    scanf("%d", &t);
    while(t--) {

        //Scanear coeficientes e k
        scanf("%d%d%d%d", &a, &b, &c, &k);

        //Encontrar o menor x que satisfaça a desigualdade >
        while(achou != 0) {
            
            //Verificar condicao
            if((a*x*x) + (b*x) + (c) >= k) {

                //Saida
                printf("%d\n", x);
                achou=0;
            }

            //Continuar looping
            x++;
        }

        //Zerar variaveis
        x=0; achou=1;

    }

    //Retorno do main
    return 0;

}