#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int h[1000010], v[1000010], l[1000010], r[1000010];
ll ans[1000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> h[i] >> v[i];

    stack<int> q1, q2;
    for (int i = n; i >= 1; i--) {
        while (!q1.empty() && h[q1.top()] <= h[i])
            q1.pop();
        r[i] = q1.empty() ? 0 : q1.top();
        q1.push(i);
    }

    for (int i = 1; i <= n; i++) {
        while (!q2.empty() && h[q2.top()] <= h[i])
            q2.pop();
        l[i] = q2.empty() ? 0 : q2.top();
        q2.push(i);
    }

    for (int i = 1; i <= n; i++)
        ans[l[i]] += v[i], ans[r[i]] += v[i];
    
    ll maxn = 0;
    for (int i = 1; i <= n; i++)
        maxn = max(maxn, ans[i]);

    cout << maxn << '\n';
}