/* 
    Calculadora Virtual
*/
#include <stdio.h>

int main() 
{
    char op;
    int num, resultado, quantidade, i;

    printf("<--CALCULADORA VIRTUAL-->\n");
    printf("+ --> Adição\n");
    printf("- --> Subtração\n");
    printf("* --> Multiplicação\n");
    printf("/ --> Divisão\n");
    printf("Escolha qual tipo de operação deseja fazer: ");
    scanf(" %c", &op);
    getchar();

    switch(op) 
    {
        case '+':
            resultado = 0;
            printf("Quantos números deseja somar? ");
            scanf("%d", &quantidade);
            for(i = 0; i < quantidade; i++)
            {
                printf("Digite o número %d: ", i + 1);
                scanf("%d", &num);
                resultado += num;
            }
            printf("A soma dos números é: %d\n", resultado);
            break;
        case '-':
            printf("Quantos números deseja subtrair? ");
            scanf("%d", &quantidade);
            if(quantidade > 0) 
            {
                printf("Digite o número 1: ");
                scanf("%d", &resultado);
                for(i = 1; i < quantidade; i++)
                {
                    printf("Digite o número %d: ", i + 1);
                    scanf("%d", &num);
                    resultado -= num; //Subtrai o número atual de resultado
                }
                printf("O resultado da subtração é: %d\n", resultado);
            }
            break;
        case '*':
            resultado = 1;
            printf("Quantos números deseja multiplicar? ");
            scanf("%d", &quantidade);
            for(i = 0; i < quantidade; i++) 
            {
                printf("Digite o número %d: ", i + 1);
                scanf("%d", &num);
                resultado *= num;
            }
            printf("O resultado da multiplicação é: %d\n", resultado);
            break;
        case '/':
            printf("Quantos números deseja dividir? ");
            scanf("%d", &quantidade);
            if(quantidade > 0) 
            {
                printf("Digite o número 1: ");
                scanf("%d", &resultado);
                for(i = 1; i < quantidade; i++)
                {
                    printf("Digite o número %d: ", i + 1);
                    scanf("%d", &num);
                    if(num != 0) 
                    {
                        resultado /= num; //Divide resultado pelo número atual
                    } 
                    else
                    {
                        printf("Erro: divisão por zero!\n");
                        return 1;
                    }
                }
                printf("O resultado da divisão é: %d\n", resultado);
            }
            break;
        default:
            printf("Operação inválida!\n");
            break;
    }

    return 0;
}