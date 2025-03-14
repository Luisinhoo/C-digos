/*
    Jogo de Adivinhação
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> //Para as funções srand() e rand()

int main()
{
    int numAleatorio, palpite, tentativas = 0; 

    srand(time(NULL));//Inicializa o gerador de números aleatórios com o tempo atual como semente
    numAleatorio = rand() % 100 + 1;//Gera um número aleatório entre 1 e 100

    printf("<--JOGO DE ADVINHACAO-->\n");
    printf("Tente advinhar o numero entre 1 e 100\n");

    do //Ira repetir o jogo até o jogador acertar o número pensado
    {
        printf("Digite o seu palpite: ");
        scanf("%d", &palpite);
        tentativas++;

        if(palpite > numAleatorio) //Se o chute for muito alto
        {
            printf("Chutou muito alto. Tente novamente, mas com numeros menores!\n");
        }

        else if(palpite < numAleatorio) //Se o chute for muito baixo
        {
            printf("Chutou muito baixo. Tente novamente, com com numeros maiores!\n");
        }

        else //Se for o palpite correto
        {
            printf("Parabens!Voce chutou o numero %d e acertou!!\n", numAleatorio);
        }
        
    } while(palpite != numAleatorio); //Vai repetir o looping enquanto o palpite for diferente do número aleatório, 
    
    return 0;
}