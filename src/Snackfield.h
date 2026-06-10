#ifndef SNACKFIELD_H
#define SNACKFIELD_H

#include <vector>
using namespace std;

class Snackfield {
private:
    int rows;
    int cols;
    int totalSausage;
    int totalBone;
    vector<vector<char>> grid;    // true map  — hidden from player
    vector<vector<char>> visible; // what the player sees

    void placeTiles(char type, int count);

public:
    Snackfield(int r, int c);

    // Game logic
    char  reveal(int r, int c) const;
    void  markVisible(int r, int c, char symbol);
    int   countNearby(char type, int r, int c) const;
    bool  inBounds(int r, int c) const;
    bool  alreadyDug(int r, int c) const;

    // Display
    void displayVisible() const;

    // Getters
    int getTotalSausage() const;
    int getTotalBone()    const;
};

#endif
