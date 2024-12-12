#include <stdio.h>
#include <stdlib.h>

#define MAX 3  // Maximum number of keys in a node (order - 1)
#define MIN (MAX / 2)  // Minimum number of keys in a node

struct BTreeNode {
    int keys[MAX + 1];  // One extra space for temporary key
    struct BTreeNode *child[MAX + 2];  // Child pointers
    int n;  // Number of keys currently in the node
    int leaf;  // Boolean flag for leaf
};

typedef struct BTreeNode BTreeNode;

BTreeNode *root = NULL;

// Function prototypes
BTreeNode *createNode(int leaf);
void insert(int key);
void splitChild(BTreeNode *parent, int i, BTreeNode *child);
void insertNonFull(BTreeNode *node, int key);
void traverse(BTreeNode *node);

int main() {
    int choice, key;

    while (1) {
        printf("\nB-Tree Operations:\n");
        printf("1. Insert\n");
        printf("2. Display\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("B-Tree elements: ");
                traverse(root);
                printf("\n");
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

// Create a new node
BTreeNode *createNode(int leaf) {
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->n = 0;
    node->leaf = leaf;
    for (int i = 0; i < MAX + 2; i++) {
        node->child[i] = NULL;
    }
    return node;
}

// Insert a key into the B-Tree
void insert(int key) {
    if (root == NULL) {  // If tree is empty
        root = createNode(1);
        root->keys[0] = key;
        root->n = 1;
    } else {
        if (root->n == MAX) {  // Root is full, need to split
            BTreeNode *newRoot = createNode(0);
            newRoot->child[0] = root;
            splitChild(newRoot, 0, root);
            int i = (newRoot->keys[0] < key) ? 1 : 0;
            insertNonFull(newRoot->child[i], key);
            root = newRoot;
        } else {
            insertNonFull(root, key);
        }
    }
}

// Split a full child
void splitChild(BTreeNode *parent, int i, BTreeNode *child) {
    BTreeNode *newChild = createNode(child->leaf);
    newChild->n = MIN;

    for (int j = 0; j < MIN; j++) {
        newChild->keys[j] = child->keys[j + MIN + 1];
    }

    if (!child->leaf) {
        for (int j = 0; j <= MIN; j++) {
            newChild->child[j] = child->child[j + MIN + 1];
        }
    }

    child->n = MIN;

    for (int j = parent->n; j >= i + 1; j--) {
        parent->child[j + 1] = parent->child[j];
    }

    parent->child[i + 1] = newChild;

    for (int j = parent->n - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }

    parent->keys[i] = child->keys[MIN];
    parent->n += 1;
}

// Insert into a non-full node
void insertNonFull(BTreeNode *node, int key) {
    int i = node->n - 1;

    if (node->leaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }

        node->keys[i + 1] = key;
        node->n += 1;
    } else {
        while (i >= 0 && key < node->keys[i]) {
            i--;
        }
        i++;

        if (node->child[i]->n == MAX) {
            splitChild(node, i, node->child[i]);
            if (key > node->keys[i]) {
                i++;
            }
        }
        insertNonFull(node->child[i], key);
    }
}

// Traverse and print the B-Tree
void traverse(BTreeNode *node) {
    if (node != NULL) {
        int i;
        for (i = 0; i < node->n; i++) {
            if (!node->leaf) {
                traverse(node->child[i]);
            }
            printf("%d ", node->keys[i]);
        }
        if (!node->leaf) {
            traverse(node->child[i]);
        }
    }
}
