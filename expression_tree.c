#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define MAX_STACK_SIZE 10000

struct Node
{
    char data;
    struct Node* left;
    struct Node* right;   
};

struct Node* new_node(char data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* expression_tree(int length, char expression[length]) {
    
    // create a stack;
    struct Node* stack[MAX_STACK_SIZE];
    int stack_size = 0;

    for (int i = 0; i < length; ++i)
    {
        char symbol = expression[i];
        if('0' <= symbol && symbol <= '9') {
            stack[stack_size++] = new_node(symbol);
        }
        else {
            struct Node* parent = new_node(symbol);
            parent->right = stack[--stack_size];
            parent->left = stack[--stack_size];
            stack[stack_size++] = parent;
        }
    }
    assert(stack_size == 1);
    return stack[0];
}

void print(struct Node* node) {
    printf("%c", node->data);
}

// recursive preorder
void preorder(struct Node* root) {
    if(root == NULL) return;
    print(root);
    preorder(root->left);
    preorder(root->right);
}

// recursive inorder
void inorder(struct Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    print(root);
    inorder(root->right);
}

// recursive postorder
void postorder(struct Node* root) {
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    print(root);
}

// non recursive preorder
void preorderNonRecursive(struct Node* root) {
    struct Node* stack[MAX_STACK_SIZE];
    int stack_size = 0;

    stack[stack_size++] = root;

    while(stack_size > 0) {
        struct Node* root = stack[--stack_size];
        if(root == NULL) continue;
        print(root);
        stack[stack_size++] = root->right;
        stack[stack_size++] = root->left;
    }
}

// non recursive inorder
void inorderNonRecursive(struct Node* root) {
    // struct Node* stack[MAX_STACK_SIZE];
    // int stack_size = 0;

    // stack[stack_size++] = root;

    // while(stack_size > 0) {
    //     struct Node* root = stack[--stack_size];
    //     if(root == NULL) continue;
    //     print(root);
    //     stack[stack_size++] = root->right;
    //     stack[stack_size++] = root;
    //     stack[stack_size++] = root->left;
    // }
}

// non recursive postorder

int main() {

    int length;
    printf("Enter Length of Postfix Expression: ");
    scanf("%d", &length);

    // input postfix expression
    char expression[length];
    printf("Enter Expression: ");
    scanf("%s", expression);

    struct Node* root = expression_tree(length, expression);

    // PreOrder Traversal
    printf("PreOrder: ");
    preorder(root);

    // InOrder Traversal
    printf("\nInOrder: ");
    inorder(root);

    // PostOrder Traversal
    printf("\nPostOrder: ");
    postorder(root);

    // // PreOrder Non Recursive Traversal
    // printf("\nPreOrder Non Recursive Traversal: ");
    // preorderNonRecursive(root);

    printf("\n\n");

    return 0;
}