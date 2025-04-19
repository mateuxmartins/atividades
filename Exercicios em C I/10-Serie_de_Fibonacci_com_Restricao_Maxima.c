/*
 **    Função : Exercício 10 - Série de Fibonacci com Restrição Máxima
 **    Autor : Mateus Martins
 **    Data  : 12/04/2025
 **    Observações: -
*/

#include <stdio.h>
#include <stdlib.h>

int fibonacci_max(int n) {

    int resultado = 0;
    int capacidade = 1;
    int *numeros = (int *)malloc(capacidade * sizeof(int));
    int contador = 2;

    numeros[0] = 0;
    numeros[1] = 1;

    int novoContador = 1;

    for(contador; contador <= n; contador++){
        
        int temp = numeros[(contador-1)] + numeros[(contador-2)];
        
        if(temp >= n){
            numeros[contador] = -1;
            contador++;
            break;
        }
        
        numeros[contador] = temp;

        novoContador++;

    }

    for(int x=0; x<contador; x++){
        printf("%d", numeros[x]);

        if(numeros[x] != -1){
            printf(", ");
        }
    }
    printf("\n");

}

int main() {
    int numero = 0;
    printf("digite um numero para ser o max: ");
    scanf("%d", &numero);

    fibonacci_max(numero);
}