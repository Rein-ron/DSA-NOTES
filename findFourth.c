#include <stdio.h>
#include <stdbool.h>

int findFourth(char val){
    int sum;
    return sum = val >> 3 & 1;

}

void displayBit(int val){
    int bits = sizeof(int) * 2;
    unsigned int mask = 1 << (bits - 1);

    while(mask != 0){
        printf("%d", (val & mask) ? 1 : 0);
        mask >>= 1;
    }    
}   

int main(){
    int bin = 252;

    int catcher = findFourth(bin);

    printf("%d\n", catcher);
    displayBit(bin);
    return 0;
}