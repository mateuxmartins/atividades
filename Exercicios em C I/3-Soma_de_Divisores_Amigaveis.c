/*
 **    Fun��o : Exerc�cio 3 - Soma de Divisores Amig�veis
 **    Autor : Mateus Martins
 **    Data  : 08/04/2025
 **    Observa��es: -
*/

#include <stdio.h>

int calcula(int n, int log){
	if(log == 1){
		printf("Divisores de %d: \n ", n);	
	}
	int total = 0;
	
	for(int i = 1; i < n; i++){
		int resto = n % i;
		if(resto == 0){
			if(log == 1){
				printf("%d \n ", i);
			}
			total += i;
		}
		
	}
	if(log == 1){
		printf("O total e: %d\n\n", total);	
	}
	
	return total;
}

//1)  escreva uma fun��o em C que verifica se dois n�meros s�o amig�veis. 
//Esta fun��o deve exibir na tela os divisores de ambos os n�meros, assim como a soma desses divisores
int verifica(int n1, int n2, int log){
	
	int resultado1 = calcula(n1, log);
	int resultado2 = calcula(n2, log);
	
	if(log == 1){
		printf("----------------------\n");
	}	
	
	if(resultado1 == n2 && resultado2 == n1){
		printf("%d e %d Sao numeros amigaveis\n", n1, n2);
		
	}else{
		if(log == 1){
			printf("%d e %d Nao sao numeros amigaveis\n", n1, n2);	
		}
	}
	
	return 0;

}

//2)  escreva outra fun��o que verifica todos os pares de n�meros amig�veis at� 
//um determinado valor n que ser� fornecido pelo usu�rio
int verificacaoUsuario(int n){
	for(int i=1; i < n; i++){
		for(int m=1; m < n; m++){
			if(i != m){
				verifica(i, m, 0);	
			}
		}
	}
}

int main(){
	
	verifica(220, 284, 1);
	
	printf("Agora digite um valor limite para verificar todos os numeros amigaveis ate ele:\n");
	int input = 0;
	scanf("%d", &input);
	verificacaoUsuario(input);
	
	return 0;
}
