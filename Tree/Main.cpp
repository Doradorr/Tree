#include <iostream>
#include <windows.h>  
#include <thread>     
#include <chrono>     

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void drawTree(int n) {
    for (int i = 1; i <= n; i++) {
        int rows = i + 1;
        for (int j = 0; j < rows; j++) {
            int stars = 2 * j + 1;
            int spaces = n - j - 1;
            for (int k = 0; k < spaces; k++) {
                cout << " ";
            }
            for (int k = 0; k < stars; k++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    int trunkHeight = (n / 2) + 1;
    int trunkWidth = 3;
    int trunkSpaces = n - 1 - trunkWidth / 2;

    for (int i = 0; i < trunkHeight; i++) {
        for (int j = 0; j < trunkSpaces; j++) {
            cout << " ";
        }
        for (int j = 0; j < trunkWidth; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of tree levels: ";
    cin >> n;

    while (true) {
        for (int color = 1; color <= 15; color++) {
            setColor(color);
            drawTree(n);
            this_thread::sleep_for(chrono::milliseconds(500));
            system("cls");
        }
    }

    return 0;
}