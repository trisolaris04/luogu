#include <bits/stdc++.h>
using namespace std;

long long dep[1000010], sz[1000010], f[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> edge(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y), edge[y].push_back(x);
    }

    auto dfs = [&](auto self, int i, int fa) -> void {
        sz[i] = 1;
        for (auto j : edge[i]) {
            if (j == fa)
                continue;
            dep[j] = dep[i] + 1;
            self(self, j, i);
            sz[i] += sz[j];
        }
    };

    dfs(dfs, 1, -1);
    for (int i = 2; i <= n; i++)
        f[1] += dep[i];

    auto dfs1 = [&](auto self, int i, int fa) -> void {
        for (auto j : edge[i]) {
            if (j == fa)
                continue;
            f[j] = (n - sz[j]) + f[i] - sz[j];
            self(self, j, i);
        }
    };

    dfs1(dfs1, 1, 0);
    long long max = 0;
    int id;
    for (int i = 1; i <= n; i++)
        if(f[i] > max)
            max = f[i], id = i;

    cout << id << '\n';
}