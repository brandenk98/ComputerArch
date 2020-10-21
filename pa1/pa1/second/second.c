#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    Node *prev;
    Node *next;
    int value;
};
void free_list(Node * head) {
    Node * temp;

    while( head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void input_node(Node **head, Node *tg_node_prev, Node *tg_node_next, Node *inserted_node) {

    if( !(*head) ) {
        *head = inserted_node;
    }

    else if (!tg_node_prev) {
        inserted_node->next = tg_node_next;
        tg_node_next->prev = inserted_node;
        *head = inserted_node;
    }
    else if (!tg_node_next) {
        inserted_node->prev = tg_node_prev;
        tg_node_prev->next = inserted_node;
    }

    else {
        tg_node_prev->next = inserted_node;
        inserted_node->prev = tg_node_prev;

        tg_node_next->prev = inserted_node;
        inserted_node->next = tg_node_next;
    }
}

void getRid_node(Node **list, Node *tg_node) {

    if(!(tg_node->prev)) {
        *list = tg_node->next;
        if(*list != NULL)
            tg_node->next->prev = NULL;
    }

    else if (!(tg_node->next)) {
        tg_node->prev->next = NULL;
    }

    else {
        tg_node->prev->next = tg_node->next;
        tg_node->next->prev = tg_node->prev;
    }

    free(tg_node);
}

Node * lookUp_node(Node *list, int tg_value) {

    Node *now_node = list;

    while(now_node) {
        if(now_node->value == tg_value) {
            return now_node;
        }
        else {
            now_node = now_node->next;
        }
    }

    return NULL;
}

int findSize(Node *first_node) {

    int count = 0;
    Node *now_node = first_node;

    while(now_node) {
        count++;
        now_node = now_node->next;
    }

    return count;
}

void print_list(Node *first_node) {

    Node *now_node = first_node;
    while( now_node ) {

        if( now_node->prev == NULL || now_node->value != now_node->prev->value) {
            printf("%d\t", now_node->value);
        }

        now_node = now_node->next;
    }
    printf("\n");
}
int main(int argc, char *argv[]) {
    FILE *tfile;
    tfile = fopen(argv[1], "r");
    if(tfile == NULL) {
        printf("error\n");
        return 0;
    }
    char option;
    int num;
    Node *list = NULL;
    Node **list_ptr;
    while( fscanf(tfile, "%c\t%d\n", &option, &num) == 2) {
        if(option == 'i') {
            Node *new_node = malloc(sizeof (Node));
            new_node->prev = NULL;
            new_node->next = NULL;
            new_node->value = num;

            if(!list) {
                list = new_node;
                list_ptr = &list;
            } else {
                Node *now_node;
                now_node = *list_ptr;
                while(now_node) {
                    if(now_node->value >= num) {
                        input_node(list_ptr, now_node->prev, now_node, new_node);
                        break;
                    }
                    else if (!now_node->next) {
                        input_node(list_ptr, now_node, NULL, new_node);
                        break;
                    }
                    else {
                        now_node = now_node->next;
                    }
                }
            }
        }
        if(option == 'd') {
            Node *tg_node;
            tg_node = lookUp_node(list, num);

            if(tg_node)
                getRid_node(list_ptr, tg_node);
        }
    }
    printf("%d\n" , findSize(list));
    print_list(list);
    free_list(list);
    fclose(tfile);
    return 0;
}

