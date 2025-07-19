#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            v.push_back(i + 1);
        }
    }
    for (int i = 0; i < v.size(); i += 2) {
        cout << v[i] << "," << v[i + 1] << endl;
    }
    return 0;
}
