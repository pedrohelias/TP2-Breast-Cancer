#include<stdlib.h>
#include<stdio.h>
#include<string.h>


int main(){

    char opcao, nomeArquivo[50];
    FILE *arquivo = NULL;
    long int posicao[962];


    while(opcao != '3'){

        printf("\n1 - Carregar Arquivo de Dados\n");
        printf("2 - Emitir Relatório\n");
        printf("3 - Fechar Aplicação\n\n");

        scanf("%c", &opcao);
        getchar();

        switch(opcao){
            case '1':
                
                printf("\nInforme o nome do arquivo a ser lido:");
                scanf("%s", nomeArquivo);
                getchar();

                arquivo = fopen(nomeArquivo, "r");
                if(arquivo == NULL ){
                    printf("Insira um arquivo válido, ocorreu um erro ao tentar ler o arquivo\n\n");
                    break;
                }

                
                break;

            case '2':
                if(arquivo == NULL){
                    printf("\nArquivo vazio\n\n");
                    break;
                }

                
                break;

            case '3':
                return 0;
        }
    }

    return 0;
}