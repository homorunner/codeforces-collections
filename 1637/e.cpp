#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;

    // c stores the pair of {count[x], x}. 
    // an interesting fact is that size(c) < sqrt(N)
    map<int, vector<int>> c;

    // cnt is the indexed reverse map of c
    map<int, int> cnt;

    for(int i = 0; i < N; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(auto [x, y]: cnt){
        c[y].push_back(x);
    }
    unordered_set<long long> bad;
    for(int i=0; i<M; i++){
        int a, b;
        cin >> a >> b;
        if(a>b) swap(a, b);
        bad.insert(((long long)a << 32) + b);
    }
    long long ans = 0;
    for(auto& [x, vx]: c){
        sort(vx.begin(), vx.end());
        for(auto& [y, vy]: c) {
            for(auto px: vx){
                for(int i = vy.size()-1; i >= 0; i--){
                    int py = vy[i];
                    if(py != px && 
                    bad.find(((long long)min(px, py) << 32) + max(px, py))==bad.end()){
                        ans = max(ans, 1ll*(px+py)*(x+y));
                        break;
                    }
                }
            }
            if(x==y) break;
        }
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
