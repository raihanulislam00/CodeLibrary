#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string str(n, '.');

    for (int i = 0; i < n; i++) {
        if (s[i] == '#') {
            str[i] = '#';
        }
    }

    int i = 0;
    while (i < n) {
        if (s[i] == '#') {
            i++;
        } else {
            int j = i;
            while (j < n && s[j] != '#') {
                j++;
            }
            int mid = (i + j) / 2;
            str[mid] = 'o';
            i = j;
        }
    }

    cout << str << endl;
    return 0;
}