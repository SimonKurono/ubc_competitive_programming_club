

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

using ll = long long;
using vi = vector<int>;
using vll = vector<long long>;

int solve(std::string str) {
    int count = 0;
    int zeros = 0;
    
    for (int i = 0; i < (int) str.size(); i++) {
        if (str[i] == '1') {
            count++;
            count += (zeros)/3;
            zeros = 0;
        } else {
            zeros++;
        }
    }

    count += std::ceil((double)zeros/3);

    return count;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t; 

    while (t--) {         
        int n;
        cin >> n;
        std::string str;
        cin >> str;
        auto p = solve(str);
        cout << p << "\n";
    }
    return 0;
}

