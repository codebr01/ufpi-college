#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da árvore 2-3
typedef struct Node {
    int value1;
    int value2;
    struct Node* child1;
    struct Node* child2;
    struct Node* child3;
} Node;

// Função para criar um novo nó com um único valor
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value1 = value;
    newNode->value2 = -1;
    newNode->child1 = NULL;
    newNode->child2 = NULL;
    newNode->child3 = NULL;
    return newNode;
}

// Função para inserir um valor em uma árvore 2-3
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (root->value2 == -1) {
        if (value < root->value1) {
            root->value2 = root->value1;
            root->value1 = value;
        } else {
            root->value2 = value;
        }
        return root;
    }
    if (value < root->value1) {
        root->child1 = insert(root->child1, value);
    } else if (value > root->value2) {
        root->child3 = insert(root->child3, value);
    } else {
        root->child2 = insert(root->child2, value);
    }
    return root;
}

// Função para imprimir a árvore 2-3 (ordem de exibição: in-order)
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->child1);
        printf("%d ", root->value1);
        inorderTraversal(root->child2);
        if (root->value2 != -1) {
            printf("%d ", root->value2);
            inorderTraversal(root->child3);
        }
    }
}

// Função para encontrar o valor mínimo em uma subárvore
int findMinValue(Node* root) {
    while (root->child1 != NULL) {
        root = root->child1;
    }
    return root->value1;
}

// Função para remover um valor de uma árvore 2-3
Node* removeValue(Node* root, int value) {
    if (root == NULL) {
        return NULL;
    }

    if (root->value1 == value) {
        if (root->child1 == NULL && root->child2 == NULL && root->child3 == NULL) {
            // Caso 1: Remoção de um valor em uma folha
            free(root);
            return NULL;
        } else if (root->child1 != NULL && root->child2 != NULL) {
            // Caso 2: Remoção de um valor com dois filhos
            int minValue = findMinValue(root->child3);
            root->value1 = minValue;
            root->child3 = removeValue(root->child3, minValue);
            return root;
        } else {
            // Caso 3: Remoção de um valor com um filho
            if (root->child1 != NULL) {
                Node* temp = root->child1;
                free(root);
                return temp;
            } else {
                Node* temp = root->child2;
                free(root);
                return temp;
            }
        }
    } else if (root->value2 == value) {
        if (root->child1 == NULL && root->child2 == NULL && root->child3 == NULL) {
            // Caso 1: Remoção de um valor em uma folha
            free(root);
            return NULL;
        } else if (root->child2 != NULL && root->child3 != NULL) {
            // Caso 2: Remoção de um valor com dois filhos
            int minValue = findMinValue(root->child3);
            root->value2 = minValue;
            root->child3 = removeValue(root->child3, minValue);
            return root;
        } else {
            // Caso 3: Remoção de um valor com um filho
            if (root->child2 != NULL) {
                Node* temp = root->child2;
                free(root);
                return temp;
            } else {
                Node* temp = root->child3;
                free(root);
                return temp;
            }
        }
    } else if (value < root->value1) {
        root->child1 = removeValue(root->child1, value);
    } else if (value > root->value2) {
        root->child3 = removeValue(root->child3, value);
    } else {
        root->child2 = removeValue(root->child2, value);
    }

    return root;
}

int main() {
    Node* root = NULL;

    // Inserindo valores na árvore 2-3
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 60);

    printf("Árvore 2-3 antes da remoção: ");
    inorderTraversal(root);
    printf("\n");

    // Removendo um valor da árvore 2-3
    root = removeValue(root, 30);

    printf("Árvore 2-3 após a remoção: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}