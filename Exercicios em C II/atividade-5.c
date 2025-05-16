#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    float preco;
    int quantidade;

}Produto;

int cadastrarProdutos(Produto meusProdutos[], int qtd){

    printf("Digite o nome do produto:\n");
    scanf("%s", &meusProdutos[qtd].nome);

    printf("Digite o preco:\n");
    scanf("%f", &meusProdutos[qtd].preco);

    printf("Digite a quantidade:\n");
    scanf("%d", &meusProdutos[qtd].quantidade);

    return 0;
}

void listarProdutos(Produto meusProdutos[],int index, int qtd){
    
    if(meusProdutos[index].quantidade < 5){
        printf("%-20s %-20f %-20d\n", meusProdutos[index].nome, meusProdutos[index].preco, meusProdutos[index].quantidade);
    }else{
        return;
    }

    index++;
    listarProdutos(meusProdutos, index, qtd);
}

float calcularValorEmEstoque(Produto meusProdutos[], int qtd){
    float total = 0;
    for(int i=0; i<qtd; i++){
        total += meusProdutos[i].preco * meusProdutos[i].quantidade;
    }

    return total;
}

void main(){
    printf("Bem vindo ao sistema de produtos\n");
    int qtd = 0;
    Produto *meusProdutos = (Produto *)malloc( qtd * sizeof(Produto));

    while(1){
        printf("\n\nMENU:\n1-Cadastrar Produto\n2-Listar todos os produtos com estoque menor que 5\n3-Calcular valor total em estoque\nDigite a opcao escolhida:\n");
        int opcao = 0;
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case 1:
            qtd++;
            meusProdutos = (Produto *)realloc(meusProdutos, qtd * sizeof(Produto));
            cadastrarProdutos(meusProdutos, (qtd-1));
            break;
        case 2:
            printf("%-20s %-20s %-20s\n","Nome", "Preco","Quantidade");
            listarProdutos(meusProdutos, 0, qtd);
        break;
        case 3:
            printf("O valor total em estoque e: %f", calcularValorEmEstoque(meusProdutos, qtd));
        break;
        default:
            break;
        }
    }

    free(meusProdutos);
    
}