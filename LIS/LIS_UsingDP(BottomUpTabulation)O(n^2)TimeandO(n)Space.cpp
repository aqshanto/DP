#include <bits/stdc++.h>
using namespace std;
#define int long long

//---------------------------------------//

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector<int> LIS(n, 1), prev(n, -1);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                if (LIS[j] + 1 >= LIS[i]) {
                    prev[i] = j;
                }
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
    }
    int mx = INT_MIN, index = -1;
    for (int i = 0; i < n; i++) {
        if (mx < LIS[i]) {
            mx = max(mx, LIS[i]);
            index = i;
        }
    }
    cout << mx << endl;
    vector<int> ansindex, ans;
    while (index != -1) {
        ans.push_back(v[index]);
        ansindex.push_back(index);
        index = prev[index];
    }
    for (int i = ansindex.size() - 1; i >= 0; --i) {
        cout << ansindex[i] << " ";
    }
    cout << endl;
    for (int i = ans.size() - 1; i >= 0; --i) {
        cout << ans[i] << " ";
    }
    cout << endl;
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