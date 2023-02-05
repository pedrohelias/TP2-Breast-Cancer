#include<stdlib.h>
#include<stdio.h>
#include<string.h>




// typedef struct {
//   int age;
//   int race; // 0 = white, 1 = black, 2 = other.
//   int marital; // 2 single, 0 married, 1 divorced
//   int status; // number of the status of the tumor
//   char tstage[2]; // t stage of the tumor;
//   char nstage[2]; // n stage of the tumor;
//   char sixthstage[6];
//   int tumorSize;
//   int grade;
//   char differentiate[64];
//   char aStage[16];
//   int estrogenStatus; // 1 = positive, 0 negative
//   int prostegeroneStatus; // 1 positive 0 negative
//   int regionlNodeExamined;
//   int regionlNodePositive;
//   int survivalMonths;
//   int aliveStatus; // 0 = alive, 1 = dead;
//   int sortColumn;
//   struct TumorData * left;
//   struct TumorData * right; 
// } TumorData;






FILE * carregarDatabase(char arquivo[50]){
    FILE *file;
    file = fopen(arquivo, "r");

    if(file == NULL){
        printf("Erro ao abrir o documento\n");
        return 1;
    }

    return file;

}




// TumorData tratarDados(FILE *arquivo, int *posicao){
//     TumorData arvore;

// }



int main(){

    char opcao, nomeArquivo[50];
    FILE *arquivo = NULL;
    long int posicao[962];


    while(opcao != '3'){

        printf("\n1 - Inserir Base de Dados\n");
        printf("2 - Emitir Relatório\n");
        printf("3 - Fechar Aplicação\n\n");

        scanf("%c", &opcao);
        getchar();

        switch(opcao){
            case '1':
                
                printf("\nInforme o nome do arquivo a ser lido:");
                scanf("%s", nomeArquivo);
                getchar();

                arquivo = carregarDatabase(nomeArquivo);
                
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