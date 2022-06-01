//Priority Queue

#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    char key;
    struct node* next;
};

int insertQueue(char key, int val, struct node** root){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->val = val;
    if(*root == NULL){
        *root = new_node;
        new_node->next = NULL;
        return 1;
    }
    if(new_node->val <= (*root)->val){
        new_node->next = *root;
        *root = new_node;
        return 1;
    }
    else{
        struct node* ant = *root;
        struct node* aux = (*root)->next;
        while(aux != NULL){
                if(new_node->val > ant->val && new_node->val <= aux->val){
                    ant->next = new_node;
                    new_node->next = aux;
                    return 1;
                }
                else{
                    ant = aux;
                    aux = aux->next;
                }
        }
        ant->next = new_node;
        new_node->next = NULL;
        return 1;
    }

}

void runQueue(struct node* root){
    struct node* aux= root;
    while(aux){
        printf("%c %d \n", aux->key, aux->val);
        aux = aux->next;
    }
}

int main(){
    struct node* root;
    root = NULL;
    insertQueue('b',1, &root);
    insertQueue('d',4, &root);
    insertQueue('a',2, &root);
    insertQueue('c',3, &root);
    runQueue(root);
}
