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

const int maxn = 3003;
short deg[maxn][maxn];
bool occupied[maxn][maxn];
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};


int main() {
    IOS();
    int N;
    cin >> N;
    int last_ans = 0;
    while (N--) {
        int x, y;
        cin >> x >> y;
        x += 1000;
        y += 1000;
        queue<pii> q;
        if (deg[x][y] == 3) q.push(mk(x, y));
        if (!occupied[x][y]) {
            forn(k, 4) {
                int xx = x + d[k][0], yy = y + d[k][1];
                if (xx >= 0 && yy >= 0 && xx <= 3000 && yy <= 3000) {
                    deg[xx][yy]++;
                    if (occupied[xx][yy] && deg[xx][yy] == 3) {
                        q.push(mk(xx, yy));
                    }
                }
            }
        }
        if (occupied[x][y]) {
            cout << last_ans - 1 << '\n';
            last_ans--;
            continue;
        }
        occupied[x][y] = true;
        int ans = 0;
        while (!q.empty()) {
            pii t = q.front(); q.pop();
            if (deg[t.first][t.second] != 3) {
                continue;
            }
            ans++;
            forn(k, 4) {
                int xx = t.first + d[k][0], yy = t.second + d[k][1];
                if (xx >= 0 && yy >= 0 && xx <= 3000 && yy <= 3000) {
                    if (!occupied[xx][yy]) {
                        forn(kk, 4) {
                            int xxx = xx + d[kk][0], yyy = yy + d[kk][1];
                            if (xxx >= 0 && yyy >= 0 && xxx <= 3000 && yyy <= 3000) {
                                deg[xxx][yyy]++;
                                if (occupied[xxx][yyy] && deg[xxx][yyy] == 3) {
                                    q.push(mk(xxx, yyy));
                                }
                            }
                        }
                    }
                    occupied[xx][yy] = true;
                    if (deg[xx][yy] == 3) {
                        q.push(mk(xx, yy));
                    }
                }
            }
        }
        cout << last_ans + ans << '\n';
        last_ans += ans;
    }
    return 0;
}