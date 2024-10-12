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

map<int, set<int> > mpx, mpy;
map<pii, ll> dis;

struct node {
    pii cord;

    int dir;
};

int n;
int startx, starty, endx, endy;
deque<node> q;

void update(int new_dir, int x, int y, int w) {
    auto it = mpx[endx].begin();
    if (new_dir == 0) {
        it = mpx[x].upper_bound(y);
        if (it != mpx[x].end()) {
            if (dis[mk(x, *it)] > dis[mk(x, y)] + w) {
                dis[mk(x, *it)] = dis[mk(x, y)] + w;
                if (w == 1) {
                    q.pb((node){mk(x, *it), 0});
                }
                else {
                    q.push_front((node){mk(x, *it), 0});
                }
            }
        }
    }
    else if (new_dir == 1) {
        it = mpy[y].upper_bound(x);
        if (it != mpy[y].end()) {
            if (dis[mk(*it, y)] > dis[mk(x, y)] + w) {
                dis[mk(*it, y)] = dis[mk(x, y)] + w;
                if (w == 1) q.pb((node){mk(*it, y), 1});
                else q.push_front((node){mk(*it, y), 1});
            }
        }
    }
    else if (new_dir == 2) {
        it = mpx[x].lower_bound(y);
        if (it != mpx[x].begin()) {
            it--;
            if (dis[mk(x, *it)] > dis[mk(x, y)] + w) {
                dis[mk(x, *it)] = dis[mk(x, y)] + w;
                if (w == 1) q.pb((node){mk(x, *it), 2});
                else q.push_front((node){mk(x, *it), 2});
            }
        }
    }
    else {
        it = mpy[y].lower_bound(x);
        if (it != mpy[y].begin()) {
            it--;
            if (dis[mk(*it, y)] > dis[mk(x, y)] + w) {
                dis[mk(*it, y)] = dis[mk(x, y)] + w;
                if (w == 1) q.pb((node){mk(*it, y), 3});
                else q.push_front((node){mk(*it, y), 3});
            }
        }
    }
}

bool flag = false;


void bfs(pii start) {
    q.pb((node){start, 0});
    q.pb((node){start, 1});
    q.pb((node){start, 2});
    q.pb((node){start, 3});

    dis[start] = 0;


    while (!q.empty()) {
        node u = q.front(); q.pop_front();
        int x = u.cord.first, y = u.cord.second, dir = u.dir;
        if (x == endx && y == endy) {
            flag = true;
            cout << dis[mk(x, y)] << endl;
            return;
        }

        int new_dir;

        new_dir = (dir + 1) % 4;
        update(new_dir, x, y, 1);


        new_dir = ((dir - 1) % 4 + 4) % 4;
        update(new_dir, x, y, 1);

        new_dir = dir;
        update(new_dir, x, y, 0);

    }

}


int main() {
    IOS("lasers");
    cin >> n;
    cin >> startx >> starty >> endx >> endy;
    mpx[startx].insert(starty);
    mpy[starty].insert(startx);
    mpx[endx].insert(endy);
    mpy[endy].insert(endx);
    dis[mk(endx, endy)] = inf;
    
    rep(ii, n) {
        int x, y;
        cin >> x >> y;
        mpx[x].insert(y);
        mpy[y].insert(x);
        dis[mk(x, y)] = inf;
    }

    bfs(mk(startx, starty));
    if (!flag) cout << -1 << endl;
    return 0;
}
