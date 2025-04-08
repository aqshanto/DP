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
const int N = 1e5 + 100;
int dp[N + 1];

int lis(vector<int> &v, int i) {
    if (dp[i] != -1) return dp[i];
    if (i == 0) return 1;
    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (v[j] < v[i]) {
            ans = max(ans, lis(v, j) + 1);
        }
    }
    return dp[i] = ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int mx = INT_MIN;
    for (int i = 0; i < n; i++) {
        mx = max(mx, lis(v, i));
    }
    cout << mx << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    int t = 1, Case = 1;
    // cin>>t;
    while (t--) {
        // cout << "Case " << Case++ << ": ";
        solve();
    }
    return 0;
}