#include <iostream>
#include <string>
#include <vector>
using namespace std;
using vi = vector<long long>;

long long solve(vector<long long> v, long long x, long long y) {
    long long count = 0;
    long long total_trans = 0;
    long long total_mods = 0;
    long long cost = x-y;
    std::vector<long long> trans(v.size());
    std::vector<long long> mods(v.size());

    for (long long i = 0; i < v.size(); i++) {
        count += v[i];
        trans[i] = v[i]/x;
        mods[i] = v[i]%x;
        total_trans+=trans[i];
        total_mods += mods[i];
    }

    long long max = 0;
    
    for (long long j = 0; j < v.size(); j++) {
        long long total = count - ((total_trans - trans[j])*cost) - (total_mods - mods[j]);
        if (total > max) {
            max = total;
        }
    }
    return max;
}

long long main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        long long x, y;
        cin >> n >> x >> y;

        vector<long long> a(n);
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Now:
        // n = number of banks
        // x = transfer amount
        // y = credited amount
        // a = array of bank balances
        auto p = solve(a, x, y);

        cout << p << std::endl;
        
    }

    return 0;
}
