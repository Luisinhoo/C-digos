/*
    Conversor de Temperatura
*/
#include <stdio.h>

int main()
{
    float temperatura, resultado;
    char tipo;

    printf("Digite a temperatura: ");
    scanf("%f", &temperatura);

    printf("Escolha para qual tipo de temperatura deseja converter (Fahrenheit(F)/Celcius(C)): ");
    scanf(" %c", &tipo); //Espaço antes de %c para consumir qualquer espaço em branco no buffer
    //getchar(); //Limpa o buffer


    if(tipo == 'F' || tipo == 'f')
    {
        resultado = (temperatura * 9 / 5) + 32; //Converte Celcius para Fahrenheit
        printf("%.2fCelcius = %.2fFahrenheit\n", temperatura, resultado);
    } 

    else if(tipo == 'C' || tipo == 'c')
    {
        resultado = (temperatura - 32) * 5 / 9; //Converte de Fahrenheit para Celcius
        printf("%.2fFahrenheit = %.2fCelcius\n", temperatura, resultado);
    }

    else
    {
        printf("Tipo invalido!!\nTente Novamente!!\n");
    }
    return 0;
}