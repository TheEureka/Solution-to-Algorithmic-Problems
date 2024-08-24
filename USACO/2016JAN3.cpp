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

map<pair<pii, pii> , bool> vis_segment;
map<pii, bool> vis_point, is_vertex;
map<pii, int> degree;


int main() {
    IOS("gates");
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, y = 0, rx = 0, ry = 0;
    int V = 0, E = 0;
    forn(i, n) {
        vis_point[mk(x, y)] = true;
        int xx, yy;
        if (s[i] == 'N') {
            xx = x, yy = y + 1;
        }
        else if (s[i] == 'S') {
            xx = x, yy = y - 1;
        }
        else if (s[i] == 'E') {
            xx = x + 1, yy = y;
        }
        else {
            xx = x - 1, yy = y;
        }
        degree[mk(xx, yy)]++;
        degree[mk(x, y)]++;
        x = xx, y = yy;
    }
    for (auto [first, second]: degree) {
        if (second != 2) V++, is_vertex[first] = true;
        //cout << "(" << first.first << ", " << first.second << "): " << second << endl;
    }
    x = 0, y = 0;
    rx = 0, ry = 0;
    forn(i, n) {
        int xx, yy;
        if (s[i] == 'N') {
            xx = x, yy = y + 1;
        }
        else if (s[i] == 'S') {
            xx = x, yy = y - 1;
        }
        else if (s[i] == 'E') {
            xx = x + 1, yy = y;
        }
        else {
            xx = x - 1, yy = y;
        }
        //cout << "xx: " << xx << " yy: " << yy << " " << is_vertex[mk(xx, yy)] << endl;
        if (is_vertex[mk(xx, yy)] && !vis_segment[mk(mk(x, y), mk(xx, yy))]) {
            E++;
            //dbg(E);
        }
        vis_segment[mk(mk(xx, yy), mk(x, y))] = true;
        vis_segment[mk(mk(x, y), mk(xx, yy))] = true;
        x = xx, y = yy;
    }
    //dbg(V);
    //dbg(E);
    cout << E + 2 - V - 1 << '\n';
    return 0;
}