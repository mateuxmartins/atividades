#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Livros{
    char titulo[20];
    char autor[20];
    int ano;
};

void adicionar_livro(struct Livros meusLivros[], int i){

    printf("Digite o titulo:\n");
    fgets(meusLivros[i].titulo, sizeof(meusLivros[i].titulo), stdin);
    size_t tamanhoDaLinha = strlen(meusLivros[i].titulo);
    if(tamanhoDaLinha > 0 && meusLivros[i].titulo[tamanhoDaLinha - 1] == '\n'){
        meusLivros[i].titulo[tamanhoDaLinha - 1] = '\0';
    }

    printf("Digite o autor:\n");
    fgets(meusLivros[i].autor, sizeof(meusLivros[i].autor), stdin);
    tamanhoDaLinha = strlen(meusLivros[i].autor);
    if(tamanhoDaLinha > 0 && meusLivros[i].autor[tamanhoDaLinha - 1] == '\n'){
        meusLivros[i].autor[tamanhoDaLinha - 1] = '\0';
    }

    printf("Digite o ano:\n");
    scanf("%d", &meusLivros[i].ano);
    getchar();

    return;
}


void mostrar_livros(struct Livros l[], int qtd){
    printf("Aqui estao todos os livros:\n");
    printf("%-10s %-10s %-10s\n", "Título", "Autor", "Ano");
    for(int i=0; i<qtd; i++){
        printf("%-10s %-10s %-10d\n", l[i].titulo, l[i].autor, l[i].ano);
    }

    return;
}

void buscar_por_titulo(struct Livros l[], int qtd, char termo[20], int index){

    printf("\nResultado Obtido:\n");
    printf("%-10s %-10s %-10s\n", "Título", "Autor", "Ano");
    
    if(index != qtd){
        //printf("buscando index: %d\n", index);
        if(strcmp(l[index].titulo, termo) == 0){//se encontrar o termo
            printf("%-10s %-10s %-10d\n", l[index].titulo, l[index].autor, l[index].ano);
            return;
        }else{//se nao encontrar o livro mais ainda puder buscar mais
            index++;
            //printf("aumentou o index++\n");
            buscar_por_titulo(l, qtd, termo, index);
        }
    
    }else{
        printf("Nenhum resultado obtido.\n");
        return;
    }
}

int main(){
    int capacidade = 1;

    struct Livros *meusLivros;
    meusLivros = (struct Livros *) malloc(capacidade * sizeof(struct Livros));
    printf("Bem vindo ao cadastro de livros\nCadastre o primeiro livro:\n");
    adicionar_livro(meusLivros, (capacidade-1));
    
    while(1){
        printf("\n\nMENU\n1-cadastrar livro\n2-exibir todos\n3-buscar por titulo:\n");
        int opcao = 0;
        scanf("%d", &opcao);
        getchar();

        switch(opcao){
            case 1:
                capacidade++;
                meusLivros = (struct Livros *)realloc(meusLivros, capacidade * sizeof(struct Livros));
                adicionar_livro(meusLivros, (capacidade-1));
            break;
            case 2:
                mostrar_livros(meusLivros, capacidade);
            break;
            case 3:
                printf("temos %d livros registrados\n", capacidade);
                printf("Digite o titulo para buscar:\n");
                char busca[20];
                scanf("%s", &busca);
                buscar_por_titulo(meusLivros, capacidade, busca, 0);
            break;

        }
    }

    free(meusLivros);
    return 0;
}