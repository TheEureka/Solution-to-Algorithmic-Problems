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
    int n; cin >> n;
    vi a(n + 1), v(n + 1);
    vector<vi> radj(n + 1, vi());
    ll ans = 0ll;
    rep(i, n) cin >> a[i] >> v[i], ans += v[i], radj[a[i]].pb(i);
    vector<bool> vis(n + 1, false);

    auto fill_reverse = [&](int u, auto& fill_reverse) -> void {
        for (auto v: radj[u]) {
            if (vis[v]) continue;
            vis[v] = true;
            fill_reverse(v, fill_reverse);
        }
    };

    rep(i, n) {
        if (!vis[i]) {
            int x = a[i], y = a[x];
            while (x != y) {
                x = a[x];
                y = a[a[y]];
            }

            x = a[x];
            int minn = 2e9;
            while (x != y) {
                if (minn > v[x]) {
                    minn = v[x];
                }
                vis[x] = true;
                x = a[x];
            }
            if (minn > v[x]) {
                minn = v[x];
            }
            vis[x] = true;

            x = a[x];
            while (x != y) {
                fill_reverse(x, fill_reverse);
                x = a[x];
            }
            fill_reverse(x, fill_reverse);

            ans -= minn;
        }
    }
    cout << ans << endl;
    return 0;
}