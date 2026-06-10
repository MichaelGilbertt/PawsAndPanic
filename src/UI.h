#ifndef UI_H
#define UI_H

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class UI {
public:
    static void setColor(int colorCode);
    static void typeText(const string& text);
    static void displayDogArt();
    static void displayIntro();
    static void displayWin();
    static void displayLose();
};

#endif
