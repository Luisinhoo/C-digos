/*
    Gerador de números aleatórios
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Para a função srand() e rand()

int main()
{
    int limiteInferior, limiteSuperior, numAleatorio;

    printf("Digite um limite inferior: ");
    scanf("%d", &limiteInferior);

    printf("Digite um limite superior: ");
    scanf("%d", &limiteSuperior);

    srand(time(NULL)); //Inicia o gerador de números aleatórios com uma semente baseada no tempo atual
    //Ou seja, garante aparecer números aleatórios sempre que o programa for rodado.
    numAleatorio = (rand() % (limiteSuperior - limiteInferior +1)) + limiteInferior; //Gera um número aleatório dentro do intervalo [limiteInferior, limiteSuperior]

    printf("Numero aleatorio: %d\n", numAleatorio);
    return 0;
}