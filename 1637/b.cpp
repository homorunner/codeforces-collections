#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int N, x;
    cin >> N;
    long long ans = 0;
    for(int i = 0; i < N; i++) {
        cin >> x;
        ans += (1ll + (x==0)) * (i+1) * (N-i);
    }
    cout << ans << endl;
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
