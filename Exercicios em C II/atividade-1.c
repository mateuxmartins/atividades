#include <stdio.h>
#include <string.h>

//um struct criado para armazenar as informacoes
struct Alunos{
    char nome[20];
    int idade;
    int nota;
};

//funcao que calcula a media dos alunos cadastrados
float calcularMedia(int todasAsNotas, int quantidadeDeAlunos){
    float media = (todasAsNotas / quantidadeDeAlunos);

    return media;
}

//funcao que realiza o cadastro dos alunos
int cadastro(struct Alunos aluno[], int quantidadeTotalDeAlunos){
    int quantidadeDeAlunos = 0;
    int indexNovo = quantidadeTotalDeAlunos;

    printf("Digite quantos alunos voce quer cadastrar:\n");
    scanf("%d", &quantidadeDeAlunos);
    getchar();

    //armazena as informacoes no struct
    for(int i=0; i<quantidadeDeAlunos; i++){
        printf("Digite o nome do aluno:\n");
        fgets(aluno[indexNovo].nome, sizeof(aluno[indexNovo].nome), stdin);

        //remove o caractere deixado pelo fgets
        size_t tamanhoDaLinha = strlen(aluno[indexNovo].nome);
        if(tamanhoDaLinha > 0 && aluno[indexNovo].nome[tamanhoDaLinha - 1] == '\n'){
            aluno[indexNovo].nome[tamanhoDaLinha - 1] = '\0';
        }

        printf("Digite a idade do aluno:\n");
        scanf("%d", &aluno[indexNovo].idade);
        printf("Digite a nota do aluno:\n");
        scanf("%d", &aluno[indexNovo].nota);

        getchar();
        indexNovo++;
    }

    return quantidadeDeAlunos;
}

int exibir(struct Alunos aluno[], int quantidadeDeAlunos){
    float todasAsNotas = 0;

    //mostra uma tabela com os alunos e suas informacoes
    printf("\n\nAlunos cadastrados: %d\n", quantidadeDeAlunos);
    printf("%-10s %-10s %-10s\n", "Nome", "Idade", "Nota");
    for(int a=0; a<quantidadeDeAlunos; a++){
        printf("%-10s %-10d %-10d\n", aluno[a].nome, aluno[a].idade, aluno[a].nota);
    
        todasAsNotas += aluno[a].nota;
    }

    //exibe a media
    printf("Media de notas: %f\n\n", calcularMedia(todasAsNotas, quantidadeDeAlunos));
}


int menu(struct Alunos aluno[]){
    
    int quantidadeDeitems = 0;
    int opcao = 0;
    
    while(1){
        printf("Bem vindo ao programa de cadastro de alunos:\n");
        printf("Escolha uma opcao:\n1-Cadastrar Aluno\n2-Exibir Alunos e a Media\n");
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
                quantidadeDeitems += cadastro(aluno, quantidadeDeitems);
            break;
            case 2:
                exibir(aluno, quantidadeDeitems);
            break;
        }
    }


}

int main(){

    struct Alunos cadastroDeAlunos[5];

    menu(cadastroDeAlunos);


    return 0;
}