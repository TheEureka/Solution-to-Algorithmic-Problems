#include <bits/stdc++.h>
#ifdef LOCAL
#include "debugging.h"
#endif
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
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
#define ppc __builtin_popcount
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
template<class T1, class T2> istream& operator >> (istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }

void IOS(string name = "") {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    if ((int)name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

// The algorithm below has a running time of O(32n). It should be able to pass test data as large as an order of magnitude of 10 ^ 6.

int main() {
    IOS("swap");
    int n, k;
    cin >> n >> k;
    int A1, A2, B1, B2;
    cin >> A1 >> A2 >> B1 >> B2;
    vi g(n + 1), h(n + 1);
    vector<vi> f(32, vi(n + 1)); // f[k][i] denotes the position that cow i is at after 2 ^ k processes.
    rep(i, n) {
        if (A1 <= i && i <= A2) g[i] = A1 + A2 - i;
        else g[i] = i;
        if (B1 <= i && i <= B2) h[i] = B1 + B2 - i;
        else h[i] = i;
    }
    rep(i, n) f[0][i] = h[g[i]];
    rep(i, 31) { // binary jumping (if this is its name)
        rep(j, n) {
            f[i][j] = f[i - 1][f[i - 1][j]];
        }
    }
    vi ans(n + 1);
    iota(alls(ans), 0);
    dec(i, 31, 0, 1) {
        if ((k >> i) & 1) {
            rep(j, n) {
                ans[j] = f[i][ans[j]];
            }
        }
    }
    vi f_ans(n + 1);
    rep(i, n) f_ans[ans[i]] = i;
    rep(i, n) cout << f_ans[i] << endl;

    return 0;
}