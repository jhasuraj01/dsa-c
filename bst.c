#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* new_node(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int value) {
    if(root == NULL) {
        root = new_node(value);
    }
    else if(value > root->value) {
        root->right = insert(root->right, value);
    }
    else {
        root->left = insert(root->left, value);
    }
    return root;
}

struct Node* find(struct Node* root, int value) {
    if(root == NULL) {
        return NULL;
    }
    else if(root->value == value) {
        return root;
    }
    else if(root->value < value) {
        return find(root->right, value);
    }
    else return find(root->left, value);
}


int main() {

    struct Node* bas_root = NULL;

    bas_root = insert(bas_root, 5);
    bas_root = insert(bas_root, 10);
    bas_root = insert(bas_root, 15);
    bas_root = insert(bas_root, 2);

    struct Node* searched_node = find(bas_root, 105);


    return 0;
}