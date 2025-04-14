#include "bits/stdc++.h"

using namespace std;

int query(const vector<int> &stack, int n, int k, int extra) {
    vector<int> a(n, 0);
    for (int i = 0; i < k; i++) a[stack[i]] = 1;
    a[extra] = 1;

    cout << "query ";
    for (int i : a) cout << i;
    cout << endl;
    int x;
    cin >> x;
    return x;
}

void dfs(const vector<vector<int>>& children, int now){
	for(int i = 0; i < children[now].size() - 1; i++) {
        cout << '(';
    }
    // first element must be self so just print 'x'
	cout << 'x';
	for(int i = 1; i < children[now].size(); i++) {
		cout << '-';
        dfs(children, children[now][i]);
		cout << ')';
	}
}

void solve() {
    int N;
    cin >> N;

    vector<vector<int>> children(N);
    children[0] = {0}; // the tree initially has one node

    vector<int> stack = {0}; // the first x should be always 1.

    for (int i = 1; i < N; i++) {
        // suppose current expression is x - (x - (x - ?x? ...
        int first = query(stack, N, stack.size(), i);
        if (first != stack.size() % 2) {
            // maybe x - (x - (x - (x - ...
        } else {
            // maybe x - (x - (x - x - ...
            stack.pop_back();
        }

        // check if parents can be merged
        for (int k = stack.size() - 2; k > 0; k -= 2) {
            int second = query(stack, N, k, i);
            if (second != stack.size() % 2) {
                stack.pop_back();
                stack.pop_back();
            } else {
                break;
            }
        }

        children[stack.back()].push_back(i);
        children[i].push_back(i);
        stack.push_back(i);
    }


	cout << "answer ";
	dfs(children, 0);
	cout << endl;
}

int main() {
    cin.tie(nullptr), ios_base::sync_with_stdio(false);
    
    solve();
}
