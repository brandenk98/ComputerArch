#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

struct Node {
    Node *prev;
    Node *next;
    int value;
};

void freeing(Node* head)
{
    struct Node * temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

}
void gianna_node(Node **front_ptr, Node *tg_prev, Node *tg_next, Node *into_node) {

    if (!tg_prev) {
        into_node->next = tg_next;
        tg_next->prev = into_node;
        *front_ptr = into_node;
    }
    else if (!tg_next) {
        into_node->prev = tg_prev;
        tg_prev->next = into_node;
    }

    else {
        tg_prev->next = into_node;
        into_node->prev = tg_prev;
        tg_next->prev = into_node;
        into_node->next = tg_next;
    }
}
int main(int argc, char *argv[]) {

    FILE *tfile;
    tfile = fopen(argv[1], "r");

    if(tfile == NULL) {
        printf("error\n");
        return 0;
    }
    Node * ehead;
    Node * ohead;

    ehead = NULL;
    ohead = NULL;

    Node ** elist = &ehead;
    Node ** olist = &ohead;
    
    int length;
    int temp;
    Node *now_node;
    fscanf(tfile, "%d\n", &length);
    for(int i = 0; i < length; i++) {
        fscanf(tfile, "%d\t", &temp);
        Node *nNode = malloc(sizeof(Node));
        nNode->value = temp;
        nNode->prev = NULL;
        nNode->next = NULL;
        if ( (temp % 2) != 0) {
            now_node = *olist;
            if (!ohead) {
                ohead = nNode;
            }
            else {
                while(now_node) {

                    if(now_node->value <= temp) {
                        gianna_node(olist, now_node->prev, now_node, nNode);
                        break;
                    }
                    else if (!now_node->next) {
                        gianna_node(olist, now_node, NULL, nNode);
                        break;
                    }
                    else
                        now_node = now_node->next;
                }
            }
        } 
        else {
            now_node = *elist;
            if (!ehead) {
                ehead= nNode;
            }
            else {
                while(now_node) {
                    if(now_node->value >= temp) {
                        gianna_node(elist, now_node->prev, now_node, nNode);
                        break;
                    }
                    else if (!now_node->next) {
                        gianna_node(elist, now_node, NULL, nNode);
                        break;
                    }
                    else {
                        now_node = now_node->next;
                    }
                }
            }
        }
    }
    int *into = (int*) malloc(length * sizeof(int));
    int num;
    num = 0;
    now_node = *elist;
    while(now_node) {
        into[num] = now_node->value;
        num++;
        now_node = now_node->next;
    }
    now_node = *olist;
    while(now_node) {
       into[num] = now_node->value;
       num++;
       now_node = now_node->next;
    }
    for(int i = 0; i < length; i ++) {
        printf("%d\t", into[i]);
    }
    freeing(ohead);
    freeing(ehead);
    free(into);
    fclose(tfile);
    return 0;
}
