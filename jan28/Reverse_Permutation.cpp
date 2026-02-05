#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
using vi = vector<int>;

vi solve(vi a);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vi ans = solve(a);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << (i + 1 == ans.size() ? '\n' : ' ');
        }
    }
    return 0;
}

vi solve(vi a) {
    int left = 0;
    int right = a.size()-1;

    int n = a.size();

    while (left <= right) {
        if (a[left] == n) {
            left++;
            n--;
        }
        else if (a[right] == n) {
            std::reverse(a.begin() + left, a.begin() + right + 1);
            return a;
        } else {
            right--;
        }
    }

    return a;
    
}
