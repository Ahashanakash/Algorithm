#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1005];
bool visit[1005];
int level[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (auto child : graph[par])
        {
            if (visit[child] == false)
            {
                q.push(child);
                visit[child] = true;
                level[child] = level[par] + 1;
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
    memset(visit, false, sizeof(visit));
    memset(level, -1, sizeof(level));

    int src;
    cin >> src;
    BFS(src);

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << level[i] << endl;
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> graph[1005];
// int visit[1005];
// int level[1005];

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
//                 level[child] = level[parent] + 1;
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
//     int src;
//     cin >> src;
//     BFS(src);

//     for (int i = 0; i < n; i++)
//     {
//         cout << i << " " << level[i] << endl;
//     }

//     return 0;
// }