#include <iostream>

using namespace std;

void drawTicTacToe(char matrix[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << matrix[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "--+---+--" << endl;
    }
}

void putMark(char matrix[3][3], int turn) {
    int x, y;
    do {
        do {
            cout << "Inserisci il numero della riga: ";
            cin >> x;
        } while (x <= 0 || x > 3);
        do {
            cout << "Inserisci il numero della colonna: ";
            cin >> y;
        } while (y <= 0 || y > 3);
    }while (matrix[x - 1][y - 1] != ' ');

    matrix[x - 1][y - 1] = turn %2 == 0 ? 'X' : 'O';
}

char checkWin(char matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2] && matrix[i][0] != ' ')
            return matrix[i][0];
        if (matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i] && matrix[0][i] != ' ')
            return matrix[0][i];
    }
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && matrix[0][0] != ' ')
        return matrix[0][0];
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && matrix[0][2] != ' ')
        return matrix[0][2];

    return ' ';
}

bool isDraw(char matrix[3][3]) {
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if (matrix[i][j] == ' ') return false;

    return checkWin(matrix) == ' ';
}

int main() {
    char matrix[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int turn = 0;

    while (true) {
        drawTicTacToe(matrix);
        cout << "\nTurno del giocatore " << (turn % 2 == 0 ? 'X' : 'O') << endl;
        putMark(matrix, turn);

        char winner = checkWin(matrix);
        if (winner == 'X' || winner == 'O') {
            drawTicTacToe(matrix);
            cout << "\nHa vinto " << winner << "!" << endl;
            break;
        } else if (isDraw(matrix)) {
            drawTicTacToe(matrix);
            cout << "\nPareggio!" << endl;
            break;
        }

        turn++;
    }

    return 0;
}