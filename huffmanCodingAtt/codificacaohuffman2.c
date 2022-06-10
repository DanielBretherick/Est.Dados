#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    new_node->r = a;
    new_node->l = b;
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

int simetricOrder(struct node* root, char a[30], char cod[127][100]){
    if(root->r == NULL && root->l == NULL){
        strcpy(cod[root->key], a);
        return 1;
    }
    char copy[30];
    strcpy(copy, a);
    strcat(copy, "1");
    strcat(a, "0");
    simetricOrder(root->l, copy, cod);
    simetricOrder(root->r, a, cod);
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
    struct node* root;
    struct node* aux;
    struct node* aux2;
    root = NULL;
    int tamCod= 0 ;
    int cont[127];
    for(int i=0; i<127; i++){
        cont[i] = 0;
    }


    char text[]= "Daniel ambrozio bretherick marques";

    countLetter(text, cont);
    for(int i=0; i<127; i++){
        if(cont[i] != 0){
            insertQueue(createNode(i,cont[i]) , &root);
            tamCod++;
        }
    }

    runQueue(root);
    aux = huffmanTree(&root);
    aux2 = root;
    char m[] = ".";
    char c[30] = "";
    char cod[127][100];
    for(int i = 0; i<127; i++){
      strcpy(cod[i], "-");
    }
    printf("\n\n");
    simetricOrder(aux, c, cod);
    for(int i = 0; i<127; i++){
        if(strcmp(cod[i],"-"))
          printf("%c %s \n",i, cod[i]);
    }

    FILE *huffman;
    huffman = fopen("huffman.txt", "w");
    for(int i=0; text[i] != '\0' ; i++){
      fprintf(huffman, "%s", cod[text[i]]);
    }
    fclose(huffman);

    FILE *huffmanText;
    huffman = fopen("huffmanText.txt", "w");
    for(int i=0; text[i] != '\0' ; i++){
      fprintf(huffman, "%c", text[i]);
    }
    fclose(huffmanText);

}
