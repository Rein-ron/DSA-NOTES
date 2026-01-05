#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void swap(char** a,char** b){
    char* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(char* arr[], int n, int i){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && strcmp(arr[left], arr[largest]) > 0){
        largest = left;
    }
    if(right < n && strcmp(arr[right], arr[largest]) > 0){
        largest = right;
    }
    
    if(largest != i){
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(char *arr[], int n){
    int i;
    
    for (i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    
    for(i = n - 1;i > 0;i--){
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(char *arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%s ", arr[i]);
    }
    printf("\n");
}

int main() {
    char *items[] = {
        "Mango",
        "Banana",
        "Apple",
        "Pineapple",
        "Grapes",
        "Orange"
    };

    int total = sizeof(items) / sizeof(items[0]);

    printf("Items before sorting:\n");
    printArray(items, total);

    heapSort(items, total);

    printf("\nItems after sorting:\n");
    printArray(items, total);

    return 0;
}
