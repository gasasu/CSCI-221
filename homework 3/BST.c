#include <stdio.h>
#include <stdlib.h>
#include <stdint-gcc.h>
#include <stdbool.h>

typedef struct BSTNode{
    uint32_t value;
    struct BSTNode* left;
    struct BSTNode* right;
}BSTNode;

typedef struct BST{
int size;
struct BSTNode* root;
}BST;

void addnode(BST* inputTree, int value){
BSTNode* newnode = (BSTNode*) malloc(sizeof(BSTNode));
newnode->value = value;
if (inputTree->root == NULL){
    inputTree->root = newnode;
}
else{
    BSTNode* ptr = inputTree->root;
    while (true){
        if (value > ptr->value){
            if (ptr->right == NULL){
                ptr->right = newnode;
                break;
            }
            ptr = ptr->right;
        }
        else if (value <ptr->value){
            if (ptr->left == NULL){
                ptr->left = newnode;
                break;
            }
            ptr = ptr->left;
        }
        else return;
    }
}

inputTree->size++;
}

BST* createBST(int array[], int size){
    BST* tree;
    tree->size = 0;

    for (int i=0; i<size; i++){
        addnode(tree, array[i]);
    }
return tree;
}

void freeBST(BST inputTree){

void freenode(BSTNode* node){
if (node!= NULL){
    freenode(node->left);
    freenode(node->right);
    free(node);
}
}

BSTNode* node = inputTree.root;
freenode(node);

}

BSTNode* successsor(BSTNode* node){
    BSTNode* current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

int findnode(BSTNode* node, int value){
if (node == NULL) return 0;
if (node->value == value) return 1;
else if (node->value > value) return findnode(node->left, value);
else return (node->right, value);
}

int removeNode(BST* inputTree, int value){
    BSTNode* root = inputTree->root;
    int check = findnode(root, value);
    if (check == 0){
        return 0;}
BSTNode* removenode(BSTNode* node, int value){
    if (value < node->value) node->left = removenode(node->left, value);
    else if (value > node->value) node->right = removenode(node->right, value);
    else {
        if (node->left == NULL && node->right == NULL){
            free(node);
            return NULL;
        }
        else if (node->left == NULL){
            BSTNode* temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL){
            BSTNode* temp = node->left;
            free(node);
            return temp;
        }
        else{
            BSTNode* temp = successsor(node->right);
            node->value = temp->value;
            removenode(node->right, temp->value);
        }
    }
    return node;}
root = removenode(root, value);
inputTree->size--;
return 1;
}
int main(){
return 0;}
