#include <iostream>
using namespace std;

int main() {
    cout << "Enter a number to calculate the factorial: ";
    int x, fact;
    cin >> x;
    fact = 1;  
    int original_x = x;  

    while(x > 0) {
        fact = fact * x;
        x--;
    }

    cout << "The factorial of " << original_x << " is " << fact << endl;

    return 0;
}