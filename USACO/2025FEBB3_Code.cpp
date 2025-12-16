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

vi factors[101];


bool dfs(vi& a, int l, int r, int prints) {
    // dbg(l);
    // dbg(r);
    // dbg(prints);
    // cout << "--------------\n";
    bool ans = false;
    if (prints == 1) {
        inc(i, l + 1, r, 1) {
            if (a[i] != a[l]) {
                return false;
            }
        }
        return true;
    }
    for (int len: factors[r - l + 1]) {
        bool flag = true;
        inc(i, l + len, r, len) {
            forn(j, len) {
                if (a[i + j - len] != a[i + j]) {
                    flag = false;
                    goto outer;
                }
            }
        }
        outer: ;
        if (flag) ans = (ans || dfs(a, l, l + len - 1, prints));
    }
    if (!ans) {
        // Now the sequence from l to r must contain no outer REP n, where n > 1
        if (prints == 3) {
            // 2 + 1
            inc(i, l + 1, r - 1, 1) {
                ans = (ans || (dfs(a, l, i, 2) && dfs(a, i + 1, r, 1)));
            }
            // 1 + 2
            inc(i, l, r - 2, 1) {
                ans = (ans || (dfs(a, l, i, 1) && dfs(a, i + 1, r, 2)));
            }
            ans = (ans || dfs(a, l, r, 2)); // Note that we don't need EXACTLY k print statements; AT MOST is enough.
            ans = (ans || dfs(a, l, r, 1));
        }
        if (prints >= 2) {
            inc(i, l, r - 1, 1) {
                ans = (ans || (dfs(a, l, i, 1) && dfs(a, i + 1, r, 1)));
            }
            ans = (ans || dfs(a, l, r, 1));
        }
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    rep(i, n) cin >> a[i];
    cout << (dfs(a, 1, n, k) ? "YES\n" : "NO\n");
    return;
}

int main() {
    IOS();
    rep(i, 100) {
        inc(j, 2, i - 1, 1) {
            if (i % j == 0) {
                factors[i].pb(j);
            }
        }
    }
    int Eureka;
    cin >> Eureka;
    while (Eureka--) {
        solve();
    }
    return 0;
}