/*
 **    Função : Exercício 5 - Soma de Fatoriais Inversos
 **    Autor : Mateus Martins
 **    Data  : 12/04/2025
 **    Observações: -
*/

#include <stdio.h>
#include <stdlib.h>

int fatorial(int n){
	
	int resultado = n;
	
	for(int i=n; (i-1) > 0; i--){
		//printf("%d * %d\n", i, (i-1));
		resultado = resultado * (i-1);
	}
	
	return resultado;
}

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mmc(int a, int b) {
    return (a * b) / mdc(a, b);
}

int mmc_array(int arr[], int n) {
    int resultado = arr[0];
    for (int i = 1; i < n; i++) {
        resultado = mmc(resultado, arr[i]);
    }
    return resultado;
}

int soma_fatoriais_inversos(int n) {
    
    int capacidade = 0;
    int *denominadores = (int *)malloc(capacidade * sizeof(int));
    
    //pegando os denominadores com seus respectivos fatoriais
    for(int i=1; i<(n+1); i++){
        capacidade += 1;
		denominadores = (int *)realloc(denominadores, capacidade * sizeof(int));
        denominadores[(i-1)] = fatorial(i);
        printf("1/%d\n",denominadores[(i-1)]);
    }

    //pega o mmc deles
    int mmc = mmc_array(denominadores, capacidade);
    printf("mmc: %d\n", mmc);

    int capacidadeMultiplicadores = 1;
    int *multiplicadores = (int *)malloc(capacidadeMultiplicadores * sizeof(int));
    int resultado = 0;

    //calcula o denominador primeiro
    for(int d=0; d<capacidade; d++){
        int denominador = denominadores[d];
        
        //descobre por quanto tem que multiplicar para chegar ao mmc
        //e multiplica o numerador
        for(int x=1; x<=mmc; x++){
            if((denominador * x) == mmc){
                printf("%d x %d = %d\n", denominador, x, mmc);
                resultado += 1 * x;
            }
        }
    }

    printf("resultado = %d/%d\n\n", resultado, mmc);


    return 0;
}

int main() {
    int num;

    printf("Digite um número inteiro positivo: ");
    scanf("%d", &num);

   soma_fatoriais_inversos(num);

    return 0;
}