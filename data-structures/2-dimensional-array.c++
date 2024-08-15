// 2-dimensional array take input, display output multiply, add and subtract

#include <iostream>
#include <vector>
using namespace std;

void displayMatrix(int matrix[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int matrix1[2][2], int matrix2[2][2], int result[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

int main () {
    int matrix1[2][2], matrix2[2][2], result[2][2];

    cout << "Enter values for the first 2x2 matrix:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> matrix1[i][j];
        }
    }

    cout << "Enter values for the second 2x2 matrix:" << endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> matrix2[i][j];
        }
    }

    cout << "\nFirst Matrix:" << endl;
    displayMatrix(matrix1);

    cout << "\nSecond Matrix:" << endl;
    displayMatrix(matrix2);

    addMatrices(matrix1, matrix2, result);
    cout << "\nAddition Result:" << endl;
    displayMatrix(result);

    subtractMatrices(matrix1, matrix2, result);
    cout << "\nSubtraction Result:" << endl;
    displayMatrix(result);

    multiplyMatrices(matrix1, matrix2, result);
    cout << "\nMultiplication Result:" << endl;
    displayMatrix(result);

    return 0;
}
