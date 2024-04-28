#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> graph[N];
bool visit[N];

void DFS(int src)
{
    cout << src << endl;
    visit[src] = true;
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
    int n, e;
    cin>>n>>e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(visit, false, sizeof(visit));
    int src;
    cin >> src;
    DFS(0);

    return 0;
}



// #include<bits/stdc++.h>
// using namespace std;
// const int N=1e5+5;
// vector<int> graph[N];
// bool visit[N];

// void DFS(int src)
// {
//     cout<<src<<endl;
//     visit[src]=true;
//     for (int child  : graph[src])
//     {
//         if(visit[child]==false)
//         {
//             DFS(child);
//         }
//     }

// }

// int main (){
//     int n,e;
//     cin>>n>>e;
//     while (e--)
//     {
//         int a,b;
//         cin>>a>>b;
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }
//     memset(visit,false,sizeof(visit));
//     DFS(0);

// return 0;
// }