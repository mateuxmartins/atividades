/*
 **    Função : Exercício 4 - Número Automórfico
 **    Autor : Mateus Martins
 **    Data  : 11/04/2025
 **    Observações: -
*/

#include <stdio.h>
#include <stdlib.h>

int gerarValor(int n){
	
	int resultado = 10;
	int contador = 0;

	while(n  > 0){
		contador++;
		n = n / 10;
	}
	
	
	for(int i=0; i < (contador-1); i++){
		resultado = resultado * 10;
	}
	

	return resultado;
}

//1)Escreva uma função em C chamada verificar_numero_automorfico que verifica se um dado número inteiro n é automórfico ou não
int verificar_numero_automorfico(int n){
	int resultado = n * n;

	int multiplicador = gerarValor(n);
	int ultimoNumero = resultado % multiplicador;
	
	if((ultimoNumero) == n ){
		return 1;
	}else{
		return 0;
	}
	
}

//3)criar uma função em C chamada eh_numero_automorfico que recebe um número inteiro positivo como entrada e verifica se esse número é um número automórfico ou não
int eh_numero_automorfico(int n){
	int capacidade = 2;
	int *dados = (int *)malloc(capacidade * sizeof(int));

	if(n < 0){
		printf("e necessario um numero positivo\n");
		return 0;
	}
	
	int contador = 0;

	for(int i=2; i <= n; i++){
		if(verificar_numero_automorfico(i) == 1){
			capacidade *= 2;
			dados = (int *)realloc(dados, capacidade * sizeof(int));
			dados[contador] = i;
			printf("o numero %d e automorfico\n", dados[contador]);
			contador++;
		}
	}
	
}


int main(){
	
	int capacidade = 2;
	int *dados = (int *)malloc(capacidade * sizeof(int));

	//2)Usando a função mostre todos os números automórficos entre 2 e 1000. Guarde-os em um array usando alocação dinâmica
	int contador = 0;
	for(int i=2; i < 1001; i++){

		if(verificar_numero_automorfico(i) == 1){

			capacidade *= 2;
			dados = (int *)realloc(dados, capacidade * sizeof(int));

			printf("%d e automórfico\n", i);
			dados[contador] = i;
			contador++;
		}

	}

	printf("primeiro valor armazenado no array: %d\n", dados[0]);
	
	int valorDoUser = 0;
	printf("agora vamos verificar um numero de 2 ao valor escolhido pelo usuario: \n");
	printf("digite o numero:\n");
	scanf("%d", &valorDoUser);

	eh_numero_automorfico(valorDoUser);
	
	return 0;
}
