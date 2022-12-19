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
