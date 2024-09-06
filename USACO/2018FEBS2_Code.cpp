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

const int maxn = 260;
int s[maxn], d[maxn], f[maxn], dp[maxn][maxn];
int N, B;

int dfs(int tile, int ind) {
    if (dp[tile][ind] != -1) return dp[tile][ind];
    if (tile == 1) {
        return true;
    }
    int ans = 0;
    for (int i = tile; i >= tile - d[ind] && i >= 1; i--) {
        if (f[i] <= s[ind]) {
            for (int j = ind - (i == tile); j >= 1; j--) {
                if (f[i] <= s[j]) {
                    ans = ans | dfs(i, j);
                }
            }
        }
    }
    return dp[tile][ind] = ans;
}

int main() {
    IOS("snowboots");
    cin >> N >> B;
    rep(i, N) cin >> f[i];
    rep(i, B) cin >> s[i] >> d[i];
    rep(num, B) {
        rep(i, N) {
            rep(j, B) {
                dp[i][j] = -1;
            }
        }
        int flag = dfs(N, num);
        if (flag) {
            cout << num - 1 << '\n';
            break;
        }
    }
    return 0;
}