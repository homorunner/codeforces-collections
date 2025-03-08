#include "bits/stdc++.h"

using namespace std;

const int d = 15;

void solve() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> edges;
    vector<int> x(N), y(N);
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        edges.emplace_back(a-1, b-1);
    }

    // maybe optimize here, but not necessary to pass this problem.
    for(int i = 0; i < N; i++) {
        x[i] = i/d;
        y[i] = i%d;
    }

    vector<int> z(M, 0), offset_x(M, 0), offset_y(M, 0), cnt(N * 20, 0), cnt2(N * 20, 0);
    vector<vector<int>> cols(N/d + 1);
    for(int i = 0; i < M; i++) {
        auto [l, r] = edges[i];
        if (x[l] == x[r]) {
            cols[x[l]].push_back(i);
            offset_x[i] = 1;
        } else {
            offset_x[i] = -1;
        }
    }

    // edges in one column
    for(int i = 0; i <= N/d; i++) {
        for(int j = 0; j < cols[i].size(); j++) {
            int k = cols[i][j];
            z[k] = j + 1;
        }
    }
    
    // edges between two columns
    for(int j = 0; j < N * 20; j++) {
        bool found = false;
        vector<char> vis(N/d+1, 0);
        for(int i = 0; i < M; i++) {
            auto [l, r] = edges[i];
            if (!z[i] && !vis[x[l]] && !vis[x[r]]) {
                found = true;
                z[i] = j + 1;
                vis[x[l]] = true;
                vis[x[r]] = true;
                offset_y[i] = 5 * d + (cnt[j]++); 
            }
        }
        if (!found) {
            break;
        }
    }

    for(int i = 0; i < N; i++) {
        x[i] = 3*x[i] + 1;
        y[i] = 5*y[i] + 2;
        cout << x[i] << ' ' << y[i] << endl;
    }

    auto get_path = [&](int l, int e, vector<tuple<int, int, int>>& p) {
        switch(cnt2[l]++) {
            case 0:
                p.push_back({x[l], y[l], 0});
                p.push_back({x[l], y[l], z[e]});
                p.push_back({x[l]+offset_x[e], y[l], z[e]});
                if(offset_y[e]) {
                    p.push_back({x[l]+offset_x[e], offset_y[e], z[e]});
                    p.push_back({x[l]+offset_x[e], offset_y[e], z[e] + 1});
                }
            break;
            case 1:
                p.push_back({x[l], y[l], 0});
                p.push_back({x[l], y[l]-1, 0});
                p.push_back({x[l], y[l]-1, z[e]});
                p.push_back({x[l]+offset_x[e], y[l]-1, z[e]});
                if(offset_y[e]) {
                    p.push_back({x[l]+offset_x[e], offset_y[e], z[e]});
                    p.push_back({x[l]+offset_x[e], offset_y[e], z[e] + 1});
                }
            break;
            case 2:
                p.push_back({x[l], y[l], 0});
                p.push_back({x[l], y[l]+1, 0});
                p.push_back({x[l], y[l]+1, z[e]});
                p.push_back({x[l]+offset_x[e], y[l]+1, z[e]});
                if(offset_y[e]) {
                    p.push_back({x[l]+offset_x[e], offset_y[e], z[e]});
                    p.push_back({x[l]+offset_x[e], offset_y[e], z[e] + 1});
                }
            break;
            case 3:
                p.push_back({x[l], y[l], 0});
                p.push_back({x[l]+1, y[l], 0});
                p.push_back({x[l]+1, y[l]-2, 0});
                p.push_back({x[l], y[l]-2, 0});
                p.push_back({x[l], y[l]-2, z[e]});
                p.push_back({x[l]+offset_x[e], y[l]-2, z[e]});
                if(offset_y[e]) {
                    p.push_back({x[l]+offset_x[e], offset_y[e], z[e]});
                    p.push_back({x[l]+offset_x[e], offset_y[e], z[e] + 1});
                }
            break;
            case 4:
                p.push_back({x[l], y[l], 0});
                p.push_back({x[l]-1, y[l], 0});
                p.push_back({x[l]-1, y[l]+2, 0});
                p.push_back({x[l], y[l]+2, 0});
                p.push_back({x[l], y[l]+2, z[e]});
                p.push_back({x[l]+offset_x[e], y[l]+2, z[e]});
                if(offset_y[e]) {
                    p.push_back({x[l]+offset_x[e], offset_y[e], z[e]});
                    p.push_back({x[l]+offset_x[e], offset_y[e], z[e] + 1});
                }
            break;
            default:
                cout << "impossible cnt[" << l << "] = " << cnt2[l] << endl;
        }
    };
    for(int i = 0; i < M; i++) {
        z[i] *= 2;

        vector<tuple<int, int, int>> path, path2;
        get_path(edges[i].first, i, path);
        get_path(edges[i].second, i, path2);
        cout << path.size() + path2.size() << ' ';
        for(auto i: path) {
            cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << ' ';
        }
        for(int i = path2.size() - 1; i >= 0; i--) {
            cout << get<0>(path2[i]) << ' ' << get<1>(path2[i]) << ' ' << get<2>(path2[i]) << (i==0?'\n':' ');
        }
    }
}

int main() {
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    
    solve();
}
