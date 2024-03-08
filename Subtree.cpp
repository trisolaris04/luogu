#include <bits/stdc++.h>
using namespace std;

long long dp1[200010], dp2[200010];
vector<long long> pre[200010], suf[200010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, mod;
    cin >> n >> mod;

    vector<vector<int>> edge(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v), edge[v].push_back(u);
    }

    auto dfs = [&](auto self, int u, int fa) -> void {
        dp1[u] = 1; 
        for (auto v : edge[u]) {
            if (v == fa)
               continue;
            self(self, v, u);
            dp1[u] = dp1[u] * (dp1[v] + 1) % mod;
            pre[u].push_back(dp1[v] + 1);
            suf[u].push_back(dp1[v] + 1);
        }
        for (int i = 1; i < pre[u].size(); i++)
            pre[u][i] = pre[u][i] * pre[u][i - 1] % mod;
        for (int i = suf[u].size() - 2; i >= 0; i--)
            suf[u][i] = suf[u][i] * suf[u][i + 1] % mod;
    };

    auto dfs1 = [&](auto self, int u, int fa) -> void {
        int num = 0, x = pre[u].size();
        for (auto v : edge[u]) {
            if(v == fa)
                continue;
            num++;
            if (x == 1) {
                dp2[v] = dp2[u] + 1;
            }
            else if (num == 1) {
                dp2[v] = dp2[u] * suf[u][num] % mod + 1;
            }
            else if (num == x) {
                dp2[v] = dp2[u] * pre[u][num - 2] % mod + 1;
            }
            else
                dp2[v] = dp2[u] * (pre[u][num - 2] * suf[u][num] % mod) % mod + 1;
            self(self, v, u);
        }
    };

    dfs(dfs, 1, -1);
    dp2[1] = 1;
    dfs1(dfs1, 1, -1);
    for (int i = 1; i <= n; i++)
        cout << dp1[i] * dp2[i] % mod << '\n';
}