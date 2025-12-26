#include <bits/stdc++.h>
#ifdef LOCAL
#include "debugging.h"
#endif
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
#define dbg(v) cerr << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl;
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define endl '\n'
#define ppc __builtin_popcount
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
template<class T1, class T2> istream& operator >> (istream& is, pair<T1,T2>& p) { is >> p.first >> p.second; return is; }

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
    IOS("race");
    ll K; int N;
    cin >> K >> N;
    while (N--) {
        ll X; cin >> X;
        // In the code below, m denotes the maximum speed reached by Bessie.
        {
            ll l = X + 1, r = K;
            while (l <= r) {
                ll mid = (l + r) / 2;
                ll sum1 = mid * (mid + 1) / 2 + (mid + X) * (mid - X - 1) / 2;
                if (sum1 < K) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            l--;
            // dbg(l);
            if (l > X) {
                ll mid = l;
                ll sum1 = mid * (mid + 1) / 2 + (mid + X) * (mid - X - 1) / 2;
                if (sum1 + X >= K) cout << mid + (mid - X) << endl;
                else cout << (K - sum1 - X + (mid - 1)) / mid + mid + (mid - X) << endl;
                continue;
            }
        }
        {
            ll sum = X * (X - 1) / 2;
            if (sum < K) {
                cout << (K - sum + (X - 1)) / X + (X - 1) << endl;
                continue;
            }
        }
        {
            ll l = 1, r = X - 1;
            while (l <= r) {
                ll mid = (l + r) / 2;
                ll sum = mid * (mid - 1) / 2;
                if (sum < K) l = mid + 1;
                else r = mid - 1;
            }
            l--;
            ll sum = l * (l - 1) / 2;
            cout << (K - sum + (l - 1)) / l + (l - 1) << endl;
        }
    }
    return 0;
}