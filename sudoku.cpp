#include <iostream>
#include <math.h>
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int N;
void start();

void printSudoku(int sudoku[][100]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cout << sudoku[row][col] << " ";
        }
        cout << endl;
    }
}

bool emptyCell(int sudoku[][100], int row, int col, int n) {
    for (int i = 0; i < N; i++) {
        if (sudoku[row][i] == n || sudoku[i][col] == n) {
            return false;
        }
    }

    int startR = row - row % (int)sqrt(N);
    int startC = col - col % (int)sqrt(N);

    for (int i = 0; i < (int)sqrt(N); i++) {
        for (int j = 0; j < (int)sqrt(N); j++) {
            if (sudoku[startR + i][startC + j] == n) {
                return false;
            }
        }
    }
    return true;
}

bool solveSudoku(int sudoku[][100]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (sudoku[row][col] == 0) {
                for (int n = 1; n <= N; n++) {
                    if (emptyCell(sudoku, row, col, n)) {
                        sudoku[row][col] = n;

                        if (solveSudoku(sudoku)) {
                            return true;
                        }

                        sudoku[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void menu() {
    system("COLOR 02");
    int choice;

    cout << "\n\n\n\t\t\t\tWELCOME TO SUDOKU SOLVER........." << endl;
    cout << "\t\t\t\tPRESS 1 to Start...." << endl;
    cout << "\t\t\t\tPRESS 2 to EXIT...." << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            system("cls");
            start();
            break;
        case 2:
            system("cls");
            system("COLOR 02");
            cout << "\n\n\n\n\t\t\t\tEXITING.........." << endl;
            exit(0);
        default:
            system("cls");
            system("COLOR 02");
            cout << "ERROR!!! PRESS 1 or 2 only......" << endl;
    }
}

void start() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Enter size of puzzle: \n";
    cin >> N;

    int sudoku[N][100];
    cout << "Enter the Sudoku puzzle (use 0 for empty cells): \n" << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sudoku[i][j];
        }
    }

    if (solveSudoku(sudoku)) {
        cout << "\nSudoku solved:\n";
        printSudoku(sudoku);
    } else {
        cout << "\nNo solution exists.\n";
    }

    SetConsoleTextAttribute(h, 14);
    cout << "\n\n\n\n\t\t\t\t\tWant to play again??" << endl;
    cout << "\t\t\t\t\tPRESS 1 for YES" << endl;
    cout << "\t\t\t\t\tPRESS 2 for NO" << endl;

    int t;
    cin >> t;

    switch (t) {
        case 1:
            system("cls");
            menu();
            break;
        case 2:
            system("cls");
            system("COLOR 0e");
            cout << "\n\n\n\n\t\t\t\tEXITING.........." << endl;
            exit(0);
        default:
            system("cls");
            system("COLOR 0e");
            cout << "ERROR!!! PRESS 1 or 2 only......" << endl;
    }
}

int main() {
    menu();
    return 0;

}
