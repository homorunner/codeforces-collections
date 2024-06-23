#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int N;
    cin >> N;

    vector<int> a, b;
    a.reserve(N);
    b.reserve(N);

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    for(int j = 0; j < N; j++) {
        int y;
        cin >> y;
        b.push_back(y);
    }

    long long ans = 0, interv = 1e9 + 1;
    int last;
    cin >> last;
    for (int i = 0; i < N; i++) {
        int local_interv;
        if (last >= a[i] && last >= b[i]) {
            local_interv = min(last - a[i], last - b[i]);
        }
        else if (last <= a[i] && last <= b[i]) {
            local_interv = min(a[i] - last, b[i] - last);
        }
        else {
            local_interv = 0;
        }
        if (interv > local_interv) interv = local_interv;
        ans += abs(a[i] - b[i]);
    }

    cout << ans + interv + 1 << endl;
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
