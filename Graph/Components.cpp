#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> graph[1005];
bool visit[1005];

void DFS(int src)
{
    visit[src] = true;
    cout << src << endl;
    for (int child : graph[src])
    {
        if (visit[child] == false)
        {
            DFS(child);
        }
    }
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(visit, false, sizeof(visit));
    for (int i = 0; i < n; i++)
    {
        if (visit[i] == false)
        {
            DFS(i);
        }
    }

    return 0;
}