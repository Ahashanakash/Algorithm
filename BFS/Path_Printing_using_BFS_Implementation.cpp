#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1005];
bool visit[1005];
int level[1005];
int parent[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : graph[par])
        {
            if (visit[child] == false)
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(level, -1, sizeof(level));
    memset(visit, false, sizeof(visit));
    memset(parent, -1, sizeof(parent));
    int src, des;
    cin >> src >> des;
    BFS(src);
    vector<int> v;
    int x = des;
    while (x != -1)
    {
        v.push_back(x);
        x = parent[x];
    }
    reverse(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i << " ";
    }

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> graph[1005];
// int visit[1005];
// int level[1005];
// int par[1005];

// void BFS(int src)
// {
//     queue<int> q;
//     q.push(src);
//     visit[src] = true;
//     while (!q.empty())
//     {
//         int parent = q.front();
//         q.pop();
//         for (int child : graph[parent])
//         {
//             if (visit[child] == false)
//             {
//                 q.push(child);
//                 visit[child] = true;
//                level[child] = level[parent] + 1;
//                 par[child] = parent;
//             }
//         }
//     }
// }

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     while (e--)
//     {
//         int a, b;
//         cin >> a >> b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }
//     memset(visit, false, sizeof(visit));
//     memset(level, -1, sizeof(visit));
//     memset(par, -1, sizeof(par));
//     int src, des;
//     cin >> src >> des;
//     BFS(src);
//     vector<int> path;
//     while (des != -1)
//     {
//         path.push_back(des);
//         des = par[des];
//     }
//     reverse(path.begin(), path.end());
//     for (auto i : path)
//     {
//         cout << i << " ";
//     }

//     return 0;
// }