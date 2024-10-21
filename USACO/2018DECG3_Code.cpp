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

const int maxn = 10005;
int maxx[maxn][20], s[maxn], dpmax[maxn], dp[1005];
int n, K;

void init() {
    rep(i, n) maxx[i][0] = s[i];
    rep(k, 14) {
        for (int i = 1; i + (1 << k) - 1 <= n; i++) {
            maxx[i][k] = max(maxx[i][k - 1], maxx[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int qry(int l, int r) {
    int len = (int)log2(r - l + 1);
    return max(maxx[l][len], maxx[r - (1 << len) + 1][len]);
}

int main() {
    IOS("teamwork");
    cin >> n >> K;
    rep(i, n) cin >> s[i];
    init();

    rep(i, n) {
        rep(j, K) dp[j] = 0; 
        for (int k = 1; k <= min(i, K); k++) {
            dp[k] = dpmax[i - k] + qry(i - k + 1, i) * k;
        }
        rep(k, min(i, K)) dpmax[i] = max(dpmax[i], dp[k]);

    }

    cout << dpmax[n] << endl;

    return 0;
}