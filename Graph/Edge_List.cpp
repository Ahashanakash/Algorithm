

// we will use edge list, when we have to store the edges

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> v;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (pair<int, int> i : v)
    {
        cout << i.first << " " << i.second << endl;
    }
}

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int node, edge;
//     cin >> node >> edge;
//     vector<pair<int, int>> v;
//     while (edge--)
//     {
//         int a, b;
//         cin >> a >> b;
//         v.push_back({a, b});
//     }
//     for (auto i : v)
//     {
//         cout << i.first << " " << i.second << endl;
//     }

//     return 0;
// }