#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int keys[2];
    struct node *esq,*cen,*dir;
    int num_keys;
} Node;

Node* createNode(int key) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->keys[0] = key;
    newNode->keys[1] = 0;
    newNode->esq = NULL;//[0]
    newNode->cen = NULL;//[1]
    newNode->dir = NULL;//[2]
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
            insertKey(&((*root)->esq), key);
        } else {
            insertKey(&((*root)->cen), key);
        }
    } else {
        if (key < (*root)->keys[0]) {
            insertKey(&((*root)->esq), key);
        } else if (key > (*root)->keys[1]) {
            insertKey(&((*root)->dir), key);
        } else {
            insertKey(&((*root)->cen), key);
        }
    }
}

void splitNode(Node** root, Node* child, int key) {
    Node* newNode = createNode(key);

    if ((*root)->num_keys == 1) {
        if (key < (*root)->keys[0]) {
            newNode->esq = child;
            newNode->cen = (*root)->cen;
            (*root)->cen = NULL;
            (*root)->keys[1] = (*root)->keys[0];
            (*root)->keys[0] = key;
        } else {
            newNode->esq = (*root)->cen;
            newNode->cen = child;
            (*root)->cen = NULL;
            (*root)->keys[1] = key;
        }
        (*root)->num_keys = 1;
        (*root)->esq = newNode;
    } else {
        if (key < (*root)->keys[0]) {
            newNode->esq = child;
            newNode->cen = (*root)->cen;
            newNode->dir = (*root)->dir;
            (*root)->cen = NULL;
            (*root)->dir = NULL;
            newNode->keys[0] = (*root)->keys[0];
            (*root)->keys[0] = key;
        } else if (key > (*root)->keys[1]) {
            newNode->esq = (*root)->dir;
            newNode->cen = child;
            newNode->dir = NULL;
            newNode->keys[0] = (*root)->keys[1];
            (*root)->keys[1] = key;
        } else {
            newNode->esq = (*root)->cen;
            newNode->cen = child;
            newNode->dir = NULL;
            newNode->keys[0] = key;
        }
        (*root)->num_keys = 1;
        (*root)->esq = newNode;
    }
}

void insert(Node** root, int key){
    if (*root == NULL) {// primeira inserção
        *root = createNode(key);
        return;
    }

    if ((*root)->num_keys == 2) {// nó cheio, realizar quebra de nó
        Node* newNode = NULL;
        splitNode(&newNode, *root, key);
        *root = newNode;
    } else {
        if (key < (*root)->keys[0]) {// inserer chave na esquerda do maior
            insertKey(&((*root)->esq), key);
        } else if (key > (*root)->keys[0]) {// insereir na direita do menor
            insertKey(&((*root)->cen), key);
        }
    }
}

void printInOrdem(Node* root) {
    if (root != NULL) {
        printInOrdem(root->esq);
        printf("%d ", root->keys[0]);
        printInOrdem(root->cen);
        if (root->num_keys == 2) {
            printf("%d ", root->keys[1]);
            printInOrdem(root->dir);
        }
    }
}

int main() {
    Node *root = NULL;
    srand(time(NULL));

    for(int i = 0; i < 100; i++){
        insert(&root, rand() % 1000);
    }

    printf("Inorder traversal of the 2-3 tree: ");
    printInOrdem(root);
    printf("\n");

    return 0;
}
