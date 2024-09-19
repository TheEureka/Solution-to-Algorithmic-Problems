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
int main() {
    IOS();
    int n;
    cin >> n;
    vector<vi> g(n + 1, vi());
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> dep(n + 1, 0);
    int c = 0;
 
    auto dfs = [&](int u, int fa, auto &dfs) -> void {
        if (dep[c] < dep[u]) c = u;
        for (auto v: g[u]) {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u, dfs);
        }
    };
 
    dfs(1, 0, dfs);
    dep[c] = 0;
    int tmp = c;
    c = 0;
    dfs(tmp, 0, dfs);
 
    vi dep1(n + 1, 0);
    auto dfs1 = [&](int u, int fa, auto &dfs1) -> void {
        for (auto v: g[u]) {
            if (v == fa) continue;
            dep1[v] = dep1[u] + 1;
            dfs1(v, u, dfs1);
        }
    };
 
    dfs1(c, 0, dfs1);
 
    rep(i, n) cout << max(dep[i], dep1[i]) << " \n"[i == n];
    return 0;
}
