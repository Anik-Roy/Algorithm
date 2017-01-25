#include <bits/stdc++.h>
using namespace std;

#define maximum 10000
#define INF 100000

int cost[100][100];
int next[100][100];

vector <int> path;
void find_path(int source, int destination)
{
    path.push_back(source);
    while(source != destination) {
        source = next[source][destination];
        path.push_back(source);
    }
}
int main()
{
    int n, e;
    cin >> n >> e; // enter node and edges number

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j)
                cost[i][j] = 0;
            else
                cost[i][j] = INF;
        }
    }
    for(int i = 1; i <= e; i++) { // enter all connected edges
        int u, v, w;
        cin >> u >> v >> w;
        cost[u][v] = w;
        next[u][v] = v;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(cost[i][j] > cost[i][k]+cost[k][j]) {
                    cost[i][j] = cost[i][k]+cost[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    int source, destination;
    while(scanf("%d %d", &source, &destination) == 2) {
        path.clear();
        cout << cost[source][destination] << endl;
        find_path(source, destination);
        for(int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
        cout << endl;
    }
    return 0;
}
