#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, tot = 0, a[110], b[110], c[110], d[110];

void dfs(int i) {
    if(i > n) {
        if(tot <= 2) {
            for(int k = 1; k <= n; k++)
                cout << a[k] << " ";
            cout << '\n'; 
        }
        ++tot;
        return;
    }
    for(int j = 1; j <= n; j++) {
        if(!b[j] && !c[i + j] && !d[i - j + n]) {
            a[i] = j;
            b[j] = c[i + j] = d[i - j + n] = 1;
            dfs(i + 1);
            b[j] = c[i + j] = d[i - j + n] = 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    dfs(1);
    cout << tot << '\n';
}