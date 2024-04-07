#include <bits/stdc++.h>
using namespace std;
 
const double pi = acos(-1);
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<array<double, 2>> op(n);
    for(auto &i : op){
        int opp;
        double k;
        cin >> opp >> k;
        if (opp == 1)
            i[0] = k;
        else{
            i[0] = 1;
            i[1] = k;
        }
    }
    for(int i = 1; i < n; ++ i){
        op[i][0] *= op[i - 1][0];
        op[i][1] += op[i - 1][1];
    }
    for(int i = 0; i < m; ++ i){
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        -- l, -- r;
        double R = sqrt(1ll * x * x + 1ll * y * y), theta = 0;
        if (x == 0){
            if (y > 0)
                theta = pi / 2;
            else 
                theta = -pi / 2;
        }else{
            theta = atan2(y, x);
        }
        R *= op[r][0];
        theta += op[r][1];
        if (l){
            R /= op[l - 1][0];
            theta -= op[l - 1][1];
        }
        cout << fixed << setprecision(10) << R * cos(theta) << ' ' << R * sin(theta) << '\n';
    }
    return 0;
}