#include <bits/stdc++.h>
using namespace std;

int n, e;
vector<int> graph[1005];
bool visit[1005];
int Parent_Array[1005];
bool ans;

void DFS(int src)
{
    visit[src] = true;
    for (int child : graph[src])
    {
        if (visit[child] == true && Parent_Array[src] != child)
        {
            ans = true;
        }
        if (visit[child] == false)
        {
            Parent_Array[child] = src;
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
    ans = false;
    memset(visit, false, sizeof(visit));
    memset(Parent_Array, -1, sizeof(Parent_Array));
    for (int i = 0; i < n; i++)
    {
        if (!visit[i])
            DFS(i);
    }
    if (ans)
        cout << "Cycle ase";
    else
        cout << "Cycle nai";

    return 0;
}