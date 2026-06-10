#include "Game.h"
#include "UI.h"
#include <iostream>
#include <windows.h>
using namespace std;

// ── Constructor / Destructor ─────────────────────────────────────────────────

Game::Game() {
    rows  = 0;
    cols  = 0;
    field = nullptr;
}

Game::~Game() {
    delete field;
}

// ── Public ───────────────────────────────────────────────────────────────────

void Game::run() {
    UI::displayDogArt();
    UI::displayIntro();

    getMapSize();

    field = new Snackfield(rows, cols);

    gameLoop();
    showEnding();
}

// ── Private ──────────────────────────────────────────────────────────────────

void Game::getMapSize() {
    do {
        UI::setColor(3);
        cout << "Choose the size of Snackfield.\n";
        cout << "Enter Rows and Columns (row column): ";
        cin >> rows >> cols;

        if (rows < 4 || rows > 10 || cols < 4 || cols > 10) {
            UI::setColor(13);
            cout << "Rows and Columns must be between 4 and 10!\n";
        } else if (rows > cols) {
            UI::setColor(13);
            cout << "Rows must be less than or equal to Columns!\n";
        }
        UI::setColor(7);
        cout << endl;

    } while (rows < 4 || cols < 4 || rows > 10 || cols > 10 || rows > cols);
}

void Game::gameLoop() {
    while (player.isAlive() &&
           player.getSausageFound() < field->getTotalSausage()) {

        cout << "Snack Field Map\n";
        field->displayVisible();
        cout << endl;

        displayStatus();

        int r, c;
        getValidPosition(r, c);
        processTile(r, c);

        Sleep(500);
        cout << endl;
    }
}

void Game::getValidPosition(int& r, int& c) {
    do {
        UI::setColor(3);
        cout << "Enter position (row column): ";
        cin >> r >> c;

        if (!field->inBounds(r, c)) {
            UI::setColor(13);
            cout << "Position out of bounds!\n";
        }
        UI::setColor(7);

    } while (!field->inBounds(r, c));
}

void Game::processTile(int r, int c) {
    if (field->alreadyDug(r, c)) {
        UI::setColor(13);
        UI::typeText("This tile is already dug!");
        UI::setColor(7);
        return;
    }

    char tile = field->reveal(r, c);

    if (tile == 'S') {
        UI::setColor(14);
        UI::typeText("Crunch! Sausage found!");
        UI::setColor(7);
        player.foundSausage();
        field->markVisible(r, c, 'S');

    } else if (tile == 'B') {
        UI::setColor(10);
        UI::typeText("Bone found! +1 Heart");
        UI::setColor(7);
        player.gainHeart();
        player.foundBone();
        field->markVisible(r, c, 'B');

    } else if (tile == 'L') {
        UI::setColor(12);
        UI::typeText("Lightning! You lost 1 heart");
        UI::setColor(7);
        player.loseHeart();

        if (player.isAlive()) {
            int nearbySausage = field->countNearby('S', r, c);
            int nearbyBone    = field->countNearby('B', r, c);
            cout << "Sausage Nearby: " << nearbySausage << endl;
            cout << "Bone Nearby: "    << nearbyBone    << endl;
            field->markVisible(r, c, '0' + nearbySausage);
            Sleep(1000);
        }
    }
}

void Game::displayStatus() {
    cout << "Hearts       : ";
    UI::setColor(4);
    for (int i = 0; i < player.getHearts(); i++) cout << "♥ ";
    UI::setColor(7);
    cout << "(" << player.getHearts() << ")\n";

    cout << "Sausage Left : "
         << field->getTotalSausage() - player.getSausageFound() << "\n";
    cout << "Bone Left    : "
         << field->getTotalBone() - player.getBoneFound()    << "\n";
}

void Game::showEnding() {
    if (player.isAlive())
        UI::displayWin();
    else
        UI::displayLose();
}
