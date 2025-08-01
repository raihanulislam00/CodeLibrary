#include <iostream>
using namespace std;

int main() {
    int arr[7];

    cout << "Enter arr for 7 days:\n";
    for (int i = 0; i <= 7; i++) {
        cin >> arr[i];
    }

    int a = 0, b = 0, c = 0;

    for (int i = 0; i <6; i++) {
        if (arr[i] > a) {
            c = b;
            b = a;
            a = arr[i];
        } else if (arr[i] > b) {
            c = b;
            b = arr[i];
        } else if (arr[i] > c) {
            c = arr[i];
        }
    }

    int sum = a + b + c;
    cout << "Sum of best 3 arr = " << sum << endl;

    return 0;
}