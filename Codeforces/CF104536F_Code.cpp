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

vector<vi> G, H;
int n, m;


int diameter(int _n, vector<vi>& graph) {
    vector<int> dep(_n + 1, 0);
    int c = -1;
    auto dfs = [&](int u, int fa, auto &dfs) -> void {
        if (c == -1 || dep[c] < dep[u]) {
            c = u;
        }
        for (auto v: graph[u]) {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            dfs(v, u, dfs);
        }
    };
    dfs(1, 0, dfs);
    int tmp = c;
    dep[c] = 0;
    c = -1;
    dfs(tmp, 0, dfs);
    return dep[c];
}

int main() {
    IOS();
    cin >> n;
    G.assign(n + 1, vi());
    rep(i, n - 1) {
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
        G[v].pb(u);
    }
    cin >> m;
    H.assign(m + 1, vi());
    rep(i, m - 1) {
        int u, v;
        cin >> u >> v;
        H[u].pb(v);
        H[v].pb(u);
    }
    int first = diameter(n, G), second = diameter(m, H);
    cout << max({(first + 1) / 2 + (second + 1) / 2 + 1, first, second}) << endl;
    return 0;
}