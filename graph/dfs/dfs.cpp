#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

#define maximum 100000
#define inf 100000

stack <int> s;
vector <int> edges[maximum];
vector <int> path;
int level[maximum];
int par[maximum];
void dfs_path(int source, int destination)
{
    if(source == destination) {
        path.push_back(source);
        return;
    }
    else {
        path.push_back(destination);
        dfs_path(source, par[destination]);
    }
}
int dfs(int source, int destination)
{
    s.push(source);
    while(!s.empty()) {
        int cur = s.top();
        int sz = edges[cur].size();
        for(int i = 0; i < sz; i++) {
            if(level[edges[cur][i]] > level[cur] + 1) {
                level[edges[cur][i]] = level[cur]+1;
                par[edges[cur][i]] = cur;
                dfs(edges[cur][i], destination);
            }
        }
        if(s.empty())
            break;
        s.pop();
    }
    return level[destination];
}
int main()
{
    int N, E;
    scanf("%d %d", &N, &E);

    for(int i = 0; i < E; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    int source, destination;
    scanf("%d %d", &source, &destination);
    for(int i = 1; i <= N; i++) {
        level[i] = inf;
    }
    level[source] = 0;
    printf("Minimum distance from %d to %d: %d\n", source, destination, dfs(source, destination));
    dfs_path(source, destination);
    for(int i = path.size()-1; i >= 0; i--)
        printf("%d ", path[i]);
    return 0;
}
