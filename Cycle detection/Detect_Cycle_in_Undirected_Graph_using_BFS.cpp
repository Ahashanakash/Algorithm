#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1005];
bool visit[1005];
int Parent_Array[1005];
int n, e;
bool ans;

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();

        for (int child : graph[parent])
        {
            if (visit[child] == true && Parent_Array[parent] != child)
                ans = true;
            if (visit[child] == false)
            {
                q.push(child);
                visit[child] = true;
                Parent_Array[child] = parent;
            }
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
            BFS(i);
    }

    if (ans)
        cout << "Cycle detected" << endl;
    else
        cout << "Cycle not detected" << endl;

    return 0;
}