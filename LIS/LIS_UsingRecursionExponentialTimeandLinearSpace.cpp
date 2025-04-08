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

int lis(vector<int>& v, int i) {
    if (i == 0) return 1;
    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (v[j] < v[i]) {
            ans = max(ans, lis(v, j) + 1);
        }
    }
    return ans;
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
    int t = 1, Case = 1;
    // cin>>t;
    while (t--) {
        // cout << "Case " << Case++ << ": ";
        solve();
    }
    return 0;
}