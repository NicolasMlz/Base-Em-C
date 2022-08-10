#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Main
int main() {
    
    //Variaveis
    int n, i, tamanho, vogais=0;
    char frase[10000];

    //Scanear quantidade de casos de teste
    scanf("%d", &n);
    while(n--) {

        //Scanear frase
        scanf(" %[^\n]", frase);

        //Percorrer frase
        tamanho = strlen(frase);
        for(i=0; i<tamanho; i++) {

            //Contar vogais
            if((frase[i] == 'A' || frase[i] == 'a') || (frase[i] == 'E' || frase[i] == 'e') ||
            (frase[i] == 'I' || frase[i] == 'i') || (frase[i] == 'O' || frase[i] == 'o') || 
            (frase[i] == 'U' || frase[i] == 'u')) {    
                
                //Contador de vogais
                vogais++;
            }  
        }

        //Saida
        printf("%d\n", vogais);

        //Reiniciar looping
        vogais=0;
    }

    //Retorno do main
    return 0;

}