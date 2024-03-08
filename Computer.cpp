#include <bits/stdc++.h>
using namespace std;

int val[10010][10010], dp[3][10010], id[10010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;

    while(~scanf("%d", &n)) { 
        memset(dp, 0, sizeof(dp));
        vector<vector<int>> edge(n + 1);
        for (int i = 2; i <= n; i++) {
            int x, y;
            cin >> x >> y;
            edge[i].push_back(x), edge[x].push_back(i);
            val[i][x] = val[x][i] = y;        
        }

        auto dfs1 = [&](auto self, int i, int fa) -> void {
            for (auto j : edge[i]) {
                if (j == fa)
                    continue;
                self(self, j, i);
                //dp[0][i] = max(dp[0][i], dp[0][j] + val[i][j]);
                if (dp[0][j] + val[i][j] > dp[0][i])
                    id[i] = j, dp[0][i] = dp[0][j] + val[i][j]; 
            }

            for (auto j : edge[i]) {
                if (j == fa)
                    continue;
                if (j == id[i])
                    continue;
                self(self, j, i);
                if (dp[1][j] + val[i][j] > dp[1][i])
                    dp[1][i] = dp[1][j] + val[i][j];
            }
        };

        auto dfs2 = [&](auto self, int i, int fa) -> void {
            for (auto j : edge[i]) {
                if (j == fa)
                    continue;
                if(j == id[i]) {
                    dp[2][j] = max(dp[2][i], dp[1][i]) + val[j][i];
                } else {
                    dp[2][j] = max(dp[0][i], dp[2][i]) + val[j][i];
                }
                self(self, j, i);
            }
        };

        dfs1(dfs1, 1, -1);
        dfs2(dfs2, 1, -1);

        for(int i = 1; i <= n; i++)
            cout << max(dp[0][i], dp[2][i]) << '\n';
        }
}
