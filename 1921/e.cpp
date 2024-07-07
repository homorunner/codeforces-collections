#include "bits/stdc++.h"

// using the std namespace is not recommanded in projects but common in competitive programming
using namespace std;

// this function judges the state that delta_x % 2 == 1.
bool can_win(int M, int y1, int y2, int delta_x) {
    if (delta_x <= 0) return false;
    if (delta_x == 1 && abs(y1 - y2) <= 1) return true;

    // Alice take the first step
    if (y1 < y2) y1++;
    else if (y1 > y2) y1--;
    else return true;

    // Bob run from either direction, check if Alice can catch him at the wall.
    if (y1 < y2) {
        return M - y1 < (delta_x + 1) / 2;
    }
    else if (y1 > y2) {
        return y1 - 1 < (delta_x + 1) / 2;
    }
    else return true;
}

std::string judge(int M, int y1, int y2, int x1, int x2) {
    if (x1 >= x2) return "Draw";
    
    int delta_x = x2 - x1;
    if (delta_x % 2) {
        return can_win(M, y1, y2, delta_x) ? "Alice" : "Draw";
    }

    delta_x--;
    if (y1 > y2) y1 = min(y1 + 1, M);
    else if (y1 < y2) y1 = max(0, y1 - 1);

    return can_win(M, y2, y1, delta_x) ? "Bob" : "Draw";
}

void solve() {
    int N, M;
    cin >> N >> M;

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << judge(M, y1, y2, x1, x2) << endl;
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
