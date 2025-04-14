#include "bits/stdc++.h"

using namespace std;

int dfs(int u, int pa, int& id, const vector<vector<int>> &edges, vector<int> &dfn, vector<int> &sta, vector<char> &in_sta) {
    if (dfn[u]) {
        if (in_sta[u]) {
            int size = 0;
            for (int i = sta.size() - 1; i >= 0; i--) {
                size++;
                if (sta[i] == dfn[u]) break;
            }
            // cout << "Found cycle of size " << size << endl;
            return size % 2;
        }
        else return 0;
    }
    dfn[u] = id;
    sta.push_back(id);
    in_sta[u] = 1;
    int result = 0;
    for (auto v : edges[u]) {
        if (v == pa) continue;
        result += dfs(v, u, ++id, edges, dfn, sta, in_sta);
    }
    sta.pop_back();
    in_sta[u] = 0;
    return result;
}

void solve() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> edges(N);
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    vector<int> dfn(N, 0);
    vector<int> sta;
    vector<char> in_sta(N, 0);
    int id = 1;
    int ans = M + 1;

    for (int i = 0; i < N; i++) {
        if (dfn[i]) continue;
        ans -= dfs(i, -1, id, edges, dfn, sta, in_sta);
    }

    cout << ans << endl;
}

int main() {
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    
    solve();
}
