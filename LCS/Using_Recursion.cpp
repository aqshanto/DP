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
string s1,s2;

int lcs(int i,int j){
    if(i==s1.size() || j==s2.size()){
        return 0;
    }else if(s1[i]==s2[j]){
        cout<<s1[i];
        return 1+lcs(i+1,j+1);
    }else{
        return max(lcs(i+1,j),lcs(i,j+1));
    }
}

void solve() {
    cin>>s1>>s2;
    cout<<lcs(0,0)<<endl;
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