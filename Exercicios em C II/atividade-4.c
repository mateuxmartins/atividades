#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    char telefone[12];
    int idade;

}Agenda;

int cadastrarContatos(Agenda agendaUsada[], int qtd){

    printf("Digite o nome do contato:\n");
    scanf("%s", &agendaUsada[qtd].nome);

    printf("Digite o telefone:\n");
    scanf("%s", &agendaUsada[qtd].telefone);

    printf("Digite a idade:\n");
    scanf("%d", &agendaUsada[qtd].idade);

    return 0;
}

void listarContatos(Agenda agendaUsada[],int index, int qtd){
    
    if(index < qtd){
        printf("%-20s %-20s %-20d\n", agendaUsada[index].nome, agendaUsada[index].telefone, agendaUsada[index].idade);
    }else{
        return;
    }

    index++;
    listarContatos(agendaUsada, index, qtd);
}

void main(){
    printf("Bem vindo a agenda de contatos\n");
    int qtd = 0;
    Agenda *minhaAgenda = (Agenda *)malloc( qtd * sizeof(Agenda));

    while(1){
        printf("MENU:\n1-Cadastrar Contato\n2-Listar todos os contatos\nDigite a opcao escolhida:\n");
        int opcao = 0;
        scanf("%d", &opcao);
        
        switch (opcao)
        {
        case 1:
            qtd++;
            minhaAgenda = (Agenda *)realloc(minhaAgenda, qtd * sizeof(Agenda));
            cadastrarContatos(minhaAgenda, (qtd-1));
            break;
        case 2:
            printf("%-20s %-20s %-20s\n","Nome", "Telefone","Idade");
            listarContatos(minhaAgenda, 0, qtd);
        break;
        default:
            break;
        }
    }

    free(minhaAgenda);
    
}
