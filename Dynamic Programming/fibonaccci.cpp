#include <bits/stdc++.h>
//dp
#define ll unsigned long long
using namespace std;

//dp
const ll N = 1e5 + 5; 
//dp
ll dp[N];             

ll fibo(ll n)
{
    if (n == 0 || n == 1)
        return n;
    //dp
    if (dp[n] != -1)
        return dp[n];
    
    ll ans = fibo(n - 1) + fibo(n - 2);
    //dp
    dp[n] = ans;
    return ans;
}

int main()
{
    ll n;
    cin >> n;
    //dp
    memset(dp, -1, sizeof(dp));
    cout << "fibonacci of " << n << " is " << fibo(n);
}