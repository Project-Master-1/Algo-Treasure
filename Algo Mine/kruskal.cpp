#include <bits/stdc++.h>
using namespace std;
int i, j, a, b, u, v, n, ne = 1, minn, minncost = 0, cost[9][9], parent[9];
int find(int);
int uni(int, int);
int main()
{
    cout << "Enter the number of vertex: ";
    cin >> n;

    cout << "Enter the adjacent matrix"<<endl;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    while (ne < n)
    {
        for (i = 1, minn = 999; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (cost[i][j] < minn)
                {
                    minn = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if(uni(u , v)){
            cout<<"Edge"<<ne++<<"("<<a<<","<<b<<") ="<<minn;
            minncost += minn;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    cout<<"minn cost is: "<<minncost;
    return 0;
}

int find(int i){
    while (parent[i])
    {
        i = parent[i];
    }
        return i;
    
}

int uni(int i , int j){
    if(i!=j){
        parent[j] = i;
        return 1;
    }
    return 0;
}
