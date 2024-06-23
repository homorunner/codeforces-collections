#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;


// calculates max required tower height & min cost of subtree
pair<int, long long> dfs(int x, int fa
        , const vector<int>& h
        , const vector<vector<int>>& e){
    int max_height = 0, submax_height = 0;
    long long sum_cost = 0;
    for(auto i: e[x]) if(i!=fa){
        auto [subtree_height, subtree_cost] = dfs(i, x, h, e);
        if(max_height < subtree_height){
            submax_height = max_height;
            max_height = subtree_height;
        }
        else if(submax_height < subtree_height){
            submax_height = subtree_height;
        }
        sum_cost += subtree_cost;
    }
    if(fa==-1){
        return {h[x], sum_cost + h[x]*2 - max_height - submax_height};
    }
    else if(h[x]<max_height){
        return {max_height, sum_cost};
    }
    return {h[x], sum_cost + h[x] - max_height};
}

void solve() {
    int N;
    cin >> N;
    
    vector<int> h(N);
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }
    vector<vector<int>> edges(N);
    for(int i = 0; i < N-1; i++){
        int a, b;
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }
    
    int root = 0;
    for(int i = 1; i < N; i++){
        if(h[i] > h[root]) root = i;
    }
    auto [_, ans] = dfs(root, -1, h, edges);

    cout << ans << endl;
}

int main() {
    // disables the synchronization between the c and c++ standard streams, accelerate input functions.
    cin.tie(nullptr), ios_base::sync_with_stdio(false);

    solve();
}
