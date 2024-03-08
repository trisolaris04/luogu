#include <bits/stdc++.h>
using namespace std;

int dp[6010][2], r[6010], fa[6010];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> r[i];

    vector<int> edge[n + 1];
    for (int i = 1; i <= n; i++) {
        int l, k;
        cin >> l >> k;
        fa[l] = k;
        edge[l].push_back(k), edge[k].push_back(l);
    }

    auto dfs = [&](auto self, int i) {
        dp[i][1] = a[i];
        dp[i][0]
    }
}