#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

long long solve(vector<long long> arr, long long c, long long k) {
    sort(arr.begin(), arr.end());
    

    for (int i = 0; i < arr.size(); i++) {
        //cout << "c: " << c << ", arr[i]: " << arr[0] << endl;
        if (c < arr[i]) {
            return c;
        }
        long long rem = c - arr[i];
        rem = min(k, rem);
        c = c + rem + arr[i];
        k-=rem;
        
    }

    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;                 // If problem has no t, delete this line and keep t=1
    while (t--) {
        int n;
        long long c, k;
        cin >> n >> c >> k;

        vector<long long> a(n);

        
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << solve(a, c, k) << endl;
    }
    return 0;
}
