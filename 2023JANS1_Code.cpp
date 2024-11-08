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
template<typename T> bool chkmin(T &a, T b){ return (b < a) ? a = b, 1 : 0; }
template<typename T> bool chkmax(T &a, T b){ return (b > a) ? a = b, 1 : 0; }
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
#define uid(lef, rig) uniform_int_distribution<int>(lef, rig)(rng)
#define ulld(lef, rig) uniform_int_distribution<ll>(lef, rig)(rng64)

void IOS(string name = "") {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    if ((int)name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int maxn = 1505;
vector<pii> g[maxn][maxn];
int preced[maxn][maxn];
pii nxt[maxn][maxn];
char s[maxn][maxn];
int row[maxn], col[maxn];
bool vis[maxn][maxn];
int n;

void dfs(int x, int y) {
    for (auto it: g[x][y]) {
        dfs(it.first, it.second);
        preced[x][y] += preced[it.first][it.second];
    }
}

int cost(pii where) {
    if (where.first == n + 1) {
        return col[where.second];
    }
    return row[where.first];
}

int change(int x, int y, int val) {
    preced[x][y] += val;
    if (x == n + 1 || y == n + 1) {
        return cost(mk(x, y));
    }
    int xx, yy;
    tie(xx, yy) = nxt[x][y];
    return change(xx, yy, val);
}




int main() {
    IOS();
    cin >> n;
    rep(i, n) {
        rep(j, n) {
            preced[i][j] = 1;
            cin >> s[i][j];
            if (s[i][j] == 'R') {
                nxt[i][j] = mk(i, j + 1);
                g[i][j + 1].pb(mk(i, j));
            }
            else {
                nxt[i][j] = mk(i + 1, j);
                g[i + 1][j].pb(mk(i, j));
            }
        }
        preced[i][n + 1] = 1;
        cin >> row[i];
    }
    rep(j, n) {
        preced[n + 1][j] = 1;
        cin >> col[j];
    }

    rep(i, n) {
        dfs(i, n + 1);
        dfs(n + 1, i);
    }
    
    int ans = 0;
    rep(i, n) {
        ans += row[i] * (preced[i][n + 1] - 1) + col[i] * (preced[n + 1][i] - 1);
    }
    cout << ans << '\n';
    int q; cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        int old_dest, new_dest;
        if (s[x][y] == 'R') {
            old_dest = change(x, y + 1, -preced[x][y]);
            new_dest = change(x + 1, y, preced[x][y]); 
            s[x][y] = 'D';
            nxt[x][y] = mk(x + 1, y);
        }
        else {
            old_dest = change(x + 1, y, -preced[x][y]);
            new_dest = change(x, y + 1, preced[x][y]); 
            s[x][y] = 'R';
            nxt[x][y] = mk(x, y + 1);
        }
        ans += (new_dest - old_dest) * preced[x][y];
        cout << ans << '\n';
    }

    return 0;
}