#include <iostream>
#include <string>

using namespace std;

struct Card { char mark; int value; };

void bubbleSort(struct Card card[], int n);
void selectionSort(Card card[], int n);
void output(Card card[], int n);
bool isStable(struct Card c1[], struct Card c2[], int n);

void swap(Card* c1, Card* c2){ Card buf=*c1; *c1=*c2; *c2=buf; }


void bubbleSort(struct Card card[], int n){
    for(int i=0; i<n; i++){
        for(int j=n-1; j>i; j--){
            if(card[j-1].value > card[j].value){
                swap(&card[j-1], &card[j]);
            }
        }
    }
}


void selectionSort(struct Card card[], int n){
    for(int i=0; i<n; i++){
        int minind = i;
        for(int j=i+1; j<n; j++){
            if(card[minind].value > card[j].value){
                minind = j;
            }
        }
        swap(&card[i], &card[minind]);
    }
}


bool isStable(struct Card c1[], struct Card c2[], int n){
    for(int i=0; i<n; i++){
        if(c1[i].mark != c2[i].mark){
            return false;
        }
    }
    return true;
}


void output(struct Card card[], int n){
    for(int i=0; i<n; i++) cout << card[i].mark << card[i].value << " ";
    cout << endl;
}


int main(void){
    int n;
    Card card1[36];
    Card card2[36];

    cout << "num: ";
    cin >> n;
    cout << "cards:" << endl;
    for(int i=0; i<n; i++){
        cin >> card1[i].mark >> card1[i].value;
        card2[i] = card1[i];
    }

    bubbleSort(card1, n);
    selectionSort(card2, n);

    output(card1, n);
    cout << "Stable" << endl;
    output(card2, n);
    if(isStable(card1, card2, n)){
        cout << "Stable" << endl;
    }else{
        cout << "Not stable" << endl;
    }

    while(true){
        ;
    }
}