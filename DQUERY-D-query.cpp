#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define nthElement(x) find_by_order(x)
#define lessThan(x) order_of_key(x)

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define dd double
#define pb push_back
#define eb emplace_back
#define ef emplace_front
#define em emplace
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define ll long long
#define ull unsigned long long
#define ld long double
#define mx 1000077
#define mod 1000000007
#define fr first
#define se second
#define End cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define memo(Array,val) memset(Array, val, sizeof Array)
#define PI acos(-1)
#define per(i) cout<<fixed<<setprecision(i)
#define con continue
#define all(ele) (ele).begin(),(ele).end()
#define Ones(x) __builtin_popcount(x)
#define len(ele) (ele).size()

template<typename... T> void get(T&... args) { ((cin >> args), ...); }

template<typename... T> void Get(T&... args){ ((getline(cin,args)), ...); }

template<typename... T> void print(T&&... args) { ((cout << args << ""), ...); }

bool check(ll n, ll pos){ return (n&(1<<pos)); }
bool Set(ll n, ll pos) {  return (n | (1<<pos)); }
ld LOG(ld b, ld e){ return log(b)/log(e); }
ld rad(ld x) {  return ((ld)PI*x)/180.0; }

/// Code Starts From Here.............................................///

int block, a[mx], cnt[mx], tc=1, ans[mx];

struct hello
{
    int L, R, idx;
}q[mx];

bool cmp(hello x, hello y)
{
    if(x.L/block != y.L/block){
        return x.L/block < y.L/block;
    }
    return x.R < y.R;
}

void solve(int kk)
{
    int n;
    cin >> n;
    block = sqrt(n);
    if(block*block != n) block++;

    for(int i=0; i<n; i++) cin >> a[i];
    int qq;
    cin >> qq;
    for(int i=0,l,r; i<qq; i++) cin >> l >> r, q[i].L = l-1, q[i].R = r-1, q[i].idx = i;
    sort(q,q+qq,cmp);

    int currSum=0;
    int currL=0, currR=-1;
    for(int i=0; i<qq; i++){
        int left = q[i].L, right = q[i].R;
        while(currL<left){
            ///currSum-=a[currL], currL++;
            cnt[a[currL]]--;
            if(cnt[a[currL]] == 0) currSum--;
            currL++;
        }
        while(currL>left){
            ///currSum+=a[currL-1], currL--;
            cnt[a[currL-1]]++;
            if(cnt[a[currL-1]] == 1) currSum++;
            currL--;
        }
        while(currR<=right){
            ///currSum+=a[currR], currR++;
            cnt[a[currR]]++;
            if(cnt[a[currR]] == 1) currSum++;
            currR++;
        }
        while(currR>right+1){
             ///currSum-=a[currR-1], currR--;
             cnt[a[currR-1]]--;
             if(cnt[a[currR-1]] == 0) currSum--;
             currR--;
        }
        ans[q[i].idx]=currSum;

       // cout << currSum << "\n";
    }


    for(int i=0; i<qq; i++)
        cout << ans[i] << "\n";

}

int main()
{
   //freopen("text.txt", "r", stdin);
   //freopen("text2.txt", "w", stdout);
   fast;
   int kk=0;
   //cin >> tc;
   //scanf("%d", &tc);
   while(++kk<=tc) solve(kk);

   return 0;
}
