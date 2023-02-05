#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct node {
  int data;
  int value;
  char race;
  char marital;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data, int value, char race, char marital) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->value = value;
  newNode->race = race;
  newNode->marital = marital;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int compare(int a, int b) {
  return (a - b);
}

void insert(struct node **root, int data, int value, char race, char marital) {
  if (*root == NULL) {
    *root = createNode(data, value, race, marital);
  } else {
    if (compare(data, (*root)->data) < 0) {
      insert(&(*root)->left, data, value, race, marital);
    } else {
      insert(&(*root)->right, data, value, race, marital);
    }
  }
}

void inOrder(struct node *root) {
  if (root != NULL) {
    inOrder(root->left);
    printf("%d,%d,%d,%d \n", root->data, root->value, root-> race, root-> marital);
    inOrder(root->right);
  }
}

int main() {
  struct node *root = NULL;
  char line[256];
  char *token;
  char *token1;
  char *delim = ",";
  bool racePointer;
  char str[60];
  char mar[60];

  // Read the data from the CSV file
  FILE *fp;
  fp = fopen("Breast_Cancer_modified.csv", "r");
  if (fp == NULL) {
    printf("Could not open file");
    return 1;
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    line[strcspn(line, " \r\n")];
    token = strtok(line, delim);
    int data = atoi(token);
    token = strtok(NULL, delim);
    int value = atoi(token);
    token = strtok(NULL, delim);
    //token = strcpy(token1, &line[2]);
    
    char race = strcpy(str,token); //correto
    printf("%s\n", str);
    // if (race == 92){
    //     race = "white";
    // }
    token = strtok(NULL, delim);
    char marital = strcpy(mar, token);
    printf("%s\n", mar);

    insert(&root, data, value, race, marital);
  }

  fclose(fp);

  inOrder(root);

  return 0;
}
