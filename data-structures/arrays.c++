#include <iostream>
#include <vector>

using namespace std;

vector<int> inputArray(const string& name) {
    vector<int> arr;
    int size, value;
    cout << "Enter the size of array " << name << ": ";
    cin >> size;
    cout << "Enter " << size << " elements for array " << name << ":\n";
    for (int i = 0; i < size; i++) {
        cin >> value;
        arr.push_back(value);
    }
    return arr;
}

void printArray(const vector<int>& arr, const string& name) {
    cout << name << ": ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

vector<int> addArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> result(max(a.size(), b.size()), 0);
    for (size_t i = 0; i < result.size(); i++) {
        if (i < a.size()) result[i] += a[i];
        if (i < b.size()) result[i] += b[i];
    }
    return result;
}

vector<int> subtractArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> result(max(a.size(), b.size()), 0);
    for (size_t i = 0; i < result.size(); i++) {
        if (i < a.size()) result[i] += a[i];
        if (i < b.size()) result[i] -= b[i];
    }
    return result;
}

vector<int> multiplyArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> result(a.size() + b.size() - 1, 0);
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < b.size(); j++) {
            result[i + j] += a[i] * b[j];
        }
    }
    return result;
}

int main() {
    vector<int> A = inputArray("A");
    vector<int> B = inputArray("B");
    vector<int> C = inputArray("C");

    printArray(A, "A");
    printArray(B, "B");
    printArray(C, "C");

    cout << "\nArray operations:\n";

    vector<int> AB = multiplyArrays(A, B);
    cout << "A * B = ";
    printArray(AB, "");

    vector<int> BC = multiplyArrays(B, C);
    cout << "B * C = ";
    printArray(BC, "");

    vector<int> CA = multiplyArrays(C, A);
    cout << "C * A = ";
    printArray(CA, "");

    vector<int> sum = addArrays(addArrays(A, B), C);
    cout << "A + B + C = ";
    printArray(sum, "");

    vector<int> diff = subtractArrays(subtractArrays(A, B), C);
    cout << "A - B - C = ";
    printArray(diff, "");

    return 0;
}
