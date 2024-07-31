#include <iostream>
using namespace std;

int main () {
    cout << "The largest of 3 numbers program\n";
    int x, y, z;

    cout << "Enter 3 numbers\n";
    cin >> x >> y >> z;

    if (x > y) {
        if (x > z) {
            cout << x << " is the largest number\n";
        } else {
            cout << z << " is the largest number\n";
        }
    } else {
        if (y > z) {
            cout << y << " is the largest number\n";
        } else {
            cout << z << " is the largest number\n";
        }
    }

    return 0;
}
