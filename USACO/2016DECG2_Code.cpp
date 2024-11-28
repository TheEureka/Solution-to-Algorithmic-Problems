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

const int maxn = 1e3 + 3;
int H, G;
int dp[maxn][maxn]; // dp[i][j] denotes the minimum answer if we end at the ith Holstein such that the sequence of paths followed contains j Guernseys.

/*
    Base cases:
    * dp[1][0] = 0; dp[1][i] = inf; (i > 0).

    Transitions
    * chkmin(dp[i][j], dp[i - 1][k] + dis(h[i - 1], g[k + 1]) + dis(g[k + 1], g[k + 2]) + ... + dis(g[j - 1], g[j]) + dis(g[j], h[i])) (k <= j)
*/

int main() {
    IOS("checklist");
    cin >> H >> G;
    vector<pii> h(H + 1), g(G + 1);
    vector<int> sg(G + 1); // sg[i] represents dis(1, 2) + ... + dis(i - 1, i)
    rep(i, H) {
        int x, y;
        cin >> x >> y;
        h[i] = mk(x, y);
    }
    rep(i, G) {
        int x, y;
        cin >> x >> y;
        g[i] = mk(x, y);
        if (i == 1) {
            sg[i] = 0;
        }
        else {
            int xx = g[i - 1].first, yy = g[i - 1].second;
            sg[i] = sg[i - 1] + (xx - x) * (xx - x) + (yy - y) * (yy - y);
        }
    }

    auto dis = [](pii A, pii B) -> int {
        int x1, y1, x2, y2;
        tie(x1, y1) = A;
        tie(x2, y2) = B;
        return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    };

    vector<vector<ll>> dp(H + 1, vector<ll>(G + 1, INT_MAX));
    vector<ll> minn(G + 1, INT_MAX);
    dp[1][0] = 0;
    minn[0] = dis(h[1], g[1]);
    rep(k, G) {
        minn[k] = min(minn[k - 1], dp[1][k] - sg[k + 1] + dis(h[1], g[k + 1]));
    }
    inc(i, 2, H, 1) {
        vector<ll> tmp_minn(G + 1, INT_MAX);
        forn(j, G + 1) {
            chkmin(dp[i][j], dp[i - 1][j] + dis(h[i], h[i - 1]));
            if (j > 0) chkmin(dp[i][j], dis(h[i], g[j]) + sg[j] + minn[j - 1]);
            if (j == 0) tmp_minn[j] = dp[i][j] - sg[j + 1] + dis(h[i], g[j + 1]);
            else tmp_minn[j] = min(tmp_minn[j - 1], dp[i][j] - sg[j + 1] + dis(h[i], g[j + 1]));
        }
        minn = tmp_minn;
    }
    cout << dp[H][G] << endl;
    return 0;
}