
// if we need to find if there is any connection between two nodes, we can use adjacency matrix

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e;
    cin >> n >> e;
    int mat[n][n];
    memset(mat, 0, sizeof(mat));
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        //for unweighted graph giving value 1
        mat[a][b] = 1;

        //for weighted graph giving the value or cost
        //mat[a][b]= cost

        //for undirected graph
        mat[b][a] = 1;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int n1, n2;
        cin >> n1 >> n2;
        if (mat[n1][n2] == 1)
        {
            cout << "Connection ase" << endl;
        }
        else
            cout << "Connection nai" << endl;
    }
}



// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     int mat[n][n];
//     memset(mat, 0, sizeof(mat));
//     while (e--)
//     {
//         int a, b;
//         cin >> a >> b;
//         // for unweighted graph giving value 1
//         mat[a][b] = 1;

//         // for weighted graph giving the value or cost
//         // mat[a][b]= cost

//         // for undirected graph
//         mat[b][a] = 1;
//     }

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             cout << mat[i][j] << " ";
//         }
//         cout << endl;
//     }

//     // cheaking if there is any connection between two nodes
//     if (mat[3][1] == 1)
//         cout << "connection ase";
//     else
//         cout << "Connection nai";

//     return 0;
// }
