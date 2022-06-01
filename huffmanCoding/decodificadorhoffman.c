#include <stdio.h>
#include <string.h>

typedef struct{
    char a;
    struct No* esq;
    struct No* dir;
}No;


void recupera(char* preordem, char* inter){
}
void decodifica(No* raiz, char* texto){
    No *aux = raiz;
    for(int i = 0; texto[i] != "\0"; i++){
        if(aux->esq == NULL && aux->dir == NULL){
            printf("%c", texto[i]);
        }
        else{
            if(texto[i] == "0"){
                aux = aux->dir;
            }
            else{
                aux = aux->esq;
            }
        }
    }
}

int main(){

    return 0;
}
