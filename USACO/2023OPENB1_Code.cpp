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
    if (n == 1) {
        // One special case -- discovered via stress-testing.
        cout << 1 << endl;
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    forn(i, n - 1)
        if (s[i] != 'F' && s[i] == s[i + 1])
            ans++;
    vector<pii> fsegs;
    for (int i = 0; i < n;) {
        if (s[i] != 'F') {
            i++;
            continue;
        }
        int start = i;
        while (start < n && s[start] == 'F') start++;
        fsegs.pb({i, start - 1});
        i = start;
    }
    int r1 = 0, l2 = 0, r2 = 0; // [0, r1] is used for the edge cases, while [l2, r2] is used for the "in-between" cases.
    for (auto [l, r]: fsegs) {
        if (l == 0 && r == n - 1) {
            // Another special case -- discovered through stress-testing.
            cout << r - l + 1 << endl;
            forn(i, r - l + 1) {
                cout << i << endl;
            }
            return 0;
        }
        else if (l == 0 || r == n - 1) {
            r1 += (r - l + 1);
        }
        else {
            int len = r - l + 1;
            if (s[l - 1] == s[r + 1]) {
                if (len % 2 == 1) r2 += (len + 1);
                else l2++, r2 += (len + 1);
            }
            else {
                if (len % 2 == 1) l2++, r2 += len;
                else r2 += len;
            }
        }
    }
    if (r1 == 0) {
        cout << (r2 - l2) / 2 + 1 << endl;
        inc(i, ans + l2, ans + r2, 2) {
            cout << i << endl;
        }
    }
    else {
        int l = l2, r = r1 + r2;
        cout << r - l + 1 << endl;
        inc(i, ans + l, ans + r, 1) {
            cout << i << endl;
        }
    }
    return 0;
}