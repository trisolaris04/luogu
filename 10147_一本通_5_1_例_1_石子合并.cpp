#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[410], f1[410][410], f2[410][410];

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        cin >> a[i], a[i + n] = a[i], f1[i][i] = f2[i][i] = a[i];

    
}