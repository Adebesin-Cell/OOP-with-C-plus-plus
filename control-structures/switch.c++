#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number between 1 and 7: ";
    cin >> num;
    
    switch (num) {
        case 1:
            cout << "Sunday";
            break;
        case 2:
            cout << "Monday";
            break;
        case 3:
            cout << "Tuesday";
            break;
        case 4:
            cout << "Wednesday";
            break;
        case 5:
            cout << "Thursday";
            break;
        case 6:
            cout << "Friday";
            break;
        case 7:
            cout << "Saturday";
            break;
        default:
            cout << "Invalid input. Please enter a number between 1 and 7.";
            break;
    }
    
    cout << endl;
    return 0;
}