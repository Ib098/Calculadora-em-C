#include <stdio.h>
#include <math.h> /* Inclusao estrita para funcoes nao lineares */

int main() {
    double operando2, resultadoAcumulado;
    char operador;
    int estadoAtivo = 1;

    printf("=== Calculadora Analitica Cientifica ===\n");
    printf("Operadores Binarios: +, -, *, /, ^ (Potenciacao)\n");
    printf("Operadores Unarios: r (Raiz Quadrada do valor em memoria)\n");
    printf("Comando de Interrupcao: s (Sair do ciclo)\n\n");
    
    printf("Insira o valor inicial: ");
    scanf("%lf", &resultadoAcumulado);

    while (estadoAtivo) {
        printf("\nOperador Atual: ");
        scanf(" %c", &operador); 

        // 1. Verificacao da condicao de parada
        if (operador == 's' || operador == 'S') {
            estadoAtivo = 0;
            continue; // Forca a saida do laco
        }

        // 2. Isolamento do Operador Unario (Raiz Quadrada)
        if (operador == 'r' || operador == 'R') {
            if (resultadoAcumulado < 0) {
                printf("Erro Matematico: Extracao de raiz quadrada de base negativa no conjunto dos Reais.\n");
            } else {
                resultadoAcumulado = sqrt(resultadoAcumulado);
                printf(">> Resultado Atual: %.6lf\n", resultadoAcumulado);
            }
            continue; // Retorna ao inicio do ciclo sem pedir o 'operando2'
        }

        // 3. Captura condicional para Operadores Binarios
        printf("Insira o proximo valor: ");
        scanf("%lf", &operando2);

        // 4. Processamento da arvore de decisao
        switch (operador) {
            case '+': 
                resultadoAcumulado += operando2; 
                break;
            case '-': 
                resultadoAcumulado -= operando2; 
                break;
            case '*': 
                resultadoAcumulado *= operando2; 
                break;
            case '/':
                if (operando2 == 0) {
                    printf("Erro Logico: Divisao por zero e matematicamente indefinida.\n");
                    continue;
                } else {
                    resultadoAcumulado /= operando2;
                }
                break;
            case '^':
                // Funcao pow(base, expoente) da biblioteca math.h
                resultadoAcumulado = pow(resultadoAcumulado, operando2);
                break;
            default:
                printf("Erro de Sintaxe: Operador nao reconhecido pelo sistema.\n");
                continue;
        }

        printf(">> Resultado Atual: %.6lf\n", resultadoAcumulado);
    }

    printf("\nProcesso encerrado. Valor final retido na memoria: %.6lf\n", resultadoAcumulado);
    
    return 0;
}