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
    int n;
    cin >> n;
    vi a(n + 1);
    rep(i, n) cin >> a[i], a[i] += i;
    unordered_map<int, int> mp;
    set<int> ans;

    auto find_root = [&](int x, auto& find_root) -> int {
        if (!mp.count(x)) return x;
        return mp[x] = find_root(mp[x], find_root);
    }; // Similar to the find_root() function in DSU. Used to cut down time complexity.

    rep(i, n) {
        if (mp.count(a[i])) {
            int node = find_root(a[i], find_root);
            ans.insert(node);
            int cur = node;
            if (mp.count(cur - 1)) mp[cur] = mp[cur - 1];
            else mp[cur] = cur - 1;
        }
        else {
            ans.insert(a[i]);
            int cur = a[i];
            if (mp.count(cur - 1)) mp[a[i]] = mp[cur - 1];
            else mp[a[i]] = cur - 1;
        }
    }

    for (auto it = ans.rbegin(); it != ans.rend(); it++) {
        cout << *it << " ";
    }
    cout << "\n";
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