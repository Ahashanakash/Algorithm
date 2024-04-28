#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> d_graph[1005];
bool visit[1005];
bool pathVisit[1005];
bool ans = false;

void DFS(int src)
{
    visit[src] = true;
    pathVisit[src] = true;

    for (int child : d_graph[src])
    {
        if (pathVisit[child])
        {
            ans = true;
            return;
        }
        if (visit[child] == false)
        {
            //visit[child] = true;
            DFS(child);
        }
    }
    pathVisit[src] = false;
}

int main()
{
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        // undirected graph
        d_graph[a].push_back(b);
    }
    memset(visit, false, sizeof(visit));
    memset(pathVisit, false, sizeof(pathVisit));
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
        {
            DFS(i);
        }
    }
    if (ans)
        cout << "Cycle detected" << endl;
    else
        cout << "Cycle not detected" << endl;

    return 0;
}