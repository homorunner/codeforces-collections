#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

void solve() {
    int N[2];
    cin >> N[0] >> N[1];

    int total = N[0] + N[1] + 1;
    vector<int> s[2];
    s[0].reserve(total);
    s[1].reserve(total);

    for(int j = 0; j < 2; j++) {
        for(int i = 0; i < total; i++) {
            int x;
            cin >> x;
            s[j].push_back(x);
        }
    }

    // consider first N candidates first
    long long ans = 0;
    int count[2] = {0};
    int first_full = -1, index = -1; // index is the first person who falls into a job that he doesn't suit.
    for(int i = 0; i < total - 1; i++) {
        bool suit = s[0][i] <= s[1][i];
        if (count[suit] < N[suit]) {
            count[suit]++;
            ans += s[suit][i];
        } else {
            count[!suit]++;
            ans += s[!suit][i];
            if (first_full == -1) {
                first_full = suit;
                index = i;
            }
        }
    }

    // then check what happens when first i candidate doesn't come
    for (int i = 0; i < total - 1; i++) {
        bool suit = s[0][i] <= s[1][i];
        long long result;
        if (suit != first_full) {
            // this implies two possible situations:
            // 1. first_full is -1, that is, everyone fits into suit before the last one
            // 2. first_full is !suit, that is, everyone with suit fit and someone with !suit fall into suit.
            // in either case, the last one will fall into suit
            result = ans - s[suit][i] + s[suit][total - 1];
        } else if (i < index) {
            // if i < index, then current player fall into suit, and the indexed one will change from !suit to suit, and the last one will fall into !suit
            result = ans - s[suit][i] - s[!suit][index] + s[suit][index] + s[!suit][total - 1];
        } else {
            // else, nothing changes and the last one will replace the current one to fall into !suit
            result = ans - s[!suit][i] + s[!suit][total - 1];
        }
        cout << result << ' ';
    }

    // finally output the result of first N candidates
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
