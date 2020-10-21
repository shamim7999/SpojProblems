#include<bits/stdc++.h>
using namespace std;
#define mx 1200006
#define ll long long
 
int mod = 367;
int b = 37;
int preBase[mx], Hash_s1[mx], Hash_s2[mx];
int n1, n2, k;

string s1, s2;
 
void calc()
{
   preBase[0] = 1;
   for(int i=1; i<mx-4; i++){
        preBase[i] = preBase[i-1]*b;
        if(preBase[i]>=mod)
            preBase[i]%=mod;
   }
}
 
void Hashing()
{
   Hash_s1[n1] = 0;
   for(int i=n1-1; i>=0; i--){
        Hash_s1[i] = (Hash_s1[i+1]*b + (s1[i]-'a'+1));
        if(Hash_s1[i]>=mod)
            Hash_s1[i]%=mod;
   }
   Hash_s2[n2] = 0;
   for(int i=n2-1; i>=0; i--){
        Hash_s2[i] = (Hash_s2[i+1]*b + (s2[i]-'a'+1));
        if(Hash_s2[i]>=mod)
            Hash_s2[i]%=mod;
   }
}

bool okay(int st, int en, int pos)
{
    int tem = Hash_s1[en+1], sob = Hash_s1[st];
    int sz = en-st+1;
    tem*=preBase[sz];
    if(tem>=mod)
        tem%=mod;
    sob-=tem;
    if(sob<0)
        sob+=mod;
   

   int tem2 = Hash_s2[en+1-pos], sob2 = Hash_s2[st-pos];
    sz = en-st+1;
    tem2*=preBase[sz];
    if(tem2>=mod)
        tem2%=mod;
    sob2-=tem2;
    if(sob2<0)
        sob2+=mod;

 
    return sob == sob2;
}

void solve(int Case)
{
   int n, sum=0;
   cin >> s1 >> s2 >> k;
   n1 = s1.size(), n2 = s2.size();
   Hashing();
   for(int i=0; i<n1; i++){
       int be=i, en = i+n2-1, miss_match=0;
       if(en>=n1)
         break;
       for(int j=0; j<=k; j++){
           int left=be, right = en, miss=-1;
           while(left <= right){
               int mid = (left+right)/2;
               if(okay(left, mid, i)){
                   left = mid+1;
               }
               else{
                   miss = mid;
                   right = mid-1;
               }
           }

           if(miss !=-1){
               miss_match++;
               be = miss+1;
           }

           if(miss == -1){
               sum++;
               break;
           }
           if(be > en){
               sum+=(miss_match<=k);
               break;
           }

       }

   }
   cout << "Case " << Case << ": " << sum << "\n";
   
}

int main()
{
//    #ifndef ONLINE_JUDGE
//   freopen("D:\\Codings\\CPP\\input.in", "r", stdin);
//   freopen("D:\\Codings\\CPP\\output.in", "w", stdout);
//   #endif 
   ios_base::sync_with_stdio(0);
   cin.tie(0);
 
   int Case=0, t=1;
   //scanf("%d", &t);
   cin >> t;
   calc();
   while(++Case<=t)
      solve(Case);


}
