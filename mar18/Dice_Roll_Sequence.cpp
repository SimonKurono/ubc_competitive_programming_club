#include "bits/stdc++.h"
using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int solve(const vi& arr) {
    //split at each adjacent
    int n = arr.size();
    int count = 0;
    for (int i = 1; i < n; i++) {
        if ((7 - arr[i]) == arr[i-1] || arr[i] == arr[i-1]) {
            count++;
            i+=1;
        } 
    }

    return count;
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;                 // If problem has no t, delete this line and keep t=1
    while (t--) {
        int n;
        cin >> n;

        vi arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}
