#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
        cin >> wt[i] >> v[i];
    }
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = W; j >= wt[i]; j--) {
            dp[j] = max(dp[j], dp[j - wt[i]] + v[i]);
        }
    }
    cout << dp[W] << endl;
}

int main() {
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