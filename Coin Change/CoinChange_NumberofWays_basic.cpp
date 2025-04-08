#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define endl "\n"
#define inputarr(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define printarr(v)                    \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";           \
    cout << endl;

//---------------------------------------//

void solve() {
    int n, money;
    cin >> money >> n;
    vector<int> v(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> v[i];
    int dp[n + 1][money + 1];
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int j = 1; j <= money; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= money; j++) {
            if (j < v[i]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - v[i]];
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= money; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "coin change number of ways : " << dp[n][money] << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, Case = 1;
    // cin>>t;
    while (t--) {
        // cout << "Case " << Case++ << ": ";
        solve();
    }
    return 0;
}