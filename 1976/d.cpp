#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

// Sparse Table can calculate the max/min of any range in an array with O(n\log(n)) initialization and O(1) query.
template <typename T>
class SparseTable {
  vector<vector<T>> ST;

 public:
  SparseTable(const vector<T> &v) {
    int len = v.size(), l1 = ceil(log2(len)) + 1;
    ST.assign(len, vector<T>(l1, 0));
    for (int i = 0; i < len; ++i) {
      ST[i][0] = v[i];
    }
    for (int j = 1; j < l1; ++j) {
      int pj = (1 << (j - 1));
      for (int i = 0; i + pj < len; ++i) {
        ST[i][j] = max(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
      }
    }
  }

  // queries l and r inclusive
  T query(int l, int r) {
    int lt = r - l + 1;
    int q = floor(log2(lt));
    return max(ST[l][q], ST[r - (1 << q) + 1][q]);
  }
};

void solve() {
    string s;
    cin >> s;

    int N = s.length();

    // first calculate the prefix sum of the bracket sequence.
    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        a[i] = (i == 0 ? 0 : a[i-1]) + (s[i] == '(' ? 1 : -1);
    }

    // use sparse table to query max(l, r) in O(1).
    SparseTable<int> st(a);

    long long ans = 0;
    vector<int> index(N), count(N, 0);
    for(int i = 0; i < N; i++) {
        if (a[i] == 0) continue;
        if (count[a[i]] == 0 || st.query(index[a[i]], i+1) > 2 * a[i]) {
            index[a[i]] = i+1;
            count[a[i]] = 1;
        } else {
            ans += count[a[i]];
            count[a[i]] ++;
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
