#include <iostream>
using namespace std;

int main () {
    int num;
    cout << "Enter any number: ";
    cin >> num;

    if (num > 0) {
        cout << "Number is positive 😷";
    } else if (num < 0) {
        cout << "Number is negative 🫠";
    } else {
        cout << "Number is zero 😗";
    }

    return 0;
}