#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode BSTNode;

struct BSTNode {
    int value;
    BSTNode * left;
    BSTNode * right;
};
void treeFree(BSTNode * root) {
    if(root == NULL) {
        return;
    }

    treeFree(root->left);
    treeFree(root->right);
    free(root);
}
void printingTree(BSTNode * root) {

    if(!root) {
        return;
    }

    printingTree(root->left);
    printf("%d\t", root->value);
    printingTree(root->right);

}
void gianna_node(BSTNode ** root_ptr, BSTNode * into_node) {

    BSTNode * now_node;
    now_node = *root_ptr;

    if(!now_node) {
        *root_ptr = into_node;
    }
    else {
        while(now_node) {
            if(now_node->value == into_node->value) {
                free(into_node);
                break;
            }
            else if(into_node->value < now_node->value) {
                if(!now_node->left) {
                    now_node->left = into_node;
                    break;
                }
                else {
                    now_node = now_node->left;
                }
            }
            else if(into_node->value > now_node->value) {
                if(!now_node->right) {
                    now_node->right = into_node;
                    break;
                }
                else {
                    now_node = now_node->right;
                }
            }

        }
    }
}

int main(int argc, char *argv[]) {

    FILE *tfile;
    tfile = fopen(argv[1], "r");

    if(tfile == NULL) {
        printf("error\n");
        return 0;
    }
    int temp;
    char opt;
    BSTNode * root;
    root = NULL;
    BSTNode ** root_ptr;
    root_ptr = &root;
    while(fscanf(tfile, "%c\t%d\n", &opt, &temp) == 2) {
        BSTNode * nNode;
        nNode = malloc(sizeof (BSTNode));
        nNode->left = NULL;
        nNode->right = NULL;
        nNode->value = temp;
        gianna_node(root_ptr, nNode);
    }
    printingTree(root);
    treeFree(root);
    fclose(tfile);
    return 0;
}
