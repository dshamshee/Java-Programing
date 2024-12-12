#include <stdio.h>
#include <stdlib.h>

// Define the order of the B-tree (minimum degree t)
#define T 3

// Define a structure for a B-tree node
typedef struct BTreeNode {
    int keys[2 * T - 1];   // Array to store keys
    struct BTreeNode *C[2 * T]; // Array to store child pointers
    int n;                // Number of keys in the node
    int leaf;             // 1 if leaf, 0 otherwise
} BTreeNode;

// Function prototypes
BTreeNode *createNode(int leaf);
void traverse(BTreeNode *root);
void insert(BTreeNode **root, int k);
void splitChild(BTreeNode *x, int i, BTreeNode *y);
void insertNonFull(BTreeNode *x, int k);

int main() {
    BTreeNode *root = NULL;

    printf("Inserting keys into B-tree...\n");

    // Insert keys
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);
    insert(&root, 7);
    insert(&root, 17);

    printf("Traversal of the B-tree:\n");
    traverse(root);
    printf("\n");

    return 0;
}

// Function to create a new B-tree node
BTreeNode *createNode(int leaf) {
    BTreeNode *node = (BTreeNode *)malloc(sizeof(BTreeNode));
    node->leaf = leaf;
    node->n = 0;
    for (int i = 0; i < 2 * T; i++) {
        node->C[i] = NULL;
    }
    return node;
}

// Function to traverse the B-tree
void traverse(BTreeNode *root) {
    if (root != NULL) {
        for (int i = 0; i < root->n; i++) {
            if (!root->leaf) {
                traverse(root->C[i]);
            }
            printf("%d ", root->keys[i]);
        }
        if (!root->leaf) {
            traverse(root->C[root->n]);
        }
    }
}

// Function to insert a key into the B-tree
void insert(BTreeNode **root, int k) {
    if (*root == NULL) {
        *root = createNode(1);  // Create a new root node
        (*root)->keys[0] = k;  // Insert the key
        (*root)->n = 1;
    } else {
        if ((*root)->n == 2 * T - 1) { // Root is full
            BTreeNode *s = createNode(0); // Create a new root
            s->C[0] = *root;
            splitChild(s, 0, *root);

            int i = 0;
            if (s->keys[0] < k) {
                i++;
            }
            insertNonFull(s->C[i], k);

            *root = s; // Update root
        } else {
            insertNonFull(*root, k);
        }
    }
}

// Function to split a full child node
void splitChild(BTreeNode *x, int i, BTreeNode *y) {
    BTreeNode *z = createNode(y->leaf);
    z->n = T - 1;

    for (int j = 0; j < T - 1; j++) {
        z->keys[j] = y->keys[j + T];
    }

    if (!y->leaf) {
        for (int j = 0; j < T; j++) {
            z->C[j] = y->C[j + T];
        }
    }

    y->n = T - 1;

    for (int j = x->n; j >= i + 1; j--) {
        x->C[j + 1] = x->C[j];
    }

    x->C[i + 1] = z;

    for (int j = x->n - 1; j >= i; j--) {
        x->keys[j + 1] = x->keys[j];
    }

    x->keys[i] = y->keys[T - 1];
    x->n++;
}

// Function to insert a key into a non-full node
void insertNonFull(BTreeNode *x, int k) {
    int i = x->n - 1;

    if (x->leaf) {
        while (i >= 0 && x->keys[i] > k) {
            x->keys[i + 1] = x->keys[i];
            i--;
        }

        x->keys[i + 1] = k;
        x->n++;
    } else {
        while (i >= 0 && x->keys[i] > k) {
            i--;
        }
        i++;

        if (x->C[i]->n == 2 * T - 1) {
            splitChild(x, i, x->C[i]);

            if (x->keys[i] < k) {
                i++;
            }
        }
        insertNonFull(x->C[i], k);
    }
}
