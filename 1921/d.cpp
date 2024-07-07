#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    vector<int> a(N), b(M);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    // suppose we select a k, and a[i] - b[i] work for i in range[0, k), and a[i] - b[m-(n-i)] work for i in range[k, n)
    // then when k = 0, we get D
    long long D = 0;
    for (int i = 0; i < N; i++) {
        D += abs(b[M-N+i] - a[i]);
    }

    long long ans = D;
    // now we recalculate D by setting k from 1 to n
    for (int k = 0; k < N; k++) {
        D -= abs(b[M-N+k] - a[k]);
        D += abs(a[k] - b[k]);
        ans = max(ans, D);
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
