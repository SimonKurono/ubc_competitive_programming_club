#include <iostream>
#include <string>
#include <vector>
using namespace std;
using vi = vector<int>;

int solve(int boards, int width) {


    return (boards - (boards/width));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;                 // If problem has no t, delete this line and keep t=1
    while (t--) {   
        int boards;
        cin >> boards;

        int width;
        cin >> width;

        auto p = solve(boards, width);
        
        cout << p << std::endl;
    }

    return 0;
}
