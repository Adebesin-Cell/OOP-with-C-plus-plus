#include <iostream>
using namespace std;

int main () {
    char character;
    bool isProgrammingRunning = true;

    do
    {
        cout << "I'm a programmer" << endl;
        cout << "Enter a character (x to exit): ";
        cin >> character;

        character = tolower(character);

        if (character == 'x') {
            isProgrammingRunning = false;
        }
    } while (isProgrammingRunning);
    
    cout << "Program ended." << endl;
}