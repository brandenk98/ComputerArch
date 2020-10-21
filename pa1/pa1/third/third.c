#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    Node *prev;
    Node *next;
    int value;
};

int hash(int key) {
    if( (key % 10000) < 0)
        return (key % 10000) + 10000;
    else
        return (key % 10000);
	}

Node * lookUp(Node * hash_table[], int key) {

    Node * current_node = hash_table[hash(key)];

    while(current_node) {
        if(current_node->value == key) {
            return current_node;
        }
        else {
            current_node = current_node->next;
        }
    }

    return NULL;
}


void free_list(Node * head) {
    Node * temp;

    while( head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void hit(Node * hash_table[], int key) {

    Node * current_node = hash_table[hash(key)];
    Node * nNode = malloc(sizeof(Node));
    nNode->next = NULL;
    nNode->prev = NULL;
    nNode->value = key;

    while(current_node) {
        if(current_node->next == NULL) {
            current_node->next = nNode;
            nNode->prev = current_node;
            break;
        }
        else {
            current_node = current_node->next;
        }
    }
}

int main(int argc, char* argv[]) {

    FILE *tfile;
    tfile = fopen(argv[1], "r");

    if(tfile == NULL) {
        printf("error\n");
        return 0;
    }

    char opt;
    int key;
    int hitNums = 0;
    int looks = 0;

    Node * hash_table[10000];
    for(int i = 0; i < 10000; i++) {
        hash_table[i] = NULL;
    }

    while(fscanf(tfile, "%c\t%d\n", &opt, &key) == 2) {

        if(opt  == 'i') {
            int hashed_key = hash(key);

            if(hash_table[hashed_key] == NULL) {
                Node * nNode = malloc(sizeof(Node));
                nNode->value = key;
                nNode->next = NULL;
                nNode->prev = NULL;

                hash_table[hashed_key] = nNode;
            }


            else {
                hit(hash_table, key);
                hitNums++;
            }
        }

        else {
            if(lookUp(hash_table, key))
                looks++;
        }
    }

    printf("%d\n", hitNums);
    printf("%d\n", looks);

    for(int i = 0; i < 10000; i++) {
        free_list(hash_table[i]);
    }

    fclose(tfile);

    return 0;
}
