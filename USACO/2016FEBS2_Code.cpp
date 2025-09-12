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

int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

bool cmp(pii x, pii y) {
    if (x.second != y.second) return x.second < y.second;
    return x.first < y.first;
}

int main() {
    IOS("balancing");
    int n; cin >> n;
    vector<pii> cows(n);
    int ans = n;
    forn(i, n) {
        cin >> cows[i];
    }
    sort(alls(cows), cmp);

    forn(i, n) {
        for (int x: {cows[i].first - 1, cows[i].first + 1}) {
            vi s(n + 1, 0), eq(n + 1, 0);
            forn(j, n) {
                if (cows[j].first < x) s[j + 1] = s[j];
                else s[j + 1] = s[j] + 1;
                if (j > 0 && cows[j].first == cows[j - 1].first) {
                    eq[j] = eq[j - 1] + 1;
                }
            }
            int lst = -1;
            forn(j, n) {
                if (j != n - 1 && cows[j].second == cows[j + 1].second) continue;
                chkmin(ans, max({s[n] - s[lst + 1], (n - 1 - lst) - (s[n] - s[lst + 1]), (lst + 1) - s[lst + 1], s[lst + 1]}));
                chkmin(ans, max({s[n] - s[j + 1], (n - 1 - j) - (s[n] - s[j + 1]), (j + 1) - s[j + 1], s[j + 1]}));
                lst = j;
            }
        }
   }
    cout << ans << endl;
    return 0;
}