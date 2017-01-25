#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

#define inf 1000000
#define maximum 10000
vector <int> edges[maximum];
vector <int> v;
vector <int> path;
int par[maximum];

void bfs_path(int source, int destination)
{
   if(destination == source) {
        path.push_back(source);
        return;
   }
   else {
        path.push_back(destination);
        bfs_path(source, par[destination]);
   }
//   for(int i = path.size()-1; i >= 0; i--)
//        cout << path[i] << " ";
//   cout << endl;
}
int BFS(int source, int destination)
{
    queue< int > q;
    int visited[maximum] = {0};
    int level[maximum];
    for(int i = 0; i < maximum; i++)
        level[i] = inf;
    //memset(level, inf, maximum);
    q.push(source);
    level[source] = 0;
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
//        if(visited[cur] == 1)
//            continue;
//        visited[cur] = 1;
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
    printf("Enter node & edges number: ");
    scanf("%d %d", &N, &E);
    printf("Enter connected nodes:\n");
    for(int i = 0; i < E; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int source, destination;
    printf("Enter source & destination node: ");
    scanf("%d %d", &source, &destination);
    int shortest_path = BFS(source, destination);
    printf("Shortest path from %d to %d: %d\n", source, destination, shortest_path);
    bfs_path(source, destination);
    for(int i = path.size()-1; i >= 0; i--)
        cout << path[i] << " ";
    cout << endl;
    return 0;
}

