#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

long long solve(const vi& best_suffix, int l, int r);
long long solve2(const vector<long long>& prefix, int l, int r);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vi a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        vi best(n);
        for (int i = 0; i < n; i++) best[i] = max(a[i], b[i]);

        vi best_suffix(n);
        best_suffix[n - 1] = best[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            best_suffix[i] = max(best[i], best_suffix[i + 1]);
        }

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + best_suffix[i];
        }

        for (int qi = 0; qi < q; qi++) {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            
            long long ans = solve2(prefix, l, r);
            cout << ans << (qi + 1 == q ? '\n' : ' ');
        }
    }
    return 0;
}

long long solve(const vi& best_suffix, int l, int r) {
    long long sum = 0;
    for (int i = l; i <= r; i++) sum += best_suffix[i];
    return sum;
}

long long solve2(const vector<long long>& prefix, int l, int r) {
    return prefix[r + 1] - prefix[l];
}
