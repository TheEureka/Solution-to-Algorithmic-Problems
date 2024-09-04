#include <bits/stdc++.h>
#include <unordered_set>
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

char s[110][11];
int vis[110][11];
int ind = 0;
int n, k, d[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

int bfs(int startx, int starty) {
    ind++;
    queue<pii> q;
    q.push(mk(startx, starty));
    vis[startx][starty] = ind;
    int ans = 1;
    while (!q.empty()) {
        pii t = q.front(); q.pop();

        forn(k, 4) {
            int x = t.first + d[k][0];
            int y = t.second + d[k][1];
            if (x >= 1 && y >= 1 && x <= n && y <= 10) {
                if (!vis[x][y] && s[x][y] == s[t.first][t.second]) {
                    q.push(mk(x, y));
                    ans++;
                    vis[x][y] = ind;
                }
            }
        }
    }
    return ans;
}


int main() {
    IOS("mooyomooyo");
    cin >> n >> k;
    dec(i, n, 1, 1) {
        rep(j, 10) {
            cin >> s[i][j];
        }
    }
    while (1) {
        bool flag = false;
        rep(i, n) {
            rep(j, 10) {
                vis[i][j] = 0;
            }
        }
        unordered_set<int> S;
        ind = 0;
        rep(i, n) {
            rep(j, 10) {
                if (!vis[i][j] && s[i][j] != '0') {
                    int sizee = bfs(i, j);
                    if (sizee >= k) {
                        flag = true;
                        S.insert(ind);
                    }
                }
            }
        }
        if (!flag) break;
        rep(column, 10) {
            queue<char> st;
            rep(i, n) {
                if (s[i][column] == '0') break;
                if (S.count(vis[i][column]) > 0) {
                    s[i][column] = '0';
                    continue;
                }
                st.push(s[i][column]);
                s[i][column] = '0';
            }
            int pointer = 1;
            while (!st.empty()) {
                char t = st.front(); st.pop();
                s[pointer][column] = t;
                pointer++;
            }
        }
    }
    dec(i, n, 1, 1) {
        rep(j, 10) {
            cout << s[i][j];
        }
        cout << '\n';
    }
    return 0;
}
