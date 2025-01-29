#include "bits/stdc++.h"

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        int n2i = N & (1 << i), m2i = M & (1<<i);
        if (n2i == m2i) {
            ans += n2i;
            continue;
        }
        for (int j = N;; j++) {
            if (j != ans + m2i && j != ans + m2i - 1) {
                cout << ans + m2i << ' ' << ans + m2i - 1 << ' ' << j << endl;
                return;
            }
        }
    }
}

int main() {
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
