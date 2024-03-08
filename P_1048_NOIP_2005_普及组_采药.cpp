#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mem[110][1010], v[110], w[110];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, n;
    cin >> t >> n;

    for(int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    memset(mem, -1, sizeof(mem));
    auto dfs = [&](auto self, int pos, int left) -> int {
        if (mem[pos][left] != -1)
            return mem[pos][left];
        if (pos > n)
            return mem[pos][left] = 0;
        int dfs1, dfs2 = -0x3f3f3f3f;
        dfs1 = self(self, pos + 1, left);
        if (left >= v[pos])
            dfs2 = self(self, pos + 1, left - v[pos]) + w[pos];
        return mem[pos][left] = max(dfs1, dfs2);
    };

    cout << dfs(dfs, 1, t) << endl;

    return 0;
}
