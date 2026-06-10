#include "UI.h"

void UI::setColor(int colorCode) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorCode);
}

void UI::typeText(const string& text) {
    for (char c : text) {
        cout << c;
        cout.flush();
        Sleep(50);
    }
    cout << endl;
}

void UI::displayDogArt() {
    setColor(6);
    cout << "    ,    /-." << endl;
    cout << "   ((___/ __>" << endl;
    cout << "   /      }" << endl;
    cout << "   \\ .--.(    ___" << endl;
    cout << "    \\\\   \\\\  /___\\" << endl << endl;
    setColor(7);
}

void UI::displayIntro() {
    typeText("Sausy is a small hungry dachshund who loves to dig.");
    typeText("Every day, Sausy searches for sausages to eat.\n");

    typeText("One day, Sausy wanders into a strange place called Snackfield.");
    typeText("The ground looks normal, but it is not safe.\n");

    typeText("Lightning is trapped under the ground.");
    typeText("Bones are scattered everywhere.");
    typeText("Lost sausages are hidden across the field.\n");

    typeText("Sausy does not understand why Snackfield is dangerous.");
    typeText("Sausy only knows one thing:\n");
    typeText("Sausy is hungry.\n");

    setColor(11);
    typeText("Find all sausages.");
    typeText("Avoid lightning.");
    typeText("Bones restore hearts.\n");
    setColor(7);
}

void UI::displayWin() {
    typeText("Sausy found all the sausages.\n");
    typeText("The ground is quiet.");
    typeText("No lightning crackles.");
    typeText("No bones lie forgotten.\n");
    typeText("Sausy sits down and eats.\n");
    typeText("Sausy is full.\n");
    typeText("For a moment.\n");
    typeText("Then Sausy stands up.\n");
    typeText("Somewhere, the smell of sausages drifts in the air.\n");
    typeText("Sausy wags its tail.\n");
    typeText("Sausy is hungry.\n");
    typeText("THE END");
}

void UI::displayLose() {
    typeText("Sausy is tired.");
    typeText("Sausy is hurt.\n");
    typeText("The ground is silent.");
    typeText("The smell of sausages fades.\n");
    typeText("Sausy lies down.\n");
    typeText("Sausy is still hungry.\n");
    typeText("GAME OVER\n");
}
