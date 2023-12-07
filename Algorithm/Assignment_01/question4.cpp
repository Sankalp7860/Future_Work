#include <iostream>
using namespace std;

void printSquare(int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

void printHorizontalLine(int length) {
    for (int i = 0; i < length; i++) {
        cout << "* ";
    }
    cout << endl;
}

void printLineWithDirection(int size, int direction) {
    if (direction == -1) {
        cout << "* ";
        for (int i = 0; i < size - 1; i++) {
            cout << "  ";
        }
    } else {
        for (int i = 0; i < size - 1; i++) {
            cout << "  ";
        }
        cout << "* ";
    }
    cout << endl;
}

void printPattern(int size, int argument) {
    int argCopy = argument;
    int changeDirection = 1;
    int lineCount = 0;
    int i = -1;
    
    while (lineCount <= size - 1) {
        i++;
        
        if (i % 2 && lineCount <= size - 1) {
            while (argCopy-- && lineCount <= size - 1) {
                printLineWithDirection(size, changeDirection);
                lineCount++;
            }
            argCopy = argument;
            changeDirection *= -1;
        } else if (lineCount <= size + 1) {
            printHorizontalLine(size);
            lineCount++;
        }
    }
}

int main() {
    cout << "Please enter the size of the matrix (n): ";
    int matrixSize;
    cin >> matrixSize;
    
    printSquare(matrixSize);
    
    cout << "Please enter the argument: ";
    int patternArgument;
    cin >> patternArgument;
    
    printPattern(matrixSize, patternArgument);
    return 0;
}
