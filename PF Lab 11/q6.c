#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left;
  struct Node *right;
} Node;

Node *createNode(int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  if (newNode == NULL) {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }
  newNode->data = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

Node *insertNode(Node *root, int value) {
  if (root == NULL) {
    return createNode(value);
  }

  if (value < root->data) {
    root->left = insertNode(root->left, value);
  } else if (value > root->data) {
    root->right = insertNode(root->right, value);
  }

  return root;
}

Node *searchNode(Node *root, int value) {
  if (root == NULL) {
    return NULL;
  }

  if (root->data == value) {
    return root;
  }

  if (value < root->data) {
    return searchNode(root->left, value);
  } else {
    return searchNode(root->right, value);
  }
}

int findHeight(Node *root) {
  if (root == NULL) {
    return -1;
  }

  int leftHeight = findHeight(root->left);
  int rightHeight = findHeight(root->right);

  return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int countNodes(Node *root) {
  if (root == NULL) {
    return 0;
  }

  return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorderTraversal(Node *root) {
  if (root == NULL) {
    return;
  }

  inorderTraversal(root->left);

  printf("%d ", root->data);

  inorderTraversal(root->right);
}

int main() {
  Node *root = NULL;

  int values[] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 75, 5};
  int len = sizeof(values) / sizeof(values[0]);

  printf("--- 1. Building Binary Search Tree ---\n");
  printf("Inserting values: ");
  for (int i = 0; i < len; i++) {
    printf("%d ", values[i]);
    root = insertNode(root, values[i]);
  }
  printf("\n");

  printf("\n--- 2. In-order Traversal (Sorted Order) ---\n");
  printf("In-order: ");
  inorderTraversal(root);
  printf("\n");

  printf("\n--- 3. Tree Statistics ---\n");

  int count = countNodes(root);
  printf("Total Nodes: %d (Expected: %d)\n", count, len);

  int height = findHeight(root);
  printf("Tree Height: %d (Height of root = 0)\n", height);

  printf("\n--- 4. Recursive Search Tests ---\n");
  int search_val_found = 35;
  int search_val_not_found = 99;
  Node *result;

  result = searchNode(root, search_val_found);
  if (result != NULL) {
    printf("Search for %d: FOUND!\n", search_val_found);
  } else {
    printf("Search for %d: NOT FOUND.\n", search_val_found);
  }

  result = searchNode(root, search_val_not_found);
  if (result != NULL) {
    printf("Search for %d: FOUND!\n", search_val_not_found);
  } else {
    printf("Search for %d: NOT FOUND.\n", search_val_not_found);
  }

  free(root);

  printf("\n--- Test Complete ---\n");

  return 0;
}

void freeTree(Node *root) {
  if (root == NULL) {
    return;
  }
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}