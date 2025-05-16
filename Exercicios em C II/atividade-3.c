#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int nDeLinhas;
    int nDeColunas;
    int **matriz;

}InfoMatriz;

int somarTodosElementos(InfoMatriz matrix){
    int resultado = 0;

    for(int i=0; i<matrix.nDeLinhas; i++){
        for(int x=0; x<matrix.nDeColunas; x++){
            resultado += matrix.matriz[i][x];
        }
    }

    return resultado;
}

void main(){
    printf("Bem vindo ao programa matriz dinamica e structs\n");

    //define a quantidade de linhas e colunas
    int linhas, colunas;

    printf("Digite o numero de linhas:\n");
    scanf("%d", &linhas);
    printf("Digite o numero de colunas:\n");
    scanf("%d", &colunas);

    //aloca a matiz
    int **minhaMatriz = (int **)malloc(linhas * sizeof(int *));
    for(int i = 0; i < linhas; i++){
        minhaMatriz[i] = (int *)malloc(colunas * sizeof(int));
    }

    for(int x=0; x<linhas; x++){
        for(int index=0; index < colunas; index++){
            printf("Digite o valor de [%d][%d]:\n", x, index);
            scanf("%d", &minhaMatriz[x][index]);
        }
    }

    printf("Matriz completa:\n");

    for (int x = 0; x < linhas; x++) {
        for (int index = 0; index < colunas; index++) {
            printf("%d ", minhaMatriz[x][index]);
        }
        printf("\n");
    }

    InfoMatriz novaMatriz;
    novaMatriz.nDeColunas = colunas;
    novaMatriz.nDeLinhas = linhas;
    novaMatriz.matriz = minhaMatriz;

    printf("O resultado da soma e: %d", somarTodosElementos(novaMatriz));

    free(novaMatriz.matriz);

}