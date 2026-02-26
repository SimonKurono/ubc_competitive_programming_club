#include <iostream>
#include <cmath>
#include <unordered_map>
using namespace std;


int solve(long long n) {
    std::unordered_map<int, int> freqs;
    int count = 0;

    while (n>9) {
        int digit = n % 10;
        count+=digit;
        freqs[digit]++;

        n/=10;   
    }

    count+=n;
    //cout << "count: " << count << "\n";
    
    int max = 9;
    int ans = 0;
    while (count > 9) {
        if (freqs.count(max) && freqs[max] > 0) {
            if ((n-1) > max) {
                count -= (n-1);
                n = 0;
                //cout << "count: " << count << "\n";
            } else {

                count -= max;
                freqs[max]--;
                //cout << "count: " << count << "\n";
            }
            ans++;
        } else {
            max--;
        }
        
    }

    return ans;



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t = 1;
    cin >> t;                 // If problem has no t, delete this line and keep t=1
    while (t--) {
        long long n;
        cin >> n;
        cout << solve(n) << "\n";
    }

    return 0;
}

