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
const ll mod1 = 1e9 + 87;
const ll mod2 = 127397154761;
template<typename T> bool chkmin(T &a, T b){ return (b < a) ? a = b, 1 : 0; }
template<typename T> bool chkmax(T &a, T b){ return (b > a) ? a = b, 1 : 0; }
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
#define uid(lef, rig) uniform_int_distribution<int>(lef, rig)(rng)
#define ulld(lef, rig) uniform_int_distribution<ll>(lef, rig)(rng64)

void IOS(string name = "") {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    if ((int)name.size()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    IOS();
    ll N;
    int M;
    cin >> N >> M;
    vector<int> x(M);
    vector<pair<int, ll>> stones;
    ll ans = N * (N + 1) / 2;
    ll tot = 0ll;
    forn(i, M) {
        cin >> x[i];
    }
    forn(i, M) {
        ll a; cin >> a;
        tot += a;
        ans -= 1ll * a * x[i];
        stones.pb(mk(x[i], a));
    }
    sort(alls(stones));
    if (tot != N) {
        cout << -1 << '\n';
        return 0;
    }
    tot = 0ll;
    for (auto it = stones.rbegin(); it != stones.rend(); it++) {
        tot += it->second;

        if (tot > N - it->first + 1) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}