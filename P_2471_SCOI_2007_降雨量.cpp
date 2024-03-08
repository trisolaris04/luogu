#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SparseTable {
    using VT = vector<T>;
    using VVT = vector<VT>;
    using func_type = function<T(const T &, const T &)>;

    VVT ST;
    func_type op;

    static T default_func(const T &t1, const T &t2) {
        return max(t1, t2);
    }

public:
    SparseTable(const vector<T> &v, func_type _func = default_func) : op(_func) {
        int len = v.size(), l1 = ceil(log2(len)) + 1;
        ST.assign(len, VT(l1, 0));

        for (int i = 0; i < len; ++i) {
            ST[i][0] = v[i];
        }

        for (int j = 1; j < l1; ++j) {
            int pj = (1 << (j - 1));
            for (int i = 0; i + pj < len; ++i) {
                ST[i][j] = op(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    T query(int l, int r) {
        int lt = r - l + 1;
        int q = floor(log2(lt));
        return op(ST[l][q], ST[r - (1 << q) + 1][q]);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    SparseTable<int> sparseTable(b);
    
    int q;
    cin >> q;

    while(q--) {
        int x, y, l, r;
        cin >> x >> y;
        l = lower_bound(a.begin(), a.end(), x) - a.begin();
        r = lower_bound(b.begin(), b.end(), y) - a.begin();
        if (b[sparseTable.query(l, r)] == b[r])
            cout << "true\n";
        else
            cout << "false\n";
    }
}