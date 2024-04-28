#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1005];
bool visit[1005];

void BFS(int src)
{
    queue<int> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        cout << parent << endl;
        for (auto child : graph[parent])
        {
            if (visit[child] == false)
            {
                q.push(child);
                visit[child] = true;
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
    BFS(0);
}

// #include<bits/stdc++.h>
// using namespace std;

// vector<int> graph[1005];
// bool visit[1005];

// void BFS(int src)
// {
//     queue<int>q;
//     q.push(src);
//     visit[src]=true;
//     while (!q.empty())
//     {
//         int parent=q.front();
//         q.pop();
//         cout<<parent<<" ";
//         for (auto child : graph[parent])
//         {
//             if (visit[child]==false)
//             {
//                 q.push(child);
//                 visit[child]=true;
//             }

//         }

//     }

// }

// int main (){
//     int node,edge;
//     cin>>node>>edge;
//     while (edge--)
//     {
//         int a,b;
//         cin>>a>>b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }
//     int src;
//     cin>>src;
//     memset(visit,false,sizeof(visit));
//     BFS(src);

// return 0;
// }