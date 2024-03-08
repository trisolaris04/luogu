#include <bits/stdc++.h>
using namespace std;

int dp[6010][2], r[6010], fa[6010];

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> r[i];

    map<int, bool> mp;
    vector<vector<int>> edge(n + 1); 
    for (int i = 1; i < n; i++) {
        int l, k;
        cin >> l >> k;
        edge[k].push_back(l);
        mp[l] = true;
    }

    auto dfs = [&](auto self, int i) -> void {
        dp[i][1] = r[i];
        dp[i][0] = 0;
        for(auto j : edge[i]) {
            self(self, j);
            dp[i][0] += max(dp[j][0], dp[j][1]);
            dp[i][1] += dp[j][0];
        }
    };

    int p;
    for(int i = 1; i <= n; i++)
        if(!mp[i])
            p = i;
    dfs(dfs, p);

    cout << max(dp[p][0], dp[p][1]) << '\n';
}
