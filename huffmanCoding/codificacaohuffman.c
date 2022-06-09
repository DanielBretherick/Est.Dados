#include <stdio.h>
#include <stdlib.h>


struct node{
    int val;
    char key;
    struct node* next;
    struct node* l;
    struct node* r;
};


struct node* createNode(char key, int val){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->key = key;
    new_node->val = val;
    new_node->l = NULL;
    new_node->r = NULL;
    return new_node;
};

int deleteQueue(struct node** root, char key){
    struct node* aux = *root;
    if((*root)->key == key){
        *root = (*root)->next;
        return 1;
    }
    if((*root)->next == NULL){
        printf("Elemento nao esta na fila");
        return 0;
    }
    else{
        deleteQueue(&((*root)->next), key);
        return 1;
    }
}


int insertQueue(struct node* new_node, struct node** root){
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

struct node* joinNode(struct node* a, struct node* b){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

    new_node->val = (a->val) + (b->val);

    if(a->val >= b->val){
        new_node->r = a;
        new_node->l = b;
        return new_node;
    }

    new_node->r = b;
    new_node->l = a;
    return new_node;

};

struct node* huffmanTree(struct node** root){
    struct node*aux;
    if(*root == NULL){
        printf("Codificacao Vazia\n");
        return NULL;
    }
    if((*root)->next == NULL){
        return *root;
    }
    else{
        aux = joinNode((*root), (*root)->next);
        deleteQueue(root, (*root)->key);
        deleteQueue(root,(*root)->key);
        insertQueue(aux, root);
        huffmanTree(root);
    }
};


void runQueue(struct node* root){
    struct node* aux= root;
    while(aux){
        printf("%c %d \n", aux->key, aux->val);
        aux = aux->next;
    }
}

int simetricOrder(struct node* root){
    if(root->r == NULL && root->l == NULL){
        printf("%c", root->key);
        return 1;
    }
    simetricOrder(root->l);
    simetricOrder(root->r);
}



void countLetter(char *text, int*cont){
    int i=0;
    while(text[i] != '\0'){
        int val = text[i];
        cont[val]++;
        i++;
    }
}

void codeHuffman(char l, struct node* tree){

}


int main(){
    int cont[127];
    for(int i=0; i<127; i++){
        cont[i] = 0;
    }
    struct node* root;
    root = NULL;

    char text[]= "dfasdafasfdafasasassasasssss";

    countLetter(text, cont);

    for(int i=0; i<127; i++){
        if(cont[i] != 0){
            printf("%c %d\n", i, cont[i]);
        }
    }

    for(int i = 0; i<127; i++){
        if(cont[i] != 0){
            insertQueue(createNode(i, cont[i]), &root);
        }
    }
    printf("\n\n");

    runQueue(root);
    printf("\n\n");

    struct node* aux = huffmanTree(&root);
    simetricOrder(root);


    return 0;
}
