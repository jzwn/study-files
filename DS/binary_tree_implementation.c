#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};

// Create a new node
struct node* createNode(int data) {
  struct node* newNode = (struct node*)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}

// Insert node in level-order (for general binary tree)
void insert(struct node **root, int data) {
  struct node *temp = createNode(data);
  if (*root == NULL) {
    *root = temp;
    return;
  }

  struct node *queue[100];
  int front = 0, rear = 0;
  queue[rear++] = *root;

  while (front < rear) {
    struct node *current = queue[front++];

    if (current->left == NULL) {
      current->left = temp;
      return;
    } else {
      queue[rear++] = current->left;
    }

    if (current->right == NULL) {
      current->right = temp;
      return;
    } else {
      queue[rear++] = current->right;
    }
  }
}

// Inorder display
void inorder(struct node *root) {
  if (root == NULL) return;
  inorder(root->left);
  printf("%d ", root->data);
  inorder(root->right);
}

// Delete all nodes (postorder delete)
void deleteTree(struct node *root) {
  if (root == NULL) return;
  deleteTree(root->left);
  deleteTree(root->right);
  free(root);
}

int main() {
  struct node *root = NULL;

  insert(&root, 10);
  insert(&root, 20);
  insert(&root, 30);
  insert(&root, 40);
  insert(&root, 50);

  printf("Inorder traversal: ");
  inorder(root);

  deleteTree(root);
  return 0;
}
