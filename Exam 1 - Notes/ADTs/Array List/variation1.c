#include <stdio.h>
#define size 10

typedef struct{
    int elem[size];
    int count;
}List;

List init()
{
    List L;
    int i;
    L.count = 0;

    for(i = 0;i < size;i++){
        L.elem[i] = -1;
    }

    return L;
}

List insertPos(List L, int data, int position)
{
    int i;
        for(i = L.count - 1;i >= position;i--){
           L.elem[i + 1] = L.elem[i];  
        }
        L.elem[position] = data;
        L.count++;    

    return L;
}

List insertFirst(List L, int data)
{
    int i;
        for(i = L.count - 1;i >= 0;i--){
           L.elem[i + 1] = L.elem[i];  
        }
        L.elem[0] = data;
        L.count++;    

    return L;
}

List deletePos(List L, int position)
{
    int i;

    for(i = position;i < L.count;i++){
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;

    return L;
}

List deleteFirst(List L){
    int i;

    for(i = 0;i < L.count - 1;i++){
        L.elem[i] = L.elem[i + 1];
    }
    L.count--;

    return L;
}


int Locate(List L, int data){
    int i;

    for(i = 0;i < L.count;i++){
        if(L.elem[i] == data){
            return i;
        }

    }

    return -1;
}

List deleteByValue(List L, int data){
    int index;
    
    index = Locate(L, data);

    if(index != -1) L = deletePos(L, index);

    return L;
}

List insertSorted(List L, int data){
    int i, j, temp;

    L.elem[L.count] = data;
    L.count++;

    for(i = 0;i < L.count - 1;i++){
        for(j = 0;j < L.count - i - 1;j++){
            if(L.elem[j] > L.elem[j + 1]){
                temp = L.elem[j];
                L.elem[j] = L.elem[j + 1];
                L.elem[j + 1] = temp;
            }
        }
    }

    return L;
}

void display(List L){
    int i;
    
    for(i = 0;i < L.count;i++){
        printf("%d ", L.elem[i]);
    }

}
int main(){
    List L = init(L);

    int i;
    display(L);
    
    printf("\nInsertPos:\n");
    
    L = insertPos(L, 90, 0);
    L = insertPos(L, 45, 1);
    L = insertPos(L, 20, 2);
    L = insertPos(L, 25, 3);
    L = insertPos(L, 44, 4);
    L = insertPos(L, 85, 5);
    L = insertPos(L, 77, 6);
    display(L);

    printf("\nInsertFirst:\n");

    L = insertFirst(L, 10);
    display(L);

    printf("\nDeletePos:\n");

    L = deletePos(L, 4);
    display(L);

    printf("\nDeleteFirst:\n");

    L = deleteFirst(L);
    display(L);

    printf("\nLocate:\n");

    int catcher = Locate(L, 5);
    if(catcher != -1){
        printf("Found");
    }else{
        printf("Not Found");
    }
    
    printf("\nDeleteByValue:\n");
    L = deleteByValue(L, 45);
    display(L);

    printf("\nInsertSorted:\n");

    L = insertSorted(L, 16);
    display(L);

    return 0;
}