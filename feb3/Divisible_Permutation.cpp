#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n) {
    vector<int> ans(n);
    bool takeSmall = true;
    int small = 1, large = n;

    for (int i = n - 1; i >= 0; --i) {
        if (takeSmall) {
            ans[i] = small++;
        } else {
            ans[i] = large--;
        }
        takeSmall = !takeSmall;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        auto p = solve(n);
        for (int i = 0; i < n; i++) {
            cout << p[i] << (i + 1 == n ? '\n' : ' ');
        }
    }
    return 0;
}
