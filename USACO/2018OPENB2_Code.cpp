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

int main() {
    IOS("milkorder");
    int n, m, k;
    cin >> n >> m >> k;
    bool one_in = false;
    vi h(m);
    forn(i, m) {
        cin >> h[i];
        if (h[i] == 1) one_in = true;
    }
    vi pos(n + 1, -1), line(n + 1, -1);
    rep(_, k) {
        int x, y;
        cin >> x >> y;
        pos[x] = y;
        line[y] = x;
    }
    if (pos[1] != -1) {
        // If cow 1 requires a specific position itself:
        cout << pos[1] << endl;
        return 0;
    }
    if (one_in) {
        // If cow 1 is in the social hierarchy, then naturally we would want to fill the cows in the hierarchy before cow 1 at their respective earliest positions
        int first_free = 0;
        forn(i, m) {
            if (pos[h[i]] != -1) {
                first_free = pos[h[i]];
                continue;
            }
            first_free++;
            while (first_free <= n && line[first_free] != -1) first_free++;
            pos[h[i]] = first_free;
            line[first_free] = h[i];
            if (h[i] == 1) break;
        }
    }
    else {
        /* 
        If cow 1 is not in the hierarchy, then the cows in the hierarchy should be put as back in the line as possible, so that cow 1 can have the earliest 
        possible position.
        */
        int last_free = n + 1;
        dec(i, m - 1, 0, 1) {
            if (pos[h[i]] != -1) {
                last_free = pos[h[i]];
                continue;
            }
            last_free--;
            while (last_free > 0 && line[last_free] != -1) last_free--;
            pos[h[i]] = last_free;
            line[last_free] = h[i];
        }
        rep(i, n) 
            if (line[i] == -1) {
                pos[1] = i;
                break;
            }
        
    }
    cout << pos[1] << endl;
    return 0;
}