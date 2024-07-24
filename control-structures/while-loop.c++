#include <iostream>
using namespace std;

int main() {
    char character;
    bool isProgrammingRunning = true;

    while (isProgrammingRunning) {
        cout << "I'm a programmer" << endl;
        cout << "Enter a character (x to exit): ";
        cin >> character;

        character = tolower(character);

        if (character == 'x') {
            isProgrammingRunning = false;
        }
    }

    cout << "Program ended." << endl;
    return 0;
}