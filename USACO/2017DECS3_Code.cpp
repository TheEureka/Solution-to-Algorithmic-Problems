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
    IOS("shuffle");
    int n; 
    cin >> n;
    vi f(n + 1);
    vector<vi> radj(n + 1, vi());
    rep(i, n) cin >> f[i], radj[f[i]].pb(i);
    vector<bool> vis(n + 1, false);
    int ans = 0;

    auto dfs = [&](int u, auto& dfs) -> void {
        for (auto v: radj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dfs(v, dfs);
            }
        }
    };

    rep(i, n) {
        if (vis[i]) continue;
        int x = i;
        x = f[i];
        int y = f[x];

        
        while (x != y) {
            x = f[x];
            y = f[f[y]];
        }
        


        int len = 1;
        x = f[x];
        vis[x] = true;
        while (x != y) {
            len++;
            x = f[x];
            vis[x] = true;
        }
        x = f[x];
        while (x != y) {
            dfs(x, dfs);
            x = f[x];
        }
        dfs(x, dfs);

        ans += len;

    }

    cout << ans << endl;

    return 0;
}