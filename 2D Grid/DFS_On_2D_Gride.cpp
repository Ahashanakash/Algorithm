#include <bits/stdc++.h>
using namespace std;

char arr[50][50];
bool visit[50][50];
vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
int n, e;
bool valid(int i, int j)
{
    if (src_i < 0 || i >= n || j < 0 || j >= e)
        return false;
    return true;
}
void dfs(int src_i, int sj)
{
    cout << src_i << " " << sj << endl;
    visit[src_i][sj] = true;
    for (int i = 0; i < 4; i++)
    {
        int ci = src_i + d[i].first;
        int cj = sj + d[i].second;
        if (valid(ci, cj) == true && visit[ci][cj] == false)
        {
            dfs(ci, cj);
        }
    }
}
int main()
{
    cin >> n >> e;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < e; j++)
        {
            cin >> arr[i][j];
        }
    }
    int si, sj;
    cin >> si >> sj;
    memset(visit, false, sizeof(visit));
    dfs(si, sj);
    return 0;
}