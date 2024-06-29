#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int N;
    cin >> N;

    long long ans = 0;
    bool can = false;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (i == 0 || i == N-1) continue;
        if (N == 3) {
            if (x % 2 == 0) can = true;
        }
        else if (x >= 2) can = true;
        ans += (x + 1) / 2;
    }
    cout << (can ? ans : -1) << endl;
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
