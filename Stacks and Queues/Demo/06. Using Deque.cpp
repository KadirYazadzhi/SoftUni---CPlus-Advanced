#include <iostream>
#include <string>
#include <deque>
#include <cmath>

using namespace std;

const size_t MAX_CONSOLE_SIZE = 5;
const size_t SLIDER_SIZE = 3;

const int ENTER_DATA = 1;
const int MOVE_SLIDER_UP = 2;
const int MOVE_SLIDER_DOWN = 3;
const int PRINT_CONTENT = 4;
const int EXIT = 5;
const int MAX_MENU_OPTIONS = 5;

void printMenu() {
    cout << "\nChoose options:\n";
    cout << "1) enter new data" << endl;
    cout << "2) move slider up" << endl;
    cout << "3) move slider down" << endl;
    cout << "4) print content" << endl;
    cout << "5) exit" << endl;
}

bool isValidOption(int chosenOption) {
    if (0 > chosenOption) {
        return false;
    }
    if (5 < chosenOption) {
        return false;
    }
    return true;
}

string readData() {
    string input;
    getline(cin, input);
    return input;
}

void enterData(deque<string> &console, int &consoleSlideFromIdx, int &consoleSliderToIdx) {
    const string newData = readData();
    console.push_back(newData);
    if (MAX_CONSOLE_SIZE < console.size()) {
        console.pop_front();
    }

    const int maxSliderToIdx = (int) (MAX_CONSOLE_SIZE - 1);
    consoleSliderToIdx = consoleSlideFromIdx + SLIDER_SIZE - 1;
    consoleSliderToIdx = min(consoleSliderToIdx, maxSliderToIdx);
}

void moveSliderUp(int &consoleSliderFromIdx, int &consoleSliderToIdx) {
    if (consoleSliderFromIdx == 0) {
        return;
    }
    consoleSliderFromIdx--;
    consoleSliderToIdx--;
}

void moveSliderDown(int &consoleSliderFromIdx, int &consoleSliderToIdx) {
    const int maxSliderToIdx = (int) (MAX_CONSOLE_SIZE - 1);
    if (maxSliderToIdx == consoleSliderToIdx) {
        return;
    }
    consoleSliderFromIdx++;
    consoleSliderToIdx++;
}

void printContent(const deque<string> &console, int fromIdx, int toIdx) {
    if (console.empty()) {
        return;
    }
    for (int i = fromIdx; i <= toIdx && i < (int)console.size(); i++) {
        cout << "row" << i << ": " << console[i] << endl;
    }
}

void handleChosenOption(deque<string> &console, int chosenOption, int &consoleSliderFromIdx, int &consoleSliderToIdx, bool &exitFlag) {
    switch (chosenOption) {
        case ENTER_DATA:
            enterData(console, consoleSliderFromIdx, consoleSliderToIdx);
            break;
        case MOVE_SLIDER_UP:
            moveSliderUp(consoleSliderFromIdx, consoleSliderToIdx);
            break;
        case MOVE_SLIDER_DOWN:
            moveSliderDown(consoleSliderFromIdx, consoleSliderToIdx);
            break;
        case PRINT_CONTENT:
            printContent(console, consoleSliderFromIdx, consoleSliderToIdx);
            break;
        case EXIT:
            exitFlag = true;
            break;
        default:
            cerr << "Received invalid option: " << chosenOption << endl;
            break;
    }
}

void playGame(deque<string> &console, int &consoleSliderFromIdx, int &consoleSliderToIdx) {
    bool exitFlag = false;
    int chosenOption = - 1;
    while (!exitFlag) {
        printMenu();
        cin >> chosenOption;
        cin.ignore();
        if (!isValidOption(chosenOption)) {
            cout << "Chosen a valid option between 1 and " << MAX_MENU_OPTIONS << endl;
            continue;
        }

        handleChosenOption(console, chosenOption, consoleSliderFromIdx, consoleSliderToIdx, exitFlag);
    }
}

int main() {
    deque<string> console;
    int consoleSliderFromIdx = 0;
    int consoleSliderToIdx = 0;
    playGame(console, consoleSliderFromIdx, consoleSliderToIdx);

    return 0;
}
