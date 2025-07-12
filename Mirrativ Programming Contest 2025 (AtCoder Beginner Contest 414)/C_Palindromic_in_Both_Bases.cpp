#include <iostream>
using namespace std;
#define ull unsigned long long
#define int long long
int32_t main(){
    int a;
    ull n;
    if(!(cin>>a)) return 0;
    cin>>n;
    ull sum = 0;
    int l = 0;
    {
        ull tmp = n;
        if(tmp == 0) l = 1;
        while(tmp > 0){
            l++;
            tmp /= 10;
        }
    }
    for(int i = 1; i <= l; ++i){
        ull p = 0;
        if(i == 1){
            p = 1;
        } else {
            ull t = 1;
            for(int i = 1; i < i; ++i) t *= 10;
            p = t + 1;
        }
        if(p > n) break;
        int h = (i + 1) / 2;
        ull start = 1;
        for(int i = 1; i < h; ++i) start *= 10;
        ull p10 = start;
        ull end = start * 10 - 1;
        if(i % 2 == 0) p10 *= 10;
        for(ull half = start; half <= end; ++half){
            ull tmp = (i % 2 == 0) ? half : (half / 10);
            ull r = 0;
            ull t = tmp;
            while(t > 0){
                r = r * 10 + (t % 10);
                t /= 10;
            }
            ull temp1 = half * p10 + r;
            if(temp1 > n) break;
            ull num = temp1;
            bool flag = true;
            ull arr[64];
            int cnt = 0;
            if(num == 0){
                flag = true;
            } else {
                while(num > 0){
                    arr[cnt++] = num % a;
                    num /= a;
                }
                for(int i = 0, j = cnt - 1; i < j; ++i, --j){
                    if(arr[i] != arr[j]){
                        flag = false;
                        break;
                    }
                }
            }
            if(flag) sum += temp1;
        }
    }
    cout << sum;
    return 0;
}
