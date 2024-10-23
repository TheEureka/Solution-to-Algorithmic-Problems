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
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
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


const int maxn = 605;
int dp[maxn][maxn];
int w[205], h[205];
int n, H, W;

int main() {
    IOS();
    cin >> W >> H;
    cin >> n;

    rep(i, n) cin >> w[i] >> h[i];
    rep(i, W) {
        rep(j, H) {
            rep(k, n) {
                if (i >= w[k] && j >= h[k]) {
                    chkmax(dp[i][j], max(dp[i - w[k]][j] + dp[w[k]][j - h[k]], dp[i][j - h[k]] + dp[i - w[k]][h[k]]) + w[k] * h[k]);
                }
            }
        }
    }

    cout << W * H - dp[W][H] << endl;

    return 0;
}
