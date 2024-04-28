#include <bits/stdc++.h>
using namespace std;

int knapsack(int n, int weight[], int value[], int bag_weight)
{
    if (bag_weight == 0 || n < 0)
        return 0;
    if (weight[n] <= bag_weight)
    {
        int op1 = knapsack(n - 1, weight, value, bag_weight - weight[n]) + value[n];
        int op2 = knapsack(n - 1, weight, value, bag_weight);
        return max(op1, op2);
    }
    else
    {
        int op2 = knapsack(n - 1, weight, value, bag_weight);
        return op2;
    }
}

int main()
{
    int n;
    cin >> n;
    int weight[n], value[n];
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> value[i];
    }
    int bag_weight;
    cin >> bag_weight;
    cout << knapsack(n, weight, value, bag_weight);
}