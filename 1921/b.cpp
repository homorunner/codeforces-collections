#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int N;
    cin >> N;
    string a, b;
    cin >> a >> b;

    int less = 0, more = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] != b[i]) {
            if (a[i] == '0') less++;
            else more++;
        }
    }

    cout << max(less, more) << endl;
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
