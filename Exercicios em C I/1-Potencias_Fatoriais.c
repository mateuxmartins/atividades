/*
 **    Função : Exercício 1 - Potências fatoriais
 **    Autor : Mateus Martins
 **    Data  : 05/04/2025
 **    Observações: -
*/

#include <stdio.h>

//1) escreva a funcao crescente
int potencia_fatorial_crescente(int x, int n){
	
	int resultado = x;
	
	for(int i=1; i < n; i++){
		//printf("%d * %d = ", resultado, (x+i));
		resultado = resultado * (x+i);
		//printf("%d \n", resultado);
	}

	return resultado;

}

//2) escreva a funcao decrescente
int potencia_fatorial_decrescente(int x, int n){
	
	int resultado = x;
	
	for(int i=1; i < n; i++){
		//printf("%d * %d = ", resultado, (x-i));
		resultado = resultado * (x-i);
		//printf("%d\n", resultado);
	}

	return resultado;
}

int main(){
	printf("Calculadora de potencia fatorial crescente e decrescente\n");
	
	
	//3)utilizando funcoes escritas em exemplos
	printf("EXEMPLOS DE USO:\n");
	printf("---------------------------------------\n");
	printf("- Calculando o fatorial crescente de 5^3\n");
    printf("resultado = %d\n\n", potencia_fatorial_crescente(5, 3));
    
    printf("- Calculando o fatorial decrescente de 5^3\n");
    printf("resultado = %d\n\n", potencia_fatorial_decrescente(5, 3));
    
    printf("---------------------------------------\n");
    
    printf("- Calculando o fatorial crescente de 6^5\n");
    printf("resultado = %d\n\n", potencia_fatorial_crescente(6, 5));
    
    printf("- Calculando o fatorial decrescente de 6^5\n");
    printf("resultado = %d\n\n", potencia_fatorial_decrescente(6, 5));
    
    printf("---------------------------------------\n");
    
	//4) monte uma tabela
	
	int myX = 10;
	printf("CRIANDO TABELA COM X=%d:\n", myX);
	printf("%-11s\t %-11s\t %-11s\t %-11s\t \n", "Base", "Expoente", "Crescente", "Decrescente");
	for(int n=2; n < 11; n++){
	    printf("%-11d\t %-11d\t %-11d\t %-11d\t \n", myX, n, potencia_fatorial_crescente(myX, n), potencia_fatorial_decrescente(myX, n));
	}
	
	printf("---------------------------------------\n");
	
	printf("CRIANDO TABELA QUE VARIA O X E N DE 2 ATE 10 \n");
	
	printf("%-11s\t %-11s\t %-11s\t %-11s\t \n", "Base", "Expoente", "Crescente", "Decrescente");
	for(int n=2; n < 11; n++){
	    printf("%-11d\t %-11d\t %-11d\t %-11d\t \n", n, n, potencia_fatorial_crescente(myX, n), potencia_fatorial_decrescente(myX, n));
	}
	
	return 0;
}
