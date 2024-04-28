#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<pair<int, int>> graph[1005];
int dis[1005];

void dijkstra(int src)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    dis[src] = 0;
    while (!q.empty())
    {
        pair<int, int> parent = q.front();
        int node = parent.first;
        int cost = parent.second;
        q.pop();
        for (pair<int, int> child : graph[node])
        {
            int childNode = child.first;
            int childCost = child.second;

            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                q.push({childNode, dis[childNode]});
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for (int i = 0; i < n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(0);
    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }

    return 0;
}