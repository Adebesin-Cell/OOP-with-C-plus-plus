// #include <iostream>
// using namespace std;


// int main () {
//     cout << "Program to get factorial of number\n";
//     int num;

//     cout << "Enter number: ";
//     cin >> num;

//     int factorial = num;

//     for (int i = num - 1; i > 0; i--)
//     {
//         if ( i == 0) {
//             factorial = factorial * 1;
//         }

//         factorial = factorial * i;
//     }

//     cout << "The factorial of " << num << " is " << factorial;

//     return 0;
// }

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