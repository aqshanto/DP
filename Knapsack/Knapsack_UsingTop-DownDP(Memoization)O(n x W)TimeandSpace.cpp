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
int dp[100 + 1][10001];

int knapsack(vector<int>& v, vector<int>& wt, int W, int n) {
    if (n == 0 || W == 0) return 0;
    if (dp[n][W] != -1) return dp[n][W];
    if (wt[n - 1] <= W)
        return dp[n][W] = max(v[n - 1] + knapsack(v, wt, W - wt[n - 1], n - 1), knapsack(v, wt, W, n - 1));
    else
        return dp[n][W] = knapsack(v, wt, W, n - 1);
}

void solve() {
    int n, W;
    cin >> n >> W;
    vector<int> v(n), wt(n);
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> wt[i];
    }
    cout << knapsack(v, wt, W, n) << endl;
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