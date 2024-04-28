#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;

int parent[N];
int size[N];

void dsuinitialize(int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i]=-1;
        size[i]=1;
    }
    
}

int dsu_find(int node)
{
    if(parent[node]==-1)return node;
    int leader = dsu_find(parent[node]);
    parent[node]=leader;
    return leader;
}

void union_by_size(int node1, int node2)
{
    int leaderA = dsu_find(node1);
    int leaderB = dsu_find(node2);
    if(size[leaderA]>size[leaderB])
    {
        parent[leaderB]=leaderA;
        size[leaderA]+=size[leaderB];
    }
    else
    {
        parent[leaderA]=leaderB;
        size[leaderB]+=size[leaderA];
    }
    
}

int main (){
    dsuinitialize(7);

    union_by_size(1,2);
    union_by_size(2,3);
    union_by_size(4,5);
    union_by_size(5,6);
    union_by_size(4,1);
    

    cout<<dsu_find(1)<<endl;
    cout<<dsu_find(4)<<endl;
;
return 0;
}