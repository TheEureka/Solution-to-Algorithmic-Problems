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

const int maxn = 255;

int N;
ll W, w[maxn], t[maxn];

bool check(ld k) {
    vector<ld> dp(W + 1, -inf);
    dp[0] = 0.00;
    rep(i, N) {
        dec(j, W, 0, 1) {
            int x = min(W, j + w[i]);
            ld val = t[i] - k * w[i];
            chkmax(dp[x], dp[j] + val);
        }
    }
    return (dp[W] >= 0.00);
}

int main() {
    IOS("talent");
    cin >> N >> W;
    rep(i, N) {
        cin >> w[i] >> t[i];
    }
    ld low = 1.00 / 250000.0, high = 250000000.0;
    while (high - low > eps) {
        ld mid = (low + high) / 2;
        if (check(mid)) {
            low = mid;
        }
        else {
            high = mid;
        }
    }
    cout << (ll)(low * 1000) << endl;
    return 0;
}