#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int q[100010], p[100010];

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = -1; 
    for(int i = 0; i < n; i++) {
        while(r >= l && a[i] <= q[r])
            r--;
        q[++r] = a[i];
        p[r] = i;
        while(p[l] <= i - k){
            l++;
        }
        if(i >= k - 1)
            cout << q[l] << " ";
    }
    cout << '\n';
    l = 0, r = -1;
    for(int i = 0; i < n; i++) {
        while(r >= l && a[i] >= q[r])
            r--;
        q[++r] = a[i];
        p[r] = i;
        while(p[l] <= i - k){
            l++;
        }
        if(i >= k - 1)
            cout << q[l] << " ";
    }
}