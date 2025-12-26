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
    IOS();
    int n; cin >> n;
    string s; cin >> s;
    int ans = 0;
    vi a;
    inc(i, 0, n - 1, 2) {
        if (s[i] == 'G' && s[i + 1] == 'H') a.pb(-1);
        else if (s[i] == 'H' && s[i + 1] == 'G') a.pb(1);
        else a.pb(0);
    }

    /*
    Explanation for the encoding above:
    - firstly, note that the "contribution" of a (2i, 2i + 1) pair never changes if the pair is "GG" or "HH", and flips between -1 and 1 if otherwise.
    - it can be shown that we're able to flip all the *original* (-1)'s into 1's through some series of operations
    - after encoding, note that a segment without 1 can be flipped together, but if two such segments are separated by a 1, they cannot be flipped together. in this latter case, at least 2 more operations are required to flip both
    - following the last idea, we have the following code:
    */

    bool first = true;
    for (int i = 0; i < sz(a);) {
        if (a[i] == 1 || a[i] == 0) {
            if (a[i] == 1 && first) first = false;
            i++;
            continue;
        }
        int start = i;
        while (start < sz(a) && a[start] != 1) start++;
        if (first) {
            ans++;
            first = false;
        }
        else {
            ans += 2;
        }
        i = start;
    }
    cout << ans << endl;
    return 0;
}

/*
14
GGGHGHHGHHHGHG
*/