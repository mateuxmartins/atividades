/*
 **    Função : Exercício 8 - Números de Armstrong
 **    Autor : Mateus Martins
 **    Data  : 12/04/2025
 **    Observações: -
*/

#include <stdio.h>
#include <stdlib.h>

int calcular(int contador, int numeros[]){
    int resultado = 0;
    
    for(contador; contador >= 0; contador--){
        //calcula cada valor ao cubo
        resultado += numeros[contador] * numeros[contador] * numeros[contador];
        //printf(" %d * %d * %d = %d\n ", numeros[contador], numeros[contador], numeros[contador], resultado);
    }

    return resultado;
}

int eh_numero_armstrong(int n){

    int valorInicial = n;
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

    //printf("resultado-> %d, n ->> %d\n ", resultado, n);

    if(resultado == valorInicial){
        return 1;
    }else{
        return 0;
    }

}


int main() {

    printf("Mostrando todos os numeros armstrong de 0 a 100\n");

    for(int i=1; i<=100; i++){
        if(eh_numero_armstrong(i) == 1){
            printf("%d\n", i);
        }
    }

}