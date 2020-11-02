
///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME


//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█



///   ALLAH save us from COVID-19.Amin.

///   Every soul shall taste death.

///   Tag ::

/*
                                 ---------------------------
                                    #BoycottFrenceProducts
                                 ---------------------------
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>



///  order_of_key return number of elements less than x.
///  find_by_order return index.
using namespace std;
using namespace __gnu_pbds;


#define MOHAMMAD        ios::sync_with_stdio(0);cin.tie(0);
#define all(x)          (x).begin(), (x).end()
#define AE              cout << fixed << setprecision(10);
#define ld              double


/// faster.
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};


using ll = long long;
const ll MOD = 998244353 ;

bool check ( ll a , ll b ){
    return (a - (b*(a/b))) == 0;
}


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
const int N = 1e6 + 1;
const ll INF = 1e18;
const ll limit = (1LL<<64) - 1;
const ld EPS   = 1e-6;
const ll K = 1e5 + 1;


/// Global...

bitset < N > bs;
vector < ll > primes;

void sieve ( ){
    bs.set();
    bs[0] = bs[1] = 0;
    for ( ll i = 2 ; i < N ; i++ ){
         if ( bs[i] ){
           primes.push_back ( i );
           for ( ll j = i*i ; j < N ; j+=i ) bs[j] = 0;
         }
    }
}

ll phi( ll n ){

 ll res = n;

 for ( auto p : primes ){
      if ( p*p>n ) break;
      if ( n%p == 0 ){
          while ( n%p == 0 ) n/=p;
          res-=(res/p);
      }
 }
 if ( n>1 ){
     res-=(res/n);
 }
 return res;
}

void solve ( ll tc ){

  ll n , q;
  cin >> n >> q;

  vector < ll > div;
  vector < pair < ll , ll > > prefix;

  for ( ll i = 1 ; i*i < n ; i++ ){
       if ( n%i ) continue;
       ll d1 = i;
       ll d2 = n/i;
       div.push_back(d1);
       if ( d1!=d2 ) div.push_back(d2);
  }
  cout << "Case " << tc << "\n";
  sort ( all ( div ) );
  ll sum = 0;
  for ( auto d : div ){
       sum+=phi(n/d);
       prefix.push_back( { d , sum } );
  }
  while ( q-- ){
      ll x;
      cin >> x;
      pair < ll , ll > p = { x , 0 };
      ll idx = lower_bound ( prefix.begin() , prefix.end() , p ) - prefix.begin();
      if ( idx==prefix.size() ) {
         cout << n << "\n";
      }
      else{
          if ( prefix[idx].first != x ) idx--;
          if ( idx < 0 ) cout << 0 << "\n";
          else cout << prefix[idx].second << "\n";
      }
  }

  return;
}


int main()
{
    MOHAMMAD

    /*
    #ifdef OJ
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    */
    sieve();

    int t = 1 , tc = 0;
    cin >> t;


    while ( t-- ){
       solve( ++tc  );
    }
}



/*
Explanation:

 Time : 0.220s.



----------------------------------------------------------------------------------------------------------------



  Alhamdulillah
*/
