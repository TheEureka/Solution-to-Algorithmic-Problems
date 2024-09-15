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

const int maxn = 3e5 + 5;

struct SegTree {
    #define mid (l + r) / 2
    #define lson rt << 1
    #define rson rt << 1 | 1

    int lef[maxn * 4], rig[maxn * 4], maxx[maxn * 4], minn[maxn * 4], arr[maxn];
    ll sum[maxn * 4], tag[maxn * 4];

    void push_up(int rt) {
        sum[rt] = sum[lson] + sum[rson];
        maxx[rt] = max(maxx[lson], maxx[rson]);
        minn[rt] = min(minn[lson], minn[rson]);
    }

    void build(int rt, int l, int r) {
        lef[rt] = l; rig[rt] = r, tag[rt] = inf;
        if (l == r) {
            maxx[rt] = minn[rt] = sum[rt] = arr[l];
            return;
        }
        build(lson, l, mid);
        build(rson, mid + 1, r);
        push_up(rt);
    }

    void put_tag(int rt, int val) {
        minn[rt] = maxx[rt] = tag[rt] = val;
        sum[rt] = (ll)(rig[rt] - lef[rt] + 1) * (ll)val;
    }

    void push_down(int rt) {
        put_tag(lson, tag[rt]);
        put_tag(rson, tag[rt]);
        tag[rt] = inf;
    }

    void update(int rt, int L, int R, int val) {
        int l = lef[rt], r = rig[rt];
        if (L <= l && r <= R) {
            maxx[rt] = minn[rt] = tag[rt] = val;
            sum[rt] = (ll)val * (ll)(r - l + 1);
            return;
        }
        if (tag[rt] < inf) push_down(rt);
        if (L <= mid) update(lson, L, R, val);
        if (R > mid) update(rson, L, R, val);
        push_up(rt);
    }

    ll qry(int rt, int L, int R) {
        int l = lef[rt], r = rig[rt];
        if (L <= l && r <= R) {
            return sum[rt];
        }
        if (tag[rt] < inf) push_down(rt);
        ll ans = 0ll;
        if (L <= mid) ans += qry(lson, L, R);
        if (R > mid) ans += qry(rson, L, R);
        return ans;
    }

    int findl(int rt, int L, int val) {
        if (maxx[rt] < val) {
            return -1;
        }
        int l = lef[rt], r = rig[rt];
        if (l == r) {
            return l;
        }
        if (tag[rt] < inf) push_down(rt);
        if (mid >= L) {
            return findl(lson, L, val);
        }
        int ret = findl(lson, L, val);
        if (ret == -1) return findl(rson, L, val);
        else return ret;
    }

    int findr(int rt, int L, int val) {
        if (minn[rt] > val) {
            return -1;
        }
        int l = lef[rt], r = rig[rt];
        if (tag[rt] < inf) push_down(rt);
        if (l == r) {
            return l;
        }
        if (tag[rt] < inf) push_down(rt);
        if (mid < L) {
            return findr(rson, L, val);
        }
        int ret = findr(rson, L, val);
        if (ret == -1) return findr(lson, L, val);
        else return ret;
    }
}segtree;

int n, q, a[maxn];
ll ans = 0ll;

int main() {
    IOS();
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        a[i] -= i;
        segtree.arr[i] = a[i];
    }
    segtree.build(1, 1, n);
    cin >> q;
    while (q--) {
        int T, G;
        cin >> T >> G;
        G -= T;
        ll cur = segtree.qry(1, T, T);
        if (cur < G) {
            int r = segtree.findr(1, T, G);
            ans += (ll)G * (ll)(r - T + 1) - segtree.qry(1, T, r);
            segtree.update(1, T, r, G);
        }
        else {
            int l = segtree.findl(1, T, G);
            ans += segtree.qry(1, l, T) - (ll)G * (ll)(T - l + 1);
            segtree.update(1, l, T, G);
        }
    }
    cout << ans << '\n';
    return 0;
}
