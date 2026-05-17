#include <stdio.h>

int main() {
    double operando2, resultadoAcumulado;
    char operador;
    int estadoAtivo = 1;

    printf("=== Calculadora Analitica Fundamental ===\n");
    printf("Instrucao: Utilize os operadores (+, -, *, /) ou 's' para encerrar o ciclo.\n\n");
    
    // Captura do valor basilar para iniciar a cadeia de operações
    printf("Insira o valor inicial: ");
    scanf("%lf", &resultadoAcumulado);

    // Ciclo de execução contínua
    while (estadoAtivo) {
        printf("\nOperador: ");
        /* O espaco antes de %c e estritamente necessario para ignorar 
           caracteres de quebra de linha residuais na memoria de entrada */
        scanf(" %c", &operador); 

        // Verificacao imediata da condicao de encerramento
        if (operador == 's' || operador == 'S') {
            estadoAtivo = 0;
            continue;
        }

        // Captura do segundo elemento da equacao
        printf("Insira o proximo valor: ");
        scanf("%lf", &operando2);

        // Processamento da arvore de decisao aritmetica
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
                // Protecao contra indeterminacao matematica
                if (operando2 == 0) {
                    printf("Erro Logico: A divisao por zero e matematicamente indefinida.\n");
                    // O resultadoAcumulado permanece inalterado
                } else {
                    resultadoAcumulado /= operando2;
                }
                break;
            default:
                printf("Erro de Sintaxe: Operador nao reconhecido pelo sistema.\n");
                break;
        }

        // Exposicao factual do estado atual se a operacao for valida
        if (operador == '+' || operador == '-' || operador == '*' || (operador == '/' && operando2 != 0)) {
            printf(">> Resultado Atual: %.4lf\n", resultadoAcumulado);
        }
    }

    // Exibicao terminal após a interrupcao do ciclo
    printf("\nProcesso encerrado. Valor final retido na memoria: %.4lf\n", resultadoAcumulado);
    
    return 0;
}