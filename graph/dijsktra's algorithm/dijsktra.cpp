#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

#define maximum 10000
#define INF 1000000
vector <int> edges[maximum];
vector <int> cost[maximum];
int N, E;

struct data {
    int city, dist;
    bool operator < ( const data& p) const {
        return dist > p.dist;
    }
};
int dijsktra(int source, int destination)
{
    priority_queue <data> q;
    vector <int> distance;
    for(int i = 0; i <= N; i++)
        distance.push_back(INF);

    data u, v;
    u.city = source, u.dist = 0;
    q.push(u);
    distance[source] = 0;
    while(!q.empty()) {
        u = q.top();
        int ucost = distance[u.city];
        q.pop();
        int sz = edges[u.city].size();
        for(int i = 0; i < sz; i++) {
            v.city = edges[u.city][i], v.dist = cost[u.city][i] + ucost;
            if(distance[v.city] > v.dist) {
                distance[v.city] = v.dist;
                q.push(v);
            }
        }
    }
    return distance[destination];
}
int main()
{
    scanf("%d %d", &N, &E);

    for(int i = 1; i <= E; i++) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        edges[x].push_back(y);
        cost[x].push_back(c);
    }
    int source, destination;
    scanf("%d %d", &source, &destination);
    int shortest_path = dijsktra(source, destination);
    printf("Shortest cost to reach from %d to %d: %d\n", source, destination, shortest_path);
    return 0;
}
