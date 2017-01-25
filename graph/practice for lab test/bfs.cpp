#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define maximum 100000
#define inf 1000000
vector <int> edges[maximum];
vector <int> path;
int par[maximum];

void bfs_path(int source, int destination)
{
    if(source == destination) {
        path.push_back(source);
        return;
    }
    else {
        path.push_back(destination);
        bfs_path(source, par[destination]);
    }
}
int bfs(int source, int destination)
{
    queue <int> q;
    int visited[maximum] = {0};
    int level[maximum];
    for(int i = 0; i < maximum; i++)
        level[i] = inf;
    q.push(source);
    level[source] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        int sz = edges[cur].size();
        for(int i = 0; i < sz; i++) {
            if(level[edges[cur][i]] == inf) {
                level[edges[cur][i]] = level[cur]+1;
                par[edges[cur][i]] = cur;
                q.push(edges[cur][i]);
            }
        }
    }
    return level[destination];
}
int main()
{
    int N, E;
    cin >> N >> E;

    for(int i = 0; i < E; i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int source, destination;
    cin >> source >> destination;
    printf("Minimum distance from %d to %d: %d\n", source, destination, bfs(source, destination));
    printf("Path from %d to %d: ", source, destination);
    bfs_path(source, destination);
    for(int i = path.size()-1; i >= 0; i--)
        printf("%d ", path[i]);
    return 0;
}
