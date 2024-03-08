#include <bits/stdc++.h>
using namespace std;

int f[210][210];

int main() {
    int n, m, t;
    cin >> n >> m >> t;

    for (int k = 1; k <= n; k++) {
        int M, T;
        cin >> M >> T;
        for (int i = m; i >= M; i--)
            for (int j = t; j >= T; j--)
                f[i][j] = max(f[i][j], f[i - M][j - T] + 1);                
    } 

    cout << f[m][t] << '\n';
}