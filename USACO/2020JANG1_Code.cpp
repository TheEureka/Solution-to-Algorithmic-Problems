/*
Come seek us where our voices sound,
we cannot sing above the ground.
And while you're searching, ponder this:
we've taken what you'll sorely miss.
An hour long you'll have to look, 
and to recover what we took.
But past an hour, the prospect's black,
too late, it's gone, it won't come back.
*/
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
const ll mod1 = 1e9 + 87;
const ll mod2 = 127397154761;
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

/*
If dis[T][i] means the answer to the question if we end at city i on day T, then:
    1) Initialisation:
        dis[0][1] = 0
        dis[0][others] = inf
    2) Transition:
        dis[T + 1][sons[u]] = min(dis[T + 1][sons[u]], dis[T][u] - C * (2T + 1))
    3) Answer:
        The maximum value of dis[T][1] over 1 <= T <= 1000.
*/

int n, m, c;
int moonies[1005];
ll dp[1005][1005];
vi g[1005];

int main() {
    IOS("time");
    cin >> n >> m >> c;
    rep(i, n) cin >> moonies[i];
    rep(ii, m) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
    }
    dp[0][1] = 0;
    inc(i, 2, n, 1) dp[0][i] = -1;
    rep(i, n) {
        rep(j, n) {
            dp[i][j] = -1;
        }
    }
    ll ans = 0ll;
    forn(T, 1000) {
        ans = max(ans, dp[T][1]);
        rep(u, n) {
            if (dp[T][u] != -1)
            for (auto v: g[u]) {
                dp[T + 1][v] = max(dp[T + 1][v], dp[T][u] + moonies[v] - 1ll * c * (2 * T + 1));
            }
        }
    }

    cout << ans << endl;
    return 0;
}