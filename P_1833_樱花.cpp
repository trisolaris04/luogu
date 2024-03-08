#include <bits/stdc++.h>
using namespace std;

long long f[100000];

char c;
int main() {
    int h1, h2, m1, m2;
    scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);

    if (m2 < m1)
        m2 += 60, h2--;
    int V = (h2 - h1) * 60 + m2 - m1;

    int n;
    cin >> n;  // Add this line to read the value of n
    for (int i = 1; i <= n; i++) {
        int v, w, l;
        cin >> v >> w >> l;
        if (l == 0) {
            for (int j = v; j <= V; j++)
                f[j] = max(f[j], f[j - v] + w);
        } else {
            if (l == 1) {
                for (int j = V; j >= v; j--)
                    f[j] = max(f[j], f[j - v] + w);
            } else {
                for (int j = 1; j <= l; l -= j, j *= 2)
                    for (int k = V; k >= j * v; k--)
                        f[k] = max(f[k], f[k - j * v] + j * w);
                for (int j = V; j >= l * v; j--)
                    f[j] = max(f[j], f[j - l * v] + l * w);
            }
        }
    }
    cout << f[V] << '\n';
}
