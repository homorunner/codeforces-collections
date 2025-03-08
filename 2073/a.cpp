#include "bits/stdc++.h"

using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> mp(N, vector<int>(M, 0));
    vector<int> c(M, 0), r(N, 0), sumc(N, 0), sumr(M, 0);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            char x = cin.get();
            while(x != '.' && x != '#') x = cin.get();
            if (x == '.') mp[i][j] = 1, c[j]++, r[i]++;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mp[i][j]) {
                sumc[i] += c[j];
                sumr[j] += r[i];
            }
        }
    }

    long long ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) { // iterate for point b
            if (mp[i][j]) {    
                // if b-c is on a row
                ans += 1ll * (sumc[i] - c[j] - r[i] + 1) * (c[j] - 1); // a-b and c-d are all column
                ans += 2ll * (r[i] - 1) * (r[i] - 2) * (c[j] - 1);                  // a-b is row or c-d is row, reflectively
                ans += 1ll * (r[i] - 1) * (r[i] - 2) * (r[i] - 3);

                // if b-c is on a column
                ans += 1ll * (sumr[j] - c[j] - r[i] + 1) * (r[i] - 1);
                ans += 2ll * (c[j] - 1) * (c[j] - 2) * (r[i] - 1);
                ans += 1ll * (c[j] - 1) * (c[j] - 2) * (c[j] - 3);
            }
        }
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    
    solve();
}
