#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

bool subset_sum(int n, int arr[], int sum)
{
    if (n == 0)
    {
        if (sum == 0)
            return true;
        return false;
    }
    if (dp[n][sum] != -1)
    {
        return dp[n][sum];
    }

    if (arr[n-1] <= sum)
    {
        bool op1 = subset_sum(n - 1, arr, sum - arr[n-1]);
        bool op2 = subset_sum(n - 1, arr, sum);
        return dp[n][sum] = op1 || op2;
    }
    else
    {
        return dp[n][sum] = subset_sum(n - 1, arr, sum);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum;
    cin >> sum;
    memset(dp, -1, sizeof(dp));
    if (subset_sum(n, arr, sum))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}