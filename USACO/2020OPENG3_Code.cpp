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

/*
A k-step path is possible if and only if the sum of all seperate prime powers in the prime factorization of k is less than or equal to n.
*/

const int maxn = 1e4 + 4;
bool isprime[maxn];
int primes[maxn];
int cnt = 0;

void euler(int n) {
    memset(isprime, true, sizeof(isprime));
    isprime[1] = false;
    for (int i = 1; i <= n; i++) {
        if(isprime[i]) {
            primes[++cnt] = i;
        }   
        for (int j = 1; j <= cnt && i * primes[j] <= n; j++) {
            isprime[i * primes[j]] = false;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

/*
* Suppose that dp[i][j] denotes the answer for the first i primes, such that the sum of the powers is less than or equal to j.

Transitions:
    ? dp[i][j] = (sum (dp[i - 1][j - p ^ k] * p ^ k) over 1 <= k <= log_p(j)) + dp[i - 1][j].

Base cases:
    ? dp[0][j] = 1 for all j.
*/


ll n, m;
ll dp[maxn];

int main() {
    IOS();
    cin >> n >> m;
    euler(n);
    forn(i, n + 1) dp[i] = 1;

    for (int i = 1; i <= cnt; i++) {
        dec(j, n, 1, 1) {
            ll p = primes[i];
            ll add = 0ll;
            while (p <= j) {
                add += (dp[j - p] * p) % m;
                add %= m;
                p *= primes[i];
            }
            dp[j] = add + dp[j];
            dp[j] %= m;
        }
    }

    cout << dp[n] << endl;
    return 0;
}