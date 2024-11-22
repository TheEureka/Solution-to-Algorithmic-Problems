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
#define endl '\n'
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
template<class T> istream& operator >> (istream& is, vector<T>& v) { int n; is >> n; v.resize(n); for (auto &i: v) is >> i; return is; }
template<class T1, class T2> istream& operator >> (istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }
template<class T> ostream& operator << (ostream& os, const vector<T>& v) { int f = 0; cout << "["; for (const auto &i: v) os << (f++ ? "," : "") << i; cout << "]"; return os; }
template<class T> ostream& operator << (ostream& os, const set<T>& v) { cout << "{"; auto it = v.begin(); while (it != v.end()) { os << *it; it++; if (it != v.end()) cout << ", "; } cout << "}"; return os; }
template<class T> ostream& operator << (ostream& os, const multiset<T>& v) { cout << "{"; auto it = v.begin(); while (it != v.end()) { os << *it; it++; if (it != v.end()) cout << ", "; } cout << "}"; return os; }
template<class T1, class T2> ostream& operator << (ostream& os, const map<T1, T2>& v) { cout << "{\n"; for (auto [x, y]: v) { os << "    " << x << ": " << y << ",\n"; } cout << "}"; return os; }
template<class T1, class T2> ostream& operator << (ostream& os, const pair<T1,T2>& p) { os << p.first << ' ' << p.second;  return os; }

void IOS(string name = "") {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    if ((int)name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

const int maxn = 5e6 + 5;
bool dp[maxn][2];
int t, a, b;

int main() {
    IOS("feast");
    cin >> t >> a >> b;
    dp[0][0] = dp[0][1] = true;
    rep(i, t) {
        if (i >= a) {
            dp[i][0] |= dp[i - a][0];
        }
        if (i >= b) {
            dp[i][0] |= dp[i - b][0];
        }
    }
    rep(i, t) {
        if (i >= a) {
            dp[i][1] |= dp[i - a][1];
        }
        if (i >= b) {
            dp[i][1] |= dp[i - b][1];
        }
        if (i * 2 <= t) {
            dp[i][1] |= dp[i * 2][0];
        }
        if (i * 2 + 1 <= t) {
            dp[i][1] |= dp[i * 2 + 1][0];
        }
    }
    dec(i, t, 0, 1) {
        if (dp[i][0] || dp[i][1]) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}