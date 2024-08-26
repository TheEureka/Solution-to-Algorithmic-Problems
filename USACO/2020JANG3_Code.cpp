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

const int maxn = 4e5 + 10;
vector<int> cc;

struct SegmentTree {
    #define mid (l + r) / 2
    #define lson rt << 1, l, mid
    #define rson rt << 1 | 1, mid + 1, r 
    vector<ll> minn;

    SegmentTree(int n) : minn(vector<ll>(n * 4 + 1, inf)) {}

    void push_up(int rt) {
        minn[rt] = min(minn[rt << 1], minn[rt << 1 | 1]);
    }


    void update(int rt, int l, int r, int pos, ll val) {
        if (l == r) {
            minn[rt] = min(minn[rt], val);
            return;
        }
        if (pos <= mid) update(lson, pos, val);
        else update(rson, pos, val);
        push_up(rt);
    }

    ll qry(int rt, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return minn[rt];
        }
        ll ans = inf;
        if (L <= mid) ans = min(ans, qry(lson, L, R));
        if (R > mid) ans = min(ans, qry(rson, L, R));
        return ans;
    }
    #undef mid
    #undef lson
    #undef rson
};

int ind(int x) {
    return lower_bound(alls(cc), x) - cc.begin() + 1; //(0, 0) has an ind of 1.
}

int main() {
    IOS("boards");
    ll N;
    int P;
    cin >> N >> P;
    /*
    type1: start of springboard
    type2: end of springboard
    */
    vector< array<int, 3> > boards;
    map<pii, ll> ans_record;
    map<pii, pii> mp1, mp2;
    rep(i, P) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cc.pb(x1);
        cc.pb(y1);
        cc.pb(x2);
        cc.pb(y2);
        mp1[mk(x2, y2)] = mk(x1, y1);
        array<int, 3> tmp1 = {x1, y1, 1}, tmp2 = {x2, y2, 2};
        boards.pb(tmp1);
        boards.pb(tmp2);
    }
    cc.pb(0);
    sort(alls(cc));
    cc.erase(unique(alls(cc)), cc.end());
    for (auto &[x, y, type]: boards) {
        if (mp1.find(mk(x, y)) != mp1.end()) {
            int x2 = mp1[mk(x, y)].first, y2 = mp1[mk(x, y)].second;
            x = ind(x);
            y = ind(y);
            mp2[mk(x, y)] = mk(ind(x2), ind(y2));
        }
        else {
            x = ind(x);
            y = ind(y);
        }
    }
    SegmentTree segtree(maxn);
    segtree.update(1, 1, maxn, ind(0), 0);
    sort(alls(boards));
    for (auto [x, y, type]: boards) {
        //distance = previous_step + (x - prev_x) + (y - prev_y) = (previous_step - prev_x - prev_y) + (x + y), so i only need to minimise (previous_step - prev_x - prev_y)
        ll prev_min;
        if (type == 1) {
            prev_min = segtree.qry(1, 1, maxn, ind(0), y);
            segtree.update(1, 1, maxn, y, prev_min);
            ans_record[mk(x, y)] = prev_min + (ll)cc[x - 1] + (ll)cc[y - 1];
        }
        else {
            int xx = mp2[mk(x, y)].first, yy = mp2[mk(x, y)].second;
            ll firsty = segtree.qry(1, 1, maxn,1, y) + (ll)cc[x - 1] + (ll)cc[y - 1], secondy = ans_record[mk(xx, yy)];
            if (firsty < secondy) {
                prev_min = firsty - cc[x - 1] - cc[y - 1];
                segtree.update(1, 1, maxn, y, prev_min);
                ans_record[mk(x, y)] = prev_min + cc[x - 1] + cc[y - 1];
            }
            else {
                prev_min = secondy;
                segtree.update(1, 1, maxn, y, prev_min - cc[x - 1] - cc[y - 1]);
                ans_record[mk(x, y)] = prev_min;
            }
        }
    }
    ll ans = segtree.qry(1, 1, maxn, 1, maxn) + N + N;
    if (ans_record.find(mk(ind(N), ind(N))) != ans_record.end()) {
        ans = min(ans_record[mk(ind(N), ind(N))], ans);
    }
    cout << ans << "\n";
    return 0;
}