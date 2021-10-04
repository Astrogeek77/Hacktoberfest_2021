#include <bits/stdc++.h>
using namespace std;
typedef int64_t i64;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ULL;

#define endl "\n"
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
void read(int &sum){sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) sum=-sum;}
void read(ll &sum){sum=0;char c=getchar( );bool f=0;while(c<'0' || c>'9') {if(c=='-') f=1;c=getchar( );}while(c>='0' && c<='9') {sum=sum*10+c-'0';c=getchar( );}if(f) sum=-sum;}
void readarr(ll a[], ll n){for(int i=0;i<n;i++)read(a[i]);}
void readarr(int a[], int n){for(int i=0;i<n;i++)read(a[i]);}
void aout(ll a[], ll n){for(int i=0;i<n;i++)cout<<a[i]<<" ";}
void aout(int a[], int n){for(int i=0;i<n;i++)cout<<a[i]<<" ";}
const int MAXN = (int)1e6 + 7;
const int MOD = (int)1e9 + 7;
const int INF = (int)2e9 + 7;
const ll LINF = (i64)1e18;
const ld PI = 3.1415926535897932384626433832795; 

int maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (int i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 
  
int main() 
{ 
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = maxSubArraySum(a, n); 
    cout << "Maximum contiguous sum is " << max_sum; 
    return 0; 
} 
