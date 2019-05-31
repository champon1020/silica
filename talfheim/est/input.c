#include <stdio.h>


void sample1(){
    int size;
    size = 30;
    char str[size];
    int i;

    printf("input: ");
    fgets(str, size, stdin);

    printf("%s\n", str);

    for(i=0; i<5; i++){
        printf("%c\n", str[i]);
    }
}


void sample2(){
    int size;
    size = 3;
    char str[size];
    int i;

    printf("input: ");
    scanf("%s", str);

    printf("%s\n", str);

    for(i=0; i<5; i++){
        printf("%c\n", str[i]);
    }
}


int main(void){
    //sample1();
    sample2();
    return 0;
}