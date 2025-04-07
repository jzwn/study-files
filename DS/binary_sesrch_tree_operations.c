#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create node
struct node *newNode(int key) {
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

// Insert node in BST
struct node *insert(struct node *root, int key) {
  if (root == NULL) return newNode(key);
  if (key < root->key)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);
  return root;
}

// Find min value node
struct node *minValue(struct node *node) {
  struct node *current = node;
  while (current && current->left != NULL)
    current = current->left;
  return current;
}

// Delete node in BST
struct node *delete(struct node *root, int key) {
  if (root == NULL) return root;

  if (key < root->key)
    root->left = delete(root->left, key);
  else if (key > root->key)
    root->right = delete(root->right, key);
  else {
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }
    struct node *temp = minValue(root->right);
    root->key = temp->key;
    root->right = delete(root->right, temp->key);
  }
  return root;
}

// Inorder traversal
void inorder(struct node *root) {
  if (root != NULL) {
    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
  }
}

int main() {
  struct node *root = NULL;
  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  printf("Inorder before deletion: ");
  inorder(root);

  root = delete(root, 20);
  root = delete(root, 30);
  root = delete(root, 50);

  printf("\nInorder after deletion: ");
  inorder(root);

  return 0;
}
