#include <stdio.h>
#include <string.h>

int hash(int value){
    return value % 5;
}

int hashName(char *name) {
    return toupper(name[0]) - 'A';
}

int hashRgb(int r, int g, int b) {
    return (r  + g + b) % 64;
}

int main(){
    int value = 43;

    int result = hash(value);

    printf("Hundredths Place of %d is %d\n", value, result);

    printf("%d\n", hashName("Anderson")); 
    printf("%d\n", hashName("Brown"));    
    printf("%d\n", hashName("Zelda"));    

    printf("\n");
    printf("%d\n", hashRgb(255, 0, 0));     
    printf("%d\n", hashRgb(0, 255, 0));    
    printf("%d\n", hashRgb(0, 0, 255));    
    printf("%d\n", hashRgb(123, 200, 45));

    return 0;
}

