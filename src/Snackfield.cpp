#include "Snackfield.h"
#include "UI.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Snackfield::Snackfield(int r, int c) {
    rows  = r;
    cols  = c;
    int total  = r * c;
    totalSausage = static_cast<int>(0.25 * total);
    totalBone    = static_cast<int>(0.15 * total);

    // Fill both grids with defaults
    grid    = vector<vector<char>>(r, vector<char>(c, 'L'));
    visible = vector<vector<char>>(r, vector<char>(c, '?'));

    srand(time(0));
    placeTiles('S', totalSausage);
    placeTiles('B', totalBone);
}

// ── Private ──────────────────────────────────────────────────────────────────

void Snackfield::placeTiles(char type, int count) {
    while (count > 0) {
        int r = rand() % rows;
        int c = rand() % cols;
        if (grid[r][c] == 'L') {
            grid[r][c] = type;
            count--;
        }
    }
}

// ── Public ───────────────────────────────────────────────────────────────────

char Snackfield::reveal(int r, int c) const {
    return grid[r][c];
}

void Snackfield::markVisible(int r, int c, char symbol) {
    visible[r][c] = symbol;
}

int Snackfield::countNearby(char type, int r, int c) const {
    int count = 0;
    for (int i = -1; i < 2; i++) {
        for (int g = -1; g < 2; g++) {
            if (i == 0 && g == 0) continue;
            int nr = r + i;
            int nc = c + g;
            if (inBounds(nr, nc) && grid[nr][nc] == type)
                count++;
        }
    }
    return count;
}

bool Snackfield::inBounds(int r, int c) const {
    return r >= 0 && r < rows && c >= 0 && c < cols;
}

bool Snackfield::alreadyDug(int r, int c) const {
    return visible[r][c] != '?';
}

void Snackfield::displayVisible() const {
    cout << " ";
    for (int c = 0; c < cols; c++) {
        cout << "| ";
        UI::setColor(14);
        cout << c << " ";
        UI::setColor(7);
    }
    cout << "|" << endl;

    cout << "-";
    for (int c = 0; c < cols; c++) cout << "+---";
    cout << "+" << endl;

    for (int r = 0; r < rows; r++) {
        UI::setColor(14);
        cout << r;
        UI::setColor(7);
        for (int c = 0; c < cols; c++)
            cout << "| " << visible[r][c] << " ";
        cout << "|" << endl;

        cout << "-";
        for (int c = 0; c < cols; c++) cout << "+---";
        cout << "+" << endl;
    }
}

int Snackfield::getTotalSausage() const { return totalSausage; }
int Snackfield::getTotalBone()    const { return totalBone;    }
