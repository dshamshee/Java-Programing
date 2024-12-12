#include <stdio.h>
#include <stdlib.h>

#define ORDER 3 // B+ Tree order (maximum number of children)

// Node structure for B+ Tree
typedef struct Node {
    int keys[ORDER - 1];           // Array to store keys
    struct Node* children[ORDER];  // Array to store pointers to children
    int num_keys;                 // Number of keys in the node
    int is_leaf;                  // Flag to check if the node is a leaf
} Node;

// Forward declaration of split_child
void split_child(Node* parent, int index);

// Function to create a new node
Node* create_node(int is_leaf) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->num_keys = 0;
    new_node->is_leaf = is_leaf;
    
    for (int i = 0; i < ORDER; i++) {
        new_node->children[i] = NULL;
    }
    
    return new_node;
}

// Function to insert a key in a non-full node
void insert_non_full(Node* node, int key) {
    int i = node->num_keys - 1;
    
    if (node->is_leaf) {
        // Insert key in leaf node
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->num_keys++;
    } else {
        // Find the child where the key should be inserted
        while (i >= 0 && node->keys[i] > key) {
            i--;
        }
        i++;
        
        // If the child is full, split it
        if (node->children[i]->num_keys == ORDER - 1) {
            split_child(node, i);
            if (node->keys[i] < key) {
                i++;
            }
        }
        insert_non_full(node->children[i], key);
    }
}

// Function to split a child node
void split_child(Node* parent, int index) {
    Node* full_child = parent->children[index];
    Node* new_child = create_node(full_child->is_leaf);
    
    new_child->num_keys = ORDER / 2;
    
    // Move the second half of the keys to the new child node
    for (int i = 0; i < ORDER / 2; i++) {
        new_child->keys[i] = full_child->keys[i + ORDER / 2];
    }
    
    // If the child is not a leaf, move the children to the new node
    if (!full_child->is_leaf) {
        for (int i = 0; i < ORDER / 2; i++) {
            new_child->children[i] = full_child->children[i + ORDER / 2];
        }
    }
    
    full_child->num_keys = ORDER / 2;
    
    // Shift the parent's children and keys to make room for the new child
    for (int i = parent->num_keys; i > index; i--) {
        parent->children[i + 1] = parent->children[i];
    }
    parent->children[index + 1] = new_child;
    
    // Move the middle key from the full child to the parent
    for (int i = parent->num_keys - 1; i >= index; i--) {
        parent->keys[i + 1] = parent->keys[i];
    }
    parent->keys[index] = full_child->keys[ORDER / 2 - 1];
    parent->num_keys++;
}

// Function to insert a key into the B+ tree
void insert(Node** root, int key) {
    Node* r = *root;
    
    if (r->num_keys == ORDER - 1) {
        // Create a new root if the current root is full
        Node* s = create_node(0);
        s->children[0] = r;
        *root = s;
        split_child(s, 0);
        insert_non_full(s, key);
    } else {
        insert_non_full(r, key);
    }
}

// Function to print the B+ Tree (In-order traversal)
void print_tree(Node* root, int level) {
    if (root == NULL) return;
    
    // Print all keys in the node
    for (int i = 0; i < root->num_keys; i++) {
        printf("%d ", root->keys[i]);
    }
    printf("\n");
    
    // If the node is not a leaf, recursively print its children
    if (!root->is_leaf) {
        for (int i = 0; i <= root->num_keys; i++) {
            print_tree(root->children[i], level + 1);
        }
    }
}

int main() {
    Node* root = create_node(1);  // Create root node as a leaf node
    
    // Inserting keys into the B+ tree
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 12);
    insert(&root, 30);
    insert(&root, 7);
    insert(&root, 17);
    
    // Print the B+ tree
    printf("B+ Tree after insertions:\n");
    print_tree(root, 0);
    
    return 0;
}
