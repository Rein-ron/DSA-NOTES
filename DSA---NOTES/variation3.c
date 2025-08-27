#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

typedef struct{
    int* elemPtr;
    int count;
    int max;
}List;

List init(List L){
    L.elemPtr = malloc(sizeof(int) * LENGTH);
    int i;

    for(i = 0;i < LENGTH;i++){
        L.elemPtr[i] = -1;
    }

    L.count = 0;
    L.max = LENGTH;


    return L;
}

List insertPos(List L, int data, int position){
    int i;

    if(L.count <= max){
    for(i = L.count;i > position;i--){
        L.elemPtr[i + 1] = L.elemPtr[i]; 
    }
    L.elemPtr[position] = data;
    L.count++;
    }else{
        L = resize(L);
    }

    return L;
}

List insertFirst(List L, int data){
    int i;

    if(L.count <= max){
    for(i = L.count;i > 0;i--){
        L.elemPtr[i + 1] = L.elemPtr[i];
    }
    L.elemPtr[0] = data;
    L.count++;
    }else{
        L = resize(L);
    }

    return L;
}

List deletePos(List L, int position){
    int i;

    for(i = position;i < L.count - 1;i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }

    L.count--;

    return L;
}

List deleteFirst(List L){
    int i;

    for(i = 0;i < L.count - 1;i++){
        L.elemPtr[i] = L.elemPtr[i + 1];
    }

    L.count--;

    return L;
}

int Locate(List L, int data){
    int i;

    for(i = 0;i < L.count;i++){
        if(L.elemPtr[i] == data){
            return i;
        }
    }

    return -1;
}

List insertSorted(List L, int data){
    int i, j;
    int temp;

    if(L.count <= max){
    L.elemPtr[L.count] = data;
    L.count++;

    for(i = 0;i < L.count - 1;i++){
        for(j = 0;j < L.count - i - 1;j++){
            if(L.elemPtr[j] > L.elemPtr[j + 1]){
                    temp = L.elemPtr[j];
                    L.elemPtr[j] = L.elemPtr[j + 1];
                    L.elemPtr[j + 1] = temp;
                }
            }
        }
    }else{
        L = resize(L);
    }

    return L;
}

void display(List L){
    int i;

    for(i = 0;i < L.count;i++){
        printf("%d ", L.elemPtr[i]);
    }
}

List resize(List L){
    int* temp = realloc(L.elemPtr, sizeof(int) * LENGTH);

    L.elemPtr = temp;
    L.max = (L.max * 2);

    return L;
}

int main(){
    List L;

    L = init(L);

    printf("\nInsertPos\n");
    L = insertPos(L, 32, 0);
    L = insertPos(L, 50, 1);
    L = insertPos(L, 43, 2);
    display(L);

    printf("\nInsertFirst\n");
    L = insertFirst(L, 19);
    L = insertFirst(L, 21);
    display(L);

    printf("\nDeletePos\n");
    L = deletePos(L, 2);
    display(L);

    printf("\nDeleteFirst\n");
    L = deleteFirst(L);
    display(L);

    printf("\nLocate\n");
    int result = Locate(L, 50);
    if(result){
        printf("Found");
    }else{
        printf("Not Found");
    }

    printf("\nInsertSorted\n");
    L = insertSorted(L, 78);
    display(L);

    return 0;
}