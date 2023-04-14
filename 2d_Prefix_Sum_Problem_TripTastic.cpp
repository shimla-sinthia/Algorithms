//https://www.codechef.com/problems/TRPTSTIC

// Bismillah Hir Rehmanir Rahim
// Allah knows best
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define gap ' '
#define mini -10000000000000000
#define endl '\n'
#define f(i, a, n) for (int i = a; i < n; i++)
#define int long long
#define ll long long
#define pi 3.141592653589793
#define vi vector<int>
#define si set<int>
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rr return 0
#define ff first
#define in insert
#define ss second
int hash58 = 288230376151711717;
int hash32 = 1610612741;
#define erase_unique(st) st.erase(unique(st.begin(), st.end()), st.end())
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
#define setbits(x) __builtin_popcountll(x)
#define zrbits(x) __builtin_ctzll(x)
#define unset_bit(x, inx) x = (x & ~(1ll << (inx)))
#define set_bit(x, idx) x = x | 1LL << idx
#define check_bit(x, idx) min(x & (1LL << idx), 1LL)
#define toggle_bit(x, idx) x = x ^ (1LL << idx)
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int>>
#define maxheap2 priority_queue<pair<int, int>>
#define minheap2                                           \
    priority_queue<pair<int, int>, vector<pair<int, int>>, \
                   greater<pair<int, int>>>
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x, y) uniform_int_distribution<int>(x, y)(rng)
inline int uceil(int a, int b) { return (a % b ? a / b + 1 : a / b); }
#define ordered_set                              \
    tree<int, null_type, less<int>, rb_tree_tag, \
         tree_order_statistics_node_update>
#ifdef DEBUG
#include "tpc.hpp"
#define ios
#define dbg(...)                                                   \
    {                                                              \
        cerr << __LINE__ << " : ";                                 \
        cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__); \
    }
#define ok tikkk
#else
#define ios                               \
    {                                     \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
    }
#define dbg(...)
#define ok
#endif
#define ld long double
#pragma GCC target("popcnt")
const int dx[8] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

void solve(int ct) {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n + 5, vector<ll>(m + 5));
    k++;
    f(i, 1, n + 1) f(j, 1, m + 1) cin >> a[i][j];
    vector<vector<ll>> pre(n + 5, vector<ll>(m + 5));
    pre[0][0] = a[0][0];

    for (int i = 1; i <= n; i++) pre[i][1] += (pre[i - 1][1] + a[i][1]);
    for (int i = 2; i <= m; i++) pre[1][i] += (pre[1][i - 1] + a[1][i]);
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            pre[i][j] +=
                (pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j]);
        }
    }
    // dbg(pre);
    ll ans = 1e18, mid, l = 0, h = max(n , m);
    while (l <= h) {
        mid = (l + h) / 2;
        ll ase = 0;
        f(i, 1, n + 1) {
            f(j, 1, m + 1) {
                if(a[i][j] == 0) continue;
                ll x1 = max(1ll, i - mid);
                ll y1 = max(1ll, j - mid);
                ll x2 = min(n, i + mid);
                ll y2 = min(m, mid + j);
                // dbg(x1, y1, x2, y2);
                ase = max(ase, pre[x2][y2] - pre[x2][y1 - 1] - pre[x1 - 1][y2] +
                                   pre[x1 - 1][y1 - 1]);
            }
        }
        // dbg(mid, ase, k);
        if (ase >= k) {
            h = mid - 1;
            ans = mid;
        } else
            l = mid + 1;
    }
    if (ans != 1e18)
        cout << ans << endl;
    else
        cout << -1 << endl;
}
int32_t main() {
    ios int t = 1;
    cin >> t;
    for (int ct = 1; ct <= t; ct++) {
        solve(ct);
    }
    rr;
}
