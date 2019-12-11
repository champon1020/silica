#include <iostream>
#include <cstdio>
#include <cstring>

#define M 1046527
#define L 14

using namespace std;

// hash
char H[M][L];


// char to num
int getChar(char ch){
    if (ch == 'A') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else if (ch == 'T') return 4;
    else return 0;
}


// str to key
int getKey(char str[]){
    int sum = 0, p=1;
    for(int i=0; i < strlen(str); i++){
        sum += p*(getChar(str[i]));
        p *= 5;
    }
    return sum;
}


int h1(int key){
    return key % M;
}

int h2(int key){
    return 1 + (key % (M-1));
}


// strlen() is func of getting str length.
// then, '\0' is not included.
int find(char str[]){
    int h;
    int key = getKey(str);

    for(int i=0; ; i++){
        h = (h1(key) + i*h2(key)) % M;
        
        if(!strcmp(H[h], str)){
            return 1;

        }else if(strlen(H[h]) == 0){
            return 0;
        }
    }
    return 0;
}


int insert(char str[]){
    int h;
    int key = getKey(str);

    for(int i=0; ; i++){
        h = (h1(key) + i*h2(key)) % M;

        if(!strcmp(H[h], str)){
            return 1;

        }else if(strlen(H[h]) == 0){
            strcpy(H[h], str);
            return 0;
        }
    }

    return 0;
}


int main(void){
    int n, h;
    char str[L], op[9];

    // initialize
    for(int i=0; i<M; i++) H[i][0] = '\0';
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%s %s", op, str);

        if(op[0] == 'i'){
            insert(str);

        }else{
            if(find(str)){
                printf("yes\n");

            }else{
                printf("no\n");
            }
        }
    }
    return 0;
}