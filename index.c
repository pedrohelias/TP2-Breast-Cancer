#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct {
  int age;
  int race; // 0 = white, 1 = black, 2 = other.
  int marital; // 0 single, 1 married, 2 divorced
  int status; // number of the status of the tumor
  char tstage[2]; // t stage of the tumor;
  char nstage[2]; // n stage of the tumor;
  char sixthstage[6];
  int tumorSize;
  int grade;
  char differentiate[64];
  char aStage[16];
  int estrogenStatus; // 1 = positive, 0 negative
  int prostegeroneStatus; // 1 positive 0 negative
  int regionlNodeExamined;
  int regionlNodePositive;
  int survivalMonths;
  int aliveStatus; // 0 = alive, 1 = dead;
  int sortColumn;
}, TumorData;

int main(){
    char opcao, nomeArquivo[50];
    FILE *arquivo = NULL;
    long int posicao[962];
    TumorData* cache;
    int dataSize = 1;
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
                char race[16];
                char marital[32];
                char estrogenStatus[16];
                char prostegeroneStatus[16];
                char status[5];
                while (fgets(line, 1024, arquivo)){
                   TumorData *new;
                   new = realloc(data,dataSize * sizeof *cache);
                   if (new == NULL){
                       perror("realloc");
                       free(cache);
                       return 2;
                   }
                   cache = new;

                   int index = dataSize - 1;

                   int cnt = fscanf(fp,"%d,%s,%s,%s,%s,%d,%s,%s,%d,%d,%d,%s", &cache[index].age,
                    &race, &marital, &cache[index].tstage, &cache[index].nstage,
                    &cache[index].sixthstage,&cache[index].grade, &cache[index].aStage,
                    &cache[index].tumorSize, &estrogenStatus, &prostegeroneStatus,
                    &cache[index].regionlNodeExamined, &cache[index].regionlNodePositive,
                    &cache[index].survivalMonths, &status);

                    // assign race.
                    if(race[0] == 'O'){
                      cache[index].race = 2;
                    } else {
                      cache[index].race = race[0] == 'B';
                    }
                    cache[index].aliveStatus = (status[0] == 'D');
                    cache[index].sortColumn = cache[index].age + cache[index].tumorSize;
                    cache[index].estrogenStatus = (estrogenStatus[0] == 'P');
                    cache[index].prostegeroneStatus = (prostegeroneStatus[0] == 'P');
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