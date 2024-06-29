#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int N;
    cin >> N;
    vector<int> s(N);
    for(int i = 0; i < N; i++) {
        cin >> s[i];
    }
    auto t = s;
    sort(t.begin(), t.end());
    bool test = true;
    for(int i = 0; i < N; i++) {
        if (s[i] != t[i]) test = false;
    }
    cout << (test ? "NO" : "YES") << endl; 
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
