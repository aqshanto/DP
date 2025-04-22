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

void lis(vector<int>& v) {
    int n = v.size();
    vector<int> ans, ansin;
    vector<int> prev(n, -1);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
        if (pos < ans.size()) {
            ans[pos] = v[i];
            ansin[pos] = i;
        } else {
            ans.push_back(v[i]);
            ansin.push_back(i);
        }
        if (pos > 0) {
            prev[i] = ansin[pos - 1];
        }
    }
    int i = ansin.back();
    vector<int> res;
    while (i != -1) {
        res.push_back(v[i]);
        i = prev[i];
    }

    cout << ans.size() << endl;
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << " ";
    }
    cout << endl;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    lis(v);
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