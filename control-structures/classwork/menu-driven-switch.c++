#include <iostream>
using namespace std;

int main() {
    int choice;
    double num1, num2, result;

    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    cout << "\nMenu:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch (choice) {
        case 1:
            result = num1 + num2;
            cout << "Result: " << result << endl;
            break;
        case 2:
            result = num1 - num2;
            cout << "Result: " << result << endl;
            break;
        case 3:
            result = num1 * num2;
            cout << "Result: " << result << endl;
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Division by zero!" << endl;
            }
            break;
        case 5:
            if (num2 != 0) {
                result = int(num1) % int(num2);
                cout << "Result: " << result << endl;
            } else {
                cout << "Error: Modulus by zero!" << endl;
            }
            break;
        default:
            cout << "Invalid choice!" << endl;
    }

    return 0;
}
