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

/*
Lemmas:
1.
2.
3.
*/

// Program:


void solve() {
    int n;
    cin >> n;
    vi a(n);
    cin >> a[0];
    int GCD = a[0];
    rep(i, n - 1) {
        cin >> a[i];
        GCD = gcd(GCD, a[i]);
    }
    forn(i, n) {
        a[i] /= GCD;
    }
    ll ans = 0;
    int minn = 0;
    forn(i, n) {
        if (a[i] < a[minn]) {
            minn = i;
        }
    }
    swap(a[0], a[minn]);
    int cur_GCD = a[0];
    ans += a[0];
    rep(i, n - 1) {
        int minn = 2e9, ind = -1;
        inc(j, i, n - 1, 1) {
            if (gcd(a[j], cur_GCD) < minn) {
                minn = gcd(a[j], cur_GCD);
                ind = j;
            }
        }
        cur_GCD = minn;
        ans += cur_GCD;
        swap(a[i], a[ind]);
        if (cur_GCD == 1) {
            ans += (n - 1) - i;
            break;
        }
    }
    ans = ans * (ll)GCD;
    cout << ans << '\n';

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