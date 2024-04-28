#include <bits/stdc++.h>
using namespace std;

int dis[20][20];
char arr[20][20];
vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool vis[20][20];
int n, e;

bool valid(int ci, int cj)
{
    if (ci < 0 || ci >= n || cj < 0 || cj >= e)
        return false;
    return true;
}

void BFS(int src_i, int src_j)
{
    queue<pair<int, int>> q;
    q.push({src_i, src_j});
    vis[src_i][src_j] = true;
    dis[src_i][src_j] = 0;

    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first;
        int b = par.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ci = a + v[i].first;
            int cj = b + v[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
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
    memset(vis, false, sizeof(vis));
    memset(dis, -1, sizeof(dis));
    
    int src_i, src_j, des_i, des_j;
    cin >> src_i >> src_j >> des_i >> des_j;
    BFS(src_i, src_j);
    cout << dis[des_i][des_j];

    return 0;
}














// #include <bits/stdc++.h>
// using namespace std;

// bool vis[20][20];
// char arr[20][20];
// vector<pair<int, int>> v = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
// int dis[20][20];
// int n, e;

// bool valid(int ci, int cj)
// {
//     if (ci < 0 || ci >= n || cj < 0 || cj >= e)
//         return false;
//     return true;
// }

// void BFS(int src_i, int src_j)
// {
//     queue<pair<int, int>> q;
//     q.push({src_i, src_j});
//     vis[src_i][src_j] = true;
//     dis[src_i][src_j] = 0;

//     while (!q.empty())
//     {
//         pair<int, int> par = q.front();
//         int a = par.first;
//         int b = par.second;
//         q.pop();

//         for (int i = 0; i < 4; i++)
//         {
//             int ci = a + v[i].first;
//             int cj = b + v[i].second;
//             if (valid(ci, cj) == true && vis[ci][cj] == false)
//             {
//                 q.push({ci, cj});
//                 vis[ci][cj] = true;
//                 dis[ci][cj] = dis[a][b] + 1;
//             }
//         }
//     }
// }

// int main()
// {
//     cin >> n >> e;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < e; j++)
//         {
//             cin >> arr[i][j];
//         }
//     }
//     memset(vis, false, sizeof(vis));
//     memset(dis, -1, sizeof(dis));

//     int src_i, src_j, des_i, des_j;
//     cin >> src_i >> src_j >> des_i >> des_j;
//     BFS(src_i, src_j);
//     cout << dis[des_i][des_j];

//     return 0;
// }