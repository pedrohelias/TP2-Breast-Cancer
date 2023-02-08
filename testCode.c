#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct node {
  int data;
  int value;
  char race;
  char marital;
  char tStage;
  char nStage;
  char sixStage;
  char diff; 
  int grade;
  char aStage;
  char estrogStatus;
  char progesStatus;
  int regionalNodeExa;
  int regionalNodePos;
  int survivalMonths;
  char status;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data, int value, char *race, char marital, char tStage, char nStage, char sixStage, char diff, int grade, char aStage, char estrogStatus, char progesStatus, int regionalNodeExa, int regionalNodePos, int survivalMonths, char status){ // int regionalNodeExa, int regionalNodePos, int survivalMonths, char status) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->value = value;
  newNode->race = race;
  newNode->marital = marital;
  newNode->tStage = tStage;
  newNode->nStage = nStage;
  newNode->sixStage = sixStage;
  newNode->diff = diff; 
  newNode->grade = grade; 
  newNode->aStage = aStage;
  newNode->estrogStatus = estrogStatus;
  newNode->progesStatus = progesStatus;
  newNode->regionalNodeExa = regionalNodeExa;
  newNode->regionalNodePos = regionalNodePos;
  newNode->survivalMonths = survivalMonths;
  newNode->status = status;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int compare(int a, int b) {
  return (a - b);
}

void insert(struct node **root, int data, int value, char* race, char marital, char tStage, char nStage, char sixStage, char diff, int grade, char aStage, char estrogStatus, char progesStatus, int regionalNodeExa, int regionalNodePos, int survivalMonths, char status){ //  char estrogStatus, char progesStatus, int regionalNodeExa, int regionalNodePos, int survivalMonths, char status) {
  if (*root == NULL) {
    *root = createNode(data, value, race, marital, tStage, nStage, sixStage, diff, grade, aStage, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status); //, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status);
  } else {
    if (compare(data, (*root)->data) < 0 && compare(value, (*root)->value) ) {
      insert(&(*root)->left, data, value, race, marital, tStage, nStage, sixStage, diff, grade, aStage, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status); // tStage, nStage, sixStage, diff, grade, aStage, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status);
    } else {
      insert(&(*root)->right, data, value, race, marital, tStage, nStage, sixStage, diff, grade, aStage, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status);  // tStage, nStage, sixStage, diff, grade, aStage, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status);
    }
  }
}

void inOrder(struct node *root) {
  char str[60];

  if (root != NULL) {
    
    inOrder(root->left);
/*     printf("%d, %d, %d, %d, %d, %d, %d, %d,%d, %d, %d, %d, %d, %d, %d, %d \n", root->data, root->value, root-> race, root-> marital, root -> tStage, root -> nStage, root -> sixStage, root -> diff, root -> grade, root -> aStage, root -> estrogStatus, root -> progesStatus, root -> regionalNodeExa, root -> regionalNodePos, root -> survivalMonths, root -> status); */
    printf("%d, ", root->data);
    printf("%d, ", root->value); 
    printf("%d", root-> race);
    
    //sprintf(str, "%d", root->race);
    printf("\n");
    

    inOrder(root->right);
  }
}

FILE * carregarDatabase(char arquivo[50]){
    FILE *file;
    file = fopen(arquivo, "r");

    if(file == NULL){
        printf("Erro ao abrir o documento\n");
        return 1;
    }

    return file;

}

int main() {

  struct node *root = NULL;
  char line[256];
  char *token;
  char *token1;
  char *delim = ",";
  char race[60];
  char marital[60];
  char tStage[60];
  char nStage[60];
  char sixStage[60];
  char diff[60];
  int grade;
  char aStage[60];
  char estrogStatus[60];
  char progesStatus[60];
  int regionalNodeExa;
  int regionalNodePos;
  int survivalMonths;
  char status[40];

  // char opcao, nomeArquivo[50];
  // FILE *arquivo = NULL;
  // long int posicao[962];


  // while(opcao != '3'){

  //     printf("\n1 - Inserir Base de Dados\n");
  //     printf("2 - Emitir Relatório\n");
  //     printf("3 - Fechar Aplicação\n\n");

  //     scanf("%c", &opcao);
  //     getchar();

  //     switch(opcao){
  //         case '1':
              
  //             printf("\nInforme o nome do arquivo a ser lido:");
  //             scanf("%s", nomeArquivo);
  //             getchar();

  //             arquivo = carregarDatabase(nomeArquivo);
              
  //             break;

  //         case '2':
  //             if(arquivo == NULL){
  //                 printf("\nArquivo vazio\n\n");
  //                 break;
  //             }

              
  //             break;

  //         case '3':
  //             return 0;
  //     }
  // }





  // Read the data from the CSV file
  FILE *fp;
  fp = fopen("Breast_Cancer_modified.csv", "r");
  if (fp == NULL) {
    printf("Could not open file");
    return 1;
  }

  // int data;
  // int value;
  // char race;
  // char marital;
  // char tStage;
  // char nStage;
  // char sixStage;
  // char diff; 
  // int grade;
  // char aStage;
  // char estrogStatus;
  // char progesStatus;
  // int regionalNodeExa;
  // int regionalNodePos;
  // int survivalMonths;
  // char status;

  while (fgets(line, sizeof(line), fp) != NULL) {
    line[strcspn(line, " \r\n")];
    token = strtok(line, delim);
    int data = atoi(token);
    printf("%d ,", data);
  
    token = strtok(NULL, delim);
    int value = atoi(token);
    printf("%d, ", value);

    token = strtok(NULL, delim);
    //token = strcpy(token1, &line[2]);
    char raceP = strcpy(race,token); //correto
    printf("%s,", race);
    // if (race == 92){
    //     race = "white";
    // }
    token = strtok(NULL, delim);
    char maritalP = strcpy(marital, token);
    printf("%s, ", marital);

    token = strtok(NULL, delim);
    char tStageP = strcpy(tStage, token);
    printf("%s, ", tStage);

    token = strtok(NULL, delim);
    char nStageP = strcpy(nStage, token);
    printf("%s, ", nStage);

    token = strtok(NULL, delim);
    char  sixStageP = strcpy(sixStage, token); 
    printf("%s, ", sixStage);
   

    token = strtok(NULL, delim);
    char diffP = strcpy(diff, token);
    printf("%s, ", diff);

    token = strtok(NULL, delim);
    int gradeP = atoi(token);
    int ig = (int)gradeP;
    printf("%d, ", ig);


    token = strtok(NULL, delim);
    char aStageP = strcpy(aStage, token);
    printf("%s, ", aStage);

    token = strtok(NULL, delim);
    char estrogStatusP = strcpy(estrogStatus, token);
    printf("%s, ", estrogStatus);

    token = strtok(NULL, delim);    
    char progesStatusP = strcpy(progesStatus, token);
    printf("%s, ", progesStatus);

    token = strtok(NULL, delim);
    char regionalNodeExaP = atoi(token);
    int ic = (int)regionalNodeExaP;
    printf("%d,", ic);


    token = strtok(NULL, delim);
    char regionalNodePosP = atoi(token);
    int ia = (int)regionalNodePosP;
    printf("%d, ", ia);

    token = strtok(NULL, delim);
    char survivalMonthsP = atoi(token);
    int ib = (int)survivalMonthsP;
    printf("%d, ", ib);


    token = strtok(NULL, delim);
    char statusP = strcpy(status, token);
    printf("%s \n", status);


  

    insert(&root, data, value, raceP, maritalP, tStageP, nStageP, sixStageP, diffP, gradeP, aStageP, estrogStatusP, progesStatusP, regionalNodeExaP, regionalNodePosP, survivalMonthsP, statusP); // nStageP, sixStageP, diffP, gradeP, aStageP, estrogStatusP, progesStatusP, regionalNodeExaP, regionalNodePosP, survivalMonthsP, statusP);
  }

  fclose(fp);

  inOrder(root);

  return 0;
}
