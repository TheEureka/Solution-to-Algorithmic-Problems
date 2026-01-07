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

// Solution: https://www.luogu.com.cn/article/doyr4ecl

int main() {
    IOS();
    int n; cin >> n;
    vector<vi> a(n, vi(n));
    forn(i, n) {
        forn(j, n) {
            cin >> a[i][j];
        }
    }
    int ans = 0;

    {
        // Rows
        int maxx = 0;
        forn(i, n) {
            int tot_o = 0, tot_e = 0;
            inc(j, 0, n - 1, 2) {
                tot_e += a[i][j];
            }
            inc(j, 1, n - 1, 2) {
                tot_o += a[i][j];
            }
            maxx += max(tot_o, tot_e);
        }
        chkmax(ans, maxx);
    }

    {
        // Columns
        int maxx = 0;
        forn(i, n) {
            int tot_o = 0, tot_e = 0;
            inc(j, 0, n - 1, 2) {
                tot_e += a[j][i];
            }
            inc(j, 1, n - 1, 2) {
                tot_o += a[j][i];
            }
            maxx += max(tot_o, tot_e);
        }
        chkmax(ans, maxx);
    }

    cout << ans << endl;
    return 0;
}