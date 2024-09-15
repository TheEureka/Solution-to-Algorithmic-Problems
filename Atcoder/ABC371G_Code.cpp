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

const int maxn = 2e5 + 5
int A[maxn], P[maxn], ans[maxn], rem[maxn];
vi divs[maxn];
bool vis[maxn];
int n;

int main() {
    IOS();
    cin >> n;
    rep(i, n) cin >> P[i];
    rep(i, n) cin >> A[i], rem[i] = -1;
    rep(i, n) for (int j = i; j <= n; j += i) divs[j].pb(i);
    rep(i, n) {
        if (!vis[i]) {
            vi cyc;
            for (int u = i; !vis[u]; u = P[u]) {
                cyc.pb(u);
                vis[u] = true;
            }
            int steps = -1;
            forn(s, sz(cyc)) {
                bool flag = true;
                for (int d: divs[sz(cyc)]) {
                    if (rem[d] != -1 && s % d != rem[d]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    if (steps == -1 || A[cyc[s]] < A[cyc[steps]]) {
                        steps = s;
                    }
                }
            }
            forn(i, sz(cyc)) ans[cyc[i]] = A[cyc[(i + steps) % sz(cyc)]];
            for (int d: divs[sz(cyc)]) {
                rem[d] = steps % d;
            }
        }
    }
    rep(i, n) cout << ans[i] << " \n"[i == n];
    return 0;
}