///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   Every soul shall taste death.

///   Tag ::

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>


///  order_of_key return number of elements less than x.
///  find_by_order return index.
using namespace std;
using namespace __gnu_pbds;


#define MOHAMMAD  ios::sync_with_stdio(0);cin.tie(0);
#define all(x)    (x).begin(), (x).end()
#define AE        cout << fixed << setprecision(10);
#define ld        double


/// faster.
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

using ll = long long;
const ll MOD = 1e9 + 7;

typedef tree< int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

//debug
template<typename F,typename S>ostream&operator<<(ostream&os,const pair<F,S>&p){return os<<"("<<p.first<<", "<<p.second<<")";}
template<typename T>ostream&operator<<(ostream&os,const vector<T>&v){os<<"{";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"}";}
template<typename T>ostream&operator<<(ostream&os,const set<T>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<",";os<<*it;}return os<<"]";}
template<typename T>ostream&operator<<(ostream&os,const multiset<T>&v) {os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<*it;}return os<<"]";}
template<typename F,typename S>ostream&operator<<(ostream&os,const map<F,S>&v){os<<"[";for(auto it=v.begin();it!=v.end();++it){if(it!=v.begin())os<<", ";os<<it->first<<" = "<<it->second;}return os<<"]";}
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu(){cerr << endl;}
template<typename T>void faltu(T a[],int n){for(int i=0;i<n;++i)cerr<<a[i]<<' ';cerr<<endl;}
template<typename T,typename...hello>void faltu(T arg,const hello&...rest){cerr<<arg<<' ';faltu(rest...);}
//#else
//#define dbg(args...)

/// Modular arithmetic
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }  /// When MOD is prime.
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }

//***********************************************  The END **********************************************************************************************************************************
const ll N = 4e5 + 1;
const ll INF = 1e18;
const ll limit = (1LL<<64) - 1;
const ld EPS   = 1e-8;
const ll K = 20;
bitset < N+1 > bs;
vector < ll > primes;
vector < ll > e[N+1] , pfk;

void sieve ( ){
bs.set();
bs[0] = bs[1] = 0;
for ( ll i = 2 ; i<=N ; ++i ){
     if ( bs[i] ) {
         primes.push_back( i );
         for ( ll j = i * i ; j<=N ; j+=i ) bs[j] = 0;
     }
}
return;
}

void solve ( ){

  ll n , k , cur = 1;
  cin >> n >> k;
  ll arr[n];
  for ( ll i = 0 ; i < n ; ++i ) cin >> arr[i];
  map < ll , ll > id , oc , to;

  if ( k==1 ){
      cout << n*(n+1)/2;
      return;
  }

  /// prime factorize of k.
  for ( auto p : primes ){
       if ( p*p>k ) break;
       while ( k%p == 0 ){
             k/=p;
             if ( id[p] == 0 ) id[p] = cur++ , to[cur-1] = p;
             oc[p]++;
       }
       if ( id[p] ) pfk.push_back(p);
  }
  if ( k>1 ){
         id[k] = cur++;
         pfk.push_back(k);
         oc[k]++;
         to[cur-1] = k;
  }

  /// take all factor index.

  for ( ll i = 0 ; i < n ; ++i ){
       ll curr = arr[i];

       for ( auto p : pfk ){
       // if ( p*p>curr ) break;
       while ( curr%p == 0 ){
             curr/=p;
             ll pos = id[p];
             if ( pos>0 ) e[pos].push_back ( i );
             }
       }
       if ( curr>1 ){
         if ( id[curr]>0 ) e[id[curr]].push_back ( i );
        }
  }

  ll way = 0;
  dbg ( cur );
  /*
  for ( ll i = 1 ; i < cur ; ++i ){

       for ( ll j = 0 ; j<e[i].size() ; j++ )   {
            cout << e[i][j] << "\n";
       }
  }
  */

  for ( ll i = 0 ; i < n ; ++i ){
       ll mn = INF;
       for ( ll j = 1 ; j<cur ; j++ ){
            ll need = oc[to[j]];
            auto pos = lower_bound( e[j].begin() , e[j].end() , i );
            if ( pos == e[j].end() ) { mn = 0 ; break;}

            ll idx = pos - e[j].begin();

            idx+=(need-1);

            if ( idx>=e[j].size() ) { mn = 0 ; break;}

            ll rem = (n) - e[j][idx];
            mn = min ( mn , rem );
       }
       if ( mn == 0 ) break;
       way+=mn;
  }

  cout << way << "\n";







}


int main()
{

    MOHAMMAD
    sieve ( );
    int t = 1 , tc = 0;
    /// cin >> t;

    while ( t-- ){
          solve (  );
    }
}



/*
Explanation:





----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/
