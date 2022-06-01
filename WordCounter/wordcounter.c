
//Letter counter
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char key;
    int freq;
}node;

void countLetter(char *text, int*cont){
    int i=0;
    while(text[i] != '\0'){
        int val = text[i];
        cont[val]++;
        i++;
    }
}



int main(){
    int cont[256];
    for(int i = 0; i<256; i++){
        cont[i] = 0;
    }
    char text[] = "Oi tudo bem como vai! KKKK";

    countLetter(text, cont);

    for(int i=0; i<256; i++){
        printf("%c %d\n", i, cont[i]);
    }
    return 0;
}
