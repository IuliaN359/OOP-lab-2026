#include <iostream>
#include <cmath>

using namespace std;

float Quadratwurzel(float number) {
    if (number == 0)
        return 0;
    float root = number;
    while (abs(root * root - number) > 0.00001)
        root = 0.5 * (root + number / root);
    return root;
}

float teilproblemA(float number) {
    return Quadratwurzel(number);
}

bool prim(int number) {
    if (number <= 1)
        return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0)
            return false;
    }
    return true;
}


void teilproblemB(int array[], int number) {
    int max_len = 1, len = 1, end = 0;
    for (int i = 1; i < number; i++) {
        if (prim(abs(array[i - 1] - array[i]))) {
            len++;
            if (len > max_len) {
                max_len = len;
                end = i;
            }
        } else
            len = 1;
    }
    for (int i = end - max_len + 1; i <= end; i++)
        cout << array[i] << ' ';
}

int main() {
    float float_number;
    int array[100], int_number;
    cin >> float_number;
    cout << teilproblemA(float_number);
    cin >> int_number;
    for (int i = 0; i < int_number; i++)
        cin >> array[i];
    teilproblemB(array, int_number);
    return 0;
}
