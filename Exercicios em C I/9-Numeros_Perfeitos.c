/*
 **    Função : Exercício 9 - Números Perfeitos
 **    Autor : Mateus Martins
 **    Data  : 12/04/2025
 **    Observações: -
*/

#include <stdio.h>
#include <stdlib.h>

int eh_numero_perfeito(int n) {

    int resultado = 0;
    int capacidade = 1;
    int *numeros = (int *)malloc(capacidade * sizeof(int));
    int contador = 0;

    //pega os divisores
    for(int x=1; x<n; x++){
        
        if((n % x) == 0){
            capacidade += 1;
		    numeros = (int *)realloc(numeros, capacidade * sizeof(int));
            numeros[contador] = x;
            contador++;
        }

        
    }

    //soma os divisores
    for(int x=0; x<contador; x++){
        //printf("%d", numeros[x]);
        resultado += numeros[x];
    }
    
    if(resultado == n){
        return 1;
    }else{
        return 0;
    }

}

int main() {

    printf("Numeros perfeitos de 1 a 100000: ");

    for(int x=1; x<=100000; x++){
        if(eh_numero_perfeito(x) == 1){
            printf("%d\n", x);
        }
    }
}