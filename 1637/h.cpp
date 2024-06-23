#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> s(N), c(N);
    for (int i = 0; i < N; i++) {
        cin >> s[i];
    }

    // T is segment tree that accumulates the number of indexes that s[i] < x
    vector<int> T(N + 1, 0);

    // inv is the number of inversed paires of the original sequence s
    long long inv = 0;

    for (int i = 0; i < N; i++) {
        // ...T[x]... i ...
        int l = 0;
        for (int x = s[i]; x; x -= (x & -x)) {
            l += T[x];
        }
        c[i] = 2 * s[i] - 2 - i;
        inv += i - l;
        for (int x = s[i]; x <= N; x += (x & -x)) {
            T[x]++;
        }
    }

    sort(c.begin(), c.end());
    long long sum = 0;
    for (int k = 0; k < N; k++) {
        long long ans = inv + sum;
        cout << ans << ' ';
        sum += c[k] - k;
    }
    cout << inv << endl;
}

int main() {
    // disables the synchronization between the c and c++ standard streams, accelerate input functions.
    cin.tie(nullptr), ios_base::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
