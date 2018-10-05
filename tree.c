#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node* l_leaf;
    struct node* r_leaf;
} node_t;

void ShowSort(node_t* root)
{
    if (root == NULL) {
        //printf("+\n");
        return;
    }
    ShowSort(root->l_leaf);
    printf("%d\n", root->val);
    ShowSort(root->r_leaf);
}

void Push(node_t** root, int value)
{
    if (*root == NULL) {
        *root = malloc(sizeof(root));
        (*root)->val = value;
        (*root)->l_leaf = NULL;
        (*root)->r_leaf = NULL;
        return;
    }

    if (value < (*root)->val){
        Push((&(*root)->l_leaf), value);
    } else {
        Push((&(*root)->r_leaf), value);
    }
}

int main(int argc, char const *argv[])
{
    node_t* root = NULL;

    for (int i = 0; i < 10; i++) {
        Push(&root, rand()%10);

        //printf("%p\n", root);
    }

    ShowSort(root);
}