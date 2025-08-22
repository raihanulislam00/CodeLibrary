#include<bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        double r, l, deg;
        cin >> r >> l >> deg;
        
        double rad = deg * PI / 180.0;
        double theta = rad / 2.0;
        double sin0 = sin(theta);
        double term = 4 * r * r * sin0 * sin0;
        double d = sqrt(l * l - term);
        
        cout << fixed << setprecision(6) << d << endl;
    }
    
    return 0;
}