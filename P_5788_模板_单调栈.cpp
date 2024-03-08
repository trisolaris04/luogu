#include <bits/stdc++.h>
using namespace std;

int a[3000010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    stack<int> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++) {
        if (!q.empty() && q.top() < a[i])
            cout << i << " ", q.pop();
        q.push(a[i]);
    }
}