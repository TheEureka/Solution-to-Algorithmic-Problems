#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define mk make_pair
#define pb push_back
#define alls(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define rep(i, n) for (int i = 1; i <= int(n); i++)
#define inc(i, l, r, d) for (int i = l; i <= r; i += d)
#define dec(i, r, l, d) for (int i = r; i >= l; i -= d) 
#define dbg(x) cerr << #x << " = " << x << endl;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
const ld eps = 1e-12;
const ll inf = 1e16;
const ll mod = 998244353;
const ll mod1 = 1e9 + 87;
const ll mod2 = 127397154761;
ll qpow(ll a, ll b) {if (b == 0) return 1; ll ans = qpow(a, b >> 1); ans = ans * ans % mod; if (b & 1) ans = ans * a % mod; return ans;}
using namespace std;

void IOS(string name = "") {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    if ((int)name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int maxn = 1e6 + 1;

struct SegmentTree {
    #define mid (l + r) / 2
    #define lson rt << 1, l, mid
    #define rson rt << 1 | 1, mid + 1, r 
    //Information stored about each node; data type can be changed according to problem contexts.
    //Sum is used below as an example.
    int _n;
    vector<int> sum, maxx;

    SegmentTree(int n) : _n(n), sum(vi(n * 4 + 1, 0)), maxx(vi(n * 4 + 1, 0)) {}

    void push_up(int rt) {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
        maxx[rt] = max(maxx[rt << 1 | 1], sum[rt << 1 | 1] + maxx[rt << 1]);
    }



    void update(int rt, int l, int r, int pos, int val) {
        if (l == r) {
            sum[rt] += val;
            maxx[rt] = sum[rt];
            return;
        }
        if (pos <= mid) update(lson, pos, val);
        else update(rson, pos, val);
        push_up(rt);
    }

    int qry(int rt, int l, int r, int suf) {
        if (maxx[rt] <= 0) return -1;
        if (l == r) return l;
        if (maxx[rt << 1 | 1] + suf > 0) return qry(rson, suf);
        else return qry(lson, suf + sum[rt << 1 | 1]);
    }
    #undef mid
    #undef lson
    #undef rson
};

int main() {
    IOS();
    int n, m;
    cin >> n >> m;
    vi a(n + 1, 0), b(m + 1, 0);
    SegmentTree segtree(maxn);
    rep(i, n) {
        cin >> a[i];
        segtree.update(1, 1, maxn - 1, a[i], 1);
    }
    rep(i, m) {
        cin >> b[i];
        segtree.update(1, 1, maxn - 1, b[i], -1);
    }
    int q; cin >> q;
    while (q--) {
        int ins, pos, x;
        cin >> ins >> pos >> x;
        if (ins == 1) {
            segtree.update(1, 1, maxn - 1, a[pos], -1);
            segtree.update(1, 1, maxn - 1, a[pos] = x, 1);
        }
        else {
            segtree.update(1, 1, maxn - 1, b[pos], 1);
            segtree.update(1, 1, maxn - 1, b[pos] = x, -1);
        }
        cout << segtree.qry(1, 1, maxn - 1, 0) << "\n";
    }
    return 0;
}