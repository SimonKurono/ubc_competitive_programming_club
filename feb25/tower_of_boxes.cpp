#include <cmath>
#include <iostream>
using namespace std;




int solve(double n, double m, double d) {

  if (m > d) {
    return (int)n;
  }

  return (int) ceil(n / ((int)(d / m) + 1));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t = 1;
  cin >> t; // If problem has no t, delete this line and keep t=1
  while (t--) {
    double n, m, d;
    cin >> n >> m >> d;
    cout << solve(n, m, d) << "\n";
  }
  return 0;
}
