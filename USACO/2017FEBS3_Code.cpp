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

const int maxn = 101;
bool vis[maxn][maxn];
int ind[maxn][maxn], d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0}, occurrences[maxn][maxn];
map<pair<pii, pii>, bool> mp;
int N, K, R;

int main() {
    IOS("countcross");
    cin >> N >> K >> R;
    rep(ii, R) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        mp[mk(mk(a, b), mk(c, d))] = true;
        mp[mk(mk(c, d), mk(a, b))] = true;
    }
    vector<pii> cows(K);
    forn(i, K) cin >> cows[i].first >> cows[i].second;
    int cnt = 0;
    auto check = [&](int x, int y) -> bool {
        return x >= 1 && y >= 1 && x <= N && y <= N;
    };
    rep(i, N) {
        rep(j, N) {
            if (!vis[i][j]) {
                queue<pii> q;
                cnt++;
                q.push(mk(i, j));
                vis[i][j] = true;
                while (!q.empty()) {
                    pii t = q.front(); q.pop();
                    ind[t.first][t.second] = cnt;
                    occurrences[t.first][t.second]++;

                    forn(k, 4) {
                        int x = t.first + d[k][0];
                        int y = t.second + d[k][1];
                        if (check(x, y) && !vis[x][y] && !mp[mk(t, mk(x, y))]) {
                            vis[x][y] = true;
                            q.push(mk(x, y));
                        }
                    }
                }

            }
        }
    }
    ll ans = 0ll;
    map<int, ll> counting;
    forn(i, K) {
        counting[ind[cows[i].first][cows[i].second]]++;
    }
    ll sum = 0ll, sum_square = 0ll;
    for (auto [first, second]: counting) {
        sum += second;
        sum_square += second * second;
    }
    ans = (sum * sum - sum_square) / 2;
    cout << ans << endl;
    return 0;
}
