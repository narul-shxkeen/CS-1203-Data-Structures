#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

//Using a stack to keep track of nodes that need to be visited. Root gets pushed first to the stack.

void inOrderTrav(struct node* curr) {
    if (curr == NULL)
        return;
    struct node* stack[100]; // Assuming a maximum of 100 nodes in the stack.
    int top = -1;
    while (1) {
        while (curr != NULL) {
            stack[++top] = curr;
            curr = curr->left; //Goes to the left child of current node.
        }
        if (top == -1)       //Breaks when the stack is empty.
            break;
        curr = stack[top--];
        printf("%d ", curr->data); //When there are no child, print the node and move on to right child of parent node.
        curr = curr->right;
    }
}

//The following is a function to create a horizontal representation of binary search tree.
//All nodes below a selected node are smaller and the ones above are greater.
void printTree(struct node* root, int level) {

    if (root == NULL)
        return;

    level += 5;

    printTree(root->right, level);

    printf("\n");
    for (int i = 5; i < level; i++)
        printf(" ");
    printf("%d\n", root->data);

    printTree(root->left, level);
}

int main() {
    struct node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(14);
    root->left->left = newNode(4);
    root->left->right = newNode(9);
    root->left->right->left = newNode(6);
    root->right->left = newNode(11);
    root->right->right = newNode(30);
    root->right->right->right = newNode(45);
    printf("Horizontal representation of the Binary Tree Structure on which the traversal is being performed::\n");
    printTree(root, 0);
    printf("The inOrder Traversal of the given tree is : ");
    inOrderTrav(root);

    return 0;
}
