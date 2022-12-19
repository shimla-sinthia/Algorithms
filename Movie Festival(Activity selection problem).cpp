//Greedy Approch


//Bismillah Hir Rehmanir Rahim
//Allah knows best
using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#define endl "\n"
#include <bits/stdc++.h>
#define mini -10000000000000000
#define ios ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define f(i, a, n) for( i=a; i<n;i++)
#define ll long long
#define pi 3.141592653589793
#define vi              vector<int>
#define si              set<int>
#define pb              push_back
#define mp              make_pair
#define mod             1000000007
#define rr              return 0
#define ff              first
#define in              insert
#define ss              second
typedef pair<int, int> pii;
#define setbits(x)      builtin_popcountll(x)
#define zrbits(x)       builtin_ctzll(x)
#define deb(x)          cout << #x << " = " << x << endl
#define set_bit(x, idx) x = x|1LL<<idx
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define toggle_bit(x, idx) x = x^(1LL<<idx)
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using    namespace __gnu_pbds;
#define multi_ordered_set       tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> rordered_set;
#ifdef DEBUG
#define ok cerr << __LINE__ <<"is done "<<endl;
#else
#define ok 
#endif
int main()
{
    ios;
    #ifdef DEBUG
    freopen("in", "r", stdin);
    #endif
    ll i,j,k,n,m;
    cin>>n;
    vector<pair<ll,ll> > p;
    for(i=0;i<n;i++)
    {
        ll a,b;
        cin>>a>>b;
        p.pb({b,a});
    }
    sort(p.begin(),p.end());
    ll cnt=1,mx=0;
    ll l=p[0].ff;
    for(i=1;i<n;i++)
    {
        if(p[i].ss>=l)
        {
            l=p[i].ff;
            cnt++;
        }
        mx=max(cnt,mx);
    }
    mx=max(mx,cnt);
    cout<<mx<<endl;
    rr;
}


//Dp Approch


//Bismillah Hir Rehmanir Rahim
//Allah knows best
#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using    namespace __gnu_pbds;
#define gap ' '
#define mini -10000000000000000
#define endl '\n'
#define f(i, a, n) for(int i=a; i<n;i++)
#define int long long
#define ll long long
#define pi 3.141592653589793
#define vi              vector<int>
#define si              set<int>
#define pb              push_back
#define mp              make_pair
#define mod             1000000007
#define rr              return 0
#define ff              first
#define in              insert
#define ss              second
int hash58 = 288230376151711717;
int hash32 = 1610612741;
#define erase_unique(st)  st.erase(unique(st.begin(), st.end()),st.end())
#define all(a) a.begin(), a.end()
typedef pair<int, int> pii;
#define setbits(x)      __builtin_popcountll(x)
#define zrbits(x)       __builtin_ctzll(x)
#define unset_bit(x,inx) x = (x & ~(1ll<<(inx)))
#define set_bit(x, idx) x = x|1LL<<idx
#define check_bit(x, idx) min(x&(1LL<<idx),1LL)
#define toggle_bit(x, idx) x = x^(1LL<<idx)
#define maxheap                  priority_queue<int>
#define minheap                  priority_queue<int, vector<int>, greater<int>>
#define maxheap2                 priority_queue<pair<int,int>>
#define minheap2                 priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>
inline int uceil(int a,int b) {return (a % b ? a / b + 1 : a / b);}
#define ordered_set             tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#ifdef DEBUG
#include "tpc.hpp"
#define ios
#define dbg(...) {cerr << __LINE__ << " : " ;cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__);}
#define ok tikkk
#else
#define ios {ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);}
#define dbg(...) 
#define ok
#endif
#define ld long double
const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
 
ll n, dp[200005];
vector<pii>a;
 
ll solve2(ll pos)
{
    if(pos >= n)
    return 0;
    if(dp[pos] != -1)
    return dp[pos];
    pii d = mp(a[pos].ss, 0);
    ll nxt = lower_bound(all(a), d) - a.begin();
    return dp[pos] = max(1 + solve2(nxt), solve2(pos + 1));
}
 
void solve(int ct) {
    cin >> n;
    for(int i= 0; i < n; i++)
    {
        ll u, v;
        cin >> u >> v;
        a.pb({u, v});
    }
    sort(all(a));
    memset(dp, -1, sizeof(dp));
    ll ans = solve2(0);
    cout << ans << endl;
}
int32_t main()
{
    ios
    int t=1;
    //cin>>t;
    for(int ct = 1; ct <= t; ct++){
        solve(ct);
    }
    rr;
}
