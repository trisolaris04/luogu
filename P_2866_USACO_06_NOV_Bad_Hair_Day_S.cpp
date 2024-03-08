#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> q;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        while (!q.empty() && q.top() <= x)
            q.pop();
        ans += q.size();
        q.push(x);
    }
    cout << ans << '\n';
}