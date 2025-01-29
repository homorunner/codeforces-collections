#include "bits/stdc++.h"

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    std::map<int, int> mp;
    std::vector<int> counts;
    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        mp[k]++;
    }
    for (auto [_, cnt]: mp) {
        counts.push_back(cnt);
    }
    sort(counts.begin(), counts.end());
    int ans = counts.size();
    for (int i = 0; i < counts.size(); i++) {
        if (counts[i] <= M) {
            M -= counts[i];
            ans--;
        } else break;
    }
    cout << max(ans, 1) << endl;
}

int main() {
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
