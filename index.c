#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct {
  int age;
  int tumorSize;
}, TumorData;

int main(){

    char opcao, nomeArquivo[50];
    FILE *arquivo = NULL;
    long int posicao[962];
    TumorData* cache;
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
                if(arquivo == NULL){
                    printf("Insira um arquivo válido, ocorreu um erro ao tentar ler o arquivo\n\n");
                    break;
                }
                char line[1024];
                int dataSize = 1;
                while (fgets(line, 1024, arquivo)){
                   TumorData *new;
                   new = realloc(data,dataSize * sizeof *cache);
                   if (new == NULL) {
                       perror("realloc");
                       free(cache);
                       return 2;
                   }
                   cache = new;
                   int index = dataSize - 1;
                   int cnt = fscanf(fp,"%d,%d", &cache[index].age, &data[index].tumorSize);
                   dataSize++;
                   if (cnt == EOF) break;
                }
                break;

            case '2':
                if(arquivo == NULL){
                    printf("\nArquivo vazio\n\n");
                    break;
                }
                if(cache == NULL){
                    printf("\nArquivo vazio\n\n");
                    break;
                }
                
                break;

            case '3':
                free(cache);
                return 0;
        }
    }

    return 0;
}

int isInteger(char[] chars){
int length = sizeof(chars)/sizeof(char);
for(int i = 0; i < length; i++){
  char c = chars[i];
  if(c > 57 && c < 48){
     return 0;
  }
}
return 1;
}