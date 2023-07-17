#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int keys[2];
    struct node* children[3];
    int num_keys;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->keys[0] = key;
    newNode->keys[1] = 0;
    newNode->children[0] = NULL;
    newNode->children[1] = NULL;
    newNode->children[2] = NULL;
    newNode->num_keys = 1;
    return newNode;
}

void insertKey(Node** root, int key) {
    if (*root == NULL) {
        *root = createNode(key);
        return;
    }

    if ((*root)->num_keys == 1) {
        if (key < (*root)->keys[0]) {
            insertKey(&((*root)->children[0]), key);
        } else {
            insertKey(&((*root)->children[1]), key);
        }
    } else {
        if (key < (*root)->keys[0]) {
            insertKey(&((*root)->children[0]), key);
        } else if (key > (*root)->keys[1]) {
            insertKey(&((*root)->children[2]), key);
        } else {
            insertKey(&((*root)->children[1]), key);
        }
    }
}

void splitNode(Node** root, Node* child, int key) {
    Node* newNode = createNode(key);

    if ((*root)->num_keys == 1) {
        if (key < (*root)->keys[0]) {
            newNode->children[0] = child;
            newNode->children[1] = (*root)->children[1];
            (*root)->children[1] = NULL;
            (*root)->keys[1] = (*root)->keys[0];
            (*root)->keys[0] = key;
        } else {
            newNode->children[0] = (*root)->children[1];
            newNode->children[1] = child;
            (*root)->children[1] = NULL;
            (*root)->keys[1] = key;
        }
        (*root)->num_keys = 1;
        (*root)->children[0] = newNode;
    } else {
        if (key < (*root)->keys[0]) {
            newNode->children[0] = child;
            newNode->children[1] = (*root)->children[1];
            newNode->children[2] = (*root)->children[2];
            (*root)->children[1] = NULL;
            (*root)->children[2] = NULL;
            newNode->keys[0] = (*root)->keys[0];
            (*root)->keys[0] = key;
        } else if (key > (*root)->keys[1]) {
            newNode->children[0] = (*root)->children[2];
            newNode->children[1] = child;
            newNode->children[2] = NULL;
            newNode->keys[0] = (*root)->keys[1];
            (*root)->keys[1] = key;
        } else {
            newNode->children[0] = (*root)->children[1];
            newNode->children[1] = child;
            newNode->children[2] = NULL;
            newNode->keys[0] = key;
        }
        (*root)->num_keys = 1;
        (*root)->children[0] = newNode;
    }
}

void insert(Node** root, int key) {
    if (*root == NULL) {
        *root = createNode(key);
        return;
    }

    if ((*root)->num_keys == 2) {
        Node* newNode = NULL;
        splitNode(&newNode, *root, key);
        *root = newNode;
    } else {
        if (key < (*root)->keys[0]) {
            insertKey(&((*root)->children[0]), key);
        } else if (key > (*root)->keys[0]) {
            insertKey(&((*root)->children[1]), key);
        }
    }
}

void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->children[0]);
        printf("%d ", root->keys[0]);
        inorderTraversal(root->children[1]);
        if (root->num_keys == 2) {
            printf("%d ", root->keys[1]);
            inorderTraversal(root->children[2]);
        }
    }
}

int main() {
    Node* root = NULL;

    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 60);
    insert(&root, 71);
    insert(&root, 89);
    insert(&root, 76);
    insert(&root, 62);
    insert(&root, 100);


    printf("Inorder traversal of the 2-3 tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
