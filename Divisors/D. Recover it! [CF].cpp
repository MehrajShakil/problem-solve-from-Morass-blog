///   BISMILLAHIR RAHMANIR RAHEEM
///   ALLAH IS WATCHING ME
///   ALLAH save us from COVID-19.Amin.

///   █▀█─█──█──█▀█─█─█
///   █▄█─█──█──█▄█─█▄█
///   █─█─█▄─█▄─█─█─█─█

///   كُلُّ نَفْسٍ ذَآئِقَةُ الْمَوْت
///   Every soul shall taste death.


///   Author : Md Mehraj Hossain

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp> //order_of_key return number of elements less than x, find_by_order return index (pointer use kora lgbe)

using namespace std;
using namespace __gnu_pbds;

#define ull      unsigned long long
#define ll       long long
#define MOHAMMAD ios::sync_with_stdio(0);cin.tie(0);
#define ses      "\n"
#define all(x)   (x).begin(), (x).end()
#define INF      ((int)2e18)
#define pi       2*acos(0.0)
#define AE       cout << fixed << setprecision(8);

string digit="0123456789";
string small="abcdefghijklmnopqrstuvwxyz";
string capital="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int dx8[] = {0, 0, 1, 1, 1, -1, -1, -1}; // 8-direction.......
int dy8[] = {1,-1, 1, -1, 0, 0, -1, 1};
int dx4[]= {1,-1,0,0}; // 4-direction...........
int dy4[]= {0,0,1,-1};

const ll MAXN=1e7;
const ll MOD = 998244353 ;

template <class T> inline T bigmod(T p,T e,T M)
{
    if(e==0)
        return 1;
    if(e%2==0)
    {
        ll t=bigmod(p,e/2,M);
        return (T)((t*t)%M);
    }
    return (T)((ll)bigmod(p,e-1,M)*(ll)p)%M;
}

template <class T> inline T modinverse(T a,T M)
{
    return bigmod(a,M-2,M);   // when M is prime;
}

typedef tree< ll, null_type, less<ll>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pair<ll, ll>,null_type,less<pair<ll, ll>>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;

/// Fast read.
template<class T>inline bool read(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')
            sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}


//***********************************************  The END **********************************************************************************************************************************

/////////////////////////////////////////////////////////////////////////////
bitset<MAXN> bs;
vector<ll> primes,divv(MAXN+1,1);

void sieve()
{
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=4; i<=MAXN; i+=2)
        bs[i]=0;
    primes.push_back(2);
    for(ll i=3; i<=MAXN; i+=2)
    {
        if(bs[i])
        {
            primes.push_back(i);
            for(ll j=i*i; j<=MAXN; j+=i<<1)
                bs[j]=0;
        }
    }
}


void Gre_div()
{
    for(ll i=2; i<=MAXN; i++)
    {
        for(ll j = i+i; j<=MAXN; j+=i)
        {
            divv[j]=i;
        }
    }
}



////////////////////////////////////////////////////////////////////////////

//main function is here.........
int main()
{
    // MOHAMMAD
    sieve();
    Gre_div();
    // cout << primes.size() << endl;

    ll n,x;
    cin >> n;
    ll xx = n;
    map<ll,ll> occur;
    ll arr[2*n+1];
    for(ll i=1; i<=2*n; i++)
        cin >> arr[i],occur[arr[i]]++;
    sort(arr+1,arr+((2*n)+1));

    for(ll i=2*n; i>0; i--)
    {
        ll x = arr[i];
        if(!bs[x] and occur[x])
        {
            ll d = divv[x];
            if(occur[d])
            {
                cout << x << " ";
                occur[d]--;
                occur[x]--;
            }
        }
        if(bs[x] and occur[x] and x<=199999)
        {
            ll nth = primes[x-1];
            if(occur[nth])
            {
                cout << x << " ";
                occur[nth]--;
                occur[x]--;
            }
        }
    }
}

/*

  Alhamdulillah
*/

