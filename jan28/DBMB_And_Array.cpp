#include <iostream>
#include <string>
#include <vector>
using namespace std;
using vi = vector<int>;

string solve(const vi& a, int x, int s);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, s, x;
        cin >> n >> s >> x;
        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << solve(a, x, s) << '\n';
    }
}

string solve(const vi& a, int x, int s) {
    int count = 0;

    for (int i = 0; i < a.size(); i++) {
        count += a[i];
    }

    if (count > s) {
        return "NO";
    }

    if ((s - count) % x == 0) {
        return "YES";
    }
    return "NO";
}

