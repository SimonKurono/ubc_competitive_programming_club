#include "bits/stdc++.h"
using namespace std;


std::string solve(vector<int> arr) {
    return (std::count(arr.begin(), arr.end(), 67) > 0) ? "YES" : "NO";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    std::cin >> t;                 // If problem has no t, delete this line and keep t=1
    while (t--) {
        int n;
        std::cin >> n;

        vector<int> arr(n);

        for (int i = 0; i < n; i++) {
            std::cin >> arr[i];
        }

        std::cout << solve(arr) << "\n";
        
    }
    return 0;
}
