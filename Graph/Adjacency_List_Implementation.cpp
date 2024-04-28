
// we will use adjacency list, if we have to find the connected nodes of a graph

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> arr[n];
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        // for undirected graph
        arr[b].push_back(a);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int n1;
        cin >> n1;
        for (auto i : arr[n1])
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 1;
}


// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     vector<int> mat[n];
//     while (e--)
//     {
//         int a, b;
//         cin >> a >> b;
//         mat[a].push_back(b);
//         // for undirected graph
//         mat[b].push_back(a);
//     }

//     // kon noder shathe k k connected for example 3 no index
//     for (int i = 0; i < mat[3].size(); i++)
//     {
//         cout << mat[3][i] << " ";
//     }

//     return 0;
// }