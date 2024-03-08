#include <bits/stdc++.h>
using namespace std;

long long v[10010], w[100010], f[10000000];

int main() {
    int t, n;
    cin >> t >> n;

    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= n; i++)
        for (int j = v[i]; j <= t; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[t] << '\n'; 
}