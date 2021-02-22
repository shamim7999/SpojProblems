#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const ll mx = 200005;
//const ll block = 700;
 
#define End cout << "\n"
 
ll a[mx], pre[mx], mm=2e18;
int sq, st, en;
 
void solve()
{
    int n;
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
 
    sq = sqrt(n)+1;
    //cout << sq << "\n";
    int sz=1, cnt=0;
    for(int i=1; i<=n; i++){
        ++cnt;
        mm = min(mm, a[i]);
        if(cnt == sq){
            pre[sz] = mm;
            mm = 2e18;
            cnt=0;
            ++sz;
        }
    }
 
    pre[sz] = 1e18;
    //++sz;
 
    //for(int i=1; i<=sz; i++)
        //cout << pre[i] << " ";
 
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        ++x, ++y;
        if(x>y)
            swap(x, y);
        st = (x/sq)+1+(x%sq != 0), en = y/sq;
 
        mm = 2e18;
 
        for(int i=x; i<=y && i<=(sq*(st-1)); i++)
            mm = min(a[i], mm);
        for(int i=max(x, (en*st)+1); i<=y; i++)
            mm = min(mm, a[i]);
        for(int i=st; i<=en; i++)
            mm = min(mm, pre[i]);
        cout << mm << "\n";
    }
}
 
 
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.in", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll tc=1;
    while(tc--)
        solve();
    return 0;
} 
