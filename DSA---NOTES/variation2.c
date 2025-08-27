#include <stdio.h>
#define MAX 10

typedef struct{
    int elem[MAX];
    int count;
}Etype, *EPtr;

void init(EPtr L)
{
  int i;
  L->count = 0;

  for(i = 0;i < MAX;i++){
    L->elem[i] = -1;
  }

}

void makeNULL(EPtr L)
{
  int i;
  L->count = 0;

  for(i = 0;i < MAX;i++){
    L->elem[i] = -1;
  }

}

void insertPos(EPtr L, int data, int position)
{
  int i;

    for(i = L->count;i  >= position;i--){
      L->elem[i + 1] = L->elem[i];
    }

    L->elem[position] = data;
    L->count++;
}

void insertFirst(EPtr L, int data)
{
  int i;

    for(i = L->count;i >= 0;i--){
      L->elem[i + 1] = L->elem[i];
    }

    L->elem[0] = data;
    L->count++;
}

void deletePos(EPtr L, int position)
{
  int i;

    for(i = position;i < L->count - 1;i++){
      L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

void deleteFirst(EPtr L)
{
  int i;

    for(i = 0;i < L->count - 1;i++){
      L->elem[i] = L->elem[i + 1];
    }
    L->count--;
}

int Locate(EPtr L, int data)
{
  int i;

    for(i = 0;i < L->count;i++){
      if(L->elem[i] == data){
        return i;
      }
    }

    return -1;
}

void deleteByValue(EPtr L, int data)
{
  int num;

    num = Locate(L, data);
    deletePos(L, num);
}


void insertSorted(EPtr L, int data)
{
  int i, j, temp;
  
  L->elem[L->count] = data;
  L->count++;

    for(i = 0;i < L->count - 1;i++){
      for(j = 0;j < L->count - i - 1;j++){
          if(L->elem[j] > L->elem[j + 1]){
            temp = L->elem[j];
            L->elem[j] = L->elem[j + 1];
            L->elem[j + 1] = temp;
          }
      }
    }
}

void display(EPtr L)
{  
  int i;
    for(i = 0;i < L->count;i++){
        printf("%d ", L->elem[i]);
    }

}

int main(){
  Etype L;

  init(&L);

  printf("\nInsertPos\n");

  insertPos(&L, 10, 0);
  insertPos(&L, 20, 1);
  insertPos(&L, 30, 2);
  insertPos(&L, 40, 3);
  insertPos(&L, 50, 4);
  display(&L);

  printf("\nInsertFirst:\n");

  insertFirst(&L, 6);
  display(&L);

  printf("\nDeletePos:\n");

  deletePos(&L, 3);
  display(&L);

  printf("\nDeleteFirst:\n");

  deleteFirst(&L);
  display(&L);

  printf("\nLocate:\n");

  int catcher = Locate(&L, 20);
  if(catcher != -1){
    printf("Found");
  }else{
    printf("Not Found");
  }

  printf("\nDeleteByValue:\n");

  deleteByValue(&L, 40);
  display(&L);

  printf("\nInsertSorted:\n");

  insertSorted(&L, 28);
  display(&L);

}