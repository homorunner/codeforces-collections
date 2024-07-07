#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int lx = 1e9, rx = -1e9, ly = 1e9, ry = -1e9;

    for (int i = 0; i < 4; i++) {
        int x, y;
        cin >> x >> y;
        lx = min(x, lx);
        rx = max(x, rx);
        ly = min(y, ly);
        ry = max(y, ry);
    }
    cout << (rx - lx) * (ry - ly) << endl;
}

int main() {
    // disables the synchronization between the C and C++ standard streams, accelerate input functions.
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
