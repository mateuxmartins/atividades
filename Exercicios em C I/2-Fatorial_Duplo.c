/*
 **    Função : Exercício 2 - Fatorial Duplo
 **    Autor : Mateus Martins
 **    Data  : 07/04/2025
 **    Observações: -
*/

#include <stdio.h>

//1) escreva a funcao que retorna o fatorial duplo de n
int fatorial_duplo(int n){
	
	int resultado = n;
	int dim = 2;
	
	while(1){
		
		int nextNumber = n - dim;
		if(nextNumber == 0){
			nextNumber = 1;
		}
		
		resultado = resultado * nextNumber;
		//printf("%d * %d = \n", resultado, nextNumber);
		
		if(nextNumber == 1){
			break;
		}
		
		dim += 2;
	}

	return resultado;

}

int fatorial(int n){
	
	int resultado = n;
	
	for(int i=n; (i-1) > 0; i--){
		//printf("%d * %d\n", i, (i-1));
		resultado = resultado * (i-1);
	}
	
	return resultado;
}

int main(){
	
	//2) monte uma tabela usando 2 até 20 mostrando de forma tabulada o resultado do fatorial duplo para cada número
	//Aproveite e, na mesma tabela mostre o resultado do fatorial normal

	printf("%-10s\t %-10s\t %-10s\t \n", "valor", "fatorial", "fatorial duplo");
	
	int fatoriais_normais[20];
	int fatoriais_duplos[20];
	int v = 0;
	
	for(int i=2; i < 21; i++){
		int normal = fatorial(i);
		int duplo = fatorial_duplo(i);
		
		fatoriais_normais[v] = normal;
		fatoriais_duplos[v] = duplo;
		
		printf("%-10d\t %-10d\t %-10d\t \n", i, normal, duplo);
		v++;
	}
	
	printf("\n\n");
	
	//3) monte uma nova tabela com uma quarta coluna mostrando a diferença entre o fatorial normal e o fatorial duplo
	
	printf("%-10s\t %-10s\t %-10s\t %-10s\t \n", "valor", "fatorial", "fatorial duplo", "diferenca");
	
	for(int i=2; i < 21; i++){
		int normal = fatorial(i);
		int duplo = fatorial_duplo(i);
		int diferenca  = normal - duplo;
		 
		printf("%-10d\t %-10d\t %-10d\t %-10d\t \n", i, normal, duplo, diferenca);
	}
	
	return 0;
}
