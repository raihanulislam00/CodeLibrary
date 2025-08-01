#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cout << 2 << endl;
    for (int i = 1; i <= n; i++) {
        cout << i;
        if (i < n) 
            cout << " ";
    }
    cout << endl;
    for (int i = n; i >= 1; i--) {
        cout << i;
        if (i > 1)
            cout << " ";
    }
    cout << endl;
    return 0;
}