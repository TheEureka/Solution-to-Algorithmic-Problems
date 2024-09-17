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
const ld eps = 1e-12;
const ll inf = 1e16;
const ll mod = 998244353;
const ll mod1 = 1e9 + 87;
const ll mod2 = 127397154761;
ll qpow(ll a, ll b) {if (b == 0) return 1; ll ans = qpow(a, b >> 1); ans = ans * ans % mod; if (b & 1) ans = ans * a % mod; return ans;}
using namespace std;

void IOS(string name = "") {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    if ((int)name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    int x; cin >> x;
    int g = x;
    rep(i, n - 1) {
        int y; cin >> y;
        g = gcd(g, y);
    }
    if (n == 1) {
        if (k <= g) cout << k - 1 << '\n';
        else cout << k << '\n';
        return;
    }
    forn(i, n) {
        if (k < g) {
            cout << i * g + k << "\n";
            return;
        }
        k -= (g - 1);
    }
    cout << n * g + k - 1 << "\n";
}

int main() {
    IOS();
    int Eureka;
    cin >> Eureka;
    while (Eureka--) {
        solve();
    }
    return 0;
}