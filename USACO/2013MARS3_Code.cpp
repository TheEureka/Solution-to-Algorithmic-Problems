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

// 0-indexed!!!
// 0-indexed!!!
// 0-indexed!!!

int main() {
    IOS("cruise");
    int n, m;
    ll k;
    cin >> n >> m >> k;
    k = k * (ll)m;
    unordered_map<char, int> g;
    g['L'] = 0;
    g['R'] = 1;
    vi f(2 * n);
    vector<char> ins(m);
    forn(i, n) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        f[2 * i] = l;
        f[2 * i + 1] = r;
    }
    forn(i, m) cin >> ins[i];
    int cur = 0, step = 0;
    map<pii, int> in_stack;
    in_stack[mk(0, 0)] = 0;


    int cycle_len = -1;

    while (1) {
        if (step == k) {
            cout << cur + 1 << "\n";
            return 0;
        }
        cur = f[2 * cur + g[ins[step % m]]];
        step++;
        if (in_stack.find(mk(cur, step % m)) != in_stack.end()) {
            cycle_len = step - in_stack[mk(cur, step % m)];
            break;
        }
        in_stack[mk(cur, step % m)] = step;
    }
    
    k -= step;
    k %= (ll)cycle_len;
    rep(ii, k) {
        cur = f[2 * cur + g[ins[step % m]]];
        step++;
    }
    cout << cur + 1 << endl;


    
    return 0;
}

// 0-indexed!!!
// 0-indexed!!!
// 0-indexed!!!