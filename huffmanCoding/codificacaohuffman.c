#include <stdio.h>
#include <stdlib.h>


struct node{
    int val;
    char key;
    struct node* next;
    struct node* l;
    struct node* r;
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
void countLetter(char *text, int*cont){
    int i=0;
    while(text[i] != '\0'){
        int val = text[i];
        cont[val]++;
        i++;
    }
}


int main(){
    int cont[127];
    for(int i=0; i<127; i++){
        cont[i] = 0;
    }
    struct node* root;
    root = NULL;

    char text[]= "Daniel Ambrozio Bretherick Marques";

    countLetter(text, cont);
    for(int i=0; i<127; i++){
        if(cont[i] != 0){
            insertQueue(i,cont[i], &root);
        }
    }
    runQueue(root);


    return 0;
}
