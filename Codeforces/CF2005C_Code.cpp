#include <bits/stdc++.h>
#include <unordered_map>
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

set<char> ss;
unordered_map<char, char> correspond;

void solve() {
    int n, m;
    cin >> n >> m;
    //All 0-based.
    vector<string> arr;
    vector< vector<int> > sum(n, vector<int>(m, 0));
    forn(i, n) {
        string x; cin >> x;
        arr.pb(x);
        if (ss.count(x[0])) sum[i][0] = 1;
        for (int j = 1; j < m; j++) {
            if (ss.count(x[j])) {
                sum[i][j] = sum[i][j - 1] + 1;
            }
            else {
                sum[i][j] = sum[i][j - 1];
            }
        }
    }
    int final_ans = 0;
    map<char, int> maxx; //Stores the minimum value of (ans + (end - pos)) for each character
    forn(i, n) {
        map<char, int>  mp, pos;
        map<char, int> MAXX = maxx;
        forn(j, m) {
            char s = arr[i][j];
            if (ss.count(s)) {
                char pref = correspond[s];
                //Attaching to the one in the same string
                if (mp.find(pref) != mp.end()) {
                    int cur_ans = mp[pref] + 1 - (j > 0 ? sum[i][j - 1] : 0);
                    if (s == 'k') {
                        final_ans = max(final_ans, cur_ans - (sum[i][m - 1] - sum[i][j]));
                    }
                    if (mp.find(s) == mp.end()) mp[s] = cur_ans + sum[i][j];
                    else mp[s] = max(mp[s], cur_ans + sum[i][j]);
                    if (MAXX.find(s) == MAXX.end()) MAXX[s] = cur_ans - (sum[i][m - 1] - sum[i][j]);
                    else MAXX[s] = max(MAXX[s], cur_ans - (sum[i][m - 1] - sum[i][j]));
                }

                //Attaching to the one in another previous string
                if (maxx.find(pref) != maxx.end()) {
                    int cur_ans = maxx[pref] + 1 - (j > 0 ? sum[i][j - 1] : 0);
                    if (s == 'k') {
                        final_ans = max(final_ans, cur_ans - (sum[i][m - 1] - sum[i][j]));
                    }
                    if (mp.find(s) == mp.end()) mp[s] = cur_ans + sum[i][j];
                    else mp[s] = max(mp[s], cur_ans + sum[i][j]);
                    if (MAXX.find(s) == MAXX.end()) MAXX[s] = cur_ans - (sum[i][m - 1] - sum[i][j]);
                    else MAXX[s] = max(MAXX[s], cur_ans - (sum[i][m - 1] - sum[i][j]));
                }
                if (s == 'n') {
                    if (mp.find(s) == mp.end()) mp[s] = 1 - (j > 0 ? sum[i][j - 1] : 0) + sum[i][j]; 
                    else mp[s] = max(mp[s], 1 - (j > 0 ? sum[i][j - 1] : 0) + sum[i][j]) ;
                    if (MAXX.find(s) == MAXX.end()) MAXX[s] = 1 - (j > 0 ? sum[i][j - 1] : 0) - (sum[i][m - 1] - sum[i][j]);
                    else MAXX[s] = max(MAXX[s], 1 - (j > 0 ? sum[i][j - 1] : 0) - (sum[i][m - 1] - sum[i][j]));
                }
            }
        }
        maxx = MAXX;
    }
    cout << final_ans << '\n';
}

int main() {
    IOS();
    ss.insert('n');
    ss.insert('a');
    ss.insert('r');
    ss.insert('e');
    ss.insert('k');
    correspond['n'] = 'k';
    correspond['a'] = 'n';
    correspond['r'] = 'a';
    correspond['e'] = 'r';
    correspond['k'] = 'e';
    int Eureka;
    cin >> Eureka;
    while (Eureka--) {
        solve();
    }
    return 0;
}