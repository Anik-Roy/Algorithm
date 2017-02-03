#include <bits/stdc++.h>
using namespace std;

#define MAX 10000
#define INF 1e9

//struct data {
//    int src;
//    pair <int, int> des_cost;
//};

int v, e;
vector < vector < pair <int, int> > > edges;
int dist[MAX];

int bellman_ford(int src)
{
    for(int i = 1; i <= v; i++)
        dist[i] = INF;
    dist[src] = 0;

    for(int i = 1; i <= v-1; i++) {
        for(int j = 1; j <= e; j++) {
            for(int k = 0; k < (int)edges[j].size(); k++) {
                pair <int, int> v = edges[j][k];
                if(dist[v.first] > dist[j]+v.second)
                    dist[v.first] = dist[j]+v.second;
            }
        }
    }
    for(int i = 1; i <= v; i++) {
        for(int j = 0; j < (int)edges[i].size(); j++) {
            pair <int, int> v = edges[i][j];
            if(dist[v.first] > dist[i] + v.second)
                return -1;
        }
    }
    return 0;
}

int main()
{
    cin >> v >> e;

    edges.assign(v+10, vector < pair <int, int> >()); // assign blank vector's of pair<int, int> to edges
    for(int i = 1; i <= e; i++) {
        int u, v, c;
        cin >> u >> v >> c;

        edges[u].push_back(make_pair(v, c));
    }

    int src = 1;

    int res = bellman_ford(src);

    if(res == -1)
        printf("Negative cycle detected.\n");
    else {
        for(int i = 1; i <= v; i++) {
            printf("Source: %d-------Destination: %d--------Cost: %d\n", src, i, dist[i]);
        }
    }
    return 0;
}
