#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
bool b[10][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;
    cin >> n >> m >> t;

    vector<vector<int>> a(n, vector<int>(m, 0));
    int sx, sy, fx, fy;
    cin >> sx >> sy >> fx >> fy;
    
    for(int i = 0; i < t; i++) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        a[x][y] = 1;
    }

    int tot = 0;
    auto dfs = [&](auto self, int x, int y) {
        if (x == fx && y == fy) {
            ++tot;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && xx < n && yy >= 0 && yy < m && !a[xx][yy] && !b[xx][yy]) {
                b[x][y] = true;
                self(self, xx, yy);  
                b[x][y] = false;
            }
        }
    };

    --sx, --sy, --fx, --fy;
    dfs(dfs, sx, sy);

    cout << tot << '\n';
}