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

int main() {
    IOS();
    int n, c;
    cin >> n >> c;
    vi cnt((int)(5e5 + 5), 0), cnt_c_front(n + 1), cnt_c_back(n + 2), first_occ((int)(5e5 + 5), -1), last_occ((int)(5e5 + 5), -1);
    cnt_c_front[0] = 0;
    vi a(n + 1);
    rep(i, n) {
        cin >> a[i];
        if (first_occ[a[i]] == -1) {
            first_occ[a[i]] = i;
        }
        cnt_c_front[i] = cnt_c_front[i - 1] + (a[i] == c);
        cnt[a[i]]++;
    }
    cnt_c_back[n + 1] = 0;
    dec(i, n, 1, 1) {
        if (last_occ[a[i]] == -1) {
            last_occ[a[i]] = i;
        }
        cnt_c_back[i] = cnt_c_back[i + 1] + (a[i] == c);
    }
    int ans = 0;
    vi maxx((int)(5e5 + 5), -1), ord((int)(5e5 + 5), 0);

    rep(i, n) {
        ord[a[i]]++;
        if (maxx[a[i]] == -1) {
            ans = max(ans, 1 + cnt_c_front[i - 1] + cnt_c_back[i + 1]);
        }
        else {
            ans = max(ans, ord[a[i]] + maxx[a[i]] + cnt_c_back[i + 1]);
        }
        maxx[a[i]] = max(maxx[a[i]], -ord[a[i]] + 1 + cnt_c_front[i - 1]);
    }

    cout << ans << endl;

    return 0;
}