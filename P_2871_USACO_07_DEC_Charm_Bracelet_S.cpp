#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int w[4000], d[4000], f[400000];

int main() {
    int n, v;
    cin >> n >> v;

    for (int i = 1; i <= n; i++)
        cin >> w[i] >> d[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = v; j >= w[i]; j--)
            f[j] = max(f[j], f[j - w[i]] + d[i]);
    
    cout << f[v] << '\n';
}