#include <bits/stdc++.h>
using namespace std;

#define maximum 10000
#define INF  10000
vector <int> edges[maximum+10];
vector <int> cost[maximum+10];
vector <int> path;
int par[maximum+10];

void path_print()
{
    reverse(path.begin(), path.end());
    for(int i = 0; i < path.size(); i++)
        cout << path[i] << " ";
    cout << endl;
}

void find_path(int source, int destination)
{
    if(source == destination) {
        path.push_back(source);
        return;
    }
    path.push_back(destination);
    find_path(source, par[destination]);
}
struct data {
    int city, dist;
    bool operator < (const data& p) const {
        return dist > p.dist;
    }
};

int second_closer_distance[maximum+10];

int dijsktra(int source, int destination)
{
    priority_queue <data> q;
    int distance[maximum+10];
    for(int i = 0; i <= maximum; i++)   distance[i] = INF;

    data u, v;
    u.city = source, u.dist = 0;
    distance[source] = 0;

    q.push(u);

    while(!q.empty()) {
        u = q.top();
        q.pop();
        if(u.city == destination)
            return distance[destination];

        int ucost = distance[u.city];
        int sz = edges[u.city].size();
        for(int i = 0; i < sz; i++) {
            v.city = edges[u.city][i], v.dist = ucost + cost[u.city][i];
            if(v.dist < distance[v.city]) {
                bool flag = false;
                if(distance[v.city] != INF) {
                    second_closer_distance[v.city] = distance[v.city];
                    flag = true;
                }
                distance[v.city] = v.dist;
                par[v.city] = u.city;
                if(flag == false)
                    second_closer_distance[v.city] = distance[v.city];
                q.push(v);
            }
        }
    }
    return distance[destination];


}
int main()
{
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;
    cout << "Enter all connected nodes: " << endl;
    for(int i = 1; i <= e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back(v);
        edges[v].push_back(u);
        cost[u].push_back(w);
        cost[v].push_back(w);
    }
    int source, destination;
    cout << "Enter source and destination node: ";
    cin >> source >> destination;

    int min_dist = dijsktra(source, destination);
    find_path(source, destination);
    cout << min_dist << endl;
    cout << second_closer_distance[destination] << endl;
    path_print();
    return 0;
}
