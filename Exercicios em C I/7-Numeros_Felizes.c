/*
 **    Função : Exercício 7 - Números felizes
 **    Autor : Mateus Martins
 **    Data  : 12/04/2025
 **    Observações: -
*/

#include <stdio.h>
#include <stdlib.h>



int calcular(int contador, int numeros[]){
    int resultado = 0;
    
    for(contador; contador >= 0; contador--){
        //tira a raiz quadrada de cada um e soma
        resultado += numeros[contador] * numeros[contador];
    }

    return resultado;
}

int processar(int n){

    int capacidade = 0;
    int *numeros = (int *)malloc(capacidade * sizeof(int));
    int contador = 0;
    int base = 0;

    while(n > 0){
        capacidade += 1;
		numeros = (int *)realloc(numeros, capacidade * sizeof(int));
        base = 10;

        //printf("%d\n", (n % base));

        numeros[contador] = n % base;
        n = n / base;

        contador++;
    }
    
    contador--; //prepara a variavel para ser usada no for
    int resultado = calcular(contador, numeros);

    return resultado;
}

int eh_numero_feliz(int n) {

    int resultado = processar(n);
    int capacidade = 1;
    int *numeros = (int *)malloc(capacidade * sizeof(int));
    int contador = 0;

    printf("resultado: %d\n", resultado);

    while(resultado > 1){

        printf("resultado: %d\n", resultado);
        resultado = processar(resultado);

        //checa se o numero ja se repetiu atraves de um array com os numeros ja 
        for(int a=0; a < contador; a++){
            if(resultado == numeros[a]){
                printf("o numero se repetiu\n");
                return 0;
            }
        }

        capacidade += 1;
		numeros = (int *)realloc(numeros, capacidade * sizeof(int));
        numeros[contador] = resultado;
        contador++;

        if(resultado == 1){
            return 1;
        }
        
    }

}

int main() {

    printf("Digite um número: ");

    int numero;

    scanf("%d", &numero);

    if(eh_numero_feliz(numero) == 1){
        printf("e um numero feliz\n");
    }else{
        printf("Nao e um numero feliz\n");
    }

}