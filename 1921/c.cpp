#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int N;
    cin >> N;

    int current, per_time, per_interval;
    cin >> current >>  per_time >> per_interval;

    bool result = true;
    int last = 0;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (result) {
            auto mi = min(1ll * (x - last) * per_time, 1ll * per_interval);
            if (current <= mi) {
                result = false;
            } else {
                current -= mi;
                last = x;
            }
        }
    }

    puts(result ? "YES" : "NO");
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
