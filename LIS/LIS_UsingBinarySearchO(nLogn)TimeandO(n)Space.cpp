#include <bits/stdc++.h>
using namespace std;
vector<int> temp;
int longestIncreasingSubsequence(vector<int>& arr, int n) {
    // Create a temporary vector to store the increasing subsequence
    temp.push_back(arr[0]);

    int len = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] > temp.back()) {
            // If arr[i] is greater than the last element of temp, extend the subsequence
            temp.push_back(arr[i]);
            len++;
        } else {
            // If arr[i] is not greater, replace the element in temp with arr[i]
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }

    return len;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    cout << longestIncreasingSubsequence(v, n) << endl;
    for (auto it : temp) {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
