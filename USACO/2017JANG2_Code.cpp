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

unordered_map<char, int> mp;

const int maxn = 1e5 + 5;
int dp1[maxn][3], dp2[maxn][3];
int beats[3] = {1, 2, 0};
int s[maxn][3];
int moves[maxn];
int max1[maxn][3][3], max2[maxn][3][3];

/*
Firstly, I need to figure out what dp[i][k][c] means.
Here, it means the maximum possible number of wins when Bessie has got to round i, and gives out a gesture of c, using at most k changes.

Next, I need to figure out how dp[i][k][c] gets updated.

The first clear thing is that dp[i][k][c] = dp[i - 1][k][c] + (a[i] == beats[c]). Then, we need to figure out when is the last time that Bessie 
has given out a gesture that is not c.
Suppose the last time Bessie did that was at position j (j >= 1), with gesture c' != c. Then, dp[i][k][c] shall be updated by the value 
dp[j][k - 1][c'] + (s[i][beats[c]] - s[j][beats[c]]) = (dp[j][k - 1][c'] - s[j][beats[c]]) + s[i][beats[c]].

We need to find the optimal value of j quickly. For that, we could let max2[c1][c2] represent the maximum value of dp[j][k - 1][c1] - s[j][c2] that has occurred so far over all j's,
given that k is fixed. 

Once we determine the value of dp[i][k][c] for each c at the current i and k, we can update the to-be-updated version of max2, max1, by going through c1 and c2 and performing max1[c1][c2] = max(max[c1][c2], dp[i][k][c1] - s[i][c2]).

*/

int main() {
    IOS("hps");
    mp['H'] = 0;
    mp['S'] = 1;
    mp['P'] = 2;
    // 0 beats 1, 1 beats 2, 2 beats 0
    // 0 gets 2 added, 1 gets 0 added, 2 gets 1 added.

    int n; cin >> n;
    int K; cin >> K;

    rep(i, n) {
        char c; cin >> c;
        moves[i] = mp[c];
        forn(j, 3) {
            if (j == mp[c]) {
                s[i][j] = s[i - 1][j] + 1;
            }
            else {
                s[i][j] = s[i - 1][j];
            }
        }
    }

    // Base case: k = 0
    rep(i, n) {
        forn(c, 3) {
            dp1[i][c] = dp1[i - 1][c] + (moves[i] == beats[c]);
        }
        forn(c1, 3) {
            forn(c2, 3) {
                max1[i][c1][c2] = max(max1[i - 1][c1][c2], dp1[i][c1] - s[i][c2]);
            }
        }
    }
    swap(max1, max2);

    rep(k, K) {
        rep(i, n) {
            forn(c, 3) {
                dp1[i][c] = dp1[i - 1][c] + (moves[i] == beats[c]);
                forn(cprime, 3) {
                    if (cprime != c) {
                        dp1[i][c] = max(dp1[i][c], max2[i - 1][cprime][beats[c]] + s[i][beats[c]]);
                    }
                }
            }
            forn(c1, 3) {
                forn(c2, 3) {
                    max1[i][c1][c2] = max(max1[i - 1][c1][c2], dp1[i][c1] - s[i][c2]);
                }
            }
        }
        swap(max1, max2);
    }

    int ans = 0;
    forn(c, 3) {
        ans = max(ans, dp1[n][c]);
    }
    cout << ans << endl;

    return 0;
}