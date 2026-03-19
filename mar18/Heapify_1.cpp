#include "bits/stdc++.h"
using namespace std;

using vi = vector<int>;

int helper(int n) {
    while((n & 1) == 0) n >>= 1;
    return n;
}

string solve(const vi& arr) {
    int n = arr.size();

    for (int i = 0; i < n; ++i) {
        int index  = helper(i+1);
        int val = helper(arr[i]);
        if (val != index) return "NO";
    }

    return "YES";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr) << '\n';
    }
    return 0;
}
