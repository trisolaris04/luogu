#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node {
    int x, y;
} a[100010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;

    for(int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y;
    
    sort(a + 1, a + n + 1, [&](Node c, Node d) {return c.y < d.y;});

    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;

    int j = 1, ans = 0x3f3f3f3f;
    for(int i = 2; i <= n; i++) {
        while(a[j].y <= a[i].y - d) {
            q1.push(a[j].x);
            ++j;
        }
        if(!q1.empty()) {
            while(q1.top() > a[i].x) {
                int p = q1.top();
                q1.pop();
                q2.push(p);
                if(q1.empty())
                    break;
            }
        }
        if(!q2.empty()) {
            while(q2.top() < a[i].x) {
                int p = q2.top();
                q2.pop();
                q1.push(p);
                if(q2.empty())
                    break;
            }
        }
        if(!q1.empty())
            ans = min(ans, a[i].x - q1.top());
        if(!q2.empty())
            ans = min(ans, q2.top() - a[i].x);
    }

    if(ans < 0x3f3f3f3f)
        cout << ans << '\n';
    else
        cout << "-1" << '\n';
}