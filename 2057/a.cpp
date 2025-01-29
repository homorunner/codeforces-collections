#include "bits/stdc++.h"

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    cout << max(N, M) + 1 << endl;
}

int main() {
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
