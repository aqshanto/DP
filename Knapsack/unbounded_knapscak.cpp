#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
#define inputarr(v, n) \
    for (int i = 0; i < n; i++) cin >> v[i];

#define printarr(v)                    \
    for (int i = 0; i < v.size(); i++) \
        cout << v[i] << " ";           \
    cout << endl;

const int N = 100005;
//---------------------------------------//

void solve() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n), wt(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> wt[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (wt[i - 1] <= j) {
                dp[i][j] = max(dp[i - 1][j], v[i - 1] + dp[i][j - wt[i - 1]]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][W] << endl;
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