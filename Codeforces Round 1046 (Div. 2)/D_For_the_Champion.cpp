#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    const ll K = 1000000000LL;
    while(t--){
        int n;
        cin >> n;
        vector<ll> xs(n), ys(n);
        for(int i = 0; i < n; i++){
            cin >> xs[i] >> ys[i];
        }
        ll X_init, Y_init;
        cin >> X_init >> Y_init;
        // Compute initial distance:
        ll s0 = LLONG_MAX;
        for(int i = 0; i < n; i++){
            ll d = llabs(xs[i] - X_init) + llabs(ys[i] - Y_init);
            s0 = min(s0, d);
        }
        // Simulate moves:
        ll pos1x = X_init - K, pos1y = Y_init;
        ll sL = LLONG_MAX;
        for(int i = 0; i < n; i++){
            ll d = llabs(xs[i] - pos1x) + llabs(ys[i] - pos1y);
            sL = min(sL, d);
        }
        ll pos2x = pos1x + 2*K, pos2y = Y_init;
        ll sR = LLONG_MAX;
        for(int i = 0; i < n; i++){
            ll d = llabs(xs[i] - pos2x) + llabs(ys[i] - pos2y);
            sR = min(sR, d);
        }
        ll pos3x = X_init, pos3y = Y_init - K;
        ll sD = LLONG_MAX;
        for(int i = 0; i < n; i++){
            ll d = llabs(xs[i] - pos3x) + llabs(ys[i] - pos3y);
            sD = min(sD, d);
        }
        ll pos4x = X_init, pos4y = pos3y + 2*K;
        ll sU = LLONG_MAX;
        for(int i = 0; i < n; i++){
            ll d = llabs(xs[i] - pos4x) + llabs(ys[i] - pos4y);
            sU = min(sU, d);
        }
        // Find extremes:
        ll xL = LLONG_MAX, yL = 0, xR = LLONG_MIN, yR = 0;
        ll xD = LLONG_MAX, yD = 0, xU = LLONG_MIN, yU = 0;
        for(int i = 0; i < n; i++){
            if(xs[i] < xL || (xs[i] == xL && ys[i] < yL)){ xL = xs[i]; yL = ys[i]; }
            if(xs[i] > xR || (xs[i] == xR && ys[i] < yR)){ xR = xs[i]; yR = ys[i]; }
            if(ys[i] < yD || (ys[i] == yD && xs[i] < xD)){ yD = ys[i]; xD = xs[i]; }
            if(ys[i] > yU || (ys[i] == yU && xs[i] < xU)){ yU = ys[i]; xU = xs[i]; }
        }
        ll Sx = (sL + sR - 2*K) + (xR - xL);
        ll Sy = (sD + sU - 2*K) + (yU - yD);
        ll ansX=0, ansY=0;
        bool haveX=false, haveY=false;
        if(Sx != (yR - yL)){
            if(Sx > (yR - yL)) ansY = (Sx + yR + yL) / 2;
            else ansY = (yR + yL - Sx) / 2;
            haveY = true;
        }
        if(Sy != (xU - xD)){
            if(Sy > (xU - xD)) ansX = (Sy + xU + xD) / 2;
            else ansX = (xU + xD - Sy) / 2;
            haveX = true;
        }
        int i0 = -1;
        for(int i = 0; i < n; i++){
            ll d = llabs(xs[i] - X_init) + llabs(ys[i] - Y_init);
            if(d == s0){ i0 = i; break; }
        }
        ll xi0 = 0, yi0 = 0;
        if(i0 != -1){ xi0 = xs[i0]; yi0 = ys[i0]; }
        ll C = xi0 + yi0 + s0;
        ll F = -xi0 - yi0 + s0;
        ll A = sR - K + (xR - yR);
        ll B = sL - K - xL + yL;
        ll D1 = sD - K - yD;
        ll U1 = sU - K + yU;
        vector<pair<ll,ll>> cand;
        if(!haveY){
            if(((A + C) % 2LL) == 0){
                ll Xc = (A + C) / 2, Yc = C - Xc;
                cand.push_back({Xc, Yc});
            }
            if(((C + B) % 2LL) == 0){
                ll Yc = (C + B) / 2, Xc = C - Yc;
                cand.push_back({Xc, Yc});
            }
            if(((F + A) % 2LL) == 0){
                ll Yc = -(F + A) / 2, Xc = A + Yc;
                cand.push_back({Xc, Yc});
            }
            if(((B + F) % 2LL) == 0){
                ll Xc = -(B + F) / 2, Yc = B + Xc;
                cand.push_back({Xc, Yc});
            }
        }
        if(!haveX){
            if(((C + D1 + xD) % 2LL) == 0){
                ll Xc = (C + D1 + xD) / 2, Yc = C - Xc;
                cand.push_back({Xc, Yc});
            }
            if(((C + U1 - xU) % 2LL) == 0){
                ll Yc = (C + U1 - xU) / 2, Xc = C - Yc;
                cand.push_back({Xc, Yc});
            }
            if(((F + D1 + xD) % 2LL) == 0){
                ll Yc = -(F + D1 + xD) / 2, Xc = -F - Yc;
                cand.push_back({Xc, Yc});
            }
            if(((F + U1 - xU) % 2LL) == 0){
                ll Xc = -(F + U1 - xU) / 2, Yc = -F - Xc;
                cand.push_back({Xc, Yc});
            }
        }
        if(haveX && haveY){
            cand.push_back({ansX, ansY});
        }
        ll finalX=0, finalY=0;
        for(auto &p : cand){
            ll Xc = p.first, Yc = p.second;
            ll dist0 = LLONG_MAX;
            for(int i = 0; i < n; i++){
                ll d = llabs(xs[i] - Xc) + llabs(ys[i] - Yc);
                dist0 = min(dist0, d);
            }
            if(dist0 != s0) continue;
            ll tL=LLONG_MAX, tR=LLONG_MAX, tD=LLONG_MAX, tU=LLONG_MAX;
            ll px1 = Xc - K, py1 = Yc;
            for(int i = 0; i < n; i++){
                tL = min(tL, llabs(xs[i] - px1) + llabs(ys[i] - py1));
            }
            ll px2 = px1 + 2*K, py2 = Yc;
            for(int i = 0; i < n; i++){
                tR = min(tR, llabs(xs[i] - px2) + llabs(ys[i] - py2));
            }
            ll px3 = Xc, py3 = Yc - K;
            for(int i = 0; i < n; i++){
                tD = min(tD, llabs(xs[i] - px3) + llabs(ys[i] - py3));
            }
            ll px4 = Xc, py4 = py3 + 2*K;
            for(int i = 0; i < n; i++){
                tU = min(tU, llabs(xs[i] - px4) + llabs(ys[i] - py4));
            }
            if(tL == sL && tR == sR && tD == sD && tU == sU){
                finalX = Xc; finalY = Yc;
                break;
            }
        }
        cout << finalX << " " << finalY;
        if(t) cout << "\n";
    }
    return 0;
}