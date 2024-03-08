#include <bits/stdc++.h>
using namespace std;

int f[4000010];

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int v, w, l;
        cin >> v >> w >> l;
        for (int j = 1; j <= l; l -= j, j *= 2)
            for (int k = m; k >= j * w; k--)
                f[k] = max(f[k], f[k - j * w] + j * v);
        for (int j = m; j >= l * w; j--)
            f[j] = max(f[j], f[j - l * w] + l * v);
    }

    cout << f[m] << '\n';
}