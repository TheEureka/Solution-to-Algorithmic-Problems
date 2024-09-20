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
const ll mod = 12;
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

template <const ll MOD>
struct modint {
    ll value;
    modint() = default;
    modint(ll value_) : value(value_) {}
    inline modint<MOD> operator + (modint<MOD> other) const { ll c = this->value + other.value; return modint<MOD>(c >= MOD ? c - MOD : c); }
    inline modint<MOD> operator - (modint<MOD> other) const { ll c = this->value - other.value; return modint<MOD>(c <    0 ? c + MOD : c); }
    inline modint<MOD> operator * (modint<MOD> other) const { ll c = (ll)this->value * other.value % MOD; return modint<MOD>(c < 0 ? c + MOD : c); }
    inline modint<MOD> & operator += (modint<MOD> other) { this->value += other.value; if (this->value >= MOD) this->value -= MOD; return *this; }
    inline modint<MOD> & operator -= (modint<MOD> other) { this->value -= other.value; if (this->value <    0) this->value += MOD; return *this; }
    inline modint<MOD> & operator *= (modint<MOD> other) { this->value = (ll)this->value * other.value % MOD; if (this->value < 0) this->value += MOD; return *this; }
    inline modint<MOD> operator - () const { return modint<MOD>(this->value ? MOD - this->value : 0); }
    modint<MOD> pow(ll k) const { modint<MOD> x = *this, y = 1; for (; k; k >>= 1) { if (k & 1) y *= x; x *= x; } return y; }
    modint<MOD> inv() const { return pow(MOD - 2); }  // MOD must be a prime
    inline modint<MOD> operator /  (modint<MOD> other) const { return *this *  other.inv(); }
    inline modint<MOD> operator /= (modint<MOD> other)       { return *this *= other.inv(); }
    inline bool operator == (modint<MOD> other) const { return value == other.value; }
    inline bool operator != (modint<MOD> other) const { return value != other.value; }
    inline bool operator < (modint<MOD> other) const { return value < other.value; }
    inline bool operator > (modint<MOD> other) const { return value > other.value; }
};
template <ll MOD> modint<MOD> operator * (ll value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <ll MOD> istream & operator >> (istream & in, modint<MOD> &n) { return in >> n.value; }
template <ll MOD> ostream & operator << (ostream & out, modint<MOD> n) { return out << n.value; }

using mint = modint<mod>;


const int maxn = 2505;
mint f[maxn];
vi g[maxn];
int n, leaves = 0;

bool flag = true;

void dfs(int u, int fa) {
    if (!flag) return;
    for (auto v: g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        f[u] -= f[v];
    }
}

int main() {
    IOS("clocktree");
    cin >> n;
    rep(i, n) {
        int x; cin >> x;
        f[i] = 12 - x;
    }
    rep(ii, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    rep(i, n) {
        if (sz(g[i]) == 1) {
            leaves++;
        }
    }
    int ans = 0;
    vector<mint> tmp(n + 1);
    rep(i, n) {
        rep(j, n) tmp[j] = f[j];
        dfs(i, 0);
        if (f[i] == 0 || f[i] == 11) {
            ans++;
        }
        rep(j, n) f[j] = tmp[j];
    }
    cout << ans << '\n';
    return 0;
}