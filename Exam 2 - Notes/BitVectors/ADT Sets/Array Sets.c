#include <stdio.h>
#include <stdbool.h>
#define MAX 100

typedef struct{
    int content[MAX];
    int count;
} Set;

void init(Set s){
    Set newSet;
    newSet.count = 0;
    s = newSet;
}


int main(){

}