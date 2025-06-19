#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Note {
    string name;
    string surname;
    int age;
    string address;
    string phone;
    string email;
};

void readDate(Note note[], int n) {
    for(int i = 0; i < n; i++) {
        cout << "Persona numero: " << i + 1 << endl;
        cout << "Inserisci il nome: ";
        getline(cin, note[i].name);
        cout << "Inserisci il cognome: ";
        getline(cin, note[i].surname);
        cout << "Inserisci l'eta: ";
        cin >> note[i].age;
        cin.ignore();
        cout << "Inserisci l'indirizzo: ";
        getline(cin, note[i].address);
        cout << "Inserisci il numero di telefono: ";
        getline(cin, note[i].phone);
        cout << "Inserisci l'email: ";
        getline(cin, note[i].email);
        cout << endl;
    }
}

void printDate(Note note[], int n) {
    ofstream f("Note.txt", ios::app);
    if (!f) {
        cout << "Errore nell'apertura del file" << endl;
        return;
    } else {
        for(int i = 0; i < n; i++) {
            f << string(50, '-') << endl;
            f << "Nome: " << note[i].name << endl;
            f << "Cognome: " << note[i].surname << endl;
            f << "Eta: " << note[i].age << endl;
            f << "Indirizzo: " <<note[i].address << endl;
            f << "Telefono: " << note[i].phone << endl;
            f << "Email: " << note[i].email << endl;
            f << string(50, '-') << endl;
        }
    }
}

int main() {
    int n;
    do {
        cout << "Inserisci il numero di persone da inserire: ";
        cin >> n;
    } while (n <= 0);
    Note note[n];
    cin.ignore();
    readDate(note, n);
    printDate(note, n);
    return 0;
}