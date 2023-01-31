#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  int data;
  int value;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data, int value) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

int compare(int a, int b) {
  return (a - b);
}

void insert(struct node **root, int data, int value) {
  if (*root == NULL) {
    *root = createNode(data, value);
  } else {
    if (compare(data, (*root)->data) < 0) {
      insert(&(*root)->left, data, value);
    } else {
      insert(&(*root)->right, data, value);
    }
  }
}

void inOrder(struct node *root) {
  if (root != NULL) {
    inOrder(root->left);
    printf("%d,%d\n", root->data, root->value);
    inOrder(root->right);
  }
}

int main() {
  struct node *root = NULL;
  char line[256];
  char *token;
  char *delim = ",";

  // Read the data from the CSV file
  FILE *fp;
  fp = fopen("./databases/Breast_Cancer_2_columns.csv", "r");
  if (fp == NULL) {
    printf("Could not open file");
    return 1;
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    line[strcspn(line, "\r\n")] = 0;
    token = strtok(line, delim);
    int data = atoi(token);
    token = strtok(NULL, delim);
    int value = atoi(token);
    insert(&root, data, value);
  }

  fclose(fp);

  inOrder(root);

  return 0;
}
