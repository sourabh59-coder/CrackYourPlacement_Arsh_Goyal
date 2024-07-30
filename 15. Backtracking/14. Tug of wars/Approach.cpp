#include <bits/stdc++.h>
#define int long long
using namespace std;

void fun(const vector<int> &v, int ind, int count, int temp, int &ans, int sum) {
    if (count == 0) {
        int val = sum - temp;
        ans = min(ans, abs(temp - val));
        return;
    }

    if (ind >= v.size()) return;

    // Not Take
    fun(v, ind + 1, count, temp, ans, sum);

    // Take
    temp += v[ind];
    fun(v, ind + 1, count - 1, temp, ans, sum);
    temp -= v[ind]; 
}

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    int sum = accumulate(v.begin(), v.end(), 0LL);
    int ans = LLONG_MAX;

    int si = n / 2;
    fun(v, 0, si, 0, ans, sum);

    cout << ans << endl;
}

signed main() {
    solve();
    return 0;
}
