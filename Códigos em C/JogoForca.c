/*
    Jogo da Forca
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //Para o uso da função time(NULL)
#include <ctype.h> //Para o uso da função tolower()

#define MAX_TENTATIVAS 6

char *gerarPalavra(int dificuldade);
void exibirForca(int erros);

int main()
{
    int tentativasRestantes = MAX_TENTATIVAS;
    int i;
    int erros = 0;
    char letrasUsadas[26];
    int numLetrasUsadas = 0;
    int dificuldade;
    int letraJaUsada = 0;
    int tamanhoPalavra;
    char palavraAdivinhada[20];
    char palpite;
    printf("Escolha a dificuldade:\n");
    printf("1 - Facil\n");
    printf("2 - Medio\n");
    printf("3 - Dificil\n");
    scanf("%d", &dificuldade);

    char *palavraSecreta = gerarPalavra(dificuldade); //Gera a palavra aleatória
    if(palavraSecreta == NULL)
    {
        printf("Erro ao gerar palavra!\n");
        return 1;
    }

    tamanhoPalavra = strlen(palavraSecreta);//Calcula o comprimento da palavra secreta e armazena na variável tamanhoPalavra
    memset(palavraAdivinhada, '_', tamanhoPalavra);//Inicializa o array palavraAdivinhada com underscores para representar as letras não adivinhadas
    palavraAdivinhada[tamanhoPalavra] = '\0';//Adiciona o caractere \0 no final da string palavraAdivinhada para indicar o término da string

    printf("Bem-vindo ao Jogo da Forca!\n");

    while(tentativasRestantes > 0 && strcmp(palavraAdivinhada, palavraSecreta) != 0)
    {
        printf("\nPalavra: %s\n", palavraAdivinhada);
        printf("Tentativas restantes: %d\n", tentativasRestantes);
        printf("Letras usadas: ");
        for(i = 0; i < numLetrasUsadas; i++)
        {
            printf("%c ", letrasUsadas[i]);
        }
        printf("\n");

        exibirForca(erros); //Exibe o desenho da forca

        printf("Digite uma letra: ");
        scanf(" %c", &palpite);
        palpite = tolower(palpite);

        for(i = 0; i < numLetrasUsadas; i++)
        {
            if(letrasUsadas[i] == palpite)
            {
                letraJaUsada = 1;
                break;
            }
        }

        if(letraJaUsada)
        {
            printf("Você já usou essa letra. Tente outra.\n");
            continue;
        }

        letrasUsadas[numLetrasUsadas++] = palpite;

        int letraEncontrada = 0;
        for(int i = 0; i < tamanhoPalavra; i++)
        {
            if(palavraSecreta[i] == palpite)
            {
                palavraAdivinhada[i] = palpite;
                letraEncontrada = 1;
            }
        }

        if(!letraEncontrada)
        {
            tentativasRestantes--;
            erros++; //Incrementa o número de erros
            printf("Letra incorreta!\n");
        }
    }

    exibirForca(erros); //Exibe a forca final

    if(strcmp(palavraAdivinhada, palavraSecreta) == 0)
    {
        printf("\nParabéns! Você adivinhou a palavra: %s\n", palavraSecreta);
    }
    else
    {
        printf("\nVocê perdeu! A palavra era: %s\n", palavraSecreta);
    }

    free(palavraSecreta); //Libera a memória alocada para a palavra

    return 0;
}

//Função para gerar uma palavra aleatória com base na dificuldade
char *gerarPalavra(int dificuldade)
{
    char consoantes[] = "bcdfghjklmnpqrstvwxyz";
    char vogais[] = "aeiou";
    int numConsoantes = strlen(consoantes);
    int numVogais = strlen(vogais);
    int comprimento;
    int i;

    if(dificuldade == 1)//Fácil
    {
        comprimento = rand() % 4 + 3; //3 a 6 letras
    }
    else if(dificuldade == 2)//Médio
    {
        comprimento = rand() % 5 + 6; //6 a 10 letras
    }
    else//Difícil
    {
        comprimento = rand() % 6 + 10; //10 a 15 letras
    }

    char *palavra = (char *)malloc((comprimento + 1) * sizeof(char)); //Aloca memória para a palavra
    if(palavra == NULL)
    {
        return NULL; //Falha na alocação de memória
    }

    for(i = 0; i < comprimento; i++)
    {
        if(i % 2 == 0)//Consoante
        {
            palavra[i] = consoantes[rand() % numConsoantes];
        }
        else//Vogal
        {
            palavra[i] = vogais[rand() % numVogais];
        }
    }
    palavra[comprimento] = '\0'; //Adiciona o caractere nulo

    return palavra;
}

//Função para exibir o desenho da forca com base no número de erros
void exibirForca(int erros)
{
    printf("  _______\n");
    printf("  |     |\n");

    if(erros > 0)
    {
        printf("  O     |\n");
    }
    else
    {
        printf("        |\n");
    }

    if(erros == 2)
    {
        printf("  |     |\n");
    }
    else if(erros == 3)
    {
        printf(" \\|     |\n");
    }
    else if(erros >= 4)
    {
        printf(" \\|/    |\n");
    }
    else
    {
        printf("        |\n");
    }

    if(erros == 5)
    {
        printf(" /      |\n");
    }
    else if(erros >= 6)
    {
        printf(" / \\    |\n");
    }
    else
    {
        printf("        |\n");
    }

    printf("        |\n");
    printf("________|_\n");
}
