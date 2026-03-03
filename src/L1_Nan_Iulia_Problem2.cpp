#include <iostream>
using namespace std;

bool prim(int number) {
    if (number<=1)
        return false;
    for (int i=2;i*i<=number;i++) {
        if (number%i==0)
            return false;
    }
    return true;
}

void teilproblemA(int number) {
    int i=2;
    while (number) {
        if (prim(i)) {
            cout<<i<<' ';
            number--;
        }
        i++;
    }
}

int gcd(int num_a, int num_b) {
    if (num_a==0)
        return num_b;
    if (num_b==0)
        return num_a;
    while (num_a != num_b)
        if (num_a > num_b)
            num_a -= num_b;
        else
            num_b -= num_a;
    return num_a;
}

bool coprime(int num_a, int num_b) {
    if (gcd(num_a, num_b) == 1)
        return true;
    return false;
}

void teilproblemB(int array[], int number) {
    int max_len = 1, len = 1, end = 0;

    for (int i = 1; i < number; i++) {
        if (coprime(array[i - 1], array[i])) {
            len++;
            if (len > max_len) {
                max_len = len;
                end = i;
            }
        } else {
            len = 1;
        }
    }

    for (int i = end - max_len + 1; i <= end; i++)
        cout << array[i] << ' ';
}

int main() {
    int number, array[100];
    cin>>number;
    teilproblemA(number);
    cin>>number;
    for (int i=0;i<number;i++)
        cin>>array[i];
    teilproblemB(array, number);
}
