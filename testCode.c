#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct node {
  int data;
  int value;
  char * race;
  char * marital;
  char * tStage;
  char * nStage;
  char * sixStage;
  char * diff; 
  int grade;
  char * aStage;
  char * estrogStatus;
  char * progesStatus;
  int regionalNodeExa;
  int regionalNodePos;
  int survivalMonths;
  char * status;
  struct node *left;
  struct node *right;
};

typedef struct node * Node;

struct node *createNode(int data, int value, char race[], char marital[], char tStage[], char nStage[], char sixStage[], char diff[], int grade, char aStage[], char estrogStatus[], char progesStatus[], int regionalNodeExa, int regionalNodePos, int survivalMonths, char status[]){ // int regionalNodeExa, int regionalNodePos, int survivalMonths, char status) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->value = value;
  newNode->race = strdup(race);
  newNode->marital = strdup(marital);
  newNode->tStage = strdup(tStage);
  newNode->nStage = strdup(nStage);
  newNode->sixStage = strdup(sixStage);
  newNode->diff = strdup(diff); 
  newNode->grade = grade; 
  newNode->aStage = strdup(aStage);
  newNode->estrogStatus = strdup(estrogStatus);
  newNode->progesStatus = strdup(progesStatus);
  newNode->regionalNodeExa = regionalNodeExa;
  newNode->regionalNodePos = regionalNodePos;
  newNode->survivalMonths = survivalMonths;
  newNode->status = strdup(status);
  newNode->left = NULL;
  newNode->right = NULL;
  
  return newNode;

  
}

int compare(int a, int b) {
  return (a - b);
}

void insert(struct node **root, int data, int value, char race[], char marital[], char tStage[], char nStage[], char sixStage[], char diff[], int grade, char aStage[], char estrogStatus[], char progesStatus[], int regionalNodeExa, int regionalNodePos, int survivalMonths, char status[]){ //  char estrogStatus, char progesStatus, int regionalNodeExa, int regionalNodePos, int survivalMonths, char status) {
  if (*root == NULL) {
    *root = createNode(data, value, race, marital, tStage, nStage, sixStage, diff, grade, aStage, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status); //, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status);
  } else {
    if (compare((data+value), (*root)-> data + (*root)-> value )  < 0  ){
      insert(&(*root)->left, data, value, race, marital, tStage, nStage, sixStage, diff, grade, aStage, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status); // tStage, nStage, sixStage, diff, grade, aStage, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status);
    } else {
      insert(&(*root)->right, data, value, race, marital, tStage, nStage, sixStage, diff, grade, aStage, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status);  // tStage, nStage, sixStage, diff, grade, aStage, estrogStatus, progesStatus, regionalNodeExa, regionalNodePos, survivalMonths, status);
    }
  }
}

void inOrder(struct node *root) {
  //char str[60];

  if (root != NULL) {
    
    inOrder(root->left);  
    printf("%d, %d, %s, %s, %s, %s, %s, %s, %d, %s, %s, %s, %d, %d, %d, %s \n", root->data, root->value, root-> race, root-> marital, root -> tStage, root -> nStage, root -> sixStage, root -> diff, root -> grade, root -> aStage, root -> estrogStatus, root -> progesStatus, root -> regionalNodeExa, root -> regionalNodePos, root -> survivalMonths, root -> status); 
    
/*     printf("%d, ", root->data);
    printf("%d, ", root->value);
    printf("%s, ", root->race);
    printf("%s \n", root->marital); */
    
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
 void limpa(Node Node){
    if(Node == NULL)
        free(Node);

    if(Node->left != NULL){
        free(Node->left);
        }

    if(Node->right != NULL){
        free(Node->right);
    }
    free(Node);
}


Node processar(FILE *fp){
   
    struct node * root = NULL;
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


  while (fgets(line, sizeof(line), fp) != NULL) {
    line[strcspn(line, " \r\n")];
    token = strtok(line, delim);
    int data = atoi(token);
    //printf("%d ,", data);
  
    token = strtok(NULL, delim);
    int value = atoi(token);
    //printf("%d, ", value);

    token = strtok(NULL, delim);
    //token = strcpy(token1, &line[2]);
    char * raceP = strcpy(race,token); //correto
    //printf("%s,", race);

    token = strtok(NULL, delim);
    char * maritalP = strcpy(marital, token);
    //printf("%s, ", marital);

    token = strtok(NULL, delim);
    char * tStageP = strcpy(tStage, token);
    //printf("%s, ", tStage);

    token = strtok(NULL, delim);
    char * nStageP = strcpy(nStage, token);
    //printf("%s, ", nStage);

    token = strtok(NULL, delim);
    char * sixStageP = strcpy(sixStage, token); 
    //printf("%s, ", sixStage);
   

    token = strtok(NULL, delim);
    char * diffP = strcpy(diff, token);
    //printf("%s, ", diff);

    token = strtok(NULL, delim);
    int gradeP = atoi(token);
    int ig = (int)gradeP;
    //printf("%d, ", ig);


    token = strtok(NULL, delim);
    char * aStageP = strcpy(aStage, token);
    //printf("%s, ", aStage);

    token = strtok(NULL, delim);
    char * estrogStatusP = strcpy(estrogStatus, token);
    //printf("%s, ", estrogStatus);

    token = strtok(NULL, delim);    
    char * progesStatusP = strcpy(progesStatus, token);
    //printf("%s, ", progesStatus);

    token = strtok(NULL, delim);
    char regionalNodeExaP = atoi(token);
    int ic = (int)regionalNodeExaP;
    //printf("%d,", ic);


    token = strtok(NULL, delim);
    char regionalNodePosP = atoi(token);
    int ia = (int)regionalNodePosP;
    //printf("%d, ", ia);

    token = strtok(NULL, delim);
    char survivalMonthsP = atoi(token);
    int ib = (int)survivalMonthsP;
    //printf("%d, ", ib);


    token = strtok(NULL, delim);
    char * statusP = strcpy(status, token);
    //printf("%s \n", status);


  

    insert(&root, data, value, raceP, maritalP, tStageP, nStageP, sixStageP, diffP, gradeP, aStageP, estrogStatusP, progesStatusP, regionalNodeExaP, regionalNodePosP, survivalMonthsP, statusP); 

  }

  return root;


}

int main() {

  struct node *root = NULL;


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
                  
              }else{
              root = processar(arquivo);
              inOrder(root);
                  break;

              }
                 
              
          case '3':
              fclose(arquivo);
              limpa(root);
              return 0;
      }
  }





  return 0;
}
