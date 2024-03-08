#include <bits/stdc++.h>
using namespace std;

int w[410], f[410][310];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> edge(n + 1);
    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k >> w[i];
        edge[k].push_back(i);
    }

    auto dfs = [&](auto self, int i) -> int {
        f[i][1] = w[i];
        int p = 1;
        for (auto j : edge[i]) {
            int sz = self(self, j);
            for (int x = min(p, m + 1); x; x--)
                for (int y = 1; y + x <= m + 1 && y <= sz; y++)
                    f[i][x + y] = max(f[i][x + y], f[i][x] + f[j][y]);
            p += sz;
        }
        return p;
    };

    dfs(dfs, 0);
    cout << f[0][m + 1] << '\n';
}