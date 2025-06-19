#include <iostream>

using namespace std;

void leggi(char &op, int &num1, int &num2) {
    do {
        cout << "Inserisci l'operatore (+, -, *, /): ";
        cin >> op;
    } while (op != '+' && op != '-' && op != '*' && op != '/');

    cout << "Inserisci il primo numero: ";
    cin >> num1;
    cout << "Inserisci il secondo numero: ";
    cin >> num2;
}

void calcola(int num1, int num2, char op, double &risultato) {
    switch(op){ 
        case '+':
            risultato = num1 + num2;
            break;
        case '-':
            risultato = num1 - num2;
            break;
        case '*':
            risultato = num1 * num2;
            break;
        case '/':
            risultato = num1 / num2;
            break;
    }
}

void stampa(double risultato) {
    cout << "Il risultato e': " << risultato << endl;
}
 
int main() {
    int num1, num2;
    double risultato;
    char op;

    leggi(op, num1, num2);
    calcola(num1, num2, op, risultato);
    stampa(risultato);

    return 0;
}