#include<bits/stdc++.h>
using namespace std;
#define dd double
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 1005
#define mod 1000000007
#define fr first
#define cti(a) (a-48)
#define itc(a) char(a+48)
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld e, ld b){ return log(e)/log(b); }

vector <int> g[mx];
int par[mx][11],level[mx],tc;

int lca(int u, int v)
{
    if(level[u]<level[v]) swap(u,v);

    int diff = level[u]-level[v];

    while(diff>0){
        int cc = LOG(diff,2);
        u = par[u][cc];
        diff -= (1<<cc);
    }
    while(u!=v){
        int cc = LOG(level[u],2);
        // for(; cc>0 && par[u][cc] == par[v][cc]; cc--);
        if(cc>0 && par[u][cc] == par[v][cc]) cc=0;
        u = par[u][cc], v = par[v][cc];
    }
    return u;
}

int kth_parent(int u, int k)
{
    while(k>0){
        int cc = LOG(k,2);
        u = par[u][cc];
        k-=(1<<cc);
        if(u == -1) return u;
    }
    return u;
}

int dist(int u, int v)
{
    return level[u]+level[v]-(2*level[lca(u,v)]);
}

void dfs(int node, int baba)
{
    par[node][0]=baba, level[node] = 1+level[baba];
    for(auto it : g[node]) if(it!=baba) dfs(it,node);
}

void clr()
{
    for(int i=1; i<mx; i++) g[i].clear();
}

void solve(int kk)
{
    int q,n;
    cin >> n;

    for(int i=1; i<=n; i++){
        int mot;
        cin >> mot;
        while(mot--){
            int n1;
            cin >> n1;
            g[i].pb(n1), g[n1].pb(i);
        }
    }

   // for(int i=1,n1,n2; i<=edge; i++) cin >> n1 >> n2, g[n1].pb(n2), g[n2].pb(n1);
    memo(par, -1);
    memo(level,-1);
    dfs(1,-1);
    for(int j=1; j<=11; j++){
        for(int i=1; i<=n; i++){
            if(par[i][j-1]!=-1) par[i][j] = par[par[i][j-1]][j-1];
        }
    }

    cin >> q;
    cout << "Case " << kk <<  ":\n";
    while(q--){
        int aa,bb;
        cin >> aa >> bb;
        cout << lca(aa,bb) << "\n";
    }

    clr();

}

int main()
{
   fast;
   int kk=0;
   cin >> tc;
   while(++kk<=tc) solve(kk);

   return 0;
}
