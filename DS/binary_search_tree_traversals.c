#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create new node
struct node *newNode(int key) {
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

// Insert into BST
struct node *insert(struct node *root, int key) {
  if (root == NULL) return newNode(key);
  if (key < root->key)
    root->left = insert(root->left, key);
  else
    root->right = insert(root->right, key);
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

// Preorder traversal
void preorder(struct node *root) {
  if (root != NULL) {
    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
  }
}

// Postorder traversal
void postorder(struct node *root) {
  if (root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
  }
}

int main() {
  struct node *root = NULL;
  root = insert(root, 40);
  root = insert(root, 20);
  root = insert(root, 10);
  root = insert(root, 30);
  root = insert(root, 60);
  root = insert(root, 50);
  root = insert(root, 70);

  printf("Inorder traversal: ");
  inorder(root);

  printf("\nPreorder traversal: ");
  preorder(root);

  printf("\nPostorder traversal: ");
  postorder(root);

  return 0;
}
