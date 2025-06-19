#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void readMinMax(int &min, int &max) {
    do {
        cout << "Inserisci il minimo: ";
        cin >> min;
        cout << "Inserisci il massimo: ";
        cin >> max;
    }while(min > max);
}
int generateNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

void run(int guess) {
    int life = 5;
    while (life > 0) {
        int num;
        cout << "Vite: " << life << endl;
        cout << "Inserisci un numero: ";
        cin >> num;
        if (num == guess) {
            cout << "Hai vinto!";
            return;
        } else {
            if (num < guess) {
                cout << "Il numero e' piu' grande" << endl;
            } else {
                cout << "Il numero e' piu' piccolo" << endl;
            }
            life--;
        }
    }
}

int main() {
    srand(time(NULL));
    int min, max;
    readMinMax(min, max);
    int guess = generateNumber(min, max);
    run(guess);
    return 0;
}