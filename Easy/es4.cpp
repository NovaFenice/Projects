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

int evaluate(char matrix[3][3]) {
    char winner = checkWin(matrix);
    if (winner == 'O') return +10;
    if (winner == 'X') return -10;
    return 0;
}

bool movesLeft(char matrix[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (matrix[i][j] == ' ') return true;
    
    return false;
}

int minimax(char matrix[3][3], bool isMax) {
    int score = evaluate(matrix);
    if (score != 0) return score;
    if (!movesLeft(matrix)) return 0;

    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (matrix[i][j] == ' ') {
                    matrix[i][j] = 'O';
                    best = max(best, minimax(matrix, false));
                    matrix[i][j] = ' ';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (matrix[i][j] == ' ') {
                    matrix[i][j] = 'X';
                    best = min(best, minimax(matrix, true));
                    matrix[i][j] = ' ';
                }
            }
        }
        return best;
    }
}

void bestMoveAI(char matrix[3][3]) {
    int bestVal = -1000;
    int moveX = -1, moveY = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i][j] == ' ') {
                matrix[i][j] = 'O';
                int moveVal = minimax(matrix, false);
                matrix[i][j] = ' ';

                if (moveVal > bestVal) {
                    bestVal = moveVal;
                    moveX = i;
                    moveY = j;
                }
            }
        }
    }

    matrix[moveX][moveY] = 'O';
}

int main() {
    char matrix[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int scelta;

    do {
        cout << "Vuoi giocare con un' amico o l' AI? (1 per giocare con un' amico, 2 per giocare con l' AI): ";
        cin >> scelta;
    } while (scelta != 1 && scelta != 2);

    int turn = 0;

    if (scelta == 1) {
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
    } else {
        while (true) {
            drawTicTacToe(matrix);
            cout << "\nTurno del giocatore " << (turn % 2 == 0 ? 'X' : 'O') << endl;
            
            if (turn % 2 == 0) {
                putMark(matrix, turn);
            } else {
                bestMoveAI(matrix);
            }

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
    }

    return 0;
}