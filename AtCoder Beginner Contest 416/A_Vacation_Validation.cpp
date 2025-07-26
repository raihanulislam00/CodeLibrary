#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, l, r;
    string s;
    cin >> n >> l >> r >> s;
    
    bool flag = true;
    for (int i = l - 1; i < r; ++i) {
        if (s[i] != 'o') {
            flag = false;
            break;
        }
    }
    
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}